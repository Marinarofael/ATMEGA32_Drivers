/*
 * External_Interrupt.c
 *
 * Created: 1/27/2023 10:21:11 AM
 * Author : lenovo
 */ 
#define F_CPU 8000000UL 
#include <util/delay.h>
#include <avr/interrupt.h>
#include "Std_types.h"
#include "DIO.h"
#include "EXTERNAL_INTERRUPT.h"
#include "EXTERNAL_INTERRUPT_cfg.h"
#include "GLOBAL_INTERRUPT.h"
#include "GLOBAL_INTERRUPT_cfg.h"
#include "SSEGMENT.h"
#include "SSEGMENT_cfg.h"

u8 u8Counter = -1;
ISR(INT0_vect)
{
	u8Counter++;
	SSEGMENT_enuPrintSevenSegment(u8Counter);
	_delay_ms(100);
}
ISR(INT1_vect)
{
	u8Counter--;
	SSEGMENT_enuPrintSevenSegment(u8Counter);
	_delay_ms(100);
}

int main(void)
{
	DIO_enuInit();
	GLOBAL_INTERRUPT_enuGlobalInterruptEnable();
	EXTERNAL_INTERRUPT_enuInit();
	SSEGMENT_enuPrintSevenSegment(0);
	
    /* Replace with your application code */
    while (1) 
    {
		
    }
}

