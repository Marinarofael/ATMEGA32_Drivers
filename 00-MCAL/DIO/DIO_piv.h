/***************************/
/* DIO private file        */
/***************************/

#ifndef DIO_PRV_H
#define DIO_PRV_H

/*DIO registers for PORTA */
#define DIO_DDRA_Register *((volatile u8*) 0x3A)
#define DIO_PORTA_Register *((volatile u8*) 0x3B)
#define DIO_PINA_Register *((volatile u8*) 0x39)

/*DIO registers for PORTB */
#define DIO_DDRB_Register *((volatile u8*) 0x37)
#define DIO_PORTB_Register *((volatile u8*) 0x38)
#define DIO_PINB_Register *((volatile u8*) 0x36)

/*DIO registers for PORTC */
#define DIO_DDRC_Register *((volatile u8*) 0x34)
#define DIO_PORTC_Register *((volatile u8*) 0x35)
#define DIO_PINC_Register *((volatile u8*) 0x33)

/*DIO registers for PORTD */
#define DIO_DDRD_Register *((volatile u8*) 0x31)
#define DIO_PORTD_Register *((volatile u8*) 0x32)
#define DIO_PIND_Register *((volatile u8*) 0x30)

#endif /*DIO_PRV_H*/