#include "uart.h"



void UART0_Init(void)
{
	DIO_WritePort(SYSCTL_RCGCUART_R, SYS_UART_EN, STD_HIGH);//Enable uart clk
	DIO_WritePort(SYSCTL_RCGCGPIO_R, SYS_PORT_EN, STD_HIGH);//enable port clk
	DIO_WritePort(UART0_CTL_R, UART_CTL_M, STD_LOW); //UART disabled
	UART0_IBRD_R = intBRD;
	UART0_FBRD_R = fBRD;
	DIO_WritePort(UART0_LCRH_R, UART_CTLINE_M, STD_HIGH);//8 bits word, even parity bit and 1 stop bit enabled
	DIO_WritePort(UART0_CTL_R, UART_CTL_M_EN, STD_HIGH); //enable TX, RX and UART
	DIO_WritePort(GPIO_PORTA_AFSEL_R, GPIO_MASK, STD_HIGH);
	DIO_WritePort(GPIO_PORTA_DEN_R, GPIO_MASK, STD_HIGH);
	DIO_WritePort(GPIO_PORTA_AMSEL_R, GPIO_MASK, STD_LOW);

}
uint8_t UART0_Read (void)
{
 while((UART0_FR_R&0x0010)!=0);
 return(UART0_DR_R&0xFF);

}
