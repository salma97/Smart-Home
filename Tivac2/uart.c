#include "uart.h"



void UART0_Init(void)
{
	SYSCTL_RCGCUART_R|= 0x0001;//Enable uart clk
	SYSCTL_RCGCGPIO_R|= 0x0001;//enable port clk
	UART0_CTL_R&=~0x0001; //UART disabled
	UART0_IBRD_R = intBRD;
	UART0_FBRD_R = fBRD;
	UART0_LCRH_R |= 0x0076;//8 bits word, even parity bit and 1 stop bit enabled
	UART0_CTL_R|= 0x0070; //enable TX, RX and UART
	GPIO_PORTA_AFSEL_R|= 0x003;
	GPIO_PORTA_DEN_R |= 0x003;
	GPIO_PORTA_AMSEL_R &= ~0x003;
	
}