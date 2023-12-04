#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

// Define the structure of the schedule element
#include <stdint.h> // To use the variable of type uint??_t...

typedef struct
{
	void (*pTask)();
	uint32_t delay;			// Unsigned integer 32-bit : The amount of delay before executing the task
	uint32_t period;		// Unsigned integer 32-bit : The time executing the task
	uint8_t runMe;			// Unsigned integer 8-bit : The number of times the task need to execute
	uint32_t taskID;		// Unsigned integer 32-bit : A unique identifier for the task (optional)
} sTasks;

#define SCH_MAX_TASKS 40	// Define the max number of tasks that a scheduler can hold
#define NO_TASKS_ID	0		// ...

void SCH_Init(void);
void SCH_Add_Task(void (*pFunction)(), uint32_t delay, uint32_t period);
void SCH_Update (void);
void SCH_Dispatch_Tasks (void);
void SCH_Delete_Tasks(int index);

#endif /* INC_SCHEDULER_H_ */
