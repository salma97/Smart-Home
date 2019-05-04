#include "motor.h"
#include "systick.h"

const uint8_t steps[ ] = {0x9, 0x3, 0x6, 0xC};
uint8_t cnt =100;
void Motor_Clockwise (void)
{
		uint8_t i;
  for (i=0;i<6;i++)
  {
   GPIO_PORTB_DATA_R &= ~ 0xF;
   GPIO_PORTB_DATA_R |= steps[cnt++%4];
   delay(10);
  }
  cnt--;
}

void Motor_AntiClockwise (void)
{// assume step angle =5 degree
	// (30 degree/ angle for one step)
	uint8_t i;
 for (i=0;i<6;i++)
  {
   GPIO_PORTB_DATA_R &= ~ 0xF;
   GPIO_PORTB_DATA_R |= steps[cnt-- %4];
   delay(10);
  }
  cnt++;
}
