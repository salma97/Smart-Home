#include "potentiometer.h"
void ADC_Init_Potentiometer (void)
{
ADC0_SS3_Init ();
GPIO_PORTE_DIR_R&=~0x08;
Port_AnalogOrDigital (PE, 0x08, 0);
Port_AlternateFunction (PE,0x08,1, 0x00);

}
