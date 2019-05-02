

#ifndef LCD_H_
#define LCD_H_

#include "std_types.h"
#include "port_driver.h"
#include "dio_driver.h"

#define TWO_LINE_LCD_Eight_BIT_MODE      0x38
#define CURSOR_OFF 						 0x0C
#define SET_CURSOR_LOCATION 			 0x80 
#define CLEAR_COMMAND 					 0x01
#define RS  		   					 0x04
#define RW                				 0x08
#define	E                       		 0x10 


void LCD_IntegerToString ( uint16_t data, char* str);



#endif /* LCD_H_ */