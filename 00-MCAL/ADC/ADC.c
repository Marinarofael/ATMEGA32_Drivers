#include "ADC.h" 
/******************************************************************************************************/
/********************************************* DEFINES  ***********************************************/

/* clear masks */
#define CLR_MASK_REF_SELECTION 0xC0
#define CLR_MASK_CHANNEL 0xE0
#define CLR_MASK_TRIGGER_SOURCE 0xE0
#define CLR_MASK_PRESCALER 0xF8
#define TIME_OUT 200

/* bits of registers */
#define ADMUX_ADLAR 5
#define ADCSRA_ADEN 7
#define ADCSRA_ADSC 6
#define ADCSRA_ADATE 5
#define ADCSRA_ADIF 4
#define ADCSRA_ADIE 3

/* for interrupt */
#define ISR_(vector_no) void __vector_##vector_no(void) __attribute__((signal));\
						void __vector_##vector_no(void) 
						
#define ADC_INTERRUPT_VECTOR 16		
#define READY 1
#define BUSY 0	
#define ADC_ASYNCH 0
#define ADC_CHAINING 1			

 /******************************************************************************************************/
 /******************************************** VARIABLES ***********************************************/
  static void (* ptrISR) (void) = NULL;
  static u16 * u16Reading = NULL;
  static u8 u8State = READY;
  static u16 * u16ChainReadings = NULL;
  static u8 * u8ChainChannels = NULL; 
  static u8 u8ChainLength = 0;
  static u8 u8Index = 0;
  static u8 u8ISRcaller = ADC_ASYNCH;
 
 /******************************************************************************************************/
 /********************************** STATIC FUNCTIONS PROTOTYPES ***************************************/
 
 static void StartConversion(void);
 static u16 GetReading(void);
 static void SetChannel ( ADC_tenuAnalogInputs Cpy_enuChannel);
 static void SelectVoltageRef(u8 Cpy_u8VoltRef);
 static void SelectTriggerSource (u8 Cpy_u8TriggerSource);
 

 /******************************************************************************************************/
 /*********************************  FUNCTIONS IMPLEMENTATION ******************************************/
 
 /* implementation of initialization function according to the configuration */
 ADC_tenuErrorStatus ADC_enuInit(void)
 {
	 ADC_tenuErrorStatus Loc_enuReturn = ADC_enuOk;
	 u8 Loc_u8Register = 0;
	 
	 /* select left or right adjust */
	 #if ADC_LEFT_ADJUST == ADC_LEFTADJUST_ENABLE 
		SET_BIT(ADC_ADMUX_REGISTER,ADMUX_ADLAR);
	 #elif ADC_LEFT_ADJUST == ADC_LEFTADJUST_DISABLE
		CLR_BIT(ADC_ADMUX_REGISTER,ADMUX_ADLAR);
	#endif 
	
	/* select voltage reference */
	 SelectVoltageRef(ADC_VOLTAGE_REFERENCE);
	 
	 /* selecting prescaler */
	 Loc_u8Register = ADC_ADCSRA_REGISTER & CLR_MASK_PRESCALER;
	 Loc_u8Register |= ADC_PRESCALER;
	 ADC_ADCSRA_REGISTER = Loc_u8Register;
	 
	 /* enable ADC */
	 SET_BIT(ADC_ADCSRA_REGISTER,ADCSRA_ADEN);
	 
	 return Loc_enuReturn;
 }

 /* implementation of function to disable ADC peripheral */
 ADC_tenuErrorStatus ADC_enuDisableADC(void)
 {
	 ADC_tenuErrorStatus Loc_enuReturn = ADC_enuOk;
	 CLR_BIT(ADC_ADCSRA_REGISTER,ADCSRA_ADEN); 
	 return Loc_enuReturn; 
 }
 
