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


uint8_t UART0_Read (void)
{
	uint8_t word;
	
	return word;
}

void UART0_Write(uint8_t data){
	while((UART0_FR_R&UART_FR_TXFF) != 0);
	UART0_DR_R = data;
}
