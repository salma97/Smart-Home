#include "lcd.c"
 
 void LCD_WriteChar (uint8 LCD_DATA)
{

	DIO_WritePort( PORTA, RS, STD_HIGH);
	DIO_WritePort( PORTA, RW, STD_LOW);
	DIO_WritePort( PORTA, E, STD_HIGH);
	msdelay(1)
	DIO_setValue( PORTB, LCD_DATA);
	msdelay(1)
	DIO_WritePort( PORTA, E, STD_LOW);
}
