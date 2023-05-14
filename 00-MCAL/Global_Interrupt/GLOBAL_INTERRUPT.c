#include "Std_types.h"
#include "Bit_math.h"  
#include "GLOBAL_INTERRUPT.h" 
#include "GLOBAL_INTERRUPT_cfg.h" 
#include "GLOBAL_INTERRUPT_piv.h" 


/* implementation of global interrupt enable function */
GLOBAL_INTERRUPT_tenuErrorStatus GLOBAL_INTERRUPT_enuGlobalInterruptEnable(void)
{
	SET_BIT(GLOBAL_INTERRUPT_SREG_Register , GLOBAL_INTERRUPT_PIN);
	
	return GLOBAL_INTERRUPT_enuOk;
}

/* implementation of global interrupt disable function */
GLOBAL_INTERRUPT_tenuErrorStatus GLOBAL_INTERRUPT_enuGlobalInterruptDisnable(void)
{
	CLR_BIT(GLOBAL_INTERRUPT_SREG_Register , GLOBAL_INTERRUPT_PIN);
	
	return GLOBAL_INTERRUPT_enuOk;
}