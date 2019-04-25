#ifndef LCD_H_
#define LCD_H_

#include "port.h"
#include "DIO.h"

// LCD Pins:
#define RS 0x04
#define RW 0x08
#define E 0x10
#define LCD_CTRL_PORT PA
#define LCD_DATA_PORT PB

//LCD commands:
#define Clear_Command 0x01
#define TwoLineEightBitMode 0x38
#define Cursor_Off 0x0C
#define Cursor_On 0x0E
#define Cursor_Location 0x80

// This function is used to send 'command' to configure the LCD
void LCD_SendCommand (uint8 command);
// This function is used to send an 'uint8' type of data to the LCD 
void LCD_SendData (uint8 data);
// This function is used to display strings, (we'll use it to display numbers from 0-->999)
void LCD_DisplayString (const uint8 *str);
// This function is used to convert integers to strings (we'll use to convert numbers from 0-->999 to strings;
// because the LCD displays characters only (can translate ASCI codes of characters only)
void LCD_IntegerToString (uint16 data);
// This function is used to Initialize the LCD 
void LCD_Init (void);


//additional functions for the implementation of itoa function
void swap(uint8 *x, uint8 *y);
uint8* reverse(uint8 *buffer, uint16 i, uint16 j);
uint8* itoa(int value, uint8* buffer, uint16 base); 

#endif
