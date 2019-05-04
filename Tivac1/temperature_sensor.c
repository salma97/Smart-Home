#include "temperature_sensor.h"

void TempSensor_Init (void)
{
	Port_Init(PE);    //to enable clock
	ADC0_SS3_Init();
	Port_AnalogOrDigital (PE, 0x08, Analog);//port_analog
	//port_AlternativeFunction
	
}
