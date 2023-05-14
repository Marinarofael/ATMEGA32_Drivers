/********************************* 
    ULTRASONIC Interface File   
*********************************/ 
 
#ifndef ULTRASONIC_H 
#define ULTRASONIC_H 

#include "ULTRASONIC_cfg.h" 
 
 /*************************************************************************************/
 /**************************************** TYPES **************************************/

typedef void (* UScfg_t)(void) ;

 typedef enum
 {
	 US_enuOk = 0,
	 US_enuNotOk,
	 US_enuNullPtr

 }US_tenuErrorStatus;
 
 /*************************************************************************************/
 /***************************************** APIS **************************************/
 
 /***************************************************/
 /* ultrasonic Init function                        */
 /* Input: void                                     */
 /* Output: void                                    */
 /***************************************************/
 void US_vidUltrasonicInit(void);
  
   /***************************************************/
   /* function to set ultrasonic trigger              */
   /* Input: void                                     */
   /* Output: void                                    */
   /***************************************************/
  void US_vidSetUltrasonicTrigger(void);
   
  /***************************************************/
  /* function to get the distance                    */
  /* Input: pointer to u16                           */
  /* Output: Error Status                            */
  /***************************************************/
 US_tenuErrorStatus US_enuGetDistance(u16* Cpy_pu8Distance);
 
#endif /*ULTRASONIC_H*/ 
