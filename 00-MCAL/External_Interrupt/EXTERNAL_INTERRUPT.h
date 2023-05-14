/********************************* 
    EXTERNAL_INTERRUPT Interface File   
*********************************/ 
 
#ifndef EXTERNAL_INTERRUPT_H 
#define EXTERNAL_INTERRUPT_H 
 
 #define EXTERNAL_INTERRUPT_CLR_MASK 0b11
 
 typedef enum
 {
	 EXTERNAL_INTERRUPT_enuOk = 0,
	 EXTERNAL_INTERRUPT_enuNotOk,
	 EXTERNAL_INTERRUPT_enuNullPtr

 }EXTERNAL_INTERRUPT_tenuErrorStatus;
 
 EXTERNAL_INTERRUPT_tenuErrorStatus EXTERNAL_INTERRUPT_enuInit(void);
 
 
#endif /*EXTERNAL_INTERRUPT_H*/ 
