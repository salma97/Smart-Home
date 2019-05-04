#include "motor.h"
#include "systick.h"

const uint8_t steps[ ] = {0x9, 0x3, 0x6, 0xC};
int cnt =8;
void Motor_Clockwise (void)
{
	
}

void Motor_AntiClockwise (void)
{// assume step angle =5 degree
	// (30 degree/ angle for one step)
	uint8_t i;
 for (i=0;i<6;i++)
  {
   GPIO_PORTB_DATA_R &= ~ 0xF;
   GPIO_PORTB_DATA_R |= steps[cnt-- & 3];
   delay(10);
  }
}

void Motor_Init(void){
	Port_PinDirectionType direction = PORT_PIN_OUT;
	AnalogOrDigital type = Digital;
	Port_Init(PB);
	Port_SetPinDirection(PB, 0x1111, direction);
	Port_AnalogOrDigital (PB, 0x1111, type);
	cnt = 1;
}
