#include "scheduler.h"
#include "global.h"
#include "task.h"
#include <stdint.h>
#include <stdio.h>
// The structure of the current scheduler is an array (can be a stack, queue, tree,...)
sTasks SCH_Tasks_G[SCH_MAX_TASKS];

// An index variable that helps manage the vacant, occupied slots in the scheduler
int current_idx_task = 0;

void SCH_Init(void)
{
	for (int i = 0; i < SCH_MAX_TASKS; i++)
		SCH_Delete_Tasks(i);
	current_idx_task = 0; // Just in case (could delete this line)
}

void SCH_Add_Task (void (*pFunction)(), uint32_t delay, uint32_t period)
{
	if (current_idx_task < SCH_MAX_TASKS)
	{
		SCH_Tasks_G[current_idx_task].pTask = pFunction;
		SCH_Tasks_G[current_idx_task].delay = delay/CLOCK_TICK;
		SCH_Tasks_G[current_idx_task].period = period/CLOCK_TICK;
		SCH_Tasks_G[current_idx_task].runMe = 0;
		SCH_Tasks_G[current_idx_task].taskID = current_idx_task; // Temporarily set
		current_idx_task++; // Update the index to the next slot
	}
}

void SCH_Update(void)
{
	time_unit++;
	for(int i = 0; i < current_idx_task; i++) // Travese all active tasks
	{
		if (SCH_Tasks_G[i].pTask == 0)
			continue;
		if (SCH_Tasks_G[i].delay > 0)
			SCH_Tasks_G[i].delay--;
		else
		{
			SCH_Tasks_G[i].delay = SCH_Tasks_G[i].period;
			SCH_Tasks_G[i].runMe += 1;
		}
	}
}
void SCH_Dispatch_Tasks(void) // Runs in the super-loop
{

	for (int i = 0; i < current_idx_task; i++)
	{
		if (SCH_Tasks_G[i].pTask == 0)
			continue;
		if (SCH_Tasks_G[i].runMe > 0)
		{
			(*SCH_Tasks_G[i].pTask)();
			SCH_Tasks_G[i].runMe--; // Must put in line first
			if (SCH_Tasks_G[i].period == 0)
				SCH_Delete_Tasks(i);
		}
	}
}

void SCH_Delete_Tasks(int index)
{
	if (SCH_Tasks_G[index].pTask == 0){}
	else
	{
		SCH_Tasks_G[index].pTask = 0x0000;
		SCH_Tasks_G[index].delay = 0;
		SCH_Tasks_G[index].period = 0;
		SCH_Tasks_G[index].runMe = 0;
	}
	return;
}



