/***************************/
/* DIO Interface file      */
/***************************/

#ifndef DIO_H
#define DIO_H

#include "Std_types.h"




typedef enum
{
	DIO_enuOk = 0, 
	DIO_enuNotOk,
	DIO_enuNullPtr

}DIO_tenuErrorStatus;


typedef enum
{
	DIO_enuPORTA_Pin0 = 0,
	DIO_enuPORTA_Pin1,
	DIO_enuPORTA_Pin2,
	DIO_enuPORTA_Pin3,
	DIO_enuPORTA_Pin4,
	DIO_enuPORTA_Pin5,
	DIO_enuPORTA_Pin6,
	DIO_enuPORTA_Pin7,
	DIO_enuPORTB_Pin0,
	DIO_enuPORTB_Pin1,
	DIO_enuPORTB_Pin2,
	DIO_enuPORTB_Pin3,
	DIO_enuPORTB_Pin4,
	DIO_enuPORTB_Pin5,
	DIO_enuPORTB_Pin6,
	DIO_enuPORTB_Pin7,
	DIO_enuPORTC_Pin0,
	DIO_enuPORTC_Pin1,
	DIO_enuPORTC_Pin2,
	DIO_enuPORTC_Pin3,
	DIO_enuPORTC_Pin4,
	DIO_enuPORTC_Pin5,
	DIO_enuPORTC_Pin6,
	DIO_enuPORTC_Pin7,
	DIO_enuPORTD_Pin0,
	DIO_enuPORTD_Pin1,
	DIO_enuPORTD_Pin2,
	DIO_enuPORTD_Pin3,
	DIO_enuPORTD_Pin4,
	DIO_enuPORTD_Pin5,
	DIO_enuPORTD_Pin6,
	DIO_enuPORTD_Pin7,
	DIO_enuNumberOfPins
}DIO_tenuPins;

typedef enum
{
	DIO_enuLow = 0,
	DIO_enuHigh
}DIO_tenuPinValue;

/***********************************************/
/* DIO Init function                           */
/* Input: void                                 */
/* Output: Dio_tenuErrorStatus to report error */
/***********************************************/
DIO_tenuErrorStatus DIO_enuInit(void);

/***********************************************/
/* DIO set pin function                           */
/* Input: Pin number (range from 0 - 31)       */
/* Output: Dio_tenuErrorStatus to report error */
/***********************************************/
DIO_tenuErrorStatus DIO_enuSetPin(DIO_tenuPins Cpy_enuPinNumber);


/***********************************************/
/* DIO clear pin function                      */
/* Input: Pin number (range from 0 - 31)       */
/* Output: Dio_tenuErrorStatus to report error */
/***********************************************/
DIO_tenuErrorStatus DIO_enuClearPin(DIO_tenuPins Cpy_enuPinNumber);


/****************************************************/
/* DIO get pin function                             */
/* Input: Pin number (range from 0 - 31)            */
/* Input: Pointer to get the value of the given pin */
/* Output: Dio_tenuErrorStatus to report error      */
/****************************************************/
DIO_tenuErrorStatus DIO_enuGetPin(DIO_tenuPins Cpy_enuPinNumber, DIO_tenuPinValue* Add_penuPinValue );


/***********************************************/
/* DIO set port value function                 */
/* Input: Pin number (range from 0 - 31)       */
/* Output: Dio_tenuErrorStatus to report error */
/***********************************************/
DIO_tenuErrorStatus DIO_enuSetPortValue(DIO_tenuPins Cpy_enuPinNumber , u8 Cpy_u8PortValue);

#endif /*DIO_H*/