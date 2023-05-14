/*
 * LCD_NAME.c
 *
 * Created: 2/17/2023 10:51:17 PM
 * Author : lenovo
 */ 
#define F_CPU 8000000UL
#include <avr/delay.h>
#include "DIO.h"
#include "LCD.h"
#include "SWITCH.h"

int main(void)
{
	LCD_tenuErrorStatus LCD_Return = LCD_enuOk;
	SWITCH_tenuErrorStatus SWITCH_Return = SWITCH_enuOk;
	s8 LCD_Y = 5;
	s8 LCD_X = 0;
	u8 SWITCH_Up = 0;
	u8 SWITCH_Down = 0;
	u8 SWITCH_Left = 0;
	u8 SWITCH_Right = 0;
	u16 Pattern_m[] = {0x00,0x00, 0x00, 0x07, 0x1D, 0x05, 0x07, 0x00};
	u16 pattern_a[] = {0x04, 0x04, 0x04, 0x04, 0x07, 0x00, 0x00, 0x00};
	u16 pattern_r[] = {0x00, 0x00, 0x03, 0x03, 0x06, 0x0C, 0x08, 0x10};
	u16 pattern_i[] = { 0x00, 0x00, 0x01, 0x01, 0x1F, 0x00, 0x0A, 0x00};
	u16 pattern_n[] = {0x00, 0x04, 0x01, 0x01, 0x1F, 0x00, 0x00, 0x00};
		
	DIO_enuInit();
	LCD_enuInit();
	LCD_enuWriteCommand(LCD_COMMAND_CLEAR);
	LCD_enuGoToXY(LCD_FIRST_LINE,LCD_LOCATION_0);

	LCD_enuWriteSpecialCharacter (Pattern_m, LCD_CharNumber_0, LCD_FIRST_LINE, LCD_LOCATION_5);
	LCD_enuWriteSpecialCharacter (pattern_a, LCD_CharNumber_1, LCD_FIRST_LINE, LCD_LOCATION_4);
	LCD_enuWriteSpecialCharacter (pattern_r, LCD_CharNumber_2, LCD_FIRST_LINE, LCD_LOCATION_3);
	LCD_enuWriteSpecialCharacter (pattern_i, LCD_CharNumber_3, LCD_FIRST_LINE, LCD_LOCATION_2);
	LCD_enuWriteSpecialCharacter (pattern_n, LCD_CharNumber_4, LCD_FIRST_LINE, LCD_LOCATION_1);
	LCD_enuWriteSpecialCharacter (pattern_a, LCD_CharNumber_1, LCD_FIRST_LINE, LCD_LOCATION_0);
	
    while(1)
	{
		
		if(SWITCH_enuGetSwitchValue(SWITCH_MOVE_RIGHT, &SWITCH_Right) == SWITCH_enuOk)
		{
			if(SWITCH_Right == 0)
			{
				if( LCD_Y + 1> 15 )
				{
					/* do nothing */
				}
				else
				{
					LCD_Y++	;
					LCD_enuWriteCommand(LCD_COMMAND_CLEAR);
					LCD_enuPrintSpecialCharacter(LCD_CharNumber_0, LCD_X, LCD_Y);
					LCD_enuPrintSpecialCharacter(LCD_CharNumber_1, LCD_X, LCD_Y-1);
					LCD_enuPrintSpecialCharacter(LCD_CharNumber_2, LCD_X, LCD_Y-2);
					LCD_enuPrintSpecialCharacter(LCD_CharNumber_3, LCD_X, LCD_Y-3);
					LCD_enuPrintSpecialCharacter(LCD_CharNumber_4, LCD_X, LCD_Y-4);
					LCD_enuPrintSpecialCharacter(LCD_CharNumber_1, LCD_X, LCD_Y-5);
					_delay_ms(600);
				}
			}
		}
		
		if(SWITCH_enuGetSwitchValue(SWITCH_MOVE_LEFT, &SWITCH_Left) == SWITCH_enuOk)
		{
			if(SWITCH_Left == 0)
			{
				if( LCD_Y - 6 < 0)
				{
					/* do nothing*/
				}
				else
				{
					LCD_Y--	;
					LCD_enuWriteCommand(LCD_COMMAND_CLEAR);
					LCD_enuPrintSpecialCharacter(LCD_CharNumber_0, LCD_X, LCD_Y);
					LCD_enuPrintSpecialCharacter(LCD_CharNumber_1, LCD_X, LCD_Y-1);
					LCD_enuPrintSpecialCharacter(LCD_CharNumber_2, LCD_X, LCD_Y-2);
					LCD_enuPrintSpecialCharacter(LCD_CharNumber_3, LCD_X, LCD_Y-3);
					LCD_enuPrintSpecialCharacter(LCD_CharNumber_4, LCD_X, LCD_Y-4);
					LCD_enuPrintSpecialCharacter(LCD_CharNumber_1, LCD_X, LCD_Y-5);
					_delay_ms(600);
				}
			}
		}
		
		if(SWITCH_enuGetSwitchValue(SWITCH_MOVE_UP, &SWITCH_Up) == SWITCH_enuOk)
		{
			if(SWITCH_Up == 0)
			{
				if( LCD_X - 1 < 0 )
				{
					/* do nothing */
				}
				else
				{
					LCD_X--	;
					LCD_enuWriteCommand(LCD_COMMAND_CLEAR);
					LCD_enuPrintSpecialCharacter(LCD_CharNumber_0, LCD_X, LCD_Y);
					LCD_enuPrintSpecialCharacter(LCD_CharNumber_1, LCD_X, LCD_Y-1);
					LCD_enuPrintSpecialCharacter(LCD_CharNumber_2, LCD_X, LCD_Y-2);
					LCD_enuPrintSpecialCharacter(LCD_CharNumber_3, LCD_X, LCD_Y-3);
					LCD_enuPrintSpecialCharacter(LCD_CharNumber_4, LCD_X, LCD_Y-4);
					LCD_enuPrintSpecialCharacter(LCD_CharNumber_1, LCD_X, LCD_Y-5);
					_delay_ms(600);
				}
			}
		}
		
		if(SWITCH_enuGetSwitchValue(SWITCH_MOVE_DOWN, &SWITCH_Down) == SWITCH_enuOk)
		{
			if(SWITCH_Down == 0)
			{
				if( LCD_X + 1 > 1)
				{
					/* do nothing */
				}
				else
				{
					LCD_X++	;
					LCD_enuWriteCommand(LCD_COMMAND_CLEAR);
					LCD_enuPrintSpecialCharacter(LCD_CharNumber_0, LCD_X, LCD_Y);
					LCD_enuPrintSpecialCharacter(LCD_CharNumber_1, LCD_X, LCD_Y-1);
					LCD_enuPrintSpecialCharacter(LCD_CharNumber_2, LCD_X, LCD_Y-2);
					LCD_enuPrintSpecialCharacter(LCD_CharNumber_3, LCD_X, LCD_Y-3);
					LCD_enuPrintSpecialCharacter(LCD_CharNumber_4, LCD_X, LCD_Y-4);
					LCD_enuPrintSpecialCharacter(LCD_CharNumber_1, LCD_X, LCD_Y-5);
					_delay_ms(600);
				}
			}
		}
	}
    
}

