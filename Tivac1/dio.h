#ifndef DIO_H_
#define DIO_H_

#include "tm4c123gh6pm.h"
#include "std_types.h"

typedef enum 
{
	STD_LOW = 0,
	STD_HIGH = 1
}DIO_LevelType;

uint8_t DIO_ReadPort (uint8_t port_index, uint8_t pins_mask);
void DIO_WritePort (uint8_t port_index, uint8_t pins_mask, DIO_LevelType pins_level);
void DIO_FlipPort (uint8_t port_index, uint8_t pins_mask);
void DIO_Write8Bits (uint8_t port_index, uint8_t pins_mask);

#endif
