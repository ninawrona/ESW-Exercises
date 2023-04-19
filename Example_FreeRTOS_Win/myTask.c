#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"
#include "taskConfig.h"
#include "myTask.h"

// Testable task code
void myTaskRun()
{
	vTaskDelay(pdMS_TO_TICKS(200));
	puts("Hi from My Task");
}

/* Create the task */
void myTaskCreate()
{
	/* Create the task, not storing the handle. */
	xTaskCreate(
		taskMyTask,       /* Function that implements the task. */
		"MyTask",          /* Text name for the task. */
		TASK_MY_TASK_STACK,      /* Stack size in words, not bytes. */
		(void*)1,    /* Parameter passed into the task. */
		TASK_MY_TASK_PRIORITY,/* Priority at which the task is created. */
		NULL);      /* Used to pass out the created task's handle. */
}

// The "clean code" task
void taskMyTask(void* pvParameters)
{
	// Remove compiler warnings.
	(void)pvParameters;

	for (;;)
	{
		myTaskRun();
	}
}
