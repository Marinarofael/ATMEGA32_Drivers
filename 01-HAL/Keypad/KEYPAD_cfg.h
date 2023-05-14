/********************************* 
    KEYPAD Configuration File   
*********************************/ 
 
#ifndef KEYPAD_CFG_H 
#define KEYPAD_CFG_H 

#include "DIO.h"

typedef DIO_tenuPins KEYPAD_tenuPins ;
 
 typedef enum
 {
	 KEYPAD_enuNumber_0 = 0,
	 KEYPAD_enuNumber_1,
	 KEYPAD_enuNumber_2,
	 KEYPAD_enuNumber_3,
	 KEYPAD_enuNumber_4,
	 KEYPAD_enuNumber_5,
	 KEYPAD_enuNumber_6,
	 KEYPAD_enuNumber_7,
	 KEYPAD_enuNumber_8,
	 KEYPAD_enuNumber_9,
	 KEYPAD_enuNumber_10,
	 KEYPAD_enuNumber_11,
	 KEYPAD_enuNumber_12,
	 KEYPAD_enuNumber_13,
	 KEYPAD_enuNumber_14,
	 KEYPAD_enuNumber_15
	 
 }KEYPAD_tenuPressedNumber;
 
 typedef enum
 {
	 KEYPAD_enuColumn_0 = 0,
	 KEYPAD_enuColumn_1,
	 KEYPAD_enuColumn_2,
	 KEYPAD_enuColumn_3,
	 KEYPAD_enuMaxColumns
	 
 }KEYPAD_tenuColumns;
 
 typedef enum
 {
	 KEYPAD_enuRow_0 = 0,
	 KEYPAD_enuRow_1,
	 KEYPAD_enuRow_2,
	 KEYPAD_enuRow_3,
	 KEYPAD_enuMaxRows
	 
 }KEYPAD_tenuRows;
 
  extern const KEYPAD_tenuPressedNumber KEYPAD_arrayPressedValue [KEYPAD_enuMaxRows][KEYPAD_enuMaxColumns];
  extern const KEYPAD_tenuPins KEYPAD_arrayColumnPins [KEYPAD_enuMaxColumns];
  extern const KEYPAD_tenuPins KEYPAD_arrayRowPins [KEYPAD_enuMaxRows];
  
#endif /*KEYPAD_CFG_H*/ 
