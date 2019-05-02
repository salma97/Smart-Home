#include "adc.h"
#include "uart.h"
#include "led.h"
#include "motot.h"
#include "temperature_sensor.h"

ADC0SS3_Handler
{
	uint8_t temperature = 147.5 - ((247.5*ADC0_SS3_readValue())/4096); /* Convert the ADC value into celcus */ 
	UART0_send(temperature); /* send the temperature in celcus through uart */
	ADC0_SS3_ACK();	  /* acknoweldge the adc interrupt to clear the flag in RIS register and restart the conversion of the temp. */
	
}

void SystemInit()
{
}

int main (void)
{
	return 0;
}