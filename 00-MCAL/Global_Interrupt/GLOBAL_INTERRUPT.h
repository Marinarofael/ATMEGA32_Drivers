/********************************* 
    GLOBAL_INTERRUPT Interface File   
*********************************/ 
 
#ifndef GLOBAL_INTERRUPT_H 
#define GLOBAL_INTERRUPT_H 
 
 
 
 typedef enum
 {
	 GLOBAL_INTERRUPT_enuOk = 0,
	 GLOBAL_INTERRUPT_enuNotOk,
	 GLOBAL_INTERRUPT_enuNullPtr
 }GLOBAL_INTERRUPT_tenuErrorStatus;
 
 
 /***********************************************/
 /* Global Interrupt enable                     */
 /* Input: void                                 */
 /* Output: GLOBAL_INTERRUPT_tenuErrorStatus    */
 /***********************************************/
 GLOBAL_INTERRUPT_tenuErrorStatus GLOBAL_INTERRUPT_enuGlobalInterruptEnable(void);
 
  
  /***********************************************/
  /* Global Interrupt disable                    */
  /* Input: void                                 */
  /* Output: GLOBAL_INTERRUPT_tenuErrorStatus    */
  /***********************************************/
  GLOBAL_INTERRUPT_tenuErrorStatus GLOBAL_INTERRUPT_enuGlobalInterruptDisable(void);
 
 
 
#endif /*GLOBAL_INTERRUPT_H*/ 
