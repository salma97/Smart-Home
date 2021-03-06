#include "adc.h"
#include "uart.h"
void  ADC0SS3_Handler (void)
{
	uint8_t temperature = 147 - (247 * ADC0_SSFIFO3_R)/4096; ; // Convert the ADC value into celcus 
	UART2_Write(temperature); // send the temperature in celcus through uart 
	ADC0_InterruptAck(3); // acknoweldge the adc interrupt to clear the flag in RIS register and restart the conversion of the temp. 
	
}

void ADC0_SS3_Init (void)
{
	volatile uint8_t delay;
	 SYSCTL_RCGC0_R|=0x00010000;
	delay=0;
	SYSCTL_RCGCADC_R |= (1<<0);			//enable ADC0 clock
	delay=SYSCTL_RCGCADC_R;
	delay=0;
	SYSCTL_RCGC2_R |=0x00000010;
	delay=0;
	ADC0_ACTSS_R &= ~(1<<SS_num);				//disable sample sequncer during configuration
	ADC0_EMUX_R = (ADC0_EMUX_R& ~(0xF<<SS_num*4)) | (trigger_select<<SS_num*4) ; //choosing the triggering method
	ADC0_SSMUX3_R = 0x0;					//input from channel 0 i.e PE3
	ADC0_SSCTL3_R |= ( (ADC0_SSCTL3_TS0<<3) | (ADC0_SSCTL3_IE0<<2) | (ADC0_SSCTL3_END0<<1));  //configuring sample sequncer 3 control port

	if(ADC0_SSCTL3_IE0	==	0x1)
	{
		ADC0_IM_R |= (1<<3);
		NVIC_EN0_R |= (1<<17);
		NVIC_PRI4_R  |= 0x2000;
	}
	ADC0_ACTSS_R |= (1<<SS_num);		//enable sample sequncer during configuration
	ADC0_ISC_R |= (1<<SS_num);
}


uint16_t ADC0_SS3_readValue(void)
{
	uint16_t ADCValue= ADC0_SSFIFO3_R&0x0FFF;
	return ADCValue;
}

void ADC0_InterruptAck(uint8_t SS_Num)
{
		ADC0_ISC_R |= (1<<SS_Num);
}

void ADC0_SS3_SC (void)
{
	ADC0_PSSI_R = 1<<3 ;
}
