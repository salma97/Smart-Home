#include "tm4c123gh6pm.h"

 
 void LCD_WriteChar (uint8 LCD_DATA)
{
	uint8 RS;
	uint8 RW;
	uint8 E;
	uint8 LCD_DATA;
	RS=0x02;
	RW=0x04;
	E=0x08;
	DIO_WritePort( PORTA, RS, STD_HIGH);
	DIO_WritePort( PORTA, RW, STD_LOW);
	DIO_WritePort( PORTA, E, STD_HIGH);
	msdelay(1)
	DIO_setValue( PORTB, LCD_DATA);
	msdelay(1)
	DIO_WritePort( PORTA, E, STD_LOW);
}