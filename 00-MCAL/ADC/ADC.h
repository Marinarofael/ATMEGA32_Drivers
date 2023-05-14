/********************************* 
    ADC Interface File   
*********************************/ 
 
#ifndef ADC_H 
#define ADC_H 

 #include "Std_types.h"
 #include "Bit_math.h"
 #include "ADC_cfg.h"
 #include "ADC_piv.h"

 #define ADC_STATUS_ENABLE 0x80
 #define ADC_STATUS_DISABLE 0x00
  
 #define ADC_VOLTREF_AREF 0x00
 #define ADC_VOLTREF_AVCC 0x40
 #define ADC_VOLTREF_INTERNAL 0xC0
 
 #define ADC_LEFTADJUST_ENABLE 0x20
 #define ADC_LEFTADJUST_DISABLE 0x00
 
 #define ADC_AUTOTRIGGER_ENABLE 0x20
 #define ADC_AUTOTRIGGER_DISABLE 0x00
 
 #define ADC_TRIGGERSOURCE_FREE_RUNNING 0x00
 #define ADC_TRIGGERSOURCE_ANALOG_COMP 0x20
 #define ADC_TRIGGERSOURCE_EXT_INTERRUPT 0x40
 #define ADC_TRIGGERSOURCE_TIMER0_COMPARE_MATCH 0x60
 #define ADC_TRIGGERSOURCE_TIMER0_OVERFLOW 0x80
 #define ADC_TRIGGERSOURCE_TIMER1_COMPARE_MATCH 0xA0
 #define ADC_TRIGGERSOURCE_TIMER1_OVERFLOW 0xC0
 #define ADC_TRIGGERSOURCE_TIMER1_CAPTURE_EVENT 0xE0
 
 #define ADC_INTERRUPT_ENABLE 0x08
 #define ADC_INTERRUPT_DISABLE 0x00
 
 #define ADC_PRESCALER_2   0b001
 #define ADC_PRESCALER_4   0b010
 #define ADC_PRESCALER_8   0b011
 #define ADC_PRESCALER_16  0b100
 #define ADC_PRESCALER_32  0b101
 #define ADC_PRESCALER_64  0b110
 #define ADC_PRESCALER_128 0b111
 
typedef enum
{
	ADC_enuOk = 0,
	ADC_enuNotOk,
	ADC_enuNullPtr,
	ADC_enuNotReady

}ADC_tenuErrorStatus;

typedef enum
{
	ADC_enuChannel_SingleEnded_ADC0 = 0,
	ADC_enuChannel_SingleEnded_ADC1,
	ADC_enuChannel_SingleEnded_ADC2,
	ADC_enuChannel_SingleEnded_ADC3,
	ADC_enuChannel_SingleEnded_ADC4,
	ADC_enuChannel_SingleEnded_ADC5,
	ADC_enuChannel_SingleEnded_ADC6,
	ADC_enuChannel_SingleEnded_ADC7,
	ADC_enuChannel_Diff10x_ADC00,
	ADC_enuChannel_Diff10x_ADC10,
	ADC_enuChannel_Diff200x_ADC00,
	ADC_enuChannel_Diff20x_ADC10,
	ADC_enuChannel_Diff10x_ADC22,
	ADC_enuChannel_Diff10x_ADC32,
	ADC_enuChannel_Diff200x_ADC22,
	ADC_enuChannel_Diff200x_ADC32,
	ADC_enuChannel_Diff1x_ADC01,
	ADC_enuChannel_Diff1x_ADC11,
	ADC_enuChannel_Diff1x_ADC21,
	ADC_enuChannel_Diff1x_ADC31,
	ADC_enuChannel_Diff1x_ADC41,
	ADC_enuChannel_Diff1x_ADC51,
	ADC_enuChannel_Diff1x_ADC61,
	ADC_enuChannel_Diff1x_ADC71,
	ADC_enuChannel_Diff1x_ADC02,
	ADC_enuChannel_Diff1x_ADC12,
	ADC_enuChannel_Diff1x_ADC22,
	ADC_enuChannel_Diff1x_ADC32,
	ADC_enuChannel_Diff1x_ADC42,
	ADC_enuChannel_Diff1x_ADC52,
	ADC_enuChannel_VBG,
	ADC_enuChannel_GND
		
}ADC_tenuAnalogInputs;

