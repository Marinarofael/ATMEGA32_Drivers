#include "Std_types.h" 
#include "Bit_math.h" 
#include "DIO.h" 
#include "SSEGMENT_cfg.h"

const SSEGMENT_strNumbers_t SSEGMENT_strSSEGMENTNumbers [SSEGMENT_enuSSegmentMaxNumber] = 
{
	[SSEGMENT_enuSSegment0] = {.SSEGMENT_ActiveStatus = SSEGMENT_enuActiveHigh, .SSEGMENT_Port = DIO_enuPORTC_Pin0},
	[SSEGMENT_enuSSegment1] = {.SSEGMENT_ActiveStatus = SSEGMENT_enuActiveHigh, .SSEGMENT_Port = DIO_enuPORTD_Pin0}
};	

const SSEGMENT_tenuNumbers SSEGMENT_arrayPortsValue[SSEGMENT_enuMaxNumber] = 
{
	[SSEGMENT_enuNumber0] = SSEGMENT_NUMBER_0_VALUE,
	[SSEGMENT_enuNumber1] = SSEGMENT_NUMBER_1_VALUE,
	[SSEGMENT_enuNumber2] = SSEGMENT_NUMBER_2_VALUE,
	[SSEGMENT_enuNumber3] = SSEGMENT_NUMBER_3_VALUE,
	[SSEGMENT_enuNumber4] = SSEGMENT_NUMBER_4_VALUE,
	[SSEGMENT_enuNumber5] = SSEGMENT_NUMBER_5_VALUE,
	[SSEGMENT_enuNumber6] = SSEGMENT_NUMBER_6_VALUE,
	[SSEGMENT_enuNumber7] = SSEGMENT_NUMBER_7_VALUE,
	[SSEGMENT_enuNumber8] = SSEGMENT_NUMBER_8_VALUE,
	[SSEGMENT_enuNumber9] = SSEGMENT_NUMBER_9_VALUE
};