#include "systick.h"
#include "tm4c123gh6pm.h"
#include "std_types.h"

void systick_init(void){
		NVIC_ST_CTRL_R &= ~NVIC_ST_CTRL_ENABLE;
		NVIC_ST_RELOAD_R = NVIC_ST_RELOAD_M;
		NVIC_ST_CURRENT_R = NVIC_ST_CURRENT_S;
		NVIC_ST_CTRL_R |= (NVIC_ST_CTRL_CLK_SRC | NVIC_ST_CTRL_ENABLE);
	
}

void systick_wait1ms(void){
	NVIC_ST_RELOAD_R = 16000 - 1;
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R&NVIC_ST_CTRL_COUNT) != NVIC_ST_CTRL_COUNT);
}

void delay(uint16_t i){
	for(uint16_t j=0; j<i; j++){
		systick_wait1ms();
	}
}
