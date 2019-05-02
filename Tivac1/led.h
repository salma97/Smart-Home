#ifndef LED_H_
#define LED_H_

#include "port.h"
#include "pwm.h"

#define LED PF2

void LED_Init (void);
void LED_Intensity (uint8_t value);

#endif
