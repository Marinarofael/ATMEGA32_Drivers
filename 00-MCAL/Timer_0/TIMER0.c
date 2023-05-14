#define F_CPU 8000000ul
#include <avr/delay.h>
#include "Std_types.h" 
#include "Bit_math.h" 
#include "TIMER0.h" 


/*************************************************************************************/
/**************************************** DEFINE *************************************/

#define CLR_MASK_INIT 0x80
#define CLR_MASK_prescaler 0xF8
#define TMR0_INT_CM 1
#define TMR0_INT_OV 0

/* for interrupt */
#define ISR_(vector_no) void __vector_##vector_no(void) __attribute__((signal));\
						void __vector_##vector_no(void)

/*************************************************************************************/
/************************************* VARIABLES *************************************/

static TMR0cfg_t ISR_PtrToFunc_ov = NULL;
static TMR0cfg_t ISR_PtrToFunc_CM = NULL;

/*************************************************************************************/
/****************************** FUNCTIONS IMPLEMENTATION *****************************/

/* implementation of function to initialize the timer according to the configuration */
void TMR0_vidInit(void)
{
	u8 Loc_u8Register = 0;
	
	Loc_u8Register = TMR0_TCCR0_REGISTER;
	Loc_u8Register &= CLR_MASK_INIT;
	Loc_u8Register |= TMR0_MODE;
	TMR0_TCCR0_REGISTER = Loc_u8Register;
	
}

/* implementation to set compare match value in OCR0 */
TMR0_tenuErrorStatus TMR0_enuSetCompareMatchValue( u8 Cpy_u8CompareMatchValue)
{
	TMR0_tenuErrorStatus Loc_enuReturn = TMR0_enuOk;
	TMR0_OCR0_REGISTER = Cpy_u8CompareMatchValue;
	//_delay_ms(10);
	return Loc_enuReturn;
}

/* implementation to set pre-load value in TCNT0 */
TMR0_tenuErrorStatus TMR0_enuSetPreloadValue( u8 Cpy_u8PreloadValue)
{
	TMR0_tenuErrorStatus Loc_enuReturn = TMR0_enuOk;
	TMR0_TCNT0_REGISTER = Cpy_u8PreloadValue;
	return Loc_enuReturn;
}

/* implementation of function to start the timer */
void TMR0_enuStart(void)
{
	u8 Loc_u8Register = 0;
	
	Loc_u8Register = TMR0_TCCR0_REGISTER;
	Loc_u8Register &= CLR_MASK_prescaler;
	Loc_u8Register |= TMR0_PRESCALER;
	
	TMR0_TCCR0_REGISTER = Loc_u8Register;
}

/* implementation of function to set pointer to call back function */
TMR0_tenuErrorStatus TMR0_enuRegisterOverflowCallback(TMR0cfg_t Cpy_CallBackFunc)
{
	TMR0_tenuErrorStatus Loc_enuReturn = TMR0_enuOk;
	
	if(Cpy_CallBackFunc == NULL)
	{
		Loc_enuReturn = TMR0_enuNullPtr;
	}
	else
	{
		TMR0_TIMSK_REGISTER |= (1 << TMR0_INT_OV);
		ISR_PtrToFunc_ov = Cpy_CallBackFunc;
	}
	return Loc_enuReturn;
}

/* implementation of function to set pointer to call back function */
TMR0_tenuErrorStatus TMR0_enuRegisterCompareMatchCallback(TMR0cfg_t Cpy_CallBackFunc)
{
	TMR0_tenuErrorStatus Loc_enuReturn = TMR0_enuOk;
	
	if(Cpy_CallBackFunc == NULL)
	{
		Loc_enuReturn = TMR0_enuNullPtr;
	}
	else
	{
		TMR0_TIMSK_REGISTER |= (1 << TMR0_INT_CM);
		ISR_PtrToFunc_CM = Cpy_CallBackFunc;
	}
	return Loc_enuReturn;
}

ISR_(11)
{
	TMR0_TIFR_REGISTER &= (~(1 << TMR0_INT_OV));
	
	if(ISR_PtrToFunc_ov)
	{
		ISR_PtrToFunc_ov();
	}
}

ISR_(10)
{
	TMR0_TIFR_REGISTER &= (~(1 << TMR0_INT_CM));
	
	if(ISR_PtrToFunc_CM)
	{
		ISR_PtrToFunc_CM();
	}
}