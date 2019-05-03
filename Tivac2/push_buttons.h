#ifndef PushB_H_
#define PushB_H_

#include "tm4c123gh6pm.h"
#include <std_types.h>
#include "lcd.h"
#define PF_pins_mask 0x11
#define PCTL_pins_mask 0x00
#define GPIO_PF4_0_M		0x11
#define GPIO_PF4_0_PRI	2
void pushButtons_Init (void);
#endif
