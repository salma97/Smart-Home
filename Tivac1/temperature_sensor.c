#include "temperature_sensor.h"

void TempSensor_Init (void)
{
	//port_init    to enable clock
	//port_analog
	//port_AlternativeFunction
	ADC0_SS3_Init();
}
