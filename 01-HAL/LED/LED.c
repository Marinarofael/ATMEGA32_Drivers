#include "Std_types.h"
#include "Bit_math.h"
#include "DIO.h"

#include "LED.h"
#include "LED_cfg.h"
#include "LED_piv.h"

/*turn LED on */ 
LED_tenuErrorStatus LED_enuLedOn(DIO_tenuPins Cpy_enuPinNumber)
{
	LED_tenuErrorStatus Loc_enuReturn = 0;
	DIO_tenuErrorStatus Loc_u8ReturnDio = 0;
	Loc_u8ReturnDio = DIO_enuSetPin(Cpy_enuPinNumber);
	if(Loc_u8ReturnDio == DIO_enuOk)
	{
		Loc_enuReturn = LED_enuOk;
	}
	else if(Loc_u8ReturnDio == DIO_enuNotOk)
	{
		Loc_enuReturn = LED_enuNotOk;
	}
	return Loc_enuReturn;
}

/* turn LED off */
LED_tenuErrorStatus LED_enuLedOff(DIO_tenuPins Cpy_enuPinNumber)
{
	LED_tenuErrorStatus Loc_enuReturn = 0;
	DIO_tenuErrorStatus Loc_u8ReturnDio = 0;
	Loc_u8ReturnDio = DIO_enuClearPin(Cpy_enuPinNumber);
	if(Loc_u8ReturnDio == DIO_enuOk)
	{
		Loc_enuReturn = LED_enuOk;
	}
	else if(Loc_u8ReturnDio == DIO_enuNotOk)
	{
		Loc_enuReturn = LED_enuNotOk;
	}
	return Loc_enuReturn;
}