/***************************/
/* LED interface file      */
/***************************/
#ifndef LED_H
#define LED_H

#include "DIO.h"

typedef enum
{
	LED_enuOk = 0, 
	LED_enuNotOk,
	LED_enuNullPtr

}LED_tenuErrorStatus;

/**********************************/
/* input : pin number             */
/* output : error status          */
/* function : turn the led on     */
/**********************************/
LED_tenuErrorStatus LED_enuLedOn(DIO_tenuPins Cpy_enuPinNumber);

/**********************************/
/* input : pin number             */
/* output : error status          */
/* function : turn the led on     */
/**********************************/
LED_tenuErrorStatus LED_enuLedOff(DIO_tenuPins Cpy_enuPinNumber);

#endif /*LED_H*/