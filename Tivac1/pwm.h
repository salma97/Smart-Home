#ifndef PWM_H_
#define PWM_H_

#include "tm4c123gh6pm.h"
#include "std_types.h"


void PWM1_3_Init (uint16_t Load, uint16_t Compare, uint32_t RCC, uint32_t GENA, uint32_t PWMnEnable);

#endif