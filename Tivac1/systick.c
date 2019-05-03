#include "systick.h"
#include "tm4c123gh6pm.h"
#include "std_types.h"

void systick_wait1ms(void){
	NVIC_ST_RELOAD_R = 16000 - 1;
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R&NVIC_ST_CTRL_COUNT) != NVIC_ST_CTRL_COUNT);
}
