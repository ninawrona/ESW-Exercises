#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"
#include "myTask.h"
#include "mySecondTask.h"
#include "message_buffer.h"


/* Task Handles */
TaskHandle_t _taskSecondHandle = NULL;
MessageBufferHandle_t xMessageBuffer = NULL;

// --------------------------------------------------------------------------------------
void main(void)
{
	// Turn off buffering
	setvbuf(stdout, NULL, _IONBF, 0);

	//creating a message buffer
	xMessageBuffer = xMessageBufferCreate(200);

	if(xMessageBuffer != NULL){
		// Create all tasks
		myTaskCreate();
		mySecondTaskCreate();

		// Let the operating system take over :)
		vTaskStartScheduler();
	}else{
		puts("Failed to create a message buffer.");
	}
}