#ifndef PORT_H_
#define PORT_H_

#include "tm4c123gh6pm.h"
#include "std_types.h"

typedef enum 
{
	PORT_PIN_IN = 0,
	PORT_PIN_OUT = 1
}Port_PinDirectionType;

typedef enum 
{
	Analog = 0,
	Digital = 1
}AnalogOrDigital;

void Port_Init (uint8_t port_index);
void Port_SetPinDirection (uint8_t port_index, uint8_t pins_mask, Port_PinDirectionType direction);
void Port_SetPinPullUp (uint8_t port_index, uint8_t pins_mask, uint8_t enable);
void Port_SetPinPullDown (uint8_t port_index, uint8_t pins_mask, uint8_t enable);
void Port_AlternateFunction (uint8_t port_index, uint8_t pins_mask, uint8_t enable, uint32_t pctl_mask);
void Port_AnalogOrDigital (uint8_t port_index, uint8_t pins_mask, AnalogOrDigital pins_type);

#endif
