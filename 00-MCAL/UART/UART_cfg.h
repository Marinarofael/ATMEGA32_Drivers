/********************************* 
    UART Configuration File   
*********************************/ 
 
#ifndef UART_CFG_H 
#define UART_CFG_H 
 
 /******************** UART mode ********************/
 /* UART_MODE_ASYNCHORONOUS 
    UART_MODE_SYNCHORONOUS   */
 #define UART_MODE UART_MODE_ASYNCHORONOUS
  
  /*************** UART clock polarity ***************/
  /* UART_TRANSMIT_RISING_EDGE
     UART_TRANSMIT_FALLING_EDGE */
  #define UART_CLK_POLARITY UART_TRANSMIT_RISING_EDGE
  
  /**************** UART parity mode ****************/
  /* UART_PARITY_DISABLED 
     UART_PARITY_EVEN 
     UART_PARITY_ODD       */
  #define UART_PARITY_MODE UART_PARITY_DISABLED
  
  /**************** UART stop bit select **************/
  /* UART_STOP_BIT_1 
     UART_STOP_BIT_2  */
  #define UART_STOP_BITS UART_STOP_BIT_1
  
  /**************** UART char size*******************/
  /* UART_SIZE_5_BIT 
     UART_SIZE_6_BIT 
     UART_SIZE_7_BIT 
     UART_SIZE_8_BIT 
     UART_SIZE_9_BIT */
  #define UART_CHAR_SIZE UART_SIZE_8_BIT
  
  /*****************UART transmission speed ************/
  /* UART_DOUBLE_SPEED_ENABLE 
     UART_DOUBLE_SPEED_DISABLE */
  #define UART_U2X_SPEED UART_DOUBLE_SPEED_DISABLE
  
  /******** UART multi-processor communication mode ********/
  /* UART_MPCM_ENABLE 
     UART_MPCM_DISABLE */
  #define UART_MPCM UART_MPCM_DISABLE
  
  /*************** UART interrupts *************/
  /* UART_ENABLED 
     UART_DISABLED */
  #define UART_RX_COMPLETE_INTERRUPT UART_ENABLED
  #define UART_TX_COMPLETE_INTERRUPT UART_ENABLED
  #define UART_UDR_EMPTY_INTERRUPT UART_ENABLED
  
  /************* UART transmitter/receiver enable **************/
  /* UART_ENABLED 
     UART_DISABLED */
  #define UART_RECEIVER_ENABLE UART_ENABLED
  #define UART_TRANSMITTER_ENABLE UART_ENABLED
 
 /************** UART BAUD RATE ******************************/
 /* UART_BAUD_RATE_2400 
 	UART_BAUD_RATE_4800 
 	UART_BAUD_RATE_9600 
 	UART_BAUD_RATE_14400 
 	UART_BAUD_RATE_19200 
 	UART_BAUD_RATE_28800 
 	UART_BAUD_RATE_38400 
 	UART_BAUD_RATE_57600 
 	UART_BAUD_RATE_75800 
 	UART_BAUD_RATE_115200
 	UART_BAUD_RATE_230400
 	UART_BAUD_RATE_250k 
 	UART_BAUD_RATE_500k 
 	UART_BAUD_RATE_1M      */
 #define UART_BAUD_RATE UART_BAUD_RATE_9600
 
 /************** CLOCK FREQUENCY ************************/
 #define SYSTEM_CLK_FREQUENCY 8000000
 
 
#endif /*UART_CFG_H*/ 
