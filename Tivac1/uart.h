#ifndef UART_H_
#define UART_H_

#include "port.h"
#include "DIO.h"
#include "tm4c123gh6pm.h"
#include "std_types.h"

uint8_t UART0_Read (void);

void UART0_Write(uint8_t data);


#endif
