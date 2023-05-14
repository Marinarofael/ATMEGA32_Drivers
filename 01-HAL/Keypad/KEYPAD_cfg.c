#include "DIO.h"
#include "KEYPAD_cfg.h"

const KEYPAD_tenuPressedNumber KEYPAD_arrayPressedValue [KEYPAD_enuMaxRows][KEYPAD_enuMaxColumns] = 
{
	[KEYPAD_enuRow_0][KEYPAD_enuColumn_0] = KEYPAD_enuNumber_0,
	[KEYPAD_enuRow_0][KEYPAD_enuColumn_1] =	KEYPAD_enuNumber_1,
	[KEYPAD_enuRow_0][KEYPAD_enuColumn_2] =	KEYPAD_enuNumber_2,
	[KEYPAD_enuRow_0][KEYPAD_enuColumn_3] =	KEYPAD_enuNumber_3,
	
	[KEYPAD_enuRow_1][KEYPAD_enuColumn_0] =	KEYPAD_enuNumber_4,
	[KEYPAD_enuRow_1][KEYPAD_enuColumn_1] =	KEYPAD_enuNumber_5,
	[KEYPAD_enuRow_1][KEYPAD_enuColumn_2] =	KEYPAD_enuNumber_6,
	[KEYPAD_enuRow_1][KEYPAD_enuColumn_3] =	KEYPAD_enuNumber_7,
	
	[KEYPAD_enuRow_2][KEYPAD_enuColumn_0] =	KEYPAD_enuNumber_8,
	[KEYPAD_enuRow_2][KEYPAD_enuColumn_1] =	KEYPAD_enuNumber_9,
	[KEYPAD_enuRow_2][KEYPAD_enuColumn_2] =	KEYPAD_enuNumber_10,
	[KEYPAD_enuRow_2][KEYPAD_enuColumn_3] =	KEYPAD_enuNumber_11,
	
	[KEYPAD_enuRow_3][KEYPAD_enuColumn_0] =	KEYPAD_enuNumber_12,
	[KEYPAD_enuRow_3][KEYPAD_enuColumn_1] =	KEYPAD_enuNumber_13,
	[KEYPAD_enuRow_3][KEYPAD_enuColumn_2] =	KEYPAD_enuNumber_14,
	[KEYPAD_enuRow_3][KEYPAD_enuColumn_3] =	KEYPAD_enuNumber_15
											
};

/* configure the column pins and set it as input pull up */
const KEYPAD_tenuPins KEYPAD_arrayColumnPins [KEYPAD_enuMaxColumns] = 
{
	[KEYPAD_enuColumn_0] = DIO_enuPORTA_Pin4,
	[KEYPAD_enuColumn_1] = DIO_enuPORTA_Pin5,
	[KEYPAD_enuColumn_2] = DIO_enuPORTA_Pin6,
	[KEYPAD_enuColumn_3] = DIO_enuPORTA_Pin7
};

/* configure the row pins and set it as output high */
const KEYPAD_tenuPins KEYPAD_arrayRowPins [KEYPAD_enuMaxRows] =
{
	[KEYPAD_enuRow_0] = DIO_enuPORTA_Pin0,
	[KEYPAD_enuRow_1] = DIO_enuPORTA_Pin1,
	[KEYPAD_enuRow_2] = DIO_enuPORTA_Pin2,
	[KEYPAD_enuRow_3] = DIO_enuPORTA_Pin3
};
