#ifndef UART_H_
#define UART_H_

#include "port.h"
#include "DIO.h"
#include "tm4c123gh6pm.h"
#include "std_types.h"
#include "LED.h"
#include "motor.h"
#include "systick.h"


#define intBRD		104
#define fBRD			5
#define Enable_MASK 0x08
#define EnableUART  0x04
#define CTRL_LINE_MASK 0x0076
#define UART_CTRL_MASK 0x0060
#define GPIO_MASK 0xC0

void UART2_Init(void);
void UART2_ACK (void);
uint8_t UART2_Read(void);
void UART2_Write(uint8_t data);
uint8_t UART2_Available(void);


	


#endif
