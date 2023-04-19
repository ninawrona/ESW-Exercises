#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"
#include "myTask.h"
#include "mySecondTask.h"


/* Task Handles */
TaskHandle_t _taskSecondHandle = NULL;
int x = 0;
int y = 0;
int z = 0;
// --------------------------------------------------------------------------------------
void main(void)
{
	// Turn off buffering
	setvbuf(stdout, NULL, _IONBF, 0);

	// Create all tasks
	myTaskCreate();
	mySecondTaskCreate();

	// Let the operating system take over :)
	vTaskStartScheduler();
}