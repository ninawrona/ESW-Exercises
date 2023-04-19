#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"
#include "taskConfig.h"
#include "myThirdTask.h"
#include "event_groups.h"

extern EventGroupHandle_t eventHandler;

/* Task Handles */
extern TaskHandle_t _taskThirdHandle;

// Testable task code
void myThirdTaskRun()
{
    while(1){
	
	    xEventGroupWaitBits(eventHandler, /* The event group being tested. */
                        BIT_TASK_A_READY | BIT_TASK_B_READY, /* The bits to wait for. */
                        pdTRUE, /* Bits will be cleared before return*/
                        pdTRUE, /* Wait for all bits to be set */
                        portMAX_DELAY); /* Maximum time to wait*/

        vTaskDelay(pdMS_TO_TICKS(200));

        puts("Getting bits in task 3.");
    }
}

/* Create the task, storing the handle. */
void myThirdTaskCreate()
{
	xTaskCreate(
		taskMyThirdTask,			  /* Function that implements the task. */
		"MyThirdTask",				  /* Text name for the task. */
		TASK_MY_THIRD_TASK_STACK,	  /* Stack size in words, not bytes. */
		(void *)1,					  /* Parameter passed into the task. */
		TASK_MY_THIRD_TASK_PRIORITY, /* Priority at which the task is created. */
		&_taskThirdHandle);		  /* Used to pass out the created task's handle. */
}

// The "clean code" task
void taskMyThirdTask(void *pvParameters)
{
	// Remove compiler warnings.
	(void)pvParameters;

	for (;;)
	{
		myThirdTaskRun();
	}
}
