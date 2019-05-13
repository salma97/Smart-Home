#include "uart.h"



void UART2_Init(void)
{	
	volatile uint8_t delay;
	SYSCTL_RCGCUART_R|= EnableUART;//Enable uart clk
	delay = EnableUART;
	SYSCTL_RCGCGPIO_R|= Enable_MASK;//enable port clk
	delay = Enable_MASK;
	
	Port_Init(PD);
	
	UART2_CTL_R &= ~EnableUART; //UART disabled
	UART2_IBRD_R = intBRD;
	UART2_FBRD_R = fBRD;
	UART2_LCRH_R |= CTRL_LINE_MASK;//8 bits word, even parity bit and 1 stop bit enabled
	UART2_CTL_R|= UART_CTRL_MASK; //enable TX, RX and UART
	
	GPIO_PORTD_AFSEL_R|= GPIO_MASK;
	GPIO_PORTD_DEN_R |= GPIO_MASK;
	GPIO_PORTD_AMSEL_R &= ~ GPIO_MASK;

}

uint8_t UART2_Read (void)
{
	while((UART2_FR_R&0x0010)!=0);
	return(UART2_DR_R&0xFF);
}

void UART2_Write(uint8_t data){
	while ((UART2_FR_R&UART_FR_TXFF) != 0);
	UART0_DR_R = data;
}
