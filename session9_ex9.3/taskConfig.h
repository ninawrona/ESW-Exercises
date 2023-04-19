#pragma once

/* Priorities at which the tasks are created. */
#define TASK_MY_TASK_PRIORITY (tskIDLE_PRIORITY + 1)
#define TASK_MY_SECOND_TASK_PRIORITY (tskIDLE_PRIORITY + 1)
#define TASK_MY_THIRD_TASK_PRIORITY (tskIDLE_PRIORITY + 1)
/* Task stack sizes*/
#define TASK_MY_TASK_STACK (configMINIMAL_STACK_SIZE)
#define TASK_MY_SECOND_TASK_STACK (configMINIMAL_STACK_SIZE)
#define TASK_MY_THIRD_TASK_STACK (configMINIMAL_STACK_SIZE)
//defining bits to set for en event group
#define BIT_TASK_A_READY (1 << 0)
#define BIT_TASK_B_READY (1 << 1)