#ifndef UART_H_
#define UART_H_

#include "port.h"
#include "DIO.h"
#include "tm4c123gh6pm.h"
#include "std_types.h"

#define intBRD		0x00000000
#define fBRD			0x00000000
#define Enable_MASK 0x0001
#define CTRL_LINE_MASK 0x0076
#define UART_CTRL_MASK 0x0070
#define GPIO_MASK 0x003

void UART0_Init(void);

uint8_t UART0_Read(void);

void UART0_Write(uint8_t data);

#endif
