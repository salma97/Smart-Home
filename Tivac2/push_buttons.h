#ifndef PushB_H_
#define PushB_H_
#include "uart.h"
#include "tm4c123gh6pm.h"
#include "std_types.h"
#include "lcd.h"
#iclude "port.h"

#define PF0 0x01
#define PF4 0x10

void pushButtons_Init (void);
void pushButtons_ISR(void);