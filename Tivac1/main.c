#include "adc.h"
#include "uart.h"
#include "led.h"
#include "motor.h"
#include "temperature_sensor.h"

void  ADC0SS3_Handler (void)
{
	uint8_t temperature = 147.5 - ((247.5*ADC0_SS3_readValue())/4096); /* Convert the ADC value into celcus */ 
	UART0_Write(temperature); /* send the temperature in celcus through uart */
	ADC0_InterruptAck(SS_num); /* acknoweldge the adc interrupt to clear the flag in RIS register and restart the conversion of the temp. */
	
}

void SystemInit()
{
}

void Delay(uint16_t i){
	uint32_t time;
	uint16_t j;
  time = 145448;  // 0.1sec
  for( j=0; j<i; j++){
		while(time){
			time--;
		}
  }
}

int main (void)
{
	return 0;
}
