/********************************* 
    LM35 Interface File   
*********************************/ 
 
#ifndef LM35_H 
#define LM35_H 
 
 #include "Std_types.h"
 
 
 #define MAX_VOLTAGE 5000UL
 #define RESOLUTION 256UL
 #define VOLTAGE_TEMP_FACTOR 10
 
 typedef enum
 {
	 LM35_enuOK = 0,
	 LM35_enuNotOk,
	 LM35_enuNullPointer
 }LM35_tenuErrorStatus;
 
 
 /* convert the digital reading to temperature
 input : digital reading, pointer to variable to return the temperature
 output : error status */
 LM35_tenuErrorStatus LM35_enuGetTemperature (u16 Cpy_u16DigitalReading , u8 * Cpy_Pu8Temperature );
 
 
 
 
#endif /*LM35_H*/ 
