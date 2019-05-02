#include "lcd.h"

void LCD_IntegerToString ( uint16_t data, char* str) 
{ 	uint8_t temp;
	uint8_t start;
    uint8_t end;
    int i = 0;  
  
    /* Handle 0 explicitely, otherwise empty string is printed for 0 */
    if (data == 0) 
    { 
        str[i++] = '0'; 
        str[i] = '\0'; 
    } 
  
    // Process individual digits 
    while (data != 0) 
    { 
        uint16_t rem = data % 10; 
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0'; 
        data = data/10; 
    } 
    str[i] = '\0'; // Append string terminator 
  
    // Reverse the string 
		start = 0; 
    end = i -1; 
		
    while (start < end) 
    { temp = *(str+start);
			*(str+start) = *(str+end);
			*(str+end) = temp;
			
		    start++; 
      end--; 
    }
} 