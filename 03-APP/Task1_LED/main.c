/*
 * LED.c
 *
 * Created: 1/17/2023 10:12:19 PM
 * Author : lenovo
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "Std_types.h"
#include "Bit_math.h"
#include "LED.h"
#include "LED_cfg.h"


int main(void)
{
    u8 Loc_u8Led[10]={LED_1, LED_2, LED_3, LED_4, LED_5, LED_6, LED_7, LED_8};
	s8 Loc_s8LedNumber = 0;
	u8 Loc_enuReturnFunction = 0;
	
	DIO_enuInit();
    while(TRUE) 
    {
		for(Loc_s8LedNumber = 0; Loc_s8LedNumber < 8; Loc_s8LedNumber++)
		{
			Loc_enuReturnFunction = LED_enuLedOn(Loc_u8Led[Loc_s8LedNumber]);
			if(Loc_enuReturnFunction == LED_enuNotOk){/*Do Nothing*/}
			else
			{
				_delay_ms(500);
				Loc_enuReturnFunction = LED_enuLedOff(Loc_u8Led[Loc_s8LedNumber]);
				if(Loc_enuReturnFunction == LED_enuNotOk){/*Do Nothing*/}
				else
				{
					_delay_ms(500);					
				}
			}
		}
		for(Loc_s8LedNumber = 8; Loc_s8LedNumber > 0; Loc_s8LedNumber--)
		{
			Loc_enuReturnFunction = LED_enuLedOn(Loc_u8Led[Loc_s8LedNumber - 1]);
			if(Loc_enuReturnFunction == LED_enuNotOk){/*Do Nothing*/}
			else
			{
				_delay_ms(500);
				Loc_enuReturnFunction = LED_enuLedOff(Loc_u8Led[Loc_s8LedNumber - 1]);
				if(Loc_enuReturnFunction == LED_enuNotOk){/*Do Nothing*/}
				else
				{
					_delay_ms(500);
				}
			}
		}
    }
}

