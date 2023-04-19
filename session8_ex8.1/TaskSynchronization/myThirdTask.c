#include <stdio.h>
#include "FREERTOS.h"
#include "task.h"
#include "taskConfig.h"
#include "myThirdTask.h"
#include "semphr.h"


/* Task Handles */
extern TaskHandle_t _taskThirdHandle;
extern SemaphoreHandle_t xTestSemaphore;


// Testable task code
void myThirdTaskRun()
{
		vTaskDelay(300);
		puts("O\n");
		vTaskDelay(300);
		puts("OK\n");
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
	for (;;)
	{
		myThirdTaskRun();
	}
}
