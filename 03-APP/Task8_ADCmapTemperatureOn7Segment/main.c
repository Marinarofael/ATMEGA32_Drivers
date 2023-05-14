/*
 * LM35.c
 *
 * Created: 2/9/2023 4:22:21 PM
 * Author : lenovo
 */ 

#include "DIO.h"
#include "GLOBAL_INTERRUPT.h"
#include "EXTERNAL_INTERRUPT.h"
#include "ADC.h"
#include "SSEGMENT.h"
#include "LM35.h"

u16 ADC_Reading;
u8 LM35_Temperature;
void ADC_EOJ(void);

int main(void)
{
    
	DIO_enuInit();
	GLOBAL_INTERRUPT_enuGlobalInterruptEnable();
	EXTERNAL_INTERRUPT_enuInit();
	ADC_enuInit();
	
	/* Replace with your application code */
    while (1) 
    {
		ADC_enuGetReadingASynch(ADC_enuChannel_SingleEnded_ADC0, &ADC_Reading, ADC_EOJ);
    }
}

void ADC_EOJ(void)
{
	LM35_enuGetTemperature(ADC_Reading, &LM35_Temperature);
	
	if(LM35_Temperature > 99)
	{
		LM35_Temperature = 99;
	}
	else if(LM35_Temperature < 0)
	{
		LM35_Temperature = 0;
	}
	SSEGMENT_enuPrintSevenSegment(LM35_Temperature);
}


