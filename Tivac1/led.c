#include "led.h"

void LED_Init (void)
{
	int delay;
	SYSCTL_RCGCPWM_R |= SYSCTL_RCGCPWM_R1;
	delay = SYSCTL_RCGCPWM_R1;
	SYSCTL_RCGCGPIO_R |= (0x20); //PF
	delay = SYSCTL_RCGCPWM_R1;
	
	SYSCTL_RCC_R |= 0x001A0000; //enable pwm divisor and set it to /64
	PWM1_CTL_R &= ~0x00000008;
	PWM1_3_GENA_R = 0x00000033; //drive pwm high at 0, low at compare value
	PWM1_3_LOAD_R = 256 - 1;
	PWM1_3_CMPA_R = 254;
	PWM1_CTL_R |= 0x00000008;
	
	GPIO_PORTF_AFSEL_R |= 0x04;
	GPIO_PORTF_PCTL_R |= (GPIO_PORTF_PCTL_R & 0xFFFFF0FF) | 0x00000500;
	GPIO_PORTF_AMSEL_R &= ~0x04;
	GPIO_PORTF_DEN_R |= 0x04;
	GPIO_PORTF_DIR_R |= 0x04;
	
	PWM1_ENABLE_R |= 0x00000040;
	
}