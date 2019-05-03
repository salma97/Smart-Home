#ifndef UART_H_
#define UART_H_

#include "dio.h"
//UART init masks
#define SYS_UART_EN 0x0001
#define SYS_PORT_EN 0x0001
#define UART_CTL_M 0x0001
#define UART_CTLINE_M 0x0076
#define UART_CTL_M_EN 0x0070
#define GPIO_MASK 0x003
#define intBRD
#define fBRD


void UART0_Init(void);

#endif
