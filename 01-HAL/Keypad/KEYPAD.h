/********************************* 
    KEYPAD Interface File   
*********************************/ 
 
#ifndef KEYPAD_H 
#define KEYPAD_H 

#include "KEYPAD_cfg.h"
 
typedef enum
{
	KEYPAD_enuOk = 0, 
	KEYPAD_enuNotOk,
	KEYPAD_enuNullPtr
	
}KEYPAD_tenuErrorStatus;
 


 /****************************************************/
 /* KEYPAD get pressed value function                */
 /* Input: Pointer to get the value of the given pin */
 /* Output: KEYPAD_tenuErrorStatus to report error   */
 /****************************************************/
 KEYPAD_tenuErrorStatus KEYPAD_enuGetPressedValue( KEYPAD_tenuPressedNumber* Add_penuPressedValue );
 
 
 
#endif /*KEYPAD_H*/ 
