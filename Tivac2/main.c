#include "lcd.h"
#include "potentiometer.h"
#include "push_buttons.h"
#include "uart.h"
#include "adc.h"

uint8_t i = 0;
uint16_t j = 0;
void GPIOF_Handler(void)
{
	//uint8_t data1[] = "high";
	//uint8_t data2[] = "low";
	//LCD_DisplayString(data1);
	if (GPIO_PORTF_RIS_R & 0x01)
	{
		
		//LCD_DisplayString(data1);
		//delay(500);
		//LCD_SendCommand(Clear_Command);
		//PORT_InterruptAck(PF0);
		UART2_Write(PF0);
		PORT_InterruptAck(PF0);
		
		
	}
	else if(GPIO_PORTF_RIS_R & 0x10)
	{
		//PORT_InterruptAck(PF4);
		
		UART2_Write(PF4);
		PORT_InterruptAck(PF4);
		//LCD_DisplayString(data2);
		//delay(500);
		//LCD_SendCommand(Clear_Command);
		//PORT_InterruptAck(PF4);
	}
	PORT_InterruptAck(0x11);

	//delay(500);
}
void ADC0SS3_Handler (void)
{
	//uint8_t value = ADC0_SS3_readValue();
	//uint8_t temperature = 147.5 - ((247.5*value)/4096); // Convert the ADC value into celcus 
	uint16_t value = ADC0_SS3_readValue();
	uint8_t duty_cycle = value*100/4096;
	duty_cycle |= 0x80; //MSB = 1 to distinguish between Pushbuttons info and Potentiometer's info
//	LCD_SendCommand(Clear_Command);
	UART2_Write(duty_cycle);
//	LCD_IntegerToString (duty_cycle &= ~0x80);
	delay(100);
	//systick_wait1ms();
	//ADC0_InterruptAck(3);
	ADC0_InterruptAck(3);
}


int main(void);

void SystemInit()
{
		uint8_t data1 [] = "Temperature: ";
	__disable_irq();
	systick_init();
	LCD_Init();
	LCD_SendCommand(Clear_Command);
	LCD_DisplayString(data1);
	LCD_SendCommand(12|Cursor_Location);
	delay(3000);
	LCD_SendCommand(12|Cursor_Location);
	//LCD_IntegerToString(28);
	pushButtons_Init();
	ADC_Init_Potentiometer();
	UART2_Init();
	__enable_irq();
	
}

int __main (void)
{
	
	while(1)
		{

		ADC0_SS3_SC();
		delay(1000);
		}
		
		
		
		
}
