#include "port.h"

void Port_Init (uint8_t port_index)
{
	int delay;
	SYSCTL_RCGCGPIO_R |= (1 << port_index);
	delay = SYSCTL_RCGCGPIO_R;
	switch(port_index)
	{
		case PA:
		{
			GPIO_PORTA_LOCK_R = 0x4C4F434B;
			break;
		}

		case PB:
		{
			GPIO_PORTB_LOCK_R = 0x4C4F434B;
			break;
		}

		
		
		case PD:
		{
			GPIO_PORTD_LOCK_R = 0x4C4F434B;
			break;
		}
		
		case PE:
		{
			GPIO_PORTE_LOCK_R = 0x4C4F434B;
			break;
		}
		
		case PF:
		{
			GPIO_PORTF_LOCK_R = 0x4C4F434B;
			break;
		}		
	}
}
void Port_SetPinPullUp (uint8_t port_index, uint8_t pins_mask, uint8_t enable)
{
switch(port_index)
	{
	case PA :
	   if (enable) 
	   GPIO_PORTA_PUR_R |= pins_mask;
	   else GPIO_PORTA_PUR_R &= ~pins_mask;
    case PB :
	   if (enable) 
	   GPIO_PORTB_PUR_R |= pins_mask;
	   else GPIO_PORTB_PUR_R &= ~pins_mask;
	   
	case PC :    
	   if (enable) 
	   GPIO_PORTC_PUR_R |= pins_mask;
	   else GPIO_PORTC_PUR_R &= ~pins_mask;
	   
    case PD :
	   if (enable) 
	   GPIO_PORTD_PUR_R |= pins_mask;
	   else GPIO_PORTD_PUR_R &= ~pins_mask;
	   
	case PE :
	   if (enable) 
	   GPIO_PORTE_PUR_R |= pins_mask;
	   else GPIO_PORTE_PUR_R &= ~pins_mask;
	   
	case PF :
	   if (enable) 
	   GPIO_PORTF_PUR_R |= pins_mask;
	   else GPIO_PORTF_PUR_R &= ~pins_mask;
	   
	}   	
}
	
void Port_SetPinPullDown(uint8_t port_index,uint8_t pins_mask,uint8_t enable)
{
	switch(port_index)
	{
		case PA:
			if (enable){GPIO_PORTA_PDR_R |= pins_mask;}
			else {GPIO_PORTA_PDR_R &= ~pins_mask;}
			break;
		case PB:
			if (enable){GPIO_PORTB_PDR_R |= pins_mask;}
			else {GPIO_PORTB_PDR_R &= ~pins_mask;}
			break;
		case PC:
			if (enable){GPIO_PORTC_PDR_R |= pins_mask;}
			else {GPIO_PORTC_PDR_R &= ~pins_mask;}
			break;
		case PD:
			if (enable){GPIO_PORTD_PDR_R |= pins_mask;}
			else {GPIO_PORTD_PDR_R &= ~pins_mask;}
			break;
		case PE:
			if (enable){GPIO_PORTE_PDR_R |= pins_mask;}
			else {GPIO_PORTE_PDR_R &= ~pins_mask;}
			break;
		case PF:
			if (enable){GPIO_PORTF_PDR_R |= pins_mask;}
			else {GPIO_PORTF_PDR_R &= ~pins_mask;}
			break;
	}
}

void Port_SetPinDirection (uint8_t port_index, uint8_t pins_mask, Port_PinDirectionType pins_direction)
{
	switch (port_index)
	{
		case PA:
				if(pins_direction == PORT_PIN_OUT)
											GPIO_PORTA_DIR_R |= (pins_mask);
				else if (pins_direction == PORT_PIN_IN)
											GPIO_PORTA_DIR_R &= ~(pins_mask);
			break;
		case PB:
				if(pins_direction == PORT_PIN_OUT)
											GPIO_PORTB_DIR_R |= (pins_mask);
				else if (pins_direction == PORT_PIN_IN)
											GPIO_PORTB_DIR_R &= ~(pins_mask);
			break;
		case PC:
				if(pins_direction == PORT_PIN_OUT)
											GPIO_PORTC_DIR_R |= (pins_mask);
				else if (pins_direction == PORT_PIN_IN)
											GPIO_PORTC_DIR_R &= ~(pins_mask);
			break;
		case PD:
				if(pins_direction == PORT_PIN_OUT)
											GPIO_PORTD_DIR_R |= (pins_mask);
				else if (pins_direction == PORT_PIN_IN)
											GPIO_PORTD_DIR_R &= ~(pins_mask);
			break;
		case PE:
				if(pins_direction == PORT_PIN_OUT)
											GPIO_PORTE_DIR_R |= (pins_mask);
				else if (pins_direction == PORT_PIN_IN)
											GPIO_PORTE_DIR_R &= ~(pins_mask);
			break;
		case PF:
				if(pins_direction == PORT_PIN_OUT)
											GPIO_PORTF_DIR_R |= (pins_mask);
				else if (pins_direction == PORT_PIN_IN)
											GPIO_PORTF_DIR_R &= ~(pins_mask);
			break;
	}
}
void PORT_InterruptAck(uint8_t pins_mask)
{
	GPIO_PORTF_ICR_R |= pins_mask;
}
	
