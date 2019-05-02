#ifndef ADC_H_
#define ADC_H_

#include "port.h"
#include "DIO.h"
#include "tm4c123gh6pm.h"


#define trigger_select 0x0F
#define SS_num 3
#define ADC0_SSCTL3_IE0		0x1
#define ADC0_SSCTL3_END0	0x1
#define ADC0_SSCTL3_TS0   0x1


void ADC0_SS3_Init (void);
uint16_t ADC0_SS3_readValue(void);
#endif