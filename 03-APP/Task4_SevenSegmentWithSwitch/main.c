/*
 * SSegmentWithSwitch.c
 *
 * Created: 1/22/2023 2:39:56 PM
 * Author : lenovo
 */
#define F_CPU 8000000UL
#include <util/delay.h> 
#include "Std_types.h"
#include "DIO.h"
#include "SSEGMENT.h"
#include "SSEGMENT_cfg.h"
#include "SWITCH.h"
#include "SWITCH_cfg.h"

int main(void)
{
    u8 Loc_u8Counter = 0, Loc_enuReturnSwitchFunction = 0, Loc_enuReturnSSegmentFunction = 0, Loc_enuSwitchPointer;
	DIO_enuInit();
    while (1) 
    {
		Loc_enuReturnSwitchFunction = SWITCH_enuGetSwitchValue(SWITCH_PORT, &Loc_enuSwitchPointer );
		if(Loc_enuReturnSwitchFunction == SWITCH_enuOk)
		{
			if(Loc_enuSwitchPointer == 0)
			{
				Loc_enuReturnSSegmentFunction = SSEGMENT_enuPrintSevenSegment(Loc_u8Counter);
				if(Loc_enuReturnSSegmentFunction == SSEGMENT_enuOk)
				{
					Loc_u8Counter++;
					_delay_ms(200);
				}
				else if(Loc_enuReturnSSegmentFunction == SSEGMENT_enuNotOk) {/*Do Nothing*/}
			}
		}
		else if(Loc_enuReturnSwitchFunction == SWITCH_enuNullPtr) {/*Do Nothing*/}
		else if(Loc_enuReturnSwitchFunction == SWITCH_enuNotOk) {/*Do Nothing*/}
    }
}

