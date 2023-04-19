#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"
#include "taskConfig.h"
#include "myTask.h"
#include "queue.h"

extern xQueueHandle msg_queue;

// Testable task code
void myTaskRun()
{
	int item = 0;
	while(1){

		//see if there's a message in the queue
		if( xQueueReceive( msg_queue,
                         &( item ),
                         ( TickType_t ) 10 ))
      {
        printf("READ: %d\n", item);
      }

		//delaying the task for 1s
		vTaskDelay(1000 / portTICK_PERIOD_MS);

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
		myTaskRun();
	}
}
