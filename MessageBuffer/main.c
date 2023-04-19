#include <stdio.h>
#include "FreeRTOS.h"
#include "message_buffer.h"
#include "task.h"
#include "myTask.h"
#include "mySecondTask.h"


/* Task Handles */
TaskHandle_t _taskSecondHandle = NULL;

MessageBufferHandle_t xMessageBuffer;
const size_t xMessageBufferSizeBytes = 100;

// --------------------------------------------------------------------------------------
void main(void)
{
	xMessageBuffer = xMessageBufferCreate(xMessageBufferSizeBytes);

	// Turn off buffering
	setvbuf(stdout, NULL, _IONBF, 0);

	// Create all tasks
	myTaskCreate();
	mySecondTaskCreate();

	// Let the operating system take over :)
	vTaskStartScheduler();
}