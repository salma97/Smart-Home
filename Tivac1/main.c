 #include "adc.h"
#include "uart.h"
#include "led.h"
#include "motor.h"
#include "temperature_sensor.h"
#include "systick.h"

void SystemInit()
{
	__disable_irq();
	LED_Init();
	systick_init();
	Motor_Init();
	UART2_Init();
	TempSensor_Init();
	delay(1000);
	__enable_irq();
}


int __main(void)
{
	
	while(1){
		
		Temp_StartReading();
		delay(1000);
	 
	
		
		}
		
}
