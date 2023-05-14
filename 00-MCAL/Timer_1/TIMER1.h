/********************************* 
    TIMER1 Interface File   
*********************************/ 
 
#ifndef TIMER1_H 
#define TIMER1_H 
 
 #include "TIMER1_cfg.h"
 
 /*************************************************************************************/
 /**************************************** TYPES **************************************/

 typedef void (* TMR1cfg_t)(void) ;
 
 typedef enum
 {
	 TMR1_enuOk = 0,
	 TMR1_enuNotOk,
	 TMR1_enuNullPtr

 }TMR1_tenuErrorStatus;
 
 typedef enum
 {
	 TMR1_enuTriggerFallingEdge = 0,
	 TMR1_enuTriggerRisingEdge
	 
 }TMR1_tenuTriggerICU;
 
 /*************************************************************************************/
 /***************************************** APIS **************************************/

 /***************************************************/
 /* timer1 Init function according to configuration */
 /* Input: void                                     */
 /* Output: void                                    */
 /***************************************************/
 void TMR1_vidInit(void);
 
 /***************************************************/
 /* function to set pre-load value                  */
 /* Input: u16 pre-load value                       */
 /* Output: Error Status                            */
 /***************************************************/
 TMR1_tenuErrorStatus TMR1_enuSetPreloadValue( u16 Cpy_u16PreloadValue);
 
 /***************************************************/
 /* function to set compare match A value           */
 /* Input: u16 compare match value                  */
 /* Output: Error Status                            */
 /***************************************************/
 TMR1_tenuErrorStatus TMR1_enuSetCompareMatchAValue( u16 Cpy_u16CompareMatchValue);
 
 /***************************************************/
 /* function to set compare match B value           */
 /* Input: u16 compare match value                  */
 /* Output: Error Status                            */
 /***************************************************/
 TMR1_tenuErrorStatus TMR1_enuSetCompareMatchBValue( u16 Cpy_u16CompareMatchValue);
 
 
 /***************************************************/
 /* function to start the timer                     */
 /* Input: void                                     */
 /* Output: Error Status                            */
 /***************************************************/
 void TMR1_enuStart(void);
 
 /***************************************************/
 /* function to get the end of job function         */
 /* Input: pointer to function                      */
 /* Output: Error Status                            */
 /***************************************************/
 TMR1_tenuErrorStatus TMR1_enuRegisterOverflowCallback(TMR1cfg_t Cpy_CallBackFunc);
 
 /***************************************************/
 /* function to get the end of job function         */
 /* Input: pointer to function                      */
 /* Output: Error Status                            */
 /***************************************************/
 TMR1_tenuErrorStatus TMR1_enuRegisterCompareMatchACallback(TMR1cfg_t Cpy_CallBackFunc);
 
 /***************************************************/
 /* function to get the end of job function         */
 /* Input: pointer to function                      */
 /* Output: Error Status                            */
 /***************************************************/
 TMR1_tenuErrorStatus TMR1_enuRegisterCompareMatchBCallback(TMR1cfg_t Cpy_CallBackFunc);
 
/***************************************************/
/* function to get the end of job function         */
/* Input: pointer to function                      */
/* Output: Error Status                            */
/***************************************************/
TMR1_tenuErrorStatus TMR1_enuRegisterInputCaptureCallback(TMR1cfg_t Cpy_CallBackFunc);

/***************************************************/
/* function to set the trigger of ICU              */
/* Input: pointer to function                      */
/* Output: Error Status                            */
/***************************************************/
TMR1_tenuErrorStatus TMR1_enuSetTriggerICU(TMR1_tenuTriggerICU Cpy_enuTrigger);


/***************************************************/
/* function to read input capture unit register    */
/* Input: pointer to get the value                 */
/* Output: Error Status                            */
/***************************************************/
 TMR1_tenuErrorStatus TMR1_enuReadICR(u16 * Cpy_pu16Value);
 
 
#endif /*TIMER1_H*/ 
