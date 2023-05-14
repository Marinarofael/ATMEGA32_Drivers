/********************************* 
    UART Interface File   
*********************************/ 
 
#ifndef UART_H 
#define UART_H 
 
 #include "UART_cfg.h"
 #include "UART_piv.h"
 
 typedef enum
 {
	 UART_enuOk = 0,
	 UART_enuNotOk,
	 UART_enuNullPtr

 }UART_tenuErrorStatus;

 
 /***********************************************/
 /* UART Init function                          */
 /* Input: void                                 */
 /* Output: void							    */
 /***********************************************/
 void UART_voidInit(void);
 
 
 /***********************************************/
 /* UART synchronous function to transmit byte  */
 /* Input: u8 data                              */
 /* Output: Error status						*/
 /***********************************************/
 UART_tenuErrorStatus UART_enuSynchTransmitByte(u8 Cpy_u8Byte);
 
 /***********************************************/
 /* UART asynchronous function to transmit byte */
 /* Input: u8 data                              */
 /* Output: Error status						*/
 /***********************************************/
 UART_tenuErrorStatus UART_enuAsynchTransmitByte(u8 Cpy_u8Byte);
 
 /***********************************************/
 /* UART synchronous function to receive byte   */
 /* Input: pointer to u8 data                   */
 /* Output: Error status						*/
 /***********************************************/
 UART_tenuErrorStatus UART_enuSynchReceiveByte(u8* Cpy_pu8Byte);
 
  /***********************************************/
  /* UART asynchronous function to receive byte   */
  /* Input: pointer to u8 data                   */
  /* Output: Error status						*/
  /***********************************************/
  UART_tenuErrorStatus UART_enuAsynchReceiveByte(u8* Cpy_pu8Byte);
 
#endif /*UART_H*/ 
