#include "adc.h"
#include "uart.h"
#include "led.h"
#include "motor.h"
#include "temperature_sensor.h"

void  ADC0SS3_Handler (void)
{
	uint8_t temperature = 147.5 - ((247.5*ADC0_SS3_readValue())/4096); /* Convert the ADC value into celcus */ 
	UART2_Write(temperature); /* send the temperature in celcus through uart */
	ADC0_InterruptAck(SS_num); /* acknoweldge the adc interrupt to clear the flag in RIS register and restart the conversion of the temp. */
	
}

void SystemInit()
{
	TempSensor_Init();
	UART2_Init();
	__enable_irq();

}


int main (void)
{
	
	while(1){};
		
}
