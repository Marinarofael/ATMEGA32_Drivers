/*
 * LCD_PingPong.c
 *
 * Created: 2/19/2023 10:04:53 AM
 * Author : lenovo
 */ 

#define F_CPU 8000000U
#include <util/delay.h>
#include "DIO.h"
#include "LCD.h"
#include "SWITCH.h"

int main(void)
{
	u16 LCD_PatternLeft[] = {0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C};
	u16 LCD_PatternRight[] = {0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07};
	u16 LCD_PatternBall[] = {0x00, 0x00, 0x0E, 0x0A, 0x0E, 0x00, 0x00, 0x00};
	u8 SWITCH_Right = 1;
	u8 SWITCH_Left = 1;
	u8 LCD_IncDecFlag = 1;
	u8 LCD_ScoreRight = 0;
	u8 LCD_ScoreLeft = 0;
	u8 LCD_LineRight = LCD_FIRST_LINE;
	u8 LCD_LineLeft = LCD_FIRST_LINE;
	u8 LCD_LineBall = LCD_FIRST_LINE;
	u8 LCD_LocBall = LCD_LOCATION_1;
	
    DIO_enuInit();
    LCD_enuInit();
    LCD_enuWriteCommand(LCD_COMMAND_CLEAR);
    LCD_enuGoToXY(LCD_FIRST_LINE,LCD_LOCATION_0);
    
	LCD_enuWriteSpecialCharacter (LCD_PatternLeft, LCD_CharNumber_0, LCD_LineLeft, LCD_LOCATION_0);
	LCD_enuWriteSpecialCharacter (LCD_PatternRight, LCD_CharNumber_1, LCD_LineRight, LCD_LOCATION_15);
	LCD_enuWriteSpecialCharacter (LCD_PatternBall, LCD_CharNumber_2, LCD_LineBall, LCD_LocBall);
	LCD_enuGoToXY(LCD_FIRST_LINE,LCD_LOCATION_2);
	LCD_enuWriteNumber(LCD_ScoreLeft);
	LCD_enuGoToXY(LCD_FIRST_LINE,LCD_LOCATION_13);
	LCD_enuWriteNumber(LCD_ScoreRight);
	
	while (1) 
    {
		if((LCD_LocBall > LCD_LOCATION_0) && (LCD_LocBall < LCD_LOCATION_15))
		{
			if(LCD_IncDecFlag == 1)
			{
				LCD_LocBall++;
			}
			else if(LCD_IncDecFlag == 0)
			{
				LCD_LocBall--;
			}
			
			if(LCD_LineBall == LCD_FIRST_LINE)
			{
				LCD_LineBall = LCD_SECOND_LINE;	
			}
			else if(LCD_LineBall == LCD_SECOND_LINE)
			{
				LCD_LineBall = LCD_FIRST_LINE;
			}
			
			LCD_enuWriteCommand(LCD_COMMAND_CLEAR);
			LCD_enuPrintSpecialCharacter(LCD_CharNumber_0, LCD_LineRight, LCD_LOCATION_15);
			LCD_enuPrintSpecialCharacter(LCD_CharNumber_1, LCD_LineLeft, LCD_LOCATION_0);
			LCD_enuPrintSpecialCharacter(LCD_CharNumber_2, LCD_LineBall, LCD_LocBall);
			LCD_enuGoToXY(LCD_FIRST_LINE,LCD_LOCATION_2);
			LCD_enuWriteNumber(LCD_ScoreLeft);
			LCD_enuGoToXY(LCD_FIRST_LINE,LCD_LOCATION_13);
			LCD_enuWriteNumber(LCD_ScoreRight);
			_delay_ms(300);
		}
		else if(LCD_LocBall == LCD_LOCATION_0)
		{
			LCD_IncDecFlag = 1;
			LCD_LocBall = LCD_LOCATION_1;
			if(LCD_LineBall != LCD_LineLeft)
			{
				LCD_ScoreRight++;
				if(LCD_ScoreRight == 3)
				{
					break;
				}
			}
		}
		else if(LCD_LocBall == LCD_LOCATION_15)
		{
			LCD_IncDecFlag = 0;
			LCD_LocBall = LCD_LOCATION_14;
			if(LCD_LineBall != LCD_LineRight)
			{
				LCD_ScoreLeft++;
				if(LCD_ScoreLeft == 3)
				{
					break;
				}
			}
		}
		
		if(SWITCH_enuGetSwitchValue(SWITCH_MOVE_RIGHT, &SWITCH_Right) == SWITCH_enuOk)
		{
			if(SWITCH_Right == 0)
			{
				if(LCD_LineRight ==  LCD_FIRST_LINE )
				{
					LCD_LineRight =  LCD_SECOND_LINE;
					LCD_enuWriteCommand(LCD_COMMAND_CLEAR);
					LCD_enuPrintSpecialCharacter(LCD_CharNumber_0, LCD_LineRight, LCD_LOCATION_15);
					LCD_enuPrintSpecialCharacter(LCD_CharNumber_1, LCD_LineLeft, LCD_LOCATION_0);
					LCD_enuPrintSpecialCharacter(LCD_CharNumber_2, LCD_LineBall, LCD_LocBall);
					LCD_enuGoToXY(LCD_FIRST_LINE,LCD_LOCATION_2);
					LCD_enuWriteNumber(LCD_ScoreLeft);
					LCD_enuGoToXY(LCD_FIRST_LINE,LCD_LOCATION_13);
					LCD_enuWriteNumber(LCD_ScoreRight);
					_delay_ms(300);
				}
				else if(LCD_LineRight ==  LCD_SECOND_LINE )
				{
					LCD_LineRight =  LCD_FIRST_LINE;
					LCD_enuWriteCommand(LCD_COMMAND_CLEAR);
					LCD_enuPrintSpecialCharacter(LCD_CharNumber_0, LCD_LineRight, LCD_LOCATION_15);
					LCD_enuPrintSpecialCharacter(LCD_CharNumber_1, LCD_LineLeft, LCD_LOCATION_0);
					LCD_enuPrintSpecialCharacter(LCD_CharNumber_2, LCD_LineBall, LCD_LocBall);
					LCD_enuGoToXY(LCD_FIRST_LINE,LCD_LOCATION_2);
					LCD_enuWriteNumber(LCD_ScoreLeft);
					LCD_enuGoToXY(LCD_FIRST_LINE,LCD_LOCATION_13);
					LCD_enuWriteNumber(LCD_ScoreRight);
					_delay_ms(300);
				}
			}
		}
		
		
		if(SWITCH_enuGetSwitchValue(SWITCH_MOVE_LEFT, &SWITCH_Left) == SWITCH_enuOk)
		{
			if(SWITCH_Left == 0)
			{
				if(LCD_LineLeft ==  LCD_FIRST_LINE )
				{
					LCD_LineLeft =  LCD_SECOND_LINE;
					LCD_enuWriteCommand(LCD_COMMAND_CLEAR);
					LCD_enuPrintSpecialCharacter(LCD_CharNumber_0, LCD_LineRight, LCD_LOCATION_15);
					LCD_enuPrintSpecialCharacter(LCD_CharNumber_1, LCD_LineLeft, LCD_LOCATION_0);
					LCD_enuGoToXY(LCD_FIRST_LINE,LCD_LOCATION_2);
					LCD_enuWriteNumber(LCD_ScoreLeft);
					LCD_enuGoToXY(LCD_FIRST_LINE,LCD_LOCATION_13);
					LCD_enuWriteNumber(LCD_ScoreRight);
					_delay_ms(300);
				}
				else if(LCD_LineLeft ==  LCD_SECOND_LINE )
				{
					LCD_LineLeft =  LCD_FIRST_LINE;
					LCD_enuWriteCommand(LCD_COMMAND_CLEAR);
					LCD_enuPrintSpecialCharacter(LCD_CharNumber_0, LCD_LineRight, LCD_LOCATION_15);
					LCD_enuPrintSpecialCharacter(LCD_CharNumber_1, LCD_LineLeft, LCD_LOCATION_0);
					LCD_enuGoToXY(LCD_FIRST_LINE,LCD_LOCATION_2);
					LCD_enuWriteNumber(LCD_ScoreLeft);
					LCD_enuGoToXY(LCD_FIRST_LINE,LCD_LOCATION_13);
					LCD_enuWriteNumber(LCD_ScoreRight);
					_delay_ms(300);
				}
			}
		}
    }
	LCD_enuWriteCommand(LCD_COMMAND_CLEAR);
	if(	LCD_ScoreRight > LCD_ScoreLeft)
	{
		LCD_enuGoToXY(LCD_FIRST_LINE,LCD_LOCATION_2);
		LCD_enuWriteString("RIGHT IS THE ");
		LCD_enuGoToXY(LCD_SECOND_LINE,LCD_LOCATION_3);
		LCD_enuWriteString("WINNER !!");
	}
	else if(LCD_ScoreRight < LCD_ScoreLeft)
	{
		LCD_enuGoToXY(LCD_FIRST_LINE,LCD_LOCATION_2);
		LCD_enuWriteString("LEFT IS THE ");
		LCD_enuGoToXY(LCD_SECOND_LINE,LCD_LOCATION_3);
		LCD_enuWriteString("WINNER !!");
	}
	
}

