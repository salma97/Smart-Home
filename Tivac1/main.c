 #include "adc.h"
#include "uart.h"
#include "led.h"
#include "motor.h"
#include "temperature_sensor.h"
#include "systick.h"
void  ADC0SS3_Handler (void)
{
	uint8_t temperature = 147 - (247 * ADC0_SSFIFO3_R)/4096; ; // Convert the ADC value into celcus 
	UART2_Write(temperature); // send the temperature in celcus through uart 
	ADC0_InterruptAck(3); // acknoweldge the adc interrupt to clear the flag in RIS register and restart the conversion of the temp. 
	
}

void UART2_Handler (void)
{
	uint8_t a = 1;
	uint8_t word;
	word= UART2_Read();
	if( word & (1<<7))
	{
			word &= ~(1<<7);
		  TIMER1_TAMATCHR_R = word;
	  	//LED_Intensity (word);
	}
	else if (word & (1<<0))
	{
		Motor_Clockwise ();
	}
	else if (word & (1<<4))
	{
		Motor_AntiClockwise ();
	}
	UART2_ICR_R |= 0x10;

}

int __main(void);

void SystemInit()
{
	uint8_t delay1;
__disable_irq();
SYSCTL_RCGCTIMER_R |= (1<<1);
delay1 = 5;
SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R5;
delay1 = 5;
Port_Init(PF);
GPIO_PORTF_AFSEL_R |= (1<<2);
GPIO_PORTF_PCTL_R |= (7<<8);
GPIO_PORTF_DIR_R |= (1<<2);
GPIO_PORTF_DEN_R |=(1<<2);

TIMER1_CTL_R=~(1<<0);
TIMER1_CFG_R =0x00000004;
TIMER1_TAMR_R |= (2<<0) | (1<<3);
TIMER1_TAMR_R &=~(1<<2);
TIMER1_CTL_R &= ~(1<<14);
TIMER1_TAILR_R =100;
TIMER1_TAMATCHR_R = 99;
TIMER1_CTL_R |=(1<<0);

systick_init();
Motor_Init();
UART2_Init();
//TempSensor_Init();
delay(1000);
__enable_irq();

}


int __main(void)
{
	
	while(1){
		/*volatile uint8_t temperature ;
		ADC0_SS3_SC();
		delay(1000);
	temperature = 147 - (247 * ADC0_SSFIFO3_R)/4096; ; // Convert the ADC value into celcus 
	UART2_Write(temperature); // send the temperature in celcus through uart 
		delay(1000);
	ADC0_InterruptAck(3); // acknoweldge the adc interrupt to clear the flag in RIS register and restart the conversion of the temp. 
	
		*/
		}
		
}
