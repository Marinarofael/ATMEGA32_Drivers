#include "Std_types.h"
#include "RTOS.h" 
#include "TIMER0.h"
#include "GLOBAL_INTERRUPT.h"
#include "GLOBAL_INTERRUPT_cfg.h"

/*************************************************************************************/
/**************************** STATIC FUNCTIONS PROTOTYPES  ***************************/

static void voidScheduler (void);

/*************************************************************************************/
/****************************** FUNCTIONS IMPLEMENTATION *****************************/

/* implementation of function to start RTOS */
void RTOS_voidInit(void)
{
	GLOBAL_INTERRUPT_enuGlobalInterruptEnable();
	TMR0_vidInit();
	TMR0_enuSetCompareMatchValue(156);
	TMR0_enuRegisterCompareMatchCallback(voidScheduler);
}

/* implementation of function to start RTOS */
 void RTOS_voidStart(void)
 {
	 TMR0_enuStart();
	 while(1);
 }
 
 
 /*************************************************************************************/
 /************************* STATIC FUNCTIONS IMPLEMENTATION  **************************/
 
 static void voidScheduler (void)
 {
	 static u8 Loc_u8SystemTick = 0;
	 u8 Loc_u8Counter = 0;
	 
	 Loc_u8SystemTick++;
	 
	 for(Loc_u8Counter = 0; Loc_u8Counter < RTOS_enuTaskNumber; Loc_u8Counter++)
	 {
		 if(Loc_u8SystemTick % RTOS_strTaskArray[Loc_u8Counter].periodicity == 0)
		 {
			 RTOS_strTaskArray[Loc_u8Counter].TaskFunction();
		 }
	 }
	 
 }