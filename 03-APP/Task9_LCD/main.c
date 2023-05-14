/*
 * LCD.c
 *
 * Created: 2/10/2023 2:09:41 PM
 * Author : lenovo
 */ 
#define F_CPU 8000000UL
#include <avr/delay.h>
#include "DIO.h"
#include "LCD.h"


int main(void)
{
	
	u8 i = 0;
	u16 Pattern1[]= {0x0e,0x0e,0x04,0x04,0x1f,0x04,0x0a,0x0a};
	u16 Pattern2[]= {0x0e,0x0e,0x15,0x0e,0x04,0x04,0x0a,0x11};
		
	 DIO_enuInit();
	 LCD_enuInit();
	 LCD_enuWriteCommand(LCD_COMMAND_CLEAR);
	 LCD_enuGoToXY(LCD_FIRST_LINE,LCD_LOCATION_0);


    while (1) 
    {
		
		
		LCD_enuWriteString("MARINA");
		_delay_ms(2000);
		LCD_enuWriteCommand(LCD_COMMAND_CLEAR);
		
		LCD_enuWriteNumber(15);
		_delay_ms(2000);
		LCD_enuWriteCommand(LCD_COMMAND_CLEAR);
		
		/*LCD_enuWriteSpecialCharacter (Pattern1, LCD_CharNumber_0, LCD_FIRST_LINE, LCD_LOCATION_0);
		_delay_ms(800);
		LCD_enuWriteSpecialCharacter (Pattern2, LCD_CharNumber_1, LCD_FIRST_LINE, LCD_LOCATION_0);
		_delay_ms(800);
		*/
		
		/*
		if(LCD_enuGoToXY(LCD_FIRST_LINE,i) == LCD_enuOk)
		{
			LCD_enuWriteString("Marina");
			_delay_ms(700);
			i++	;	
			LCD_enuWriteCommand(LCD_COMMAND_CLEAR);
		}
		else
		{
			i = 0;
		}
		*/
    }
}

