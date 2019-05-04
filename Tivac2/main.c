#include "lcd.h"
#include "potentiometer.h"
#include "push_buttons.h"
#include "uart.h"
#include "adc.h"

void ADC0SS3_Handler (void)
{
	uint16_t value = ADC0_SS3_readValue();
	uint8_t duty_cycle = value*100/4096;
	duty_cycle |= 0x80; //MSB = 1 to distinguish between Pushbuttons info and Potentiometer's info
	UART0_Write(duty_cycle);
	ADC0_InterruptAck(3);
}
void UART0_Handler(void)
{
	uint16_t x;
	uint8_t *str;
UART0_ICR_R |= 0x10;
x = UART0_Read();
LCD_SendCommand(Clear_Command);
LCD_IntegerToString(x,str);
	LCD_DisplayString(str);
}
void SystemInit()
{
}

int main (void)
{
	return 0;
}
