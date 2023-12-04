#include "task.h"
#include "main.h"
#include "global.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int calc_digit(int num)
{
	int res = 1;
	while(1)
	{
		if (num % 10 != num)
		{
			res++;
			num = num / 10;
		}
		else
			return res;
	}
}

void display7SEG()
{
	char str1[] = "Time : ";
	char str2[calc_digit(time_unit)];
	sprintf(str2, "%d", time_unit);
	char str3[] = ", Task display7SEG scheduled\r\n";
	HAL_UART_Transmit(&huart2, str1, sizeof(str1), 1000);
	HAL_UART_Transmit(&huart2, str2, sizeof(str2), 1000);
	HAL_UART_Transmit(&huart2, str3, sizeof(str3), 1000);
	int count = rand() % 10;
	switch(count)
	{
		case 0:
			HAL_GPIO_WritePin(GPIOB, SEG0_Pin, RESET);
			HAL_GPIO_WritePin(GPIOB, SEG1_Pin, RESET);
			HAL_GPIO_WritePin(GPIOB, SEG2_Pin, RESET);
			HAL_GPIO_WritePin(GPIOB, SEG3_Pin, RESET);
			HAL_GPIO_WritePin(GPIOB, SEG4_Pin, RESET);
			HAL_GPIO_WritePin(GPIOB, SEG5_Pin, RESET);
			HAL_GPIO_WritePin(GPIOB, SEG6_Pin, SET);
			break;
		case 1:
			HAL_GPIO_WritePin(GPIOB, SEG0_Pin, SET);
			HAL_GPIO_WritePin(GPIOB, SEG1_Pin, RESET);
			HAL_GPIO_WritePin(GPIOB, SEG2_Pin, RESET);
			HAL_GPIO_WritePin(GPIOB, SEG3_Pin, SET);
			HAL_GPIO_WritePin(GPIOB, SEG4_Pin, SET);
			HAL_GPIO_WritePin(GPIOB, SEG5_Pin, SET);
			HAL_GPIO_WritePin(GPIOB, SEG6_Pin, SET);
			break;
		case 2:
			HAL_GPIO_WritePin(GPIOB, SEG0_Pin, RESET);
			HAL_GPIO_WritePin(GPIOB, SEG1_Pin, RESET);
			HAL_GPIO_WritePin(GPIOB, SEG2_Pin, SET);
			HAL_GPIO_WritePin(GPIOB, SEG3_Pin, RESET);
			HAL_GPIO_WritePin(GPIOB, SEG4_Pin, RESET);
			HAL_GPIO_WritePin(GPIOB, SEG5_Pin, SET);
			HAL_GPIO_WritePin(GPIOB, SEG6_Pin, RESET);
			break;
		case 3:
			HAL_GPIO_WritePin(GPIOB, SEG0_Pin, RESET);
			HAL_GPIO_WritePin(GPIOB, SEG1_Pin, RESET);
			HAL_GPIO_WritePin(GPIOB, SEG2_Pin, RESET);
			HAL_GPIO_WritePin(GPIOB, SEG3_Pin, RESET);
			HAL_GPIO_WritePin(GPIOB, SEG4_Pin, SET);
			HAL_GPIO_WritePin(GPIOB, SEG5_Pin, SET);
			HAL_GPIO_WritePin(GPIOB, SEG6_Pin, RESET);
			break;
		case 4:
			HAL_GPIO_WritePin(GPIOB, SEG0_Pin, SET);
			HAL_GPIO_WritePin(GPIOB, SEG1_Pin, RESET);
			HAL_GPIO_WritePin(GPIOB, SEG2_Pin, RESET);
			HAL_GPIO_WritePin(GPIOB, SEG3_Pin, SET);
			HAL_GPIO_WritePin(GPIOB, SEG4_Pin, SET);
			HAL_GPIO_WritePin(GPIOB, SEG5_Pin, RESET);
			HAL_GPIO_WritePin(GPIOB, SEG6_Pin, RESET);
			break;
		case 5:
			HAL_GPIO_WritePin(GPIOB, SEG0_Pin, RESET);
			HAL_GPIO_WritePin(GPIOB, SEG1_Pin, SET);
			HAL_GPIO_WritePin(GPIOB, SEG2_Pin, RESET);
			HAL_GPIO_WritePin(GPIOB, SEG3_Pin, RESET);
			HAL_GPIO_WritePin(GPIOB, SEG4_Pin, SET);
			HAL_GPIO_WritePin(GPIOB, SEG5_Pin, RESET);
			HAL_GPIO_WritePin(GPIOB, SEG6_Pin, RESET);
			break;
		case 6:
			HAL_GPIO_WritePin(GPIOB, SEG0_Pin, RESET);
			HAL_GPIO_WritePin(GPIOB, SEG1_Pin, SET);
			HAL_GPIO_WritePin(GPIOB, SEG2_Pin, RESET);
			HAL_GPIO_WritePin(GPIOB, SEG3_Pin, RESET);
			HAL_GPIO_WritePin(GPIOB, SEG4_Pin, RESET);
			HAL_GPIO_WritePin(GPIOB, SEG5_Pin, RESET);
			HAL_GPIO_WritePin(GPIOB, SEG6_Pin, RESET);
			break;
		case 7:
			HAL_GPIO_WritePin(GPIOB, SEG0_Pin, RESET);
			HAL_GPIO_WritePin(GPIOB, SEG1_Pin, RESET);
			HAL_GPIO_WritePin(GPIOB, SEG2_Pin, RESET);
			HAL_GPIO_WritePin(GPIOB, SEG3_Pin, SET);
			HAL_GPIO_WritePin(GPIOB, SEG4_Pin, SET);
			HAL_GPIO_WritePin(GPIOB, SEG5_Pin, SET);
			HAL_GPIO_WritePin(GPIOB, SEG6_Pin, SET);
			break;
		case 8:
			HAL_GPIO_WritePin(GPIOB, SEG0_Pin, RESET);
			HAL_GPIO_WritePin(GPIOB, SEG1_Pin, RESET);
			HAL_GPIO_WritePin(GPIOB, SEG2_Pin, RESET);
			HAL_GPIO_WritePin(GPIOB, SEG3_Pin, RESET);
			HAL_GPIO_WritePin(GPIOB, SEG4_Pin, RESET);
			HAL_GPIO_WritePin(GPIOB, SEG5_Pin, RESET);
			HAL_GPIO_WritePin(GPIOB, SEG6_Pin, RESET);
			break;
		case 9:
			HAL_GPIO_WritePin(GPIOB, SEG0_Pin, RESET);
			HAL_GPIO_WritePin(GPIOB, SEG1_Pin, RESET);
			HAL_GPIO_WritePin(GPIOB, SEG2_Pin, RESET);
			HAL_GPIO_WritePin(GPIOB, SEG3_Pin, RESET);
			HAL_GPIO_WritePin(GPIOB, SEG4_Pin, SET);
			HAL_GPIO_WritePin(GPIOB, SEG5_Pin, RESET);
			HAL_GPIO_WritePin(GPIOB, SEG6_Pin, RESET);
			break;
		default:
			break;
		}
}

