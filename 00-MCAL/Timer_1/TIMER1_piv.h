/********************************* 
    TIMER1 Private File   
*********************************/ 
 
#ifndef TIMER1_PIV_H 
#define TIMER1_PIV_H 
 
 /* Registers of timer1 */
 /* Timer/counter control Register */
 #define TMR1_TCCR1A_REGISTER  *((volatile u8*)(0x4F))
 #define TMR1_TCCR1B_REGISTER  *((volatile u8*)(0x4E))
 
 /* Timer/counter Register */
 #define TMR1_TCNT1_REGISTER  *((volatile u16*)(0x4C))
 
 /* Output Compare Register */
 #define TMR1_OCR1A_REGISTER   *((volatile u16*)(0x4A))
 #define TMR1_OCR1B_REGISTER   *((volatile u16*)(0x48))
 #define TMR1_ICR1_REGISTER    *((volatile u16*)(0x46))
 #define TMR1_TIMSK_REGISTER  *((volatile u8*)(0x59))
 #define TMR1_TIFR_REGISTER   *((volatile u8*)(0x58))
 #define SFIOR_REGISTER       *((volatile u8*)(0x50))
 
 /* Modes of TMR1 */
 #define TMR1_MODE_NORMAL         0b0000
 #define TMR1_MODE_PWM_PC_8BIT	  0b0001
 #define TMR1_MODE_PWM_PC_9BIT	  0b0010
 #define TMR1_MODE_PWM_PC_10BIT	  0b0011
 #define TMR1_MODE_CTC_OCR1A	  0b0100
 #define TMR1_MODE_FAST_PWM_8BIT  0b0101
 #define TMR1_MODE_FAST_PWM_9BIT  0b0110
 #define TMR1_MODE_FAST_PWM_10BIT 0b0111
 #define TMR1_MODE_PWM_PFC_ICR1	  0b1000
 #define TMR1_MODE_PWM_PFC_OCR1A  0b1001
 #define TMR1_MODE_PWM_PC_ICR1	  0b1010
 #define TMR1_MODE_PWM_PC_OCR1A	  0b1011
 #define TMR1_MODE_CTC_ICR1		  0b1100
 #define TMR1_MODE_FAST_PWM_ICR1  0b1110
 #define TMR1_MODE_FAST_PWM_OCR1A 0b1111

 /* com mode */
 #define TMR1_COM_NORMAL 0b00
 #define TMR1_COM_TOGGLE 0b01
 #define TMR1_COM_CLEAR	 0b10
 #define TMR1_COM_SET 	 0b11

 /* Clk select */
 #define TMR1_CLK_NO_SOURCE 	    0b000
 #define TMR1_CLK_PRESCALER_1 	    0b001
 #define TMR1_CLK_PRESCALER_8	    0b010
 #define TMR1_CLK_PRESCALER_64 		0b011
 #define TMR1_CLK_PRESCALER_256     0b100
 #define TMR1_CLK_PRESCALER_1024    0b101
 #define TMR1_CLK_EXT_FALLING_EDGE  0b110
 #define TMR1_CLK_EXT_RISING_EDGE   0b111
 
 
 #define TMR1_INT_OV 2
 #define TMR1_INT_CMB 3
 #define TMR1_INT_CMA 4
 #define TMR1_INT_ICU 5
 #define TMR1_ICU_TRIGGER_BIT 6
 
 #define TMR0_ICU_ENABLE 1
 #define TMR0_ICU_DISABLE 0
 
#endif /*TIMER1_PIV_H*/ 
