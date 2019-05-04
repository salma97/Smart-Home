#include "uart.h"



void UART0_Init(void)
{
	SYSCTL_RCGCUART_R|= Enable_MASK;//Enable uart clk
	SYSCTL_RCGCGPIO_R|= Enable_MASK;//enable port clk
	UART0_CTL_R &= ~Enable_MASK; //UART disabled
	UART0_IBRD_R = intBRD;
	UART0_FBRD_R = fBRD;
	UART0_LCRH_R |= CTRL_LINE_MASK;//8 bits word, even parity bit and 1 stop bit enabled
	UART0_CTL_R|= UART_CTRL_MASK; //enable TX, RX and UART
	GPIO_PORTA_AFSEL_R|= GPIO_MASK;
	GPIO_PORTA_DEN_R |= GPIO_MASK;
	GPIO_PORTA_AMSEL_R &= ~ GPIO_MASK;
	
}



uint8_t UART0_Read (void)
{
 while((UART0_FR_R&0x0010)!=0);
 return(UART0_DR_R&0xFF);

}

void UART0_Write(uint8_t data) {
	while ((UART0_FR_R&UART_FR_TXFF) != 0);
	UART0_DR_R = data;
}
