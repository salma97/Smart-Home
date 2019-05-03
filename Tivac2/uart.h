#ifndef UART_H_
#define UART_H_
#include"tm4c123gh6pm.h"
#define intBRD
#define fBRD
#define Enable_MASK 0x0001
#define CTRL_LINE_MASK 0x0076
#define UART_CTRL_MASK 0x0070
#define GPIO_MASK 0x003
void UART0_Init(void);

#endif
