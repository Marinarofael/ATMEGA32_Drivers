/********************************* 
    UART Private File   
*********************************/ 
 
#ifndef UART_PIV_H 
#define UART_PIV_H 
 
 /******************* UART registers *******************/
 #define UART_UCSRA_REGISTER *((volatile u8*)(0x2B))
 #define UART_UCSRB_REGISTER *((volatile u8*)(0x2A))
 #define UART_UCSRC_REGISTER *((volatile u8*)(0x40))
 #define UART_UBRRH_REGISTER *((volatile u8*)(0x40))
 #define UART_UBRRL_REGISTER *((volatile u8*)(0x29))
 #define UART_UDR_REGISTER *((volatile u8*)(0x2C))
 
 /******************* UART configuration *******************/
 /* UART mode */
 #define UART_MODE_ASYNCHORONOUS 0b00000000
 #define UART_MODE_SYNCHORONOUS 0b01000000
 
 /* UART clock polarity */
 #define UART_TRANSMIT_RISING_EDGE 0
 #define UART_TRANSMIT_FALLING_EDGE 1 
 
 /* UART parity mode */
 #define UART_PARITY_DISABLED 0b00000000
 #define UART_PARITY_EVEN 0b00100000
 #define UART_PARITY_ODD 0b00110000
 
 /* UART stop bit select */
 #define UART_STOP_BIT_1 0b0000
 #define UART_STOP_BIT_2 0b1000
 
 /* UART char size*/
 #define UART_SIZE_5_BIT 0b0000
 #define UART_SIZE_6_BIT 0b0010
 #define UART_SIZE_7_BIT 0b0100
 #define UART_SIZE_8_BIT 0b0110
 #define UART_SIZE_9_BIT 0b1110
 
 /*UART transmission speed */
 #define UART_DOUBLE_SPEED_ENABLE 0b10
 #define UART_DOUBLE_SPEED_DISABLE 0b00
 
 /* UART multi-processor communication mode */
 #define UART_MPCM_ENABLE 1
 #define UART_MPCM_DISABLE 0
 
 /* UART interrupts/receiver/transmitter enable */
 #define UART_ENABLED 1
 #define UART_DISABLED 0
 
 /* UART Baud Rate */
 #define UART_BAUD_RATE_2400 2400
 #define UART_BAUD_RATE_4800 4800
 #define UART_BAUD_RATE_9600 9600
 #define UART_BAUD_RATE_14400 14400
 #define UART_BAUD_RATE_19200 19200
 #define UART_BAUD_RATE_28800 28800
 #define UART_BAUD_RATE_38400 38400
 #define UART_BAUD_RATE_57600 57600
 #define UART_BAUD_RATE_75800 76800
 #define UART_BAUD_RATE_115200 115200
 #define UART_BAUD_RATE_230400 230400
 #define UART_BAUD_RATE_250k 250000
 #define UART_BAUD_RATE_500k 500000
 #define UART_BAUD_RATE_1M 1000000

 
 /******************* UART clear masks *******************/
 #define CLR_MASK_U2X 0b11111101
 #define CLR_MASK_MPCM 0b11111110
 #define CLR_MASK_RECEIVER 0b01101111
 #define CLR_MASK_TRANSMITTER 0b10110111
 #define CLR_MASK_UDRIE 0b11011111
 #define CLR_MASK_UCSRC 0b10000000
 #define CLR_MASK_UBRRH 0b00001111
 #define CLR_MASK_ERROR_CHECKING 0b00011100
 #define CLR_MASK_CHAR_SIZE 0b0111
 
 /***************** UART bits ********************/
 #define UART_RXCIE 7
 #define UART_TXCIE 6
 #define UART_UDRIE 5
 #define UART_RXEN 4
 #define UART_TXEN 3
 #define UART_UCSZ2 2
 
 #define UART_REGISTER_SELECT 7
 
 #define UART_RXC 7
 #define UART_TXC 6
 #define UART_UDRE 5
 
#endif /*UART_PIV_H*/ 
