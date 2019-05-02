#include "led.h"

void LED_Init (void)
{
	Port_Init(PF);
	PWM1_3_Init(100,100, 0x001A0000, 0x00000033, 0x00000040);

	Port_AlternateFunction (PF, 0x04, 1, 0x00000500);
	Port_AnalogOrDigital (PF, 0x04, Digital);
	Port_SetPinDirection (PF, 0x04, PORT_PIN_OUT);
	
}


void LED_Intensity (uint8_t value)
{
	
}
