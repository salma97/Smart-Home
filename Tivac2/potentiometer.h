#ifndef POTENTIOMETER_H_
#define POTENTIOMETER_H_
#include "adc.h"
#include "uart.h"
#include "systick.h"

void ADC_Init_Potentiometer (void);
void Pot_StartReading(void);

#endif
