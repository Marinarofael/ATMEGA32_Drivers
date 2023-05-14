/*
 * SeventSegment.c
 *
 * Created: 1/20/2023 3:17:29 PM
 * Author : lenovo
 */
#define F_CPU 8000000UL 
#include <avr/delay.h>
#include "Std_types.h"
#include "DIO.h"
#include "SSEGMENT.h"
#include "SSEGMENT_cfg.h"

int main(void)
{
    u8 Loc_u8Counter ;
	DIO_enuInit();
    while (1) 
    {
		for(Loc_u8Counter = 0; Loc_u8Counter < 100; Loc_u8Counter++)
		{
			SSEGMENT_enuPrintSevenSegment(Loc_u8Counter);
			_delay_ms(500);
		}
    }
}

