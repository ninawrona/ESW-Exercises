#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"
#include "taskConfig.h"
#include "mySecondTask.h"
#include "queue.h"

extern xQueueHandle msg_queue;

/* Task Handles */
extern TaskHandle_t _taskSecondHandle;

// Testable task code
void mySecondTaskRun()
{
	int number = 0;

	while(1){
		puts("sending a number to the queue:");
		//tries to add a new number to the que for 10 ticks, fail if the queue is full
		long ok = xQueueSend(msg_queue, (void*) &number, 0 );
		puts(ok ? "OK" : "FAILED");
		number++;
		
		//delaying the task for 1s
		vTaskDelay(1000);

	}
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

	for (;;)
	{
		mySecondTaskRun();
	}
}