void toggle_yellow()
{
	char str1[] = "Time : ";
	char str2[calc_digit(time_unit)];
	sprintf(str2, "%d", time_unit);
	char str3[] = ", Task toggle_yellow scheduled\r\n";
	HAL_UART_Transmit(&huart2, str1, sizeof(str1), 1000);
	HAL_UART_Transmit(&huart2, str2, sizeof(str2), 1000);
	HAL_UART_Transmit(&huart2, str3, sizeof(str3), 1000);
	HAL_GPIO_TogglePin(GPIOA, LED3_Pin);
}
void toggle_red()
{
	char str1[] = "Time : ";
	char str2[calc_digit(time_unit)];
	sprintf(str2, "%d", time_unit);
	char str3[] = ", Task toggle_red scheduled\r\n";
	HAL_UART_Transmit(&huart2, str1, sizeof(str1), 1000);
	HAL_UART_Transmit(&huart2, str2, sizeof(str2), 1000);
	HAL_UART_Transmit(&huart2, str3, sizeof(str3), 1000);
	HAL_GPIO_TogglePin(GPIOA, LED1_Pin);
}
void toggle_green()
{
	char str1[] = "Time : ";
	char str2[calc_digit(time_unit)];
	sprintf(str2, "%d", time_unit);
	char str3[] = ", Task toggle_green scheduled\r\n";
	HAL_UART_Transmit(&huart2, str1, sizeof(str1), 1000);
	HAL_UART_Transmit(&huart2, str2, sizeof(str2), 1000);
	HAL_UART_Transmit(&huart2, str3, sizeof(str3), 1000);
	HAL_GPIO_TogglePin(GPIOA, LED2_Pin);
}
void toggle_orange()
{
	char str1[] = "Time : ";
	char str2[calc_digit(time_unit)];
	sprintf(str2, "%d", time_unit);
	char str3[] = ", Task toggle_orange scheduled\r\n";
	HAL_UART_Transmit(&huart2, str1, sizeof(str1), 1000);
	HAL_UART_Transmit(&huart2, str2, sizeof(str2), 1000);
	HAL_UART_Transmit(&huart2, str3, sizeof(str3), 1000);
	HAL_GPIO_TogglePin(GPIOA, LED4_Pin);
}
void toggle_pink()
{
	char str1[] = "Time : ";
	char str2[calc_digit(time_unit)];
	sprintf(str2, "%d", time_unit);
	char str3[] = ", Task toggle_pink scheduled\r\n";
	HAL_UART_Transmit(&huart2, str1, sizeof(str1), 1000);
	HAL_UART_Transmit(&huart2, str2, sizeof(str2), 1000);
	HAL_UART_Transmit(&huart2, str3, sizeof(str3), 1000);
	HAL_GPIO_TogglePin(GPIOA, LED5_Pin);
}

