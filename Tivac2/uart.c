#include "uart.h"
#include "LCD.h"
#include "systick.h"
void UART2_Handler(void)
{
			uint8_t data1 [] = "Temperature: ";
			LCD_SendCommand(Clear_Command);
		LCD_DisplayString(data1);
		LCD_SendCommand(12|Cursor_Location);
		LCD_IntegerToString(UART2_Read());
		LCD_SendCommand(15|Cursor_Location);
		LCD_SendData('C');
UART2_ICR_R |= 0x10;		
}

void UART2_Init(void)
{	
	volatile uint8_t delay;
	SYSCTL_RCGCUART_R|= EnableUART;//Enable uart clk
	delay = EnableUART;
	//SYSCTL_RCGCGPIO_R|= Enable_MASK;//enable port clk
	delay = Enable_MASK;
	
	Port_Init(PD);
	
	GPIO_PORTD_AFSEL_R|= GPIO_MASK;
	GPIO_PORTD_PCTL_R = (GPIO_PORTD_PCTL_R & 0x00FFFFFF)|0x11000000;
	GPIO_PORTD_DEN_R |= GPIO_MASK;
	GPIO_PORTD_AMSEL_R &= ~ GPIO_MASK;
	
	UART2_CTL_R &= ~(1<<0); //UART disabled
	UART2_IBRD_R = intBRD;
	UART2_FBRD_R = fBRD;
	UART2_LCRH_R |= UART_CTRL_MASK;//8 bits word, even parity bit and 1 stop bit enabled
	UART2_IM_R |= 0x10 ;
	UART2_DR_R = 5;
	
	
	NVIC_PRI8_R |= 0x4000;
	NVIC_EN1_R |= (1<<1);
	
	UART2_CTL_R|= 1; //enable TX, RX and UART


}

uint8_t UART2_Available(void)
{
	return !((UART2_FR_R&0x0010)!=0);
}
uint8_t UART2_Read (void)
{
//	while((UART2_FR_R&0x0010)!=0);
	return(UART2_DR_R&0xFF);
}

void UART2_Write(uint8_t data){
	while ((UART2_FR_R&UART_FR_TXFF) != 0);
	UART2_DR_R = data;
}
