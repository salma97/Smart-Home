#include "led.h"

void LED_Init (void)
{	
	Port_Init(PF);
	Port_AlternateFunction (PF, 0x04, 1, 0x7);
	Port_AnalogOrDigital (PF, 0x04, Digital);
	Port_SetPinDirection (PF, 0x04, PORT_PIN_OUT);
	PWM1_3_Init();
}


void LED_Intensity (uint8_t word)
{
	TIMER1_TAMATCHR_R = word;
}
