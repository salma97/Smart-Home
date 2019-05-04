#include "lcd.h"
#include "push_buttons.h"
void pushButtons_Init (void)
	{
		void Port_Init (PF);
		void Port_SetPinDirection (PF, PF_pins_mask, PORT_PIN_IN);
		void Port_AnalogOrDigital (PF,PF_pins_mask, 1);
		void Port_AlternateFunction (PF, PF_pins_mask, 0, PCTL_pins_mask);
		void Port_SetPinPullUp (PF, PF_pins_mask, 1);
		GPIO_PORTF_IS_R &= ~GPIO_PF4_0_M;
		GPIO_PORTF_IBE_R &= ~GPIO_PF4_0_M;
		GPIO_PORTF_IEV_R &= ~GPIO_PF4_0_M;
		GPIO_PORTF_ICR_R |= GPIO_PF4_0_M;
		GPIO_PORTF_IM_R |= GPIO_PF4_0_M;
		NVIC_PRI7_R = (NVIC_PRI7_R & 0xFF00FFFF) | (GPIO_PF4_0_PRI << 21); // PRI7 bits 23:21
		NVIC_EN0_R |= (1 << 30); // EN0 bit 30
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