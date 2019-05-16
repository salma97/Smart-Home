#ifndef PWM_H_
#define PWM_H_

#include "tm4c123gh6pm.h"
#include "std_types.h"

#define Load 1000
#define Compare 0
#define RCC 0x001A0000
#define GENA 0x00000033		//33
#define PWMnEnable 0x00000040

void PWM1_3_Init ();

#endif
