/********************************* 
    EXTERNAL_INTERRUPT Configuration File   
*********************************/ 
 
#ifndef EXTERNAL_INTERRUPT_CFG_H 
#define EXTERNAL_INTERRUPT_CFG_H 

#include "EXTERNAL_INTERRUPT_piv.h"

 /************* interrupt Configurations ****************/
 
 /*EXTERNAL_INTERRUPT_01_LOW_LEVEL_MODE 
 EXTERNAL_INTERRUPT_01_LOGICAL_CHANGE_MODE
 EXTERNAL_INTERRUPT_01_FALLING_EDGE_MODE 
 EXTERNAL_INTERRUPT_01_RISING_EDGE_MODE 
 EXTERNAL_INTERRUPT_2_FALLING_EDGE_MODE
 EXTERNAL_INTERRUPT_2_RISING_EDGE_MODE*/
 #define EXTERNAL_INTERRUPT_MODE EXTERNAL_INTERRUPT_01_LOGICAL_CHANGE_MODE
 
/* enabling needed Interrupt*/
 #define EXTERNAL_INTERRUPT_0 EXTERNAL_INTERRUPT_0_ENABLED
 #define EXTERNAL_INTERRUPT_1 EXTERNAL_INTERRUPT_1_ENABLED
 #define EXTERNAL_INTERRUPT_2 EXTERNAL_INTERRUPT_2_DISABLED
 
 /********************************************************/ 

/* general interrupt flag register Pins */ 
#define EXTERNAL_INTERRUPT_GIFR_INT2pin 5
#define EXTERNAL_INTERRUPT_GIFR_INT0pin 6
#define EXTERNAL_INTERRUPT_GIFR_INT1pin 7

/* general interrupt control register Pins */ 	   
#define EXTERNAL_INTERRUPT_GICR_INT2pin 5
#define EXTERNAL_INTERRUPT_GICR_INT0pin 6
#define EXTERNAL_INTERRUPT_GICR_INT1pin 7
 
/* MCU control and status register pin */
#define EXTERNAL_INTERRUPT_MCUCSR_ISC2pin 6
 
 
#endif /*EXTERNAL_INTERRUPT_CFG_H*/ 
