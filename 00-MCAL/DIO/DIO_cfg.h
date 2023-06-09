/***************************/
/* DIO configuration file  */
/***************************/

#ifndef DIO_CFG_H
#define DIO_CFG_H

#define DIO_DIR_INPUT 0
#define DIO_DIR_OUTPUT 1

#define DIO_INPUT_PULL_UP 0
#define DIO_INPUT_PULL_DOWN 1

#define DIO_OUTPUT_HIGH 1
#define DIO_OUTPUT_LOW 0

typedef struct
{
	u8 DIO_PinDirection;
	u8 DIO_PinValue;
}DIO_strPinCnfg_t;


extern const DIO_strPinCnfg_t DIO_strPinCnfg [32] ;
#endif /*DIO_CFG_H*/