#define F_CPU 8000000UL
#include <avr/delay.h>
#include "DIO.h" 
#include "LCD.h"  

/********************************************************************************************************/
/************************************ STATIC FUNCTIONS PROTOTYPES ***************************************/

static WriteCommand(u8 Cpy_u8Command);
static WriteData(u8 Cpy_u8Character);


/********************************************************************************************************/
/********************************** USER FUNCTIONS IMPLEMENTATION ***************************************/

/* implementation of function to write command */
LCD_tenuErrorStatus LCD_enuWriteCommand (u8 Cpy_u8Command)
{
	LCD_tenuErrorStatus Loc_enuReturn = LCD_enuOk;
	
	WriteCommand(Cpy_u8Command);
	return LCD_enuOk;
}

/* implementation of function to write data */
LCD_tenuErrorStatus LCD_enuWriteData (u8 Cpy_u8Character)
{
	LCD_tenuErrorStatus Loc_enuReturn = LCD_enuOk;
	
	WriteData(Cpy_u8Character);
	return LCD_enuOk;
}

/* implementation of function to initialize the LCD according to configuration */
LCD_tenuErrorStatus LCD_enuInit(void)
{
	LCD_tenuErrorStatus Loc_enuReturn = LCD_enuOk;
	
	_delay_ms(40);
	WriteCommand(LCD_COMMAND_FUNCTION_SET);
	_delay_ms(2);
	WriteCommand(LCD_COMMAND_DISPLAY);
	_delay_ms(2);
	WriteCommand(LCD_COMMAND_CLEAR); 
	_delay_ms(5);
	return LCD_enuOk;	
}

LCD_tenuErrorStatus LCD_enuGoToXY ( u8 Cpy_u8Line, u8 Cpy_u8Location)
{
	LCD_tenuErrorStatus Loc_enuReturn = LCD_enuOk;
	u8 Loc_u8Location = 128 ;
	
	if(!((Cpy_u8Line == LCD_FIRST_LINE) || (Cpy_u8Line == LCD_SECOND_LINE)))
	{
		Loc_enuReturn = LCD_enuNotOk;
	}
	else if ((Cpy_u8Location < 0) | (Cpy_u8Location > 15))
	{
		Loc_enuReturn = LCD_enuNotOk;
	}
	else
	{
		if(Cpy_u8Line == LCD_FIRST_LINE)
		{
			Loc_u8Location = Loc_u8Location + Cpy_u8Location;
		}
		else if(Cpy_u8Line == LCD_SECOND_LINE)
		{
			Loc_u8Location = Loc_u8Location + Cpy_u8Location + 0x40;
		}
		WriteCommand(Loc_u8Location);
	}
	return Loc_enuReturn;
}

/********************************************************************************************************/
/******************************** STATIC FUNCTIONS IMPLEMENTATION ***************************************/

/* implementation of static function to write command */
static WriteCommand(u8 Cpy_u8Command)
{
	DIO_enuClearPin(LCD_CONTROL_RS);   	                  // Select Command Register
	DIO_enuClearPin(LCD_CONTROL_RW);	                  // Select Write
	DIO_enuSetPortValue(LCD_DATA_PORT, Cpy_u8Command);	  // send the command on data pins
	DIO_enuSetPin(LCD_CONTROL_E);						  // set enable pin to generate pulse
	_delay_ms(2);										  // wait 2 ms
	DIO_enuClearPin(LCD_CONTROL_E);						  // clr enable pin	
}

/* implementation of static function to write data */
static WriteData(u8 Cpy_u8Character)
{
	DIO_enuSetPin(LCD_CONTROL_RS);   	                  // Select CData Register
	DIO_enuClearPin(LCD_CONTROL_RW);	                  // Select Write
	DIO_enuSetPortValue(LCD_DATA_PORT, Cpy_u8Character);  // send the command on data pins
	DIO_enuSetPin(LCD_CONTROL_E);						  // set enable pin to generate pulse
	_delay_ms(2);										  // wait 2 ms
	DIO_enuClearPin(LCD_CONTROL_E);						  // clr enable pin
}