#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"
#include "taskConfig.h"
#include "mySecondTask.h"
#include "message_buffer.h"
#include <string.h>


/* Task Handles */
extern TaskHandle_t _taskSecondHandle;

extern MessageBufferHandle_t xMessageBuffer;


// Testable task code
void mySecondTaskRun()
{
	char rx_buf[200];
	int rec_byte = 0;

	vTaskDelay(2000);

	while(1){
		memset(rx_buf, 0, sizeof(rx_buf));
		
		rec_byte = xMessageBufferReceive(xMessageBuffer,
								rx_buf, 
								sizeof(rx_buf),
								portMAX_DELAY);

		printf("Received: rec_byte = %d, data = %s \n", rec_byte, rx_buf);
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
