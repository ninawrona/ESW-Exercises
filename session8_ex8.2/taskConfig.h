#pragma once

/* Priorities at which the tasks are created. */
#define TASK_MY_TASK_PRIORITY (tskIDLE_PRIORITY + 1)
#define TASK_MY_SECOND_TASK_PRIORITY (tskIDLE_PRIORITY + 2)
/* Task stack sizes*/
#define TASK_MY_TASK_STACK (configMINIMAL_STACK_SIZE)
#define TASK_MY_SECOND_TASK_STACK (configMINIMAL_STACK_SIZE)
