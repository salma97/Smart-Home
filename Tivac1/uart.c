#include "uart.h"
#include "LED.h"
#include "motor.h"

void UART0_Handler (void)
{
	uint8_t word = 0;
	word=UART0_Read();
	if( word & (1<<7))
	{
		LED_Intensity (word & ~(1<<7));
	}
	else if (word & (1<<0))
	{
		Motor_Clockwise ();
	}
	else if (word & (1<<4))
	{
		Motor_AntiClockwise ();
	}
}

void UART0_Init(void)
{
	SYSCTL_RCGCUART_R |= Enable_MASK;//Enable uart clk
	SYSCTL_RCGCGPIO_R |= Enable_MASK;//enable port clk
	UART0_CTL_R &= ~Enable_MASK; //UART disabled
	UART0_IBRD_R = intBRD;
	UART0_FBRD_R = fBRD;
	UART0_LCRH_R |= CTRL_LINE_MASK;//8 bits word, even parity bit and 1 stop bit enabled
	UART0_CTL_R |= UART_CTRL_MASK; //enable TX, RX and UART
	GPIO_PORTA_AFSEL_R |= GPIO_MASK;
	GPIO_PORTA_DEN_R |= GPIO_MASK;
	GPIO_PORTA_AMSEL_R &= ~GPIO_MASK;

}

uint8_t UART0_Read (void)
{
	uint8_t word;
	
	return word;
}

void UART0_Write(uint8_t data){
	while((UART0_FR_R&UART_FR_TXFF) != 0);
	UART0_DR_R = data;
}
