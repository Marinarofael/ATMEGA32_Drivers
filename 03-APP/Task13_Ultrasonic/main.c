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
#include "GLOBAL_INTERRUPT.h"
#include "GLOBAL_INTERRUPT_cfg.h"
#include "DIO.h"
#include "DIO_cfg.h"
#include "TIMER1.h"
#include "LCD.h"
#include "ULTRASONIC.h"

u16 TimerValue = 0;
u16 Distance = 0;

int main(void)
{
	
	DIO_enuInit();
	GLOBAL_INTERRUPT_enuGlobalInterruptEnable();
	LCD_enuInit();
	US_vidUltrasonicInit();

	
    LCD_enuWriteCommand(LCD_COMMAND_CLEAR);
    LCD_enuGoToXY(LCD_FIRST_LINE, LCD_LOCATION_0);
    LCD_enuWriteString("ULTRASONIC ");
	
    while (1) 
    {
		
		US_vidSetUltrasonicTrigger();
		
		while(TimerValue == 0);
		
		US_enuGetDistance(&Distance);
		
		LCD_enuWriteCommand(LCD_COMMAND_CLEAR);
		LCD_enuGoToXY(LCD_FIRST_LINE, LCD_LOCATION_0);
		LCD_enuWriteString("Distance ");
		LCD_enuWriteNumber(Distance);
		_delay_ms(300);
		
		TimerValue = 0;
	
		
	}
}

