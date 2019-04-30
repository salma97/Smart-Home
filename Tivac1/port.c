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
			GPIO_PORTA_CR_R = 0xFF;
			GPIO_PORTA_AMSEL_R &= ~ 0xFF;
			GPIO_PORTA_PCTL_R = 0x00000000;
			GPIO_PORTA_AFSEL_R = 0x00;
			GPIO_PORTA_DEN_R = 0xFF;
			break;
		}

		case PB:
		{
			GPIO_PORTB_LOCK_R = 0x4C4F434B;
			GPIO_PORTB_CR_R = 0xFF;
			GPIO_PORTB_AMSEL_R &= ~ 0xFF;
			GPIO_PORTB_PCTL_R = 0x00000000;
			GPIO_PORTB_AFSEL_R = 0x00;
			GPIO_PORTB_DEN_R = 0xFF;
			break;
		}

		
		
		case PD:
		{
			GPIO_PORTD_LOCK_R = 0x4C4F434B;
			GPIO_PORTD_CR_R = 0xFF;
			GPIO_PORTD_AMSEL_R &= ~ 0xFF;
			GPIO_PORTD_PCTL_R = 0x00000000;
			GPIO_PORTD_AFSEL_R = 0x00;
			GPIO_PORTD_DEN_R = 0xFF;
			break;
		}
		
		case PE:
		{
			GPIO_PORTE_LOCK_R = 0x4C4F434B;
			GPIO_PORTE_CR_R = 0xFF;
			GPIO_PORTE_AMSEL_R &= ~ 0xFF;
			GPIO_PORTE_PCTL_R = 0x00000000;
			GPIO_PORTE_AFSEL_R = 0x00;
			GPIO_PORTE_DEN_R = 0xFF;
			break;
		}
		
		case PF:
		{
			GPIO_PORTF_LOCK_R = 0x4C4F434B;
			GPIO_PORTF_CR_R = 0xFF;
			GPIO_PORTF_AMSEL_R &= ~ 0xFF;
			GPIO_PORTF_PCTL_R = 0x00000000;
			GPIO_PORTF_AFSEL_R = 0x00;
			GPIO_PORTF_DEN_R = 0xFF;
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

	
