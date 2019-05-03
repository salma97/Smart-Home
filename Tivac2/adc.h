
#ifndef ADC_H_
#define ADC_H_

#include "port.h"
#include "DIO.h"
#include "tm4c123gh6pm.h"
#include "std_types.h"

#ifndef PORTA
#define PORTA 0
#endif

#ifndef PORTB
#define PORTB 1
#endif

#ifndef PORTC
#define PORTC 2
#endif

#ifndef PORTD
#define PORTD 3
#endif

#ifndef PORTE
#define PORTE 4
#endif

#ifndef PORTF
#define PORTF 5
#endif

#define trigger_select 0x0F
#define SS_num 3
#define ADC0_SSCTL3_IE0		0x1
#define ADC0_SSCTL3_END0	0x1
#define ADC0_SSCTL3_TS0   0x1


void ADC0_SS3_Init (void);

#endif