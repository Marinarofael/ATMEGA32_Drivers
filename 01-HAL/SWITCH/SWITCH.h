/********************************* 
    SWITCH Interface File   
*********************************/ 
 
#ifndef SWITCH_H 
#define SWITCH_H 
 
 #include "DIO.h"
 #include "SWITCH_cfg.h"
 
 typedef enum
 {	  
	 SWITCH_enuOk = 0,
	 SWITCH_enuNotOk,
	 SWITCH_enuNullPtr
	  
 }SWITCH_tenuErrorStatus;
 
 
 
 /****************************************************/
 /* SWITCH get value function                        */
 /* Input: Pin number (range from 0 - 31)            */
 /* Input: Pointer to get the value of the given pin */
 /* Output: Switch_tenuErrorStatus to report error   */
 /****************************************************/
 SWITCH_tenuErrorStatus SWITCH_enuGetSwitchValue(DIO_tenuPins Cpy_enuPinNumber, DIO_tenuPinValue* Add_penuPinValue );
 
 
#endif /*SWITCH_H*/ 
