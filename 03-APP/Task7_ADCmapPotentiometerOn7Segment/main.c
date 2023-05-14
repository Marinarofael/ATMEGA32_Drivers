/*
 * ADC.c
 *
 * Created: 2/5/2023 10:10:46 PM
 * Author : lenovo
 */ 
#include "DIO.h"
#include "ADC.h"
#include "SSEGMENT.h"

int main(void)
{
    u32 ADC_Reading;
	ADC_tenuErrorStatus ADC_Return;
	DIO_enuInit();
	ADC_enuInit();
	/* Replace with your application code */
    while (1) 
    {
		ADC_Return = ADC_enuGetReadingSynch(ADC_enuChannel_SingleEnded_ADC0,&ADC_Reading);
		//ADC_Reading = ADC_Reading*10;
		if(ADC_Reading > 99)
		{
			ADC_Reading = 99;
		}
		else if(ADC_Reading < 0)
		{
			ADC_Reading = 0;
		}
		SSEGMENT_enuPrintSevenSegment(ADC_Reading);	
    }
}

