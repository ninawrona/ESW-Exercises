#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"

static void idelWork(int t){
	//do some idel work

	for(int i = 0; i<20000; i++){
		for(int j=0; j<2000; j++){
			for(int r = 0; r<t; r++){
				
			}
		}
	}
}