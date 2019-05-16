#include "uart.h"
#include "push_buttons.h"
void pushButtons_Init (void)
{
	Port_Init (PF);
	Port_SetPinDirection (PF, 0x11, PORT_PIN_IN);
	Port_AnalogOrDigital (PF,0x11, Digital);
	Port_AlternateFunction (PF, 0x11, 0, 0x00);
	Port_SetPinPullUp (PF, 0x11, 1);
	GPIO_PORTF_IS_R &= ~GPIO_PF4_0_M;
	GPIO_PORTF_IBE_R &= ~GPIO_PF4_0_M;
	GPIO_PORTF_IEV_R &= ~GPIO_PF4_0_M;
	GPIO_PORTF_ICR_R |= GPIO_PF4_0_M;
	GPIO_PORTF_IM_R |= GPIO_PF4_0_M;
	NVIC_PRI7_R = (NVIC_PRI7_R & 0xFF00FFFF) | (GPIO_PF4_0_PRI << 21); // PRI7 bits 23:21

	NVIC_EN0_R |= 0x40000000 ; // EN0 bit 30
}

void GPIOF_Handler(void)
{
	if (GPIO_PORTF_RIS_R & 0x01)
	{
		UART2_Write(PF0);
		PORT_InterruptAck(PF0);
	}
	else if(GPIO_PORTF_RIS_R & 0x10)
	{
		UART2_Write(PF4);
		PORT_InterruptAck(PF4);
	}
}
