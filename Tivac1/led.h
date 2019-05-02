#ifndef LED_H_
#define LED_H_

#include "tm4c123gh6pm.h"
#include "std_types.h"

#define LED PF1

void LED_Init (void);
void LED_Intensity (uint8_t value);

#endif
