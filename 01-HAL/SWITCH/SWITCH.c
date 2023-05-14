#include "Std_types.h" 
#include "Bit_math.h" 
#include "DIO.h" 
#include "SWITCH.h" 
#include "SWITCH_cfg.h" 
#include "SWITCH_piv.h" 

SWITCH_tenuErrorStatus SWITCH_enuGetSwitchValue(DIO_tenuPins Cpy_enuPinNumber, DIO_tenuPinValue* Add_penuPinValue )
{
	SWITCH_tenuErrorStatus Loc_enuReturn = 0;
	DIO_tenuErrorStatus Loc_enuReturnDio = 0;
	
	Loc_enuReturnDio = DIO_enuGetPin(Cpy_enuPinNumber,Add_penuPinValue);
	if (Loc_enuReturnDio == DIO_enuOk)
	{
		Loc_enuReturn = SWITCH_enuOk;
	}
	else if (Loc_enuReturnDio == DIO_enuNullPtr)
	{
		Loc_enuReturn = SWITCH_enuNullPtr;
	}
	else
	{
		Loc_enuReturn = SWITCH_enuNotOk;
	}
	return Loc_enuReturn;
}