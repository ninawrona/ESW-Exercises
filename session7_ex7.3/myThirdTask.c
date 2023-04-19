#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"
#include "taskConfig.h"
#include "myThirdTask.h"
#include <shared.c>

/* Task Handles */
extern TaskHandle_t _taskThirdHandle;
extern void idelWork(int t);


// Testable task code
void myThirdTaskRun()
{
    idelWork(5);
	puts("\t\t Task C \n");
}

/* Create the task, storing the handle. */
void myThirdTaskCreate()
{
	xTaskCreate(
		taskMyThirdTask,			  /* Function that implements the task. */
		"MyThirdTask",				  /* Text name for the task. */
		TASK_MY_THIRD_TASK_STACK,	  /* Stack size in words, not bytes. */
		(void *)3,					  /* Parameter passed into the task. */
		TASK_MY_THIRD_TASK_PRIORITY, /* Priority at which the task is created. */
		&_taskThirdHandle);		  /* Used to pass out the created task's handle. */
}

// The "clean code" task
void taskMyThirdTask(void *pvParameters)
{
	// Remove compiler warnings.
	(void)pvParameters;
	TickType_t xLastWakeTime;
	xLastWakeTime = xTaskGetTickCount();

	for (;;)
	{
		vTaskDelayUntil(&xLastWakeTime, 300)
		myThirdTaskRun();
	}
}