/* implementation of function to select the voltage reference */
 ADC_tenuErrorStatus ADC_enuSelectVoltageReference( u8 Cpy_u8VoltRef)
 {
	  ADC_tenuErrorStatus Loc_enuReturn = ADC_enuOk;
	  SelectVoltageRef(Cpy_u8VoltRef); 
	  return Loc_enuReturn;
 }
 
 /* implementation of function to select analog channel and the gain */
 ADC_tenuErrorStatus ADC_enuSelectAnalogChannel( ADC_tenuAnalogInputs Cpy_enuChannel)
 {
	  ADC_tenuErrorStatus Loc_enuReturn = ADC_enuOk;
	  SetChannel (Cpy_enuChannel);
	  return Loc_enuReturn;
 }
 
 /* implementation of function to select the source of auto trigger */
 ADC_tenuErrorStatus ADC_enuSelectAutoTriggerSource( u8 Cpy_u8TriggerSource)
 {
	  ADC_tenuErrorStatus Loc_enuReturn = ADC_enuOk;
	  SelectTriggerSource( Cpy_u8TriggerSource);
	  return Loc_enuReturn;
 }
 
 
 /* implementation of function to get the conversion result using pooling */
 ADC_tenuErrorStatus ADC_enuGetReadingSynch( ADC_tenuAnalogInputs Cpy_enuChannel, u16* Cpy_pu16ConversionResult)
 {
	ADC_tenuErrorStatus Loc_enuReturn = ADC_enuOk;
	u8 Loc_u8Counter = 0;
	
	if(u8State == READY)
	{
		if(Cpy_pu16ConversionResult == NULL)
		{
			Loc_enuReturn = ADC_enuNullPtr;
		}
		else
		{
			u8State = BUSY;
			SetChannel (Cpy_enuChannel);
			StartConversion();
		 
			while ((! GET_BIT(ADC_ADCSRA_REGISTER,ADCSRA_ADIF)) && (Loc_u8Counter < TIME_OUT))
			{
				Loc_u8Counter++;
			}
			if(Loc_u8Counter < TIME_OUT)
			{
				*Cpy_pu16ConversionResult = GetReading();
				SET_BIT(ADC_ADCSRA_REGISTER,ADCSRA_ADIF);
				u8State = READY;
			}  
		}
	}
	else if(u8State == BUSY)
	{
		Loc_enuReturn = ADC_enuNotReady;
	}	  
	  return Loc_enuReturn;
 }
 
 /* implementation of function to get the conversion result using interrupt */
 ADC_tenuErrorStatus ADC_enuGetReadingASynch(  ADC_tenuAnalogInputs Cpy_enuChannel, u16* Cpy_pu16ConversionResult, void (* Cpy_ptrISR) (void))
 {
	ADC_tenuErrorStatus Loc_enuReturn = ADC_enuOk;
	
	if(u8State == READY)
	{
		if(Cpy_pu16ConversionResult == NULL)
		{
			Loc_enuReturn = ADC_enuNullPtr;
		}
		else if(Cpy_ptrISR == NULL)
		{
			Loc_enuReturn = ADC_enuNullPtr;
		}
		else
		{
			u8State = BUSY ;
			u16Reading = Cpy_pu16ConversionResult;
			ptrISR = Cpy_ptrISR;
			u8ISRcaller = ADC_ASYNCH;
	
			SetChannel (Cpy_enuChannel);
			StartConversion(); 
			SET_BIT(ADC_ADCSRA_REGISTER,ADCSRA_ADIE);
		}
	}
	else if(u8State == BUSY)
	{
		Loc_enuReturn = ADC_enuNotReady;
	}
	return Loc_enuReturn;
 }
 
 /* implementation of function to get the conversion result using interrupt and chaining*/
 ADC_tenuErrorStatus ADC_enuGetReadingASynchChaining( ADC_tstructChain* Cpy_structChain)
 {
	 ADC_tenuErrorStatus Loc_enuReturn = ADC_enuOk;
	 if(u8State == READY)
	 {
		 if(Cpy_structChain->ADC_ChainChannel == NULL)
		 {
			 Loc_enuReturn = ADC_enuNullPtr;
		 }
		 else if(Cpy_structChain->ADC_ChainResult == NULL)
		 {
			 Loc_enuReturn = ADC_enuNullPtr;
		 }
		 else if(Cpy_structChain->ADC_ptrEOJ == NULL)
		 {
			 Loc_enuReturn = ADC_enuNullPtr;
		 }
		 else
		 {
			 u8State = BUSY ;
			 u16ChainReadings = Cpy_structChain->ADC_ChainResult;
			 u8ChainChannels = Cpy_structChain->ADC_ChainChannel;
			 ptrISR = Cpy_structChain->ADC_ptrEOJ;
			 u8ChainLength = Cpy_structChain->ADC_ChainLength;
			 u8Index = 0;
			 u8ISRcaller = ADC_CHAINING;
		 
			 SetChannel (u8ChainChannels[u8Index]);
			 StartConversion();
			 SET_BIT(ADC_ADCSRA_REGISTER,ADCSRA_ADIE);
		 }
	 }
	 else if(u8State == BUSY)
	 {
		 Loc_enuReturn = ADC_enuNotReady;
	 }
	 return Loc_enuReturn;
 }
 
// #if ADC_AUTO_TRIGGER_STATUS == ADC_AUTOTRIGGER_ENABLE
 /* implementation of function to get the conversion result using auto trigger */
 ADC_tenuErrorStatus ADC_enuGetReadingAutoTrigger(  ADC_tenuAnalogInputs Cpy_enuChannel, u8 Cpy_u8TriggerSource, u16* Cpy_pu16ConversionResult, void (* Cpy_ptrISR) (void))
 {
	 ADC_tenuErrorStatus Loc_enuReturn = ADC_enuOk;
	 
	 if(u8State == READY)
	 {
		 if(Cpy_pu16ConversionResult == NULL)
		 {
			 Loc_enuReturn = ADC_enuNullPtr;
		 }
		 else if(Cpy_ptrISR == NULL)
		 {
			 Loc_enuReturn = ADC_enuNullPtr;
		 }
		 else
		 {
			 u8State = BUSY ;
			 u16Reading = Cpy_pu16ConversionResult;
			 ptrISR = Cpy_ptrISR;
			 u8ISRcaller = ADC_ASYNCH;
			 
			 SetChannel (Cpy_enuChannel);
			 SET_BIT(ADC_ADCSRA_REGISTER,ADCSRA_ADIE);
			 
			 /* enable and select auto trigger source */
			 SET_BIT(ADC_ADCSRA_REGISTER,ADCSRA_ADATE);
			 SelectTriggerSource(Cpy_u8TriggerSource);
			 
			 if (Cpy_u8TriggerSource == ADC_TRIGGERSOURCE_FREE_RUNNING)
			 {
				 StartConversion();
			 }
		 }
	 }
	 else if(u8State == BUSY)
	 {
		 Loc_enuReturn = ADC_enuNotReady;
	 }
	 return Loc_enuReturn;
 }
 
