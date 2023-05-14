#include "Std_types.h" 
#include "Bit_math.h" 
#include "DIO.h" 
#include "DIO_cfg.h"

const DIO_strPinCnfg_t DIO_strPinCnfg [32] =
{
	/*PORTA*//*Pin Direction*/   /*Pin Value*/
	/*PIN0*/ {DIO_DIR_OUTPUT,   DIO_OUTPUT_LOW },
	/*PIN1*/ {DIO_DIR_OUTPUT,   DIO_OUTPUT_LOW },
	/*PIN2*/ {DIO_DIR_OUTPUT,   DIO_OUTPUT_LOW },
	/*PIN3*/ {DIO_DIR_OUTPUT,   DIO_OUTPUT_LOW },
	/*PIN4*/ {DIO_DIR_OUTPUT,   DIO_OUTPUT_LOW },
	/*PIN5*/ {DIO_DIR_OUTPUT,   DIO_OUTPUT_LOW },
	/*PIN6*/ {DIO_DIR_OUTPUT,   DIO_OUTPUT_LOW },
	/*PIN7*/ {DIO_DIR_OUTPUT,   DIO_OUTPUT_LOW },
	
	/*PORTB*//*Pin Direction*/   /*Pin Value*/
	/*PIN0*/ {DIO_DIR_OUTPUT,   DIO_OUTPUT_LOW },
	/*PIN1*/ {DIO_DIR_OUTPUT,   DIO_OUTPUT_LOW },
	/*PIN2*/ {DIO_DIR_OUTPUT,   DIO_OUTPUT_LOW },
	/*PIN3*/ {DIO_DIR_OUTPUT,   DIO_OUTPUT_LOW },
	/*PIN4*/ {DIO_DIR_OUTPUT,   DIO_OUTPUT_LOW },
	/*PIN5*/ {DIO_DIR_OUTPUT,   DIO_OUTPUT_LOW },
	/*PIN6*/ {DIO_DIR_OUTPUT,   DIO_OUTPUT_LOW },
	/*PIN7*/ {DIO_DIR_OUTPUT,   DIO_OUTPUT_LOW },

	/*PORTC*//*Pin Direction*/   /*Pin Value*/
	/*PIN0*/ {DIO_DIR_OUTPUT,   DIO_OUTPUT_LOW },
	/*PIN1*/ {DIO_DIR_OUTPUT,   DIO_OUTPUT_LOW },
	/*PIN2*/ {DIO_DIR_OUTPUT,   DIO_OUTPUT_LOW },
	/*PIN3*/ {DIO_DIR_OUTPUT,   DIO_OUTPUT_LOW },
	/*PIN4*/ {DIO_DIR_OUTPUT,   DIO_OUTPUT_LOW },
	/*PIN5*/ {DIO_DIR_OUTPUT,   DIO_OUTPUT_LOW },
	/*PIN6*/ {DIO_DIR_OUTPUT,   DIO_OUTPUT_LOW },
	/*PIN7*/ {DIO_DIR_OUTPUT,   DIO_OUTPUT_LOW },
	
	/*PORTD*//*Pin Direction*/   /*Pin Value*/
	/*PIN0*/ {DIO_DIR_OUTPUT,   DIO_OUTPUT_LOW },
	/*PIN1*/ {DIO_DIR_INPUT,   DIO_INPUT_PULL_UP },
	/*PIN2*/ {DIO_DIR_INPUT,   DIO_INPUT_PULL_UP },
	/*PIN3*/ {DIO_DIR_OUTPUT,   DIO_INPUT_PULL_DOWN },
	/*PIN4*/ {DIO_DIR_OUTPUT,   DIO_INPUT_PULL_DOWN },
	/*PIN5*/ {DIO_DIR_OUTPUT,   DIO_INPUT_PULL_DOWN },
	/*PIN6*/ {DIO_DIR_INPUT,   DIO_INPUT_PULL_UP },
	/*PIN7*/ {DIO_DIR_OUTPUT,   DIO_OUTPUT_LOW }
} ;