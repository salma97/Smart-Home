#include "motor.h"
#include "systick.h"

const uint8_t steps[ ] = {0x09, 0x03, 0x06, 0x0C};
uint8_t cnt =100;


void Motor_Clockwise (void)
{
	uint8_t i;
	for (i=0;i<180;i++)
	{
		GPIO_PORTB_DATA_R &= ~ 0xF;
		GPIO_PORTB_DATA_R |= steps[cnt++%4];
		delay(10);
	}
	cnt--;
}

void delay_1m(uint16_t time){
	uint16_t t;
	time = time*16000;
	for( t=0; t<time; t++);
}

void Motor_AntiClockwise (void)
{// assume step angle =5 degree
	// (30 degree/ angle for one step)
	uint8_t i;
	for (i=0;i<180;i++)
	{
		//GPIO_PORTB_DATA_R &= ~ 0xF;
		GPIO_PORTB_DATA_R = steps[cnt-- %4];
		delay(10);
	}
	cnt++;
}

void Motor_Init(void)
{
	Port_PinDirectionType direction = PORT_PIN_OUT;
	AnalogOrDigital type = Digital;
	Port_Init(PB);
	Port_SetPinDirection(PB, 0x0F, direction);
	Port_AnalogOrDigital (PB, 0x0F, type);
	//GPIO_PORTB_DATA_R &= ~ 0xF;
	GPIO_PORTB_DATA_R = steps[cnt%4];
}
