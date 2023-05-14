#include "Std_types.h" 
#include "Bit_math.h" 
#include "TIMER1.h" 

/*************************************************************************************/
/**************************************** DEFINE *************************************/

#define TMR1_MODE_CLR_RIGHT_BITS 0b1100
#define TMR1_MODE_CLR_LEFTT_BITS 0b0011
#define TMR1_MODE_CLR_TCCR1A 0b11111100
#define TMR1_MODE_CLR_TCCR1B 0b11100111
#define TRM1_COM_CLR_MASK 0b00001111
#define TMR1_CLR_MASK_prescaler 0b11111000
		   
/* for interrupt */
#define Interrupt_Service_Routine(vector_no) void __vector_##vector_no(void) __attribute__((signal));\
						 void __vector_##vector_no(void)

/*************************************************************************************/
/************************************* VARIABLES *************************************/

static TMR1cfg_t ISR_PtrToFunc1_ov = NULL;
static TMR1cfg_t ISR_PtrToFunc1_CMA = NULL;
static TMR1cfg_t ISR_PtrToFunc1_CMB = NULL;
static TMR1cfg_t ISR_PtrToFunc1_ICU = NULL;

extern u16 TimerValue;
/*************************************************************************************/
/****************************** FUNCTIONS IMPLEMENTATION *****************************/

/* implementation of function to initialize the timer according to the configuration */
void TMR1_vidInit(void)
{
	u8 Loc_u8RegisterTCCR1A = TMR1_TCCR1A_REGISTER;
	u8 Loc_u8RegisterTCCR1B = TMR1_TCCR1B_REGISTER;
	
	Loc_u8RegisterTCCR1A &= TMR1_MODE_CLR_TCCR1A;
	Loc_u8RegisterTCCR1A |= (TMR1_MODE & TMR1_MODE_CLR_LEFTT_BITS);
	Loc_u8RegisterTCCR1A &= TRM1_COM_CLR_MASK;
	TMR1_TCCR1A_REGISTER = Loc_u8RegisterTCCR1A;
	
	Loc_u8RegisterTCCR1B &= TMR1_MODE_CLR_TCCR1B;
	Loc_u8RegisterTCCR1B |= ((TMR1_MODE & TMR1_MODE_CLR_RIGHT_BITS) << 1);
	TMR1_TCCR1B_REGISTER = Loc_u8RegisterTCCR1B;
		
}

/* implementation of function to start the timer */
void TMR1_enuStart(void)
{
	u8 Loc_u8Register = 0;
	
	Loc_u8Register = TMR1_TCCR1B_REGISTER;
	Loc_u8Register &= TMR1_CLR_MASK_prescaler;
	Loc_u8Register |= TMR1_PRESCALER;
	TMR1_TCCR1B_REGISTER = Loc_u8Register;
}

/* implementation of function to set pointer to call back function */
TMR1_tenuErrorStatus TMR1_enuRegisterOverflowCallback(TMR1cfg_t Cpy_CallBackFunc)
{
	TMR1_tenuErrorStatus Loc_enuReturn = TMR1_enuOk;
	
	if(Cpy_CallBackFunc == NULL)
	{
		Loc_enuReturn = TMR1_enuNullPtr;
	}
	else
	{
		TMR1_TIMSK_REGISTER |= (1 << TMR1_INT_OV);
		ISR_PtrToFunc1_ov = Cpy_CallBackFunc;
	}
	return Loc_enuReturn;
}

/* implementation of function to set pointer to call back function */
TMR1_tenuErrorStatus TMR1_enuRegisterCompareMatchACallback(TMR1cfg_t Cpy_CallBackFunc)
{
	TMR1_tenuErrorStatus Loc_enuReturn = TMR1_enuOk;
	
	if(Cpy_CallBackFunc == NULL)
	{
		Loc_enuReturn = TMR1_enuNullPtr;
	}
	else
	{
		TMR1_TIMSK_REGISTER |= (1 << TMR1_INT_CMA);
		ISR_PtrToFunc1_CMA = Cpy_CallBackFunc;
	}
	return Loc_enuReturn;
}

