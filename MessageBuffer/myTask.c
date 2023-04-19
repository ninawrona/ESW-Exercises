#include <stdio.h>
#include "FreeRTOS.h"
#include "message_buffer.h"
#include "task.h"
#include "taskConfig.h"
#include "myTask.h"

extern MessageBufferHandle_t xMessageBuffer;

// Testable task code
void myTaskRun(void* pvParameters)
{

	    size_t xBytesSent;
    char* pcStringToSend = "Hey beauty!";

    //removing compiler warnings
    (void)pvParameters;

    for(;;){
        vTaskDelay(pdMS_TO_TICKS(1000));
        xBytesSent = xMessageBufferSend(xMessageBuffer,
         (void*)pcStringToSend, 
         strlen(pcStringToSend)+1,
         portMAX_DELAY);
    }
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
		myTaskRun(pvParameters);
	}
}
