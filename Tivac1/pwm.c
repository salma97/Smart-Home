#include "pwm.h"

void PWM1_3_Init (uint16_t Load, uint16_t Compare, uint32_t RCC, uint32_t GENA, uint32_t PWMnEnable)
{
	uint32_t delay;
	SYSCTL_RCGCPWM_R |= SYSCTL_RCGCPWM_R1;
	delay = SYSCTL_RCGCPWM_R1 & 0xFF00FF00 ;

	SYSCTL_RCC_R |= RCC; 

	PWM1_CTL_R &= ~0x00000008; //disable PWM1 Generator 3
	PWM1_3_GENA_R = GENA ; //action to be taken when pwm = 0, pwm = load, pwm = compare when counting up or down
	PWM1_3_LOAD_R = Load - 1;
	PWM1_3_CMPA_R = Compare;
	PWM1_CTL_R |= 0x00000008; //enable PWM1 Generator 3

	PWM1_ENABLE_R |= PWMnEnable;
}
