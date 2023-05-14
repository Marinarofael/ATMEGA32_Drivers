/********************************* 
    SSEGMENT Interface File   
*********************************/ 
 
#ifndef SSEGMENT_H 
#define SSEGMENT_H 
 
 #include "SSEGMENT_cfg.h"
 
 typedef enum
 {
	 SSEGMENT_enuOk = 0,
	 SSEGMENT_enuNotOk,
	 SSEGMENT_enuNullPtr

 }SSEGMENT_tenuErrorStatus;

 /**************************************/
 /* seven segment function             */
 /* input : number to be printed       */
 /* output : error status              */
 /**************************************/ 
 SSEGMENT_tenuErrorStatus SSEGMENT_enuPrintSevenSegment(SSEGMENT_tenuNumbers Cpy_enuSevenSegmentNumber);
 
 
 
#endif /*SSEGMENT_H*/ 
