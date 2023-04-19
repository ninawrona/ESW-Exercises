#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"
#include "taskConfig.h"
#include "mySecondTask.h"
#include <shared.c>

/* Task Handles */
extern TaskHandle_t _taskSecondHandle;
extern void idelWork(int t);

// Testable task code
void mySecondTaskRun()
{
	idelWork(20);
	puts("\t Task B \n");
}

/* Create the task, storing the handle. */
void mySecondTaskCreate()
{
	xTaskCreate(
		taskMySeccondTask,			  /* Function that implements the task. */
		"MySecondTask",				  /* Text name for the task. */
		TASK_MY_SECOND_TASK_STACK,	  /* Stack size in words, not bytes. */
		(void *)2,					  /* Parameter passed into the task. */
		TASK_MY_SECOND_TASK_PRIORITY, /* Priority at which the task is created. */
		&_taskSecondHandle);		  /* Used to pass out the created task's handle. */
}

// The "clean code" task
void taskMySeccondTask(void *pvParameters)
{
	// Remove compiler warnings.
	(void)pvParameters;
	TickType_t xLastWakeTime;
	xLastWakeTime = xTaskGetTickCount();

	for (;;)
	{
		vTaskDelayUntil(&xLastWakeTime, 200)
		mySecondTaskRun();
	}
}
