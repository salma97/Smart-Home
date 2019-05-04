#ifndef __SYSTICK_H__
#define __SYSTICK_H__
#include "port.h"
#include "DIO.h"
#include "tm4c123gh6pm.h"
#include "std_types.h"
void systick_init(void);

void systick_wait1ms(void);

void delay(uint16_t i);

#endif // __SYSTICK_H__
