
#include "LM35.h" 

LM35_tenuErrorStatus LM35_enuGetTemperature (u16 Cpy_u16DigitalReading , u8 * Cpy_Pu8Temperature )
{
	LM35_tenuErrorStatus Loc_enuReturn = LM35_enuOK;
	u16 Loc_u16MilliVolt = 0;
	u8 Loc_u8Temperature = 0;
	
	if(Cpy_Pu8Temperature == NULL)
	{
		Loc_enuReturn = LM35_enuNullPointer;
	}
	else
	{
		Loc_u16MilliVolt = (u16) (((u32)(Cpy_u16DigitalReading * MAX_VOLTAGE)) / RESOLUTION );
		Loc_u8Temperature = Loc_u16MilliVolt / VOLTAGE_TEMP_FACTOR ;
		* Cpy_Pu8Temperature = Loc_u8Temperature ;
	}
	
	return Loc_enuReturn;
}
