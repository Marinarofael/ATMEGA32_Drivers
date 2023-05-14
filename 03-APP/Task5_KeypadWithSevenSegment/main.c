/*
 * KeyPad.c
 *
 * Created: 1/29/2023 8:59:37 AM
 * Author : lenovo
 */ 
#define F_CPU 8000000
#include <util/delay.h>
#include "Std_types.h"
#include "Bit_math.h"
#include "KEYPAD.h"
#include "KEYPAD_cfg.h"
#include "SSEGMENT.h"
#include "SSEGMENT_cfg.h"

int main(void)
{
    /* Replace with your application code */
	u8 Loc_u8PressedValue = 17, Loc_u8PreviousPressedValue = 17;
	DIO_enuInit();
    while (1) 
    {
		
		while(Loc_u8PreviousPressedValue == Loc_u8PressedValue)
		{
			KEYPAD_enuGetPressedValue(&Loc_u8PressedValue);

		}
		SSEGMENT_enuPrintSevenSegment(Loc_u8PressedValue);
		Loc_u8PreviousPressedValue = Loc_u8PressedValue;
		_delay_ms(50);
    }
}

