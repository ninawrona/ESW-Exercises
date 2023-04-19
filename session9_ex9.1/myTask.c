#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"
#include "taskConfig.h"
#include "myTask.h"
#include "message_buffer.h"

extern MessageBufferHandle_t xMessageBuffer;

// Testable task code
void myTaskRun()
{
	char tx_buf[50];
	int buf_len = 0;
	int send_byte = 0;

	buf_len = sprintf(tx_buf, "My message");
	send_byte = xMessageBufferSend(xMessageBuffer,
								tx_buf, 
								buf_len,
								portMAX_DELAY);

	printf("Send: buf_len = %d, send_byte = %d\n", buf_len, send_byte);

	vTaskDelay(1000);

	buf_len = sprintf(tx_buf, "My message 2 - different length");
	send_byte = xMessageBufferSend(xMessageBuffer,
								tx_buf, 
								buf_len,
								portMAX_DELAY);

	printf("Send: buf_len = %d, send_byte = %d\n", buf_len, send_byte);

	vTaskDelete(NULL);
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
