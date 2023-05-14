/********************************* 
    TIMER Private File   
*********************************/ 
 
#ifndef TIMER0_PIV_H 
#define TIMER0_PIV_H 
 
  /* Registers of timer0 */
  /* Timer/counter control Register */
  #define TMR0_TCCR0_REGISTER  *((volatile u8*)(0x53))
  
  /* Timer/counter Register */
  #define TMR0_TCNT0_REGISTER  *((volatile u8*)(0x52))
  
  /* Output Compare Register */
  #define TMR0_OCR0_REGISTER   *((volatile u8*)(0x5C))
  #define TMR0_TIMSK_REGISTER  *((volatile u8*)(0x59))
  #define TMR0_TIFR_REGISTER   *((volatile u8*)(0x58))
  #define SFIOR_REGISTER       *((volatile u8*)(0x50))
 
  /* Modes of timer0 */
  #define TMR0_MODE_NORMAL_DISCONNECT_OC0      0b00000000
  #define TMR0_MODE_NORMAL_TOGGLE_OC0_CM       0b00010000
  #define TMR0_MODE_NORMAL_CLEAR_OC0_CM	       0b00100000
  #define TMR0_MODE_NORMAL_SET_OC0_CM	       0b00110000
  											
  #define TMR0_MODE_CTC_DISCONNECT_OC0         0b00001000
  #define TMR0_MODE_CTC_TOGGLE_OC0_CM 	       0b00011000
  #define TMR0_MODE_CTC_CLEAR_OC0_CM		   0b00101000
  #define TMR0_MODE_CTC_SET_OC0_CM		       0b00111000
  											
  #define TMR0_MODE_PWM_DISCONNECTED_OC0       0b01000000
  #define TMR0_MODE_PWM_NON_INVERTING	 	   0b01100000
  #define TMR0_MODE_PWM_INVERTING		 	   0b01110000
  												
  #define TMR0_MODE_FAST_PWM_DISCONNECTED_OC0  0b01001000
  #define TMR0_MODE_FAST_PWM_NON_INVERTING	   0b01101000
  #define TMR0_MODE_FAST_PWM_INVERTING		   0b01111000
  
  /* Clk select */
  #define TMR0_CLK_NO_SOURCE 	     0b000
  #define TMR0_CLK_PRESCALER_1 	     0b001
  #define TMR0_CLK_PRESCALER_8	     0b010
  #define TMR0_CLK_PRESCALER_64 	 0b011
  #define TMR0_CLK_PRESCALER_256     0b100
  #define TMR0_CLK_PRESCALER_1024    0b101
  #define TMR0_CLK_EXT_FALLING_EDGE  0b110
  #define TMR0_CLK_EXT_RISING_EDGE   0b111
 
  /* For Interrupt */
  #define TMR0_INT_ENABLE 1
  #define TMR0_INT_DISABLE 0
  
#endif /*TIMER0_PIV_H*/ 
