#pragma once

void uartInit(int baudrate);
void uartSend(char*data);
char* uartReceive();