#include "lcd.h"
void pushButtons_Init (void)
{
	void Port_Init (PF);
	void Port_SetPinDirection (PF, 0x11, PORT_PIN_IN);
	void Port_AnalogOrDigital (PF,0x11, 1);
	void Port_AlternateFunction (PF, 0x11, 0, 0x00);
	void Port_SetPinPullUp (PF, 0x11, 1);

	
}