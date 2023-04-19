#include <stdio.h>
#include "FreeRTOS.h"
#include "message_buffer.h"
#include "task.h"
#include "taskConfig.h"
#include "mySecondTask.h"

/* Task Handles */
extern TaskHandle_t _taskSecondHandle;
extern MessageBufferHandle_t xMessageBuffer;

// Testable task code
void mySecondTaskRun(void* pvParameters)
{
	size_t xReceivedBytes;
	char ucRxData[100];

	//removing compiler warnings
	(void)pvParameters;

	for(;;){
		vTaskDelay(pdMS_TO_TICKS(100));
		xReceivedBytes = xMessageBufferReceive(xMessageBuffer,
		(void*)ucRxData,
		sizeof(ucRxData),
		0);
		if(xReceivedBytes > 0){
			puts(ucRxData);
		}
		else{
			putch('.');
		}
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
		mySecondTaskRun(pvParameters);
	}
}
