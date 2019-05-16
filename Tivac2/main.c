#include "lcd.h"
#include "potentiometer.h"
#include "push_buttons.h"
#include "uart.h"

void SystemInit()
{
		uint8_t data1 [] = "Temperature: ";
	__disable_irq();
	systick_init();
	LCD_Init();
	LCD_SendCommand(Clear_Command);
	LCD_DisplayString(data1);
	pushButtons_Init();
	ADC_Init_Potentiometer();
	UART2_Init();
	__enable_irq();
	
}

int __main (void)
{
	
	while(1)
		{

		Pot_StartReading();
		delay(1000);
		}
		
		
		
		
}
