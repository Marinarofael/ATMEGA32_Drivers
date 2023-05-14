/********************************* 
    ADC Private File   
*********************************/ 
 
#ifndef ADC_PIV_H 
#define ADC_PIV_H 
 
 /* ADC multiplexer selection register */
 #define ADC_ADMUX_REGISTER *((volatile u8*)(0x27))
 
 /* ADC control and status register */
 #define ADC_ADCSRA_REGISTER *((volatile u8*)(0x26))
 
 /* ADC data registers */
 #define ADC_ADCH_REGISTER *((volatile u8*)(0x25))
 #define ADC_ADCL_REGISTER *((volatile u8*)(0x24))
 
 /* special function I/O register */
 #define SFIOR_REGISTER *((volatile u8*)(0x50))
 
 
 
#endif /*ADC_PIV_H*/ 