// #endif
 
 /******************************************************************************************************/
 /****************************** STATIC FUNCTIONS IMPLEMENTATION ***************************************/
 
/* implementation of static function to start conversion */
 static void StartConversion(void)
{
	SET_BIT(ADC_ADCSRA_REGISTER, ADCSRA_ADSC);
}

/* implementation of static function to get the result of conversion */
 static u16 GetReading(void)
 {
	u16 Loc_u16return = 0;
	if(( ADC_BITS == ADC_8_BITS ) && (ADC_LEFT_ADJUST == ADC_LEFTADJUST_ENABLE))
	{
		Loc_u16return = (u8) ADC_ADCH_REGISTER ;
	}
	else if(( ADC_BITS == ADC_8_BITS ) && (ADC_LEFT_ADJUST == ADC_LEFTADJUST_DISABLE))
	{
		Loc_u16return = (u8)((ADC_ADCL_REGISTER >> 2) |  (ADC_ADCH_REGISTER << 6)) ;
	}
	else if (( ADC_BITS == ADC_10_BITS ) && (ADC_LEFT_ADJUST == ADC_LEFTADJUST_ENABLE))
	{
		Loc_u16return = (ADC_ADCH_REGISTER << 2) | (ADC_ADCL_REGISTER >> 6);
	}
	else if (( ADC_BITS == ADC_10_BITS ) && (ADC_LEFT_ADJUST == ADC_LEFTADJUST_DISABLE))
	{
		Loc_u16return = (ADC_ADCH_REGISTER << 8) | ADC_ADCL_REGISTER;
	} 
	return Loc_u16return;
 }
 
 /* implementation of static function to set the channel used */
 static void SetChannel ( ADC_tenuAnalogInputs Cpy_enuChannel)
 {
	  u8 Loc_u8Register = ADC_ADMUX_REGISTER;
	  
	  Loc_u8Register &= CLR_MASK_CHANNEL;
	  Loc_u8Register |= Cpy_enuChannel;
	  ADC_ADMUX_REGISTER = Loc_u8Register;
 }
 
 /* implementation of static function to select the voltage reference used */
 static void SelectVoltageRef(u8 Cpy_u8VoltRef)
 {
	  u8 Loc_u8Register = ADC_ADMUX_REGISTER;
	  Loc_u8Register &= (~ CLR_MASK_REF_SELECTION);
	  Loc_u8Register |= Cpy_u8VoltRef;
	  ADC_ADMUX_REGISTER = Loc_u8Register;
 }
 
// #if ADC_AUTO_TRIGGER_STATUS == ADC_AUTOTRIGGER_ENABLE
  /* implementation of static function to select the trigger source used */
 static void SelectTriggerSource (u8 Cpy_u8TriggerSource)
 {
	 u8 Loc_u8Register = SFIOR_REGISTER;
	 
	 Loc_u8Register &= (~ CLR_MASK_TRIGGER_SOURCE);
	 Loc_u8Register |= Cpy_u8TriggerSource;
	 SFIOR_REGISTER = Loc_u8Register;
 }
 //#endif
 
 /* implementation of interrupt service routine function for ADC */
 ISR_(16)
{
	if(u8ISRcaller == ADC_ASYNCH)
	{
		*u16Reading = GetReading();
		ptrISR();
		CLR_BIT(ADC_ADCSRA_REGISTER,ADCSRA_ADIE);
	
		//#if ADC_AUTO_TRIGGER_STATUS == ADC_AUTOTRIGGER_ENABLE
			CLR_BIT(ADC_ADCSRA_REGISTER,ADCSRA_ADATE);
		//#endif
	
		u8State = READY;
	}
	else if(u8ISRcaller == ADC_CHAINING)
	{
		//SSEGMENT_enuPrintSevenSegment(20);
		if(u8Index == u8ChainLength)
		{
			//SSEGMENT_enuPrintSevenSegment(19);
		//	u16ChainReadings[u8Index] = GetReading();
		u8State = READY;
			ptrISR();
			//u8Index = 0;
			CLR_BIT(ADC_ADCSRA_REGISTER,ADCSRA_ADIE);
			
		}
		else
		{
			//SSEGMENT_enuPrintSevenSegment(16);
			u16ChainReadings[u8Index] = GetReading();
			u8Index++;
			SetChannel(u8ChainChannels[u8Index]);
			StartConversion();
		}	
	}
}
