#include "port.h"

void Port_Init (uint8_t port_index)
{
	 volatile int delay;
	SYSCTL_RCGCGPIO_R |= (1 << port_index);
	delay = SYSCTL_RCGCGPIO_R;
	switch(port_index)
	{
		case PA:
		{
			GPIO_PORTA_LOCK_R = 0x4C4F434B;
			GPIO_PORTA_CR_R = 0xFFFFFFFF;
			break;
		}

		case PB:
		{
			GPIO_PORTB_LOCK_R = 0x4C4F434B;
			GPIO_PORTB_CR_R = 0xFFFFFFFF;
			break;
		}

		
		
		case PD:
		{
			GPIO_PORTD_LOCK_R = 0x4C4F434B;
			GPIO_PORTD_CR_R = 0xFFFFFFFF;
			break;
		}
		
		case PE:
		{
			GPIO_PORTE_LOCK_R = 0x4C4F434B;
			GPIO_PORTE_CR_R = 0xFFFFFFFF;
			break;
		}
		
		case PF:
		{
			GPIO_PORTF_LOCK_R = 0x4C4F434B;
			GPIO_PORTF_CR_R = 0xFFFFFFFF;
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

	
void Port_AnalogOrDigital (uint8_t port_index, uint8_t pins_mask, AnalogOrDigital pins_type){
	switch (port_index)
	{
		case PA:
			if(pins_type == Analog){
				GPIO_PORTA_AMSEL_R |= (pins_mask);
				GPIO_PORTA_DEN_R &= ~(pins_mask);
			}

			else if (pins_type == Digital){
				GPIO_PORTA_AMSEL_R &= ~(pins_mask);
				GPIO_PORTA_DEN_R |= (pins_mask);
			}

			break;
		case PB:
			if(pins_type == Analog){
				GPIO_PORTB_AMSEL_R |= (pins_mask);
				GPIO_PORTB_DEN_R &= ~(pins_mask);
			}

			else if (pins_type == Digital){
				GPIO_PORTB_AMSEL_R &= ~(pins_mask);
				GPIO_PORTB_DEN_R |= (pins_mask);
			}
			
			break;
		case PC:
			if(pins_type == Analog){
				GPIO_PORTC_AMSEL_R |= (pins_mask);
				GPIO_PORTC_DEN_R &= ~(pins_mask);
			}

			else if (pins_type == Digital){
				GPIO_PORTC_AMSEL_R &= ~(pins_mask);
				GPIO_PORTC_DEN_R |= (pins_mask);
			}

			break;
		case PD:
			if(pins_type == Analog){
				GPIO_PORTD_AMSEL_R |= (pins_mask);
				GPIO_PORTD_DEN_R &= ~(pins_mask);
			}

			else if (pins_type == Digital){
				GPIO_PORTD_AMSEL_R &= ~(pins_mask);
				GPIO_PORTD_DEN_R |= (pins_mask);
			}

			break;
		case PE:
			if(pins_type == Analog){
				GPIO_PORTE_AMSEL_R |= (pins_mask);
				GPIO_PORTE_DEN_R &= ~(pins_mask);
			}

			else if (pins_type == Digital){
				GPIO_PORTE_AMSEL_R &= ~(pins_mask);
				GPIO_PORTE_DEN_R |= (pins_mask);
			}

			break;
		case PF:
			if(pins_type == Analog){
				GPIO_PORTF_AMSEL_R |= (pins_mask);
				GPIO_PORTF_DEN_R &= ~(pins_mask);
			}

			else if (pins_type == Digital){
				GPIO_PORTF_AMSEL_R &= ~(pins_mask);
				GPIO_PORTF_DEN_R |= (pins_mask);
			}

			break;
	}
}

void Port_AlternateFunction (uint8_t port_index, uint8_t pins_mask, uint8_t enable, uint32_t pctl_mask)
{
	int i;
	for (i =0 ; i<8 ;i++)
	{
		if(pins_mask&(1<<i))
		{
			break;
		}
	}
	switch (port_index)
	{
		case PA:
			if (enable)
			{
				GPIO_PORTA_AFSEL_R |= pins_mask;
				GPIO_PORTA_PCTL_R = (GPIO_PORTA_PCTL_R &~(0xF<<i*4)) | (pctl_mask & (0xF<<i*4));
			}
			else
			{
				GPIO_PORTA_AFSEL_R &= ~pins_mask;
			}
			break;
		case PB:
			if (enable)
			{
				GPIO_PORTB_AFSEL_R |= pins_mask;
				GPIO_PORTB_PCTL_R = (GPIO_PORTB_PCTL_R &~(0xF<<i*4)) | (pctl_mask & (0xF<<i*4));
			}
			else
			{
				GPIO_PORTB_AFSEL_R &= ~pins_mask;
			}
			break;
		case PC:
			if (enable)
			{
				GPIO_PORTC_AFSEL_R |= pins_mask;
				GPIO_PORTC_PCTL_R = (GPIO_PORTC_PCTL_R &~(0xF<<i*4)) | (pctl_mask & (0xF<<i*4));
			}
			else
			{
				GPIO_PORTC_AFSEL_R &= ~pins_mask;
			}
			break;
		case PD:
			if (enable)
			{
				GPIO_PORTD_AFSEL_R |= pins_mask;
				GPIO_PORTD_PCTL_R = (GPIO_PORTD_PCTL_R &~(0xF<<i*4)) | (pctl_mask & (0xF<<i*4));
			}
			else
			{
				GPIO_PORTD_AFSEL_R &= ~pins_mask;
			}
			break;
		case PE:
			if (enable)
			{
				GPIO_PORTE_AFSEL_R |= pins_mask;
				GPIO_PORTE_PCTL_R = (GPIO_PORTE_PCTL_R &~(0xF<<i*4)) | (pctl_mask & (0xF<<i*4));
			}
			else
			{
				GPIO_PORTE_AFSEL_R &= ~pins_mask;
			}
			break;
		case PF:
			if (enable)
			{
				GPIO_PORTF_AFSEL_R |= pins_mask;
				GPIO_PORTF_PCTL_R = (GPIO_PORTF_PCTL_R &~(0xF<<i*4)) | (pctl_mask & (0xF<<i*4));
			}
			else
			{
				GPIO_PORTF_AFSEL_R &= ~pins_mask;
			}
			break;
	}
}
