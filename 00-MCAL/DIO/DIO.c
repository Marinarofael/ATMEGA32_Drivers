#include "Std_types.h"
#include "Bit_math.h"
#include "DIO.h"

#include "DIO_cfg.h"
#include "DIO_piv.h"


#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

/* init function implementation */ 

DIO_tenuErrorStatus DIO_enuInit(void)
{
	u8 i;
	u8 Loc_u8PortNumber = 0;
	u8 Loc_u8PinNumber = 0;
	
	for(i = 0; i < DIO_enuNumberOfPins; i++)
	{
		Loc_u8PortNumber = i/8;
		Loc_u8PinNumber = i%8;
		
		switch(Loc_u8PortNumber)
		{
			case(DIO_PORTA):
				if(DIO_strPinCnfg[i].DIO_PinDirection == DIO_DIR_OUTPUT)
				{
					SET_BIT(DIO_DDRA_Register,Loc_u8PinNumber);
					if(DIO_strPinCnfg[i].DIO_PinValue == DIO_OUTPUT_HIGH)
					{
						SET_BIT(DIO_PORTA_Register,Loc_u8PinNumber);
					}
					else
					{
						CLR_BIT(DIO_PORTA_Register,Loc_u8PinNumber);
					}
				}
				else
				{
					CLR_BIT(DIO_DDRA_Register,Loc_u8PinNumber);
					if(DIO_strPinCnfg[i].DIO_PinValue == DIO_INPUT_PULL_UP)
					{
						SET_BIT(DIO_PORTA_Register,Loc_u8PinNumber);
					}
				}
				break;
				
			case(DIO_PORTB):
				if(DIO_strPinCnfg[i].DIO_PinDirection == DIO_DIR_OUTPUT)
				{
					SET_BIT(DIO_DDRB_Register,Loc_u8PinNumber);
					if(DIO_strPinCnfg[i].DIO_PinValue == DIO_OUTPUT_HIGH)
					{
						SET_BIT(DIO_PORTB_Register,Loc_u8PinNumber);
					}
					else
					{
						CLR_BIT(DIO_PORTB_Register,Loc_u8PinNumber);
					}
				}
				else
				{
					CLR_BIT(DIO_DDRB_Register,Loc_u8PinNumber);
					if(DIO_strPinCnfg[i].DIO_PinValue == DIO_INPUT_PULL_UP)
					{
						SET_BIT(DIO_PORTB_Register,Loc_u8PinNumber);
					}
				}
				break;
				
			case(DIO_PORTC):
				if(DIO_strPinCnfg[i].DIO_PinDirection == DIO_DIR_OUTPUT)
				{
					SET_BIT(DIO_DDRC_Register,Loc_u8PinNumber);
					if(DIO_strPinCnfg[i].DIO_PinValue == DIO_OUTPUT_HIGH)
					{
						SET_BIT(DIO_PORTC_Register,Loc_u8PinNumber);
					}
					else
					{
						CLR_BIT(DIO_PORTC_Register,Loc_u8PinNumber);
					}
				}
				else
				{
					CLR_BIT(DIO_DDRC_Register,Loc_u8PinNumber);
					if(DIO_strPinCnfg[i].DIO_PinValue == DIO_INPUT_PULL_UP)
					{
						SET_BIT(DIO_PORTC_Register,Loc_u8PinNumber);
					}
				}
				break;
				
			case(DIO_PORTD):	
				if(DIO_strPinCnfg[i].DIO_PinDirection == DIO_DIR_OUTPUT)
				{
					SET_BIT(DIO_DDRD_Register,Loc_u8PinNumber);
					if(DIO_strPinCnfg[i].DIO_PinValue == DIO_OUTPUT_HIGH)
					{
						SET_BIT(DIO_PORTD_Register,Loc_u8PinNumber);
					}
					else
					{
						CLR_BIT(DIO_PORTD_Register,Loc_u8PinNumber);
					}
				}
				else
				{
					CLR_BIT(DIO_DDRD_Register,Loc_u8PinNumber);
					if(DIO_strPinCnfg[i].DIO_PinValue == DIO_INPUT_PULL_UP)
					{
						SET_BIT(DIO_PORTD_Register,Loc_u8PinNumber);
					}
				}
				break;
			
		}
	}
	return DIO_enuOk ;
}

