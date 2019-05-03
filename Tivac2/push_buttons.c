#include "lcd.h"
#include "push_buttons.h"
void pushButtons_Init (void)
{
	void Port_Init (PF);
	void Port_SetPinDirection (PF, 0x11, PORT_PIN_IN);
	void Port_AnalogOrDigital (PF,0x11, 1);
	void Port_AlternateFunction (PF, 0x11, 0, 0x00);
	void Port_SetPinPullUp (PF, 0x11, 1);

	
}
void pushButtons_ISR(void)
{
	if ((GPIO_PORTF_DATA_R & PF0) == PF0)
	{
		PORT_InterruptAck(PF0);
		UART0_Write(PF0);
	}
	else if((GPIO_PORTF_DATA_R & PF4) ==PF4 )
	{
		PORT_InterruptAck(PF4);
		UART0_Write(PF4);
	}
#endif