#include "motor.h"

void Motor_Clockwise (void)
{
	
}

void Motor_AntiClockwise (void)
{
	//assume motor steps = 200/revolution
	// 1.8 degree /step // angle = 4 loops*4 steps* 1.8 = 28.8
 for (int i=0;i<4;i++)
  {
   GPIO_PORTB_DATA_R &= ~ 0xF;
   GPIO_PORTB_DATA_R |= 0x0C;
   delay(10);

   GPIO_PORTB_DATA_R &= ~ 0xF;
   GPIO_PORTB_DATA_R |= 0x06;
   delay(10);

   GPIO_PORTB_DATA_R &= ~ 0xF;
   GPIO_PORTB_DATA_R |= 0x03;
   delay(10);

   GPIO_PORTB_DATA_R &= ~ 0xF;
   GPIO_PORTB_DATA_R |= 0x09;
   delay(10);
  }
}
