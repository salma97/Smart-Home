#include "potentiometer.h"
void ADC_Init_Potentiometer (void)
{
	Port_Init(PE);
ADC0_SS3_Init ();
Port_SetPinDirection (PE, 0x08, PORT_PIN_IN);
Port_AnalogOrDigital (PE, 0x08, Analog);
Port_AlternateFunction (PE,0x08,1, 0x00);

}



void ADC0SS3_Handler (void)
{
	uint16_t value = ADC0_SS3_readValue();
	uint8_t duty_cycle = value*100/4096;
	duty_cycle |= 0x80; //MSB = 1 to distinguish between Pushbuttons info and Potentiometer's info
	UART2_Write(duty_cycle);
	delay(100);
	ADC0_InterruptAck(3);
}

void Pot_StartReading(void)
{
	ADC0_SS3_SC();
}
