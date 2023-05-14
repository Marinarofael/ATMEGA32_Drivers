/********************************* 
    EXTERNAL_INTERRUPT Private File   
*********************************/ 
 
#ifndef EXTERNAL_INTERRUPT_PIV_H 
#define EXTERNAL_INTERRUPT_PIV_H 
 
 /*General Interrupt Control Register */
 #define EXTERNAL_INTERRUPT_GICR_REGISTER *((volatile u8*) 0x5B)
 
 /*General Interrupt Flag Register */
 #define EXTERNAL_INTERRUPT_GIFR_REGISTER *((volatile u8*) 0x5A)
 
 /*MCU Control Register */
 #define EXTERNAL_INTERRUPT_MCUCR_REGISTER *((volatile u8*) 0x55)
 
 /*MCU Control and Status Register */
 #define EXTERNAL_INTERRUPT_MCUCSR_REGISTER *((volatile u8*) 0x54)

 /* interrupt modes for INT0 and INT1 */
 #define EXTERNAL_INTERRUPT_01_LOW_LEVEL_MODE 0b00
 #define EXTERNAL_INTERRUPT_01_LOGICAL_CHANGE_MODE 0b01
 #define EXTERNAL_INTERRUPT_01_FALLING_EDGE_MODE 0b10
 #define EXTERNAL_INTERRUPT_01_RISING_EDGE_MODE 0b11
 
 /*interrupt modes for INT2 */
 #define EXTERNAL_INTERRUPT_2_FALLING_EDGE_MODE 0b0
 #define EXTERNAL_INTERRUPT_2_RISING_EDGE_MODE 0b1
 
  /* interrupt peripheral number */
  #define EXTERNAL_INTERRUPT_0_ENABLED 1
  #define EXTERNAL_INTERRUPT_1_ENABLED 1
  #define EXTERNAL_INTERRUPT_2_ENABLED 1
  #define EXTERNAL_INTERRUPT_0_DISABLED 0
  #define EXTERNAL_INTERRUPT_1_DISABLED 0
  #define EXTERNAL_INTERRUPT_2_DISABLED 0
  
  
  
#endif /*EXTERNAL_INTERRUPT_PIV_H*/ 
