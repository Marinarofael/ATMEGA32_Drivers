#include "Std_types.h"
#include "Bit_math.h"
#include "UART.h" 

 /* implementation of function to initialize UART according to configuration*/
 void UART_voidInit(void)
 {
	 u8 Loc_u8Register = 0;
	 u16 Loc_u16UBRR = 0;
	 
	 /* UCSRA REGISTER bits initialize */
	 Loc_u8Register = UART_UCSRA_REGISTER;
	 
	 #if UART_MODE == UART_MODE_ASYNCHORONOUS
		Loc_u8Register &= CLR_MASK_U2X;
		Loc_u8Register |= UART_U2X_SPEED; 
	 #endif
	 
	 Loc_u8Register &= ~CLR_MASK_ERROR_CHECKING;
	 
	 Loc_u8Register &= CLR_MASK_MPCM;
	 Loc_u8Register |= UART_MPCM;
	 UART_UCSRA_REGISTER = Loc_u8Register;
	 
	 /* UCSRC REGISTER bits initialize */
	 Loc_u8Register = UART_UCSRB_REGISTER;
	 
	 #if  UART_RECEIVER_ENABLE == UART_ENABLED
		Loc_u8Register &= CLR_MASK_RECEIVER;
		Loc_u8Register |= (UART_RECEIVER_ENABLE << UART_RXEN);
		Loc_u8Register |= (UART_RX_COMPLETE_INTERRUPT << UART_RXCIE);
	#endif
	
	#if UART_TRANSMITTER_ENABLE == UART_ENABLED
		Loc_u8Register &= CLR_MASK_TRANSMITTER;
		Loc_u8Register |= (UART_TRANSMITTER_ENABLE << UART_TXEN);
		Loc_u8Register |= (UART_TX_COMPLETE_INTERRUPT << UART_TXCIE);
	#endif
	 
	Loc_u8Register &= CLR_MASK_UDRIE;
	Loc_u8Register |= (UART_UDR_EMPTY_INTERRUPT << UART_UDRIE);
	
	#if UART_CHAR_SIZE == UART_SIZE_9_BIT
		Loc_u8Register |= 1 << UART_UCSZ2;
	#endif
	
	UART_UCSRB_REGISTER = Loc_u8Register;
	
	/* UCSRC REGISTER bits initialize */
	UART_UCSRC_REGISTER |= 1 << UART_REGISTER_SELECT;
	Loc_u8Register = UART_UCSRC_REGISTER;
	Loc_u8Register |= 1 << UART_REGISTER_SELECT;
	
	Loc_u8Register &= CLR_MASK_UCSRC;
	
	Loc_u8Register |= UART_MODE;
	Loc_u8Register |= UART_PARITY_MODE;
	Loc_u8Register |= UART_STOP_BITS;
	Loc_u8Register |= ( UART_CHAR_SIZE & CLR_MASK_CHAR_SIZE);
	
	#if UART_MODE == UART_MODE_SYNCHORONOUS
		Loc_u8Register |= UART_CLK_POLARITY;
	#endif
	UART_UCSRC_REGISTER = Loc_u8Register;
	
	/* Baud Rate Register bits initialize */
	UART_UBRRH_REGISTER &= ~(1 << UART_REGISTER_SELECT);
	Loc_u8Register = UART_UBRRH_REGISTER;
	
	#if UART_MODE == UART_MODE_ASYNCHORONOUS
		#if UART_U2X_SPEED == UART_DOUBLE_SPEED_DISABLE
			Loc_u16UBRR = (u16)((u32)(SYSTEM_CLK_FREQUENCY / ((u32)(UART_BAUD_RATE * 16UL))) - 1);
		
		#elif UART_U2X_SPEED == UART_DOUBLE_SPEED_ENABLE
			Loc_u16UBRR = (u16)((u32)(SYSTEM_CLK_FREQUENCY / ((u32)(UART_BAUD_RATE * 8UL))) - 1);
		
		#endif
		
	#elif UART_MODE == UART_MODE_SYNCHORONOUS
		Loc_u16UBRR = (u16)((u32)(SYSTEM_CLK_FREQUENCY / ((u32)(UART_BAUD_RATE * 2UL))) - 1);
		
	#endif
	
	UART_UBRRL_REGISTER = Loc_u16UBRR;
	Loc_u8Register &= (~CLR_MASK_UBRRH);
	Loc_u8Register |= ((Loc_u16UBRR >> 8) & CLR_MASK_UBRRH);
	Loc_u8Register &= ~(1 << UART_REGISTER_SELECT);
	UART_UBRRH_REGISTER = Loc_u8Register;
 }
 
 /* implementation of function to transmit byte synchronous */
  UART_tenuErrorStatus UART_enuSynchTransmitByte(u8 Cpy_u8Byte)
  {
	  UART_tenuErrorStatus Loc_enuReturn = UART_enuOk;
	  
	  UART_UDR_REGISTER = Cpy_u8Byte;
	  while(GET_BIT(UART_UCSRA_REGISTER, UART_UDRE) == 0);
	  
	  return Loc_enuReturn;
  }
  
  /* implementation of function to transmit byte asynchronous*/
  UART_tenuErrorStatus UART_enuAsynchTransmitByte(u8 Cpy_u8Byte)
  {
	  UART_tenuErrorStatus Loc_enuReturn = UART_enuOk;
	  
	  
	  return Loc_enuReturn;  
  }
  
  /* implementation of function to receive byte synchronous*/
  UART_tenuErrorStatus UART_enuSynchReceiveByte(u8* Cpy_pu8Byte)
  {
	 UART_tenuErrorStatus Loc_enuReturn = UART_enuOk;
	 
	 if(Cpy_pu8Byte == NULL)
	 {
		 Loc_enuReturn = UART_enuNullPtr;
	 }
	 else
	 {
		 * Cpy_pu8Byte = UART_UDR_REGISTER;
		 while(GET_BIT(UART_UCSRA_REGISTER,UART_RXC) == 0);
	 }
	 
	 return Loc_enuReturn;  
  }
  
  /* implementation of function to receive byte asynchronous*/
   UART_tenuErrorStatus UART_enuAsynchReceiveByte(u8* Cpy_pu8Byte)
   {
	  UART_tenuErrorStatus Loc_enuReturn = UART_enuOk;
	  
	  if(Cpy_pu8Byte == NULL)
	  {
		  Loc_enuReturn = UART_enuNullPtr;
	  }
	  else
	  {
		  
	  }
	  
	  return Loc_enuReturn; 
   }