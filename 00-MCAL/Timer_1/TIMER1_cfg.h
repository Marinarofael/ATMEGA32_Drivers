/********************************* 
    TIMER1 Configuration File   
*********************************/ 
 
#ifndef TIMER1_CFG_H 
#define TIMER1_CFG_H 

#include "TIMER1_piv.h"

 /********** Prescaler configuration **********/
/*  TMR1_CLK_NO_SOURCE
    TMR1_CLK_PRESCALER_1
    TMR1_CLK_PRESCALER_8
    TMR1_CLK_PRESCALER_64
    TMR1_CLK_PRESCALER_256
    TMR1_CLK_PRESCALER_1024
    TMR1_CLK_EXT_FALLING_EDGE
    TMR1_CLK_EXT_RISING_EDGE    */
#define TMR1_PRESCALER TMR1_CLK_PRESCALER_1
 
 /************ Mode configuration ************/
 /* TMR1_MODE_NORMAL        
 	TMR1_MODE_PWM_PC_8BIT	 
 	TMR1_MODE_PWM_PC_9BIT	 
 	TMR1_MODE_PWM_PC_10BIT	 
 	TMR1_MODE_CTC_OCR1A	 
 	TMR1_MODE_FAST_PWM_8BIT 
 	TMR1_MODE_FAST_PWM_9BIT 
 	TMR1_MODE_FAST_PWM_10BIT
 	TMR1_MODE_PWM_PFC_ICR1	 
 	TMR1_MODE_PWM_PFC_OCR1A 
 	TMR1_MODE_PWM_PC_ICR1	 
 	TMR1_MODE_PWM_PC_OCR1A	 
 	TMR1_MODE_CTC_ICR1		 
 	TMR1_MODE_FAST_PWM_ICR1 
 	TMR1_MODE_FAST_PWM_OCR1A */
 #define TMR1_MODE TMR1_MODE_NORMAL
 
 
 /************** ICU enable *****************/
 /* TMR0_ICU_ENABLE 
 	TMR0_ICU_DISABLE */
 #define TMR1_ICU TMR0_ICU_ENABLE
 
#endif /*TIMER1_CFG_H*/ 
