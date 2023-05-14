/*
 * Timer.c
 *
 * Created: 2/27/2023 3:49:28 PM
 * Author : lenovo
 */
#define F_CPU 8000000ul
#include <util/delay.h> 
#include "Std_types.h"
#include "Bit_math.h"
#include "DIO.h"
#include "DIO_cfg.h"
#include "TIMER.h"
#include "SWITCH.h"



int main(void)
{
	u8 IncSwitchValue = 1;
	u8 DecSwitchValue = 1;
	u8 CompareMatchValue = 0;
	
	DIO_enuInit();
	TMR0_vidInit();
	TMR0_enuStart();
    /* Replace with your application code */
    while (1) 
    {
		if(SWITCH_enuGetSwitchValue(INCREMEANT_SWITCH, &IncSwitchValue) == SWITCH_enuOk)
		{
			if(IncSwitchValue == 0)
			{
				
				if(CompareMatchValue + 5 > 256)
				{
					CompareMatchValue = 255;
				}
				else
				{
					CompareMatchValue += 5;
				}
				TMR0_enuSetCompareMatchValue(CompareMatchValue);
				_delay_ms(300);
			}
		}
		
		if(SWITCH_enuGetSwitchValue(DECREMEANT_SWITCH, &DecSwitchValue) == SWITCH_enuOk)
		{
			if(DecSwitchValue == 0)
			{
				
				if(CompareMatchValue - 5 < 0)
				{
					CompareMatchValue = 0;
				}
				else
				{
					CompareMatchValue -= 5;
				}
				TMR0_enuSetCompareMatchValue(CompareMatchValue);
				_delay_ms(300);
			}
		}
		
	}
}
