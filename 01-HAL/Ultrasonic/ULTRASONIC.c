#define F_CPU 8000000UL
#include <avr/delay.h>
#include "Std_types.h"
#include "TIMER1.h"
#include "ULTRASONIC.h"

/*************************************************************************************/
/**************************************** DEFINE *************************************/

#define US_TIME_DISTANCE_CONVERTER 466.47

/*************************************************************************************/
/************************************* VARIABLES *************************************/

void US_Function(void);
extern u16 TimerValue;

/*************************************************************************************/
/****************************** FUNCTIONS IMPLEMENTATION *****************************/

/* implementation of function to initialize ultrasonic */
void US_vidUltrasonicInit(void)
{
	TMR1_enuSetTriggerICU(TMR1_enuTriggerRisingEdge);
	TMR1_vidInit();
	TMR1_enuStart();
	TMR1_enuRegisterInputCaptureCallback(US_Function);
}

/* implementation of function to set ultrasonic trigger */
void US_vidSetUltrasonicTrigger(void)
{
	DIO_enuSetPin(US_TRIGGER_PIN);
	_delay_us(10);
	DIO_enuClearPin(US_TRIGGER_PIN);
}


/* implementation of function to get the distance */
US_tenuErrorStatus US_enuGetDistance(u16* Cpy_pu8Distance)
{
	US_tenuErrorStatus Loc_enuReturn = US_enuOk;
	if(Cpy_pu8Distance == NULL)
	{
		Loc_enuReturn = US_enuNullPtr;
	}
	else
	{
		*Cpy_pu8Distance = TimerValue / 466.67 ;
	}
	return Loc_enuReturn;
}

/*************************************************************************************/
/**************************** ICU FUNCTION IMPLEMENTATION ****************************/

/* call back function */
void US_Function(void)
{
	static u8 Counter1 = 0;
	Counter1++;
	if(Counter1 == 1)
	{
		TMR1_enuSetPreloadValue(0);
		TMR1_enuSetTriggerICU(TMR1_enuTriggerFallingEdge);

	}
	else if(Counter1 == 2)
	{
		TMR1_enuReadICR(& TimerValue);
		Counter1 = 0;
		TMR1_enuSetTriggerICU(TMR1_enuTriggerRisingEdge);
	}
	
}
