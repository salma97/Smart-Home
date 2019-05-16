#include "pwm.h"
#include "port.h"


void PWM1_3_Init ()
{
	volatile uint32_t delay1;
	SYSCTL_RCGCTIMER_R |= (1<<1);
delay1 = 5;
SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R5;
delay1 = 5;
TIMER1_CTL_R=~(1<<0);
TIMER1_CFG_R =0x00000004;
TIMER1_TAMR_R |= (2<<0) | (1<<3);
TIMER1_TAMR_R &=~(1<<2);
TIMER1_CTL_R &= ~(1<<14);
TIMER1_TAILR_R =100;
TIMER1_TAMATCHR_R = 99;
TIMER1_CTL_R |=(1<<0);

}
