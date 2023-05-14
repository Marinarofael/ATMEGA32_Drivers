/********************************* 
    RTOS Configuration File   
*********************************/ 
 
#ifndef RTOS_CFG_H 
#define RTOS_CFG_H 
 #include "Std_types.h"
 /*************************************************************************************/
 /**************************************** TYPES **************************************/
 
  typedef struct
  {
	  u16 periodicity;
	  void (*TaskFunction)(void);
	  
  }RTOS_Task_t;
  
 typedef enum
 {
	RTOS_enuTaskLed1Toggle = 0,
	RTOS_enuTaskLed2Toggle ,
	RTOS_enuTaskNumber
	 
 }RTOS_tenuTasks;

 
 extern const RTOS_Task_t RTOS_strTaskArray[RTOS_enuTaskNumber];
 extern void Task1CallFunction(void);
 extern void Task2CallFunction(void);
 
#endif /*RTOS_CFG_H*/ 
