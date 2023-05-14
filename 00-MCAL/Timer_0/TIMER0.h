/********************************* 
    TIMER Interface File   
*********************************/ 
 
#ifndef TIMER0_H 
#define TIMER0_H 
 
 #include "TIMER0_cfg.h"
 
 /*************************************************************************************/
 /**************************************** TYPES **************************************/

 typedef void (* TMR0cfg_t)(void) ;
 
 typedef enum
 {
	TMR0_enuOk = 0,
	TMR0_enuNotOk,
	TMR0_enuNullPtr

}TMR0_tenuErrorStatus;

/*************************************************************************************/
/***************************************** APIS **************************************/

 /***************************************************/
 /* timer0 Init function according to configuration */                         
 /* Input: void                                     */
 /* Output: void                                    */
 /***************************************************/
 void TMR0_vidInit(void);
 
 /***************************************************/
 /* function to set pre-load value                  */
 /* Input: u8 pre-load value                        */
 /* Output: void                                    */
 /***************************************************/
 TMR0_tenuErrorStatus TMR0_enuSetPreloadValue( u8 Cpy_u8PreloadValue);
 
 /***************************************************/
 /* function to set compare match value             */
 /* Input: u8 compare match value                   */
 /* Output: void                                    */
 /***************************************************/
 TMR0_tenuErrorStatus TMR0_enuSetCompareMatchValue( u8 Cpy_u8CompareMatchValue);
 
 /***************************************************/
 /* function to start the timer                     */
 /* Input: void                                     */
 /* Output: void                                    */
 /***************************************************/
 void TMR0_enuStart(void);
 
 /***************************************************/
 /* function to get the end of job function         */
 /* Input: pointer to function                      */
 /* Output: void                                    */
 /***************************************************/
 TMR0_tenuErrorStatus TMR0_enuRegisterOverflowCallback(TMR0cfg_t Cpy_CallBackFunc);
 
 /***************************************************/
 /* function to get the end of job function         */
 /* Input: pointer to function                      */
 /* Output: void                                    */
 /***************************************************/
 TMR0_tenuErrorStatus TMR0_enuRegisterCompareMatchCallback(TMR0cfg_t Cpy_CallBackFunc);
 

 
#endif /*TIMER0_H*/ 
