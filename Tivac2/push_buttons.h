#ifndef PushB_H_
#define PushB_H_
#include "uart.h"
#include "tm4c123gh6pm.h"
#include "std_types.h"
#include "lcd.h"
#include "port.h"

#define PF0 0x01
#define PF4 0x10

void pushButtons_Init (void);
#define PF_pins_mask 0x11
#define PCTL_pins_mask 0x00
#define GPIO_PF4_0_M		0x11
#define GPIO_PF4_0_PRI	0
void pushButtons_Init (void);
#endif
