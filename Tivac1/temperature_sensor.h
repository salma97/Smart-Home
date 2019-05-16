#ifndef TEMPERATURE_SENSOR_H_
#define TEMPERATURE_SENSOR_H_

#include "port.h"
#include "DIO.h"
#include "adc.h"

void TempSensor_Init (void);
void Temp_StartReading(void);
#endif