/* implementation of function to set pointer to call back function */
TMR1_tenuErrorStatus TMR1_enuRegisterCompareMatchBCallback(TMR1cfg_t Cpy_CallBackFunc)
{
	TMR1_tenuErrorStatus Loc_enuReturn = TMR1_enuOk;
	
	if(Cpy_CallBackFunc == NULL)
	{
		Loc_enuReturn = TMR1_enuNullPtr;
	}
	else
	{
		TMR1_TIMSK_REGISTER |= (1 << TMR1_INT_CMB);
		ISR_PtrToFunc1_CMB = Cpy_CallBackFunc;
	}
	return Loc_enuReturn;
}

/* implementation of function to set pointer to call back function */
TMR1_tenuErrorStatus TMR1_enuRegisterInputCaptureCallback(TMR1cfg_t Cpy_CallBackFunc)
{
	TMR1_tenuErrorStatus Loc_enuReturn = TMR1_enuOk;
	
	if(Cpy_CallBackFunc == NULL)
	{
		Loc_enuReturn = TMR1_enuNullPtr;
	}
	else
	{
		TMR1_TIMSK_REGISTER |= (1 << TMR1_INT_ICU);
		ISR_PtrToFunc1_ICU = Cpy_CallBackFunc;
	}
	return Loc_enuReturn;
}

/* implementation to set pre-load value in TCNT0 */
TMR1_tenuErrorStatus TMR1_enuSetPreloadValue( u16 Cpy_u16PreloadValue)
{
	TMR1_tenuErrorStatus Loc_enuReturn = TMR1_enuOk;
	TMR1_TCNT1_REGISTER = Cpy_u16PreloadValue;
	return Loc_enuReturn;
}

/* implementation to set Compare match A value in OCR1A */
TMR1_tenuErrorStatus TMR1_enuSetCompareMatchAValue( u16 Cpy_u16PreloadValue)
{
	TMR1_tenuErrorStatus Loc_enuReturn = TMR1_enuOk;
	TMR1_OCR1A_REGISTER = Cpy_u16PreloadValue;
	return Loc_enuReturn;
}

/* implementation to set Compare match B value in OCR1A */
TMR1_tenuErrorStatus TMR1_enuSetCompareMatchBValue( u16 Cpy_u16PreloadValue)
{
	TMR1_tenuErrorStatus Loc_enuReturn = TMR1_enuOk;
	TMR1_OCR1B_REGISTER = Cpy_u16PreloadValue;
	return Loc_enuReturn;
}

/* implementation of function to set the trigger of ICU */
TMR1_tenuErrorStatus TMR1_enuSetTriggerICU(TMR1_tenuTriggerICU Cpy_enuTrigger)
{
	TMR1_tenuErrorStatus Loc_enuReturn = TMR1_enuOk;
	u8 Loc_u8Register = TMR1_TCCR1B_REGISTER;
	Loc_u8Register &= (~(1 << TMR1_ICU_TRIGGER_BIT));
	Loc_u8Register |= (Cpy_enuTrigger << TMR1_ICU_TRIGGER_BIT);
	TMR1_TCCR1B_REGISTER = Loc_u8Register;
	return Loc_enuReturn;
}

/* implementation of function to get ICR register*/
TMR1_tenuErrorStatus TMR1_enuReadICR(u16 * Cpy_pu16Value)
{
	TMR1_tenuErrorStatus Loc_enuReturn = TMR1_enuOk;
	*Cpy_pu16Value = TMR1_ICR1_REGISTER;
	return Loc_enuReturn;	
}

Interrupt_Service_Routine(9)
{
	TMR1_TIFR_REGISTER &= (1 << TMR1_INT_OV);
	
	if(ISR_PtrToFunc1_ov)
	{
		ISR_PtrToFunc1_ov();
	}
}

Interrupt_Service_Routine(7)
{
	TMR1_TIFR_REGISTER &= (1 << TMR1_INT_CMA);
	
	if(ISR_PtrToFunc1_CMA)
	{
		ISR_PtrToFunc1_CMA();
	}
}

Interrupt_Service_Routine(8)
{
	TMR1_TIFR_REGISTER &= (1 << TMR1_INT_CMB);
	
	if(ISR_PtrToFunc1_CMB)
	{
		ISR_PtrToFunc1_CMB();
	}
}

Interrupt_Service_Routine(6)
{
	TMR1_TIFR_REGISTER &= (1 << TMR1_INT_ICU);
	
	if(ISR_PtrToFunc1_ICU)
	{
		ISR_PtrToFunc1_ICU();
	}
}