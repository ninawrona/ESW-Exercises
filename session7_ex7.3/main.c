#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"
#include "myTask.h"
#include "mySecondTask.h"
#include "myThirdTask.h"


/* Task Handles */
TaskHandle_t _taskSecondHandle = NULL;
TaskHandle_t _taskThirdHandle = NULL;

// --------------------------------------------------------------------------------------
void main(void)
{
	// Turn off buffering
	setvbuf(stdout, NULL, _IONBF, 0);

	// Create all tasks
	myTaskCreate();
	mySecondTaskCreate();
	myThirdTaskCreate();
	

	// Let the operating system take over :)
	vTaskStartScheduler();
}