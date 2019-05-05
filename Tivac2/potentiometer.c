#include "potentiometer.h"
void ADC_Init_Potentiometer (void)
{
	Port_Init(PE);
ADC0_SS3_Init ();
Port_SetPinDirection (PE, 0x08, PORT_PIN_IN);
Port_AnalogOrDigital (PE, 0x08, Analog);
Port_AlternateFunction (PE,0x08,1, 0x00);

}
