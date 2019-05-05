#include "lcd.h"
#include "potentiometer.h"
#include "push_buttons.h"
#include "uart.h"
#include "adc.h"

uint8_t i = 0;
uint16_t j = 0;
void ADC0SS3_Handler (void)
{
	uint16_t value = ADC0_SS3_readValue();
	uint8_t duty_cycle = value*100/4096;
	duty_cycle |= 0x80; //MSB = 1 to distinguish between Pushbuttons info and Potentiometer's info
 // LCD_SendCommand(Clear_Command);
	UART2_Write(duty_cycle);
	//LCD_IntegerToString (duty_cycle & ~0x80);
	systick_wait1ms();
	ADC0_InterruptAck(3);
}
void UART2_Handler(void)
{
	uint16_t x;
	UART2_ICR_R |= 0x10;
	x = UART2_Read();
	LCD_SendCommand(Clear_Command);
	LCD_IntegerToString(2);
}
void SystemInit()
{
	uint8_t data [] = "Temperature: ";
		__disable_irq();
	systick_init();
	LCD_Init();
	LCD_SendCommand(Clear_Command);
	LCD_DisplayString(data);
	for (j=0;j<1000;j++)
		systick_wait1ms();
	ADC_Init_Potentiometer();
	pushButtons_Init();
		__enable_irq();

	
}

int main (void) {



while(1){};
	
	
}
