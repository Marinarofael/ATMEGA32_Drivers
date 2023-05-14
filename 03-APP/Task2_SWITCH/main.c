/*
 * switch.c
 *
 * Created: 1/18/2023 3:04:01 PM
 * Author : lenovo
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include <avr/delay.h>
#include "Std_types.h"
#include "Bit_math.h"
#include "LED.h"
#include "SWITCH.h"
#include "SWITCH_cfg.h"


int main(void)
{
    u8 Loc_u8Led[10]={LED_1, LED_2, LED_3, LED_4, LED_5, LED_6, LED_7};
    s8 Loc_s8LedNumber = 0;
	u8 Loc_enuReturnFunction = 0;
	DIO_tenuPinValue Loc_enuIncPointer = 1 , Loc_enuDecPointer = 1 ;
	
	DIO_enuInit();
    while (1) 
    {
		_delay_ms(125);
		Loc_enuReturnFunction = SWITCH_enuGetSwitchValue(INCREMEANT_SWITCH, &Loc_enuIncPointer );
		if(Loc_enuReturnFunction == SWITCH_enuOk)
		{
			if(Loc_enuIncPointer == 0)
			{
				if((Loc_s8LedNumber+1 < 8) && (Loc_s8LedNumber+1 > 0))
				{
					Loc_s8LedNumber++;
					LED_enuLedOn(Loc_u8Led[Loc_s8LedNumber-1]);
					
				}
			}
		}
		else if(Loc_enuReturnFunction == SWITCH_enuNullPtr) {/*Do Nothing*/}
		else if(Loc_enuReturnFunction == SWITCH_enuNotOk) {/*Do Nothing*/}
		
		_delay_ms(125);
		Loc_enuReturnFunction = SWITCH_enuGetSwitchValue(DECREMEANT_SWITCH, &Loc_enuDecPointer );
		if(Loc_enuReturnFunction == SWITCH_enuOk) 
		{
			if(Loc_enuDecPointer == 0)
			{
				if((Loc_s8LedNumber-1 < 8) && (Loc_s8LedNumber-1 >= 0))
				{
					Loc_s8LedNumber--;
					LED_enuLedOff(Loc_u8Led[Loc_s8LedNumber]);
				}
			}
		}
		else if(Loc_enuReturnFunction == SWITCH_enuNullPtr) {/*Do Nothing*/}
		else if(Loc_enuReturnFunction == SWITCH_enuNotOk) {/*Do Nothing*/}
    }
}

