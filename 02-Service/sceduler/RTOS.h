/********************************* 
    RTOS Interface File   
*********************************/ 
 
#ifndef RTOS_H 
#define RTOS_H 

#include "RTOS_cfg.h"
  
  /*************************************************************************************/
  /***************************************** APIS **************************************/

  /**************************/
  /* RTOS init function     */
  /* Input: void            */
  /* Output: void           */
  /**************************/
  void RTOS_voidInit(void);
  
  /**************************/
  /* RTOS Start function    */
  /* Input: void            */
  /* Output: void           */
  /**************************/
  void RTOS_voidStart(void);
 
 
#endif /*RTOS_H*/ 
