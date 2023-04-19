#include <stdio.h>
#include "FreeRTOS.h"
#include "semphr.h"
#include "myTask.h"
#include "mySecondTask.h"
#include "myThirdTask.h"

SemaphoreHandle_t xTestSemaphore;
/* Task Handles */
TaskHandle_t _taskSecondHandle = NULL;
TaskHandle_t _taskThirdHandle = NULL;

int shared_var; 


int main(){
    if ( xTestSemaphore == NULL )  // Check to confirm that the Semaphore has not already been created.
	{
		xTestSemaphore = xSemaphoreCreateMutex();  // Create a mutex semaphore.
		if ( ( xTestSemaphore ) != NULL )
		{
			xSemaphoreGive( ( xTestSemaphore ) );  // Make the mutex available for use, by initially "Giving" the Semaphore.
		}
	}

    // Turn off buffering
	setvbuf(stdout, NULL, _IONBF, 0);

	// Create all tasks
	myTaskCreate();
	mySecondTaskCreate();
	myThirdTaskCreate();

	// Let the operating system take over :)
	vTaskStartScheduler();
}