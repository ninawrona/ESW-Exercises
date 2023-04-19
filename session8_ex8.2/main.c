#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"
#include "myTask.h"
#include "mySecondTask.h"
#include "queue.h"


/* Task Handles */
TaskHandle_t _taskSecondHandle = NULL;
xQueueHandle msg_queue = NULL;
// --------------------------------------------------------------------------------------
void main(void)
{

	

	// Turn off buffering
	setvbuf(stdout, NULL, _IONBF, 0);

	//creating a queue
	msg_queue = xQueueCreate(10, sizeof(int));

	if(msg_queue == NULL){
		puts("QUEUE WAS NOT CREATED.");
	}

	// Create all tasks
	myTaskCreate();
	mySecondTaskCreate();

	// Let the operating system take over :)
	vTaskStartScheduler();
}