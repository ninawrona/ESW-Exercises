#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"
#include "taskConfig.h"
#include "mySecondTask.h"
#include "event_groups.h"

extern EventGroupHandle_t eventHandler;

/* Task Handles */
extern TaskHandle_t _taskSecondHandle;

// Testable task code
void mySecondTaskRun()
{
	vTaskDelay(pdMS_TO_TICKS(100));
	xEventGroupSetBits(eventHandler, BIT_TASK_B_READY);
	puts("Setting bit in task 2.");
	vTaskDelay(pdMS_TO_TICKS(200));
}

/* Create the task, storing the handle. */
void mySecondTaskCreate()
{
	xTaskCreate(
		taskMySeccondTask,			  /* Function that implements the task. */
		"MySecondTask",				  /* Text name for the task. */
		TASK_MY_SECOND_TASK_STACK,	  /* Stack size in words, not bytes. */
		(void *)1,					  /* Parameter passed into the task. */
		TASK_MY_SECOND_TASK_PRIORITY, /* Priority at which the task is created. */
		&_taskSecondHandle);		  /* Used to pass out the created task's handle. */
}

// The "clean code" task
void taskMySeccondTask(void *pvParameters)
{
	// Remove compiler warnings.
	(void)pvParameters;

	for (;;)
	{
		mySecondTaskRun();
	}
}