typedef struct chains
{
	u8 ADC_ChainLength;
	u16 * ADC_ChainResult;
	u8 * ADC_ChainChannel;
	void (* ADC_ptrEOJ) (void);
	
}ADC_tstructChain;

 /*initializing ADC according to the configuration
 input : void 
 output : error status */
 ADC_tenuErrorStatus ADC_enuInit(void);
 
 /* disabling ADC peripheral
 input : void
 output : error status */
 ADC_tenuErrorStatus ADC_enuDisableADC(void);
 
 /* choosing the reference voltage for ADC peripheral
  input : ADC_VOLTREF_AREF / ADC_VOLTREF_AVCC / ADC_VOLTREF_INTERNAL 
  output : error status */
 ADC_tenuErrorStatus ADC_enuSelectVoltageReference( u8 Cpy_u8VoltRef);
 
 /* choosing the analog channel with gain selection 
 input : one of the enumerators of ADC_tenuAnalogInputs (ADC_enuChannel_X)
 output : error status */
 ADC_tenuErrorStatus ADC_enuSelectAnalogChannel( ADC_tenuAnalogInputs Cpy_enuChannel);
 
 /* selecting auto trigger source
 input : ADC_TRIGGERSOURCE_X
 output : error status */
 ADC_tenuErrorStatus ADC_enuSelectAutoTriggerSource( u8 Cpy_u8TriggerSource);

 /* get conversion result using pooling
 input : channel :one of the enumerators of ADC_tenuAnalogInputs (ADC_enuChannel_X), pointer to get the data in it
 output : error status */
 ADC_tenuErrorStatus ADC_enuGetReadingSynch( ADC_tenuAnalogInputs Cpy_enuChannel, u16* Cpy_pu16ConversionResult);
 
  /* get conversion result using Interrupt
 input : channel : one of the enumerators of ADC_tenuAnalogInputs (ADC_enuChannel_X) , pointer to get the data in it, pointer to the end of job function 
 output : error status */
 /* NOTE : ENABLE THE GLOBAL INTERRUPT BEFORE USING ADC_enuGetReadingASynch FUNCTION */
 ADC_tenuErrorStatus ADC_enuGetReadingASynch( ADC_tenuAnalogInputs Cpy_enuChannel, u16* Cpy_pu16ConversionResult, void (* Cpy_ptrISR) (void));
 
  /* get conversion result using Interrupt and chaining
 input : variable from structure ADC_tstructChain
 output : error status */
 /* NOTE : ENABLE THE GLOBAL INTERRUPT BEFORE USING ADC_enuGetReadingASynch FUNCTION */
 ADC_tenuErrorStatus ADC_enuGetReadingASynchChaining( ADC_tstructChain* Cpy_structChain);
 
 //#if ADC_AUTO_TRIGGER_STATUS == ADC_AUTOTRIGGER_ENABLE
 /* get conversion result using auto trigger to start the conversion and firing interrupt when it ends
 input : channel : one of the enumerators of ADC_tenuAnalogInputs (ADC_enuChannel_X) , source of trigger: ADC_TRIGGERSOURCE_X, pointer to get the data in it, pointer to the end of job function 
 output : error status */
 ADC_tenuErrorStatus ADC_enuGetReadingAutoTrigger( ADC_tenuAnalogInputs Cpy_enuChannel, u8 Cpy_u8TriggerSource, u16* Cpy_pu16ConversionResult, void (* Cpy_ptrISR) (void));
 //#endif
 
#endif /*ADC_H*/ 