/* set pin function implementation */
DIO_tenuErrorStatus DIO_enuSetPin(DIO_tenuPins Cpy_enuPinNumber)
{
	DIO_tenuErrorStatus Loc_enuReturn;
	
	if (Cpy_enuPinNumber > 32)
	{
		Loc_enuReturn = DIO_enuNotOk;
	}
	else 
	{
		u8 Loc_u8PortNumber =  Cpy_enuPinNumber / 8;
		u8 Loc_u8PinNumber = Cpy_enuPinNumber % 8;
		Loc_enuReturn = DIO_enuOk;
		
		switch(Loc_u8PortNumber)
		{
			case(DIO_PORTA):
				SET_BIT(DIO_PORTA_Register, Loc_u8PinNumber);
				break;
		
			case(DIO_PORTB):
				SET_BIT(DIO_PORTB_Register, Loc_u8PinNumber);
				break;
		
			case(DIO_PORTC):
				SET_BIT(DIO_PORTC_Register, Loc_u8PinNumber);
				break;
		
			case(DIO_PORTD):
				SET_BIT(DIO_PORTD_Register, Loc_u8PinNumber);
				break;
		}
	}
	return Loc_enuReturn ;
}

/* clear pin function implementation */
DIO_tenuErrorStatus DIO_enuClearPin(DIO_tenuPins Cpy_enuPinNumber)
{
	DIO_tenuErrorStatus Loc_enuReturn;
	if (Cpy_enuPinNumber > 32)
	{
		Loc_enuReturn = DIO_enuNotOk;
	}
	else
	{
		u8 Loc_u8PortNumber =  Cpy_enuPinNumber / 8;
		u8 Loc_u8PinNumber = Cpy_enuPinNumber % 8;
		Loc_enuReturn = DIO_enuOk;
		
		switch(Loc_u8PortNumber)
		{
			case(DIO_PORTA):
				CLR_BIT(DIO_PORTA_Register, Loc_u8PinNumber);
				break;
		
			case(DIO_PORTB):
				CLR_BIT(DIO_PORTB_Register, Loc_u8PinNumber);
				break;
		
			case(DIO_PORTC):
				CLR_BIT(DIO_PORTC_Register, Loc_u8PinNumber);
				break;
		
			case(DIO_PORTD):
				CLR_BIT(DIO_PORTD_Register, Loc_u8PinNumber);
				break;
		}
	}
	return Loc_enuReturn ;
}

/* get pin function implementation */
DIO_tenuErrorStatus DIO_enuGetPin(DIO_tenuPins Cpy_enuPinNumber, DIO_tenuPinValue* Add_penuPinValue )
{
	DIO_tenuErrorStatus Loc_enuReturn;
	
	if (Add_penuPinValue == NULL)
	{
		Loc_enuReturn = DIO_enuNullPtr;
	}
	else if (Cpy_enuPinNumber > 32)
	{
		Loc_enuReturn = DIO_enuNotOk;
	}
	else
	{
		u8 Loc_u8PortNumber =  Cpy_enuPinNumber / 8;
		u8 Loc_u8PinNumber = Cpy_enuPinNumber % 8;
		Loc_enuReturn = DIO_enuOk;
		
		switch(Loc_u8PortNumber)
		{
			case(DIO_PORTA):
				*Add_penuPinValue = GET_BIT(DIO_PINA_Register, Loc_u8PinNumber);
				break;
		
			case(DIO_PORTB):
				*Add_penuPinValue = GET_BIT(DIO_PINB_Register, Loc_u8PinNumber);
				break;
		
			case(DIO_PORTC):
				*Add_penuPinValue = GET_BIT(DIO_PINC_Register, Loc_u8PinNumber);
				break;
		
			case(DIO_PORTD):
				*Add_penuPinValue = GET_BIT(DIO_PIND_Register, Loc_u8PinNumber);
				break;
		
		}
	}
		return Loc_enuReturn ;
}


/* set pin function implementation */
DIO_tenuErrorStatus DIO_enuSetPortValue(DIO_tenuPins Cpy_enuPinNumber , u8 Cpy_u8PortValue)
{
	DIO_tenuErrorStatus Loc_enuReturn;
	
	if (Cpy_enuPinNumber > 32)
	{
		Loc_enuReturn = DIO_enuNotOk;
	}
	else
	{
		u8 Loc_u8PortNumber =  Cpy_enuPinNumber / 8;
		Loc_enuReturn = DIO_enuOk;
		
		switch(Loc_u8PortNumber)
		{
			case(DIO_PORTA):
			DIO_PORTA_Register = Cpy_u8PortValue;
			break;
			
			case(DIO_PORTB):
			DIO_PORTB_Register = Cpy_u8PortValue;
			break;
			
			case(DIO_PORTC):
			DIO_PORTC_Register = Cpy_u8PortValue;
			break;
			
			case(DIO_PORTD):
			DIO_PORTD_Register = Cpy_u8PortValue;
			break;
		}
	}
	return Loc_enuReturn ;
}

