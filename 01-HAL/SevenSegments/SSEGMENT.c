#include "Std_types.h" 
#include "Bit_math.h" 
#include "DIO.h" 
#include "SSEGMENT.h" 
#include "SSEGMENT_cfg.h" 
#include "SSEGMENT_piv.h" 

/* print number on seven segment function implementation */
SSEGMENT_tenuErrorStatus SSEGMENT_enuPrintSevenSegment(SSEGMENT_tenuNumbers Cpy_enuSevenSegmentNumber)
{
	SSEGMENT_tenuErrorStatus Loc_enuReturnStatus;
	
	if (Cpy_enuSevenSegmentNumber >= SSEGMENT_enuMaxNumber)
	{
		Loc_enuReturnStatus = SSEGMENT_enuNotOk;
	}
	else
	{
		Loc_enuReturnStatus = SSEGMENT_enuOk;
		u8 Loc_u8SSegmentCounter = 0, Loc_u8PrintNumber;
		u8 Loc_u8TempNumber = Cpy_enuSevenSegmentNumber;
		
		for(Loc_u8SSegmentCounter = 0; Loc_u8SSegmentCounter < SSEGMENT_enuSSegmentMaxNumber; Loc_u8SSegmentCounter++)
		{
			Loc_u8PrintNumber = Loc_u8TempNumber % 10;
			Loc_u8TempNumber /= 10;
			
			if(SSEGMENT_strSSEGMENTNumbers[Loc_u8SSegmentCounter].SSEGMENT_ActiveStatus == SSEGMENT_enuActiveHigh)
			{
				DIO_enuSetPortValue( SSEGMENT_strSSEGMENTNumbers[Loc_u8SSegmentCounter].SSEGMENT_Port, SSEGMENT_arrayPortsValue[Loc_u8PrintNumber]);
			}
			else if(SSEGMENT_strSSEGMENTNumbers[Loc_u8SSegmentCounter].SSEGMENT_ActiveStatus == SSEGMENT_enuActiveLow)
			{
				DIO_enuSetPortValue( SSEGMENT_strSSEGMENTNumbers[Loc_u8SSegmentCounter].SSEGMENT_Port, ~ SSEGMENT_arrayPortsValue[Loc_u8PrintNumber]);
			}
		}
	}
	return Loc_enuReturnStatus;
}