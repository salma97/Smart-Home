#ifndef PushB_H_
#define PushB_H_
#include "uart.h"
#include "tm4c123gh6pm.h"
#include <std_types.h>
#include "lcd.h"
<<<<<<< HEAD
#iclude "port.h"

#define PF0 0x01
#define PF4 0x10

void pushButtons_Init (void);
void pushButtons_ISR(void);
=======
#define PF_pins_mask 0x11
#define PCTL_pins_mask 0x00
#define GPIO_PF4_0_M		0x11
#define GPIO_PF4_0_PRI	2
void pushButtons_Init (void);
#endif
>>>>>>> 5a2dea75f26f4fc0eece393e2d2176dedc226945
