#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>
#include "uart.h"

//Create a counter that is incremented, and then sendit viathe uart.
int main(){
    uartInit(9600);
    int number = 0;
    while(1){
       char *message = uartReceive();
       sprintf("%s", message);
    }
}