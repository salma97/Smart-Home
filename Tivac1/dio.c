#include "dio.h" 

uint8_t DIO_ReadPort (uint8_t port_index, uint8_t pins_mask)
{
	switch(port_index)
	{
	case PA:
	return (GPIO_PORTA_DATA_R & pins_mask);
	case PB:
	return (GPIO_PORTB_DATA_R & pins_mask);
	case PC:
	return (GPIO_PORTC_DATA_R & pins_mask);
	case PD:
	return (GPIO_PORTD_DATA_R & pins_mask);
	case PE:
	return (GPIO_PORTE_DATA_R & pins_mask);
	case PF:
	return (GPIO_PORTF_DATA_R & pins_mask);
	default: 
		return 0;
	}
}

void DIO_Write8Bits (uint8_t port_index, uint8_t pins_mask)
{
	switch(port_index)
	{
		case PA:
		  DIO_WritePort(PA, pins_mask, STD_HIGH);
		  DIO_WritePort(PA, ~(pins_mask), STD_LOW);
	   	  break;
		
		case PB:
	    DIO_WritePort(PB, pins_mask, STD_HIGH);
		  DIO_WritePort(PB, ~(pins_mask), STD_LOW);
	   	  break;
		
		case PC:
		  DIO_WritePort(PC, pins_mask, STD_HIGH);
		  DIO_WritePort(PC, ~(pins_mask), STD_LOW);
	   	  break;
		
		case PD:
	    DIO_WritePort(PD, pins_mask, STD_HIGH);
		  DIO_WritePort(PD, ~(pins_mask), STD_LOW);
	   	  break;
		
		case PE:
		  DIO_WritePort(PE, pins_mask, STD_HIGH);
		  DIO_WritePort(PE, ~(pins_mask), STD_LOW);
	   	  break;
		
		case PF:
		  DIO_WritePort(PF, pins_mask, STD_HIGH);
		  DIO_WritePort(PF, ~(pins_mask), STD_LOW);
	   	  break;
	}
}
void DIO_WritePort (uint8_t port_index, uint8_t pins_mask, DIO_LevelType pins_level)
{
	switch (port_index)
	{
		case PA:
			if (pins_level==STD_HIGH)
			{
				GPIO_PORTA_DATA_R |= pins_mask;
			}
			else
			{
				GPIO_PORTA_DATA_R &= ~(pins_mask);
			}
		break;
		
		case PB:
			if (pins_level==STD_HIGH)
			{
				GPIO_PORTB_DATA_R |= pins_mask;
			}
			else
			{
				GPIO_PORTB_DATA_R &= ~(pins_mask);
			}
	   	  break;
		
		case PC:
			if (pins_level==STD_HIGH)
			{
				GPIO_PORTC_DATA_R |= pins_mask;
			}
			else
			{
				GPIO_PORTC_DATA_R &= ~(pins_mask);
			}
	   	  break;
		
		case PD:
			if (pins_level==STD_HIGH)
			{
				GPIO_PORTD_DATA_R |= pins_mask;
			}
			else
			{
				GPIO_PORTD_DATA_R &= ~(pins_mask);
			}
	   	  break;
		
		case PE:
			if (pins_level==STD_HIGH)
			{
				GPIO_PORTE_DATA_R |= pins_mask;
			}
			else
			{
				GPIO_PORTE_DATA_R &= ~(pins_mask);
			}
	   	  break;
		
		case PF:
			if (pins_level==STD_HIGH)
			{
				GPIO_PORTF_DATA_R |= pins_mask;
			}
			else
			{
				GPIO_PORTF_DATA_R &= ~(pins_mask);
			}
			break;
			
	}
}

void DIO_FlipPort (uint8_t port_index, uint8_t pins_mask)
{
	switch(port_index)
	{
	case PA :
	   GPIO_PORTA_DATA_R ^= pins_mask;
        case PB :
	   GPIO_PORTB_DATA_R ^= pins_mask;
	case PC :    
	   GPIO_PORTC_DATA_R ^= pins_mask;
        case PD :
	   GPIO_PORTD_DATA_R ^= pins_mask;
	case PE :
	   GPIO_PORTE_DATA_R ^= pins_mask;
	case PF :
	   GPIO_PORTF_DATA_R ^= pins_mask;
	}
}
