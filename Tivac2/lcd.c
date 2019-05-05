#include "lcd.h"
#include <stdlib.h>

void LCD_SendCommand (uint8_t command)
{
	DIO_WritePort(LCD_CTRL_PORT, RS, STD_LOW);
	DIO_WritePort(LCD_CTRL_PORT, RW, STD_LOW);
	DIO_WritePort(LCD_CTRL_PORT, E, STD_HIGH);
	systick_wait1ms();
	DIO_Write8Bits(LCD_DATA_PORT, command);
	systick_wait1ms();
	DIO_WritePort(LCD_CTRL_PORT, E, STD_LOW);
	systick_wait1ms();
}

void LCD_SendData (uint8_t data) 
{
	DIO_WritePort(LCD_CTRL_PORT, RS, STD_HIGH);
	DIO_WritePort(LCD_CTRL_PORT, RW, STD_LOW);
	DIO_WritePort(LCD_CTRL_PORT, E, STD_HIGH);
	systick_wait1ms();
	DIO_Write8Bits(LCD_DATA_PORT, data);
	systick_wait1ms();
	DIO_WritePort(LCD_CTRL_PORT, E, STD_LOW);
	systick_wait1ms();
	
/*
 LCD_CTRL_PORT = 0x01;  // setting Rs = 1 and Rw =0 
 LCD_CTRL_PORT |= 0x04; // assert enable 
 LCD_DATA_PORT = data;
 delay_ms(100);
 LCD_CTRL_PORT = 0; 
*/
}

void LCD_DisplayString (const uint8_t *str)
{
	int i;
	LCD_SendCommand(Cursor_Location);
	for(i=0;str[i]!=0;i++)  
	{
		LCD_SendData (str[i]);  
	}
}

void LCD_IntegerToString (uint16_t data)
{
	uint8_t ArrayofChar [20]; //Array of Characters/String to Hold Ascii result
	itoa(data, ArrayofChar, 10);
	LCD_DisplayString(ArrayofChar);
}

void LCD_Init (void)
{
	//initiallizing data port and control port and setting their pins as output
	Port_Init(LCD_CTRL_PORT);
	Port_Init(LCD_DATA_PORT);
	Port_AnalogOrDigital(LCD_DATA_PORT, 0xFF, Digital);
	Port_AnalogOrDigital(LCD_CTRL_PORT, RS|RW|E, Digital);
	Port_AlternateFunction(LCD_DATA_PORT, 0xFF, 0, 0x00);
	Port_AlternateFunction(LCD_CTRL_PORT, RS|RW|E, 0, 0x00);
	//GPIO_PORTA_DEN_R |= (RS|RW|E);
	//GPIO_PORTA_AFSEL_R &= ~(RS|RW|E);
	//GPIO_PORTB_DEN_R |= 0xFF;
	//GPIO_PORTB_AFSEL_R &= ~(0xFF);
	Port_SetPinDirection(LCD_CTRL_PORT,RS,PORT_PIN_OUT);
	Port_SetPinDirection(LCD_CTRL_PORT,RW,PORT_PIN_OUT);
	Port_SetPinDirection(LCD_CTRL_PORT,E,PORT_PIN_OUT);
	Port_SetPinDirection(LCD_DATA_PORT,0xFF,PORT_PIN_OUT);
	//setting lcd to operate in two lines eight bits mode
	LCD_SendCommand(TwoLineEightBitMode);
	LCD_SendCommand(Cursor_Off);
	LCD_SendCommand(Clear_Command);
}

//the implementation of itoa functions and its additional functions
void swap(uint8_t *x, uint8_t *y) {
	uint8_t t = *x; *x = *y; *y = t;
}
// function to reverse buffer[i..j]
uint8_t * reverse(uint8_t *buffer, uint16_t i, uint16_t j)
{
	while (i < j)
		swap(&buffer[i++], &buffer[j--]);

	return buffer;
}
// Iterative function to implement itoa() function in C
uint8_t* itoa(int value, uint8_t* buffer, uint16_t base)
{
	uint16_t i,n;
	// invalid input
	if (base < 2 || base > 32)
		return buffer;

	// consider absolute value of number
	n=abs(value);

	i= 0;
	while (n)
	{
		uint16_t r = n % base;

		if (r >= 10) 
			buffer[i++] = 65 + (r - 10);
		else
			buffer[i++] = 48 + r;

		n = n / base;
	}

	// if number is 0
	if (i == 0)
		buffer[i++] = '0';

	// If base is 10 and value is negative, the resulting string 
	// is preceded with a minus sign (-)
	// With any other base, value is always considered unsigned
	if (value < 0 && base == 10)
		buffer[i++] = '-';

	buffer[i] = '\0'; // null terminate string

	// reverse the string and return it
	return reverse(buffer, 0, i - 1);
}



