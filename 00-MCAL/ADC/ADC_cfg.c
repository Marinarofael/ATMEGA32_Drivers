
/* implementation of functions to get the interrupt flag 
ADC_tenuErrorStatus ADC_enuGetInterruptFlag( u8* Cpy_pu8InterruptFlag)
{
	ADC_tenuErrorStatus Loc_enuReturn = ADC_enuNotOk;
	u8 Loc_u8Counter = 0;
	if(Cpy_pu8InterruptFlag == NULL)
	{
		Loc_enuReturn = ADC_enuNullPtr;
	}
	else
	{
		while ((! GET_BIT(ADC_ADCSRA_REGISTER,ADCSRA_ADIF)) && (Loc_u8Counter < TIME_OUT))
		{
			Loc_u8Counter++;
		}
		if(Loc_u8Counter < TIME_OUT)
		{
			*Cpy_pu8InterruptFlag = GET_BIT(ADC_ADCSRA_REGISTER,ADCSRA_ADIF);
			SET_BIT(ADC_ADCSRA_REGISTER,ADCSRA_ADIF);
			Loc_enuReturn = ADC_enuOk;
		}
	}
	return Loc_enuReturn;
}
*/



/* implementation of function to select the prescaler 
ADC_tenuErrorStatus ADC_enuSelectPrescaler( u8 Cpy_u8Prescaler)
{
	ADC_tenuErrorStatus Loc_enuReturn = ADC_enuOk;
	u8 Loc_u8Register = ADC_ADCSRA_REGISTER;
	
	Loc_u8Register &= CLR_MASK_PRESCALER;
	Loc_u8Register |= Cpy_u8Prescaler;
	ADC_ADCSRA_REGISTER = Loc_u8Register;
	
	return Loc_enuReturn;
}
*/


 /* implementation of function to enable ADC interrupt 
 ADC_tenuErrorStatus ADC_enuEnableADCInterrupt( u8 Cpy_u8Interrupt)
 {
	  ADC_tenuErrorStatus Loc_enuReturn = ADC_enuOk;
	  
	  switch(Cpy_u8Interrupt) 
	  {
		case ADC_INTERRUPT_ENABLE :	SET_BIT(ADC_ADCSRA_REGISTER,ADCSRA_ADIE); break;
		case ADC_INTERRUPT_DISABLE : CLR_BIT(ADC_ADCSRA_REGISTER,ADCSRA_ADIE); break;
		default : Loc_enuReturn = ADC_enuNotOk;
	  }
	  return Loc_enuReturn;
 }*/
 
 
 /* implementation of function to enable the auto triggering 
 ADC_tenuErrorStatus ADC_enuEnableAutoTrigger( u8 Cpy_u8AutoTrigger)
 {
	 ADC_tenuErrorStatus Loc_enuReturn = ADC_enuOk;
	 
	 switch(Cpy_u8AutoTrigger)
	 {
		 case ADC_AUTOTRIGGER_ENABLE : SET_BIT(ADC_ADCSRA_REGISTER,ADCSRA_ADATE); break;
		 case ADC_AUTOTRIGGER_DISABLE : CLR_BIT(ADC_ADCSRA_REGISTER,ADCSRA_ADATE); break;
		 default : Loc_enuReturn = ADC_enuNotOk;
	 }
	 return Loc_enuReturn;
 }*/