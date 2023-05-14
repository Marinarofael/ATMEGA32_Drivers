#include "Std_types.h"
#include "DIO.h"
#include "KEYPAD.h" 
#include "KEYPAD_cfg.h" 

KEYPAD_tenuErrorStatus KEYPAD_enuGetPressedValue( KEYPAD_tenuPressedNumber* Add_penuPressedValue )
{
	KEYPAD_tenuErrorStatus Loc_enuReturn = KEYPAD_enuOk;
	u8 Loc_u8RowCounter = 0, Loc_u8ColumnCounter = 0 , Loc_u8ReturnGetPin = 0;
	
	if (Add_penuPressedValue == NULL)
	{
		Loc_enuReturn = KEYPAD_enuNullPtr;
	}
	
	else
	{
		for(Loc_u8RowCounter = 0; Loc_u8RowCounter < KEYPAD_enuMaxRows; Loc_u8RowCounter++)
		{
			DIO_enuClearPin(KEYPAD_arrayRowPins[Loc_u8RowCounter]);
			
			for(Loc_u8ColumnCounter = 0; Loc_u8ColumnCounter < KEYPAD_enuMaxColumns; Loc_u8ColumnCounter++)
			{
				DIO_enuGetPin(KEYPAD_arrayColumnPins[Loc_u8ColumnCounter], &Loc_u8ReturnGetPin);
				if(! Loc_u8ReturnGetPin)
				{
					*Add_penuPressedValue = KEYPAD_arrayPressedValue[Loc_u8RowCounter][Loc_u8ColumnCounter];
					break;
				}	
			}
			
			DIO_enuSetPin(KEYPAD_arrayRowPins[Loc_u8RowCounter]);
		}
	}
	
	return Loc_enuReturn;	
}