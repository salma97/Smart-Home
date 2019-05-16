#include "led.h"

void LED_Init (void)
{
	PWM1_3_Init();
	
	Port_Init(PF);
	Port_AlternateFunction (PF, 0x04, 1, 0x5);
	Port_AnalogOrDigital (PF, 0x04, Digital);
	Port_SetPinDirection (PF, 0x04, PORT_PIN_OUT);
	
	PWM1_ENABLE_R |= PWMnEnable;
}


void LED_Intensity (uint8_t value)
{
	PWM1_3_CMPA_R = value;
}
