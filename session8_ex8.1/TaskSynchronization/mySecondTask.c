#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"
#include "taskConfig.h"
#include "mySecondTask.h"
#include "semphr.h"

/* Task Handles */
extern SemaphoreHandle_t xTestSemaphore;
extern TaskHandle_t _taskSecondHandle;

extern int shared_var;

// Testable task code
void mySecondTaskRun()
{
	
		vTaskDelay(300);
		puts("I");
		vTaskDelay(300);
		puts("OK");
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
