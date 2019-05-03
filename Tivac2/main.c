#include "lcd.h"
#include "potentiometer.h"
#include "push_buttons.h"
#include "uart.h"

ADC0SS3_Handler
{
	uint16_t value = ADC0_SS3_Read();
	uint8_t duty_cycle = value/4096;
	duty_cycle |= 0x80; //MSB = 1 to distinguish between Pushbuttons info and Potentiometer's info
	UART_Write(duty_cycle);
	ADC0_InterruptAck(3);
}
UART0_Handler(void)
{
UART0_ICR_R |= 0x10;
uint16_t x = UART0_Read;
LCD_SendCommand(Clear_Command);
LCD_IntegerToString(x);
}
void SystemInit()
{
}

int main (void)
{
	return 0;
}