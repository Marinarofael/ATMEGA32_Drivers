/********************************* 
    SSEGMENT Configuration File   
*********************************/ 
 
#ifndef SSEGMENT_CFG_H 
#define SSEGMENT_CFG_H 
 
#include "DIO.h"

//#define SSEGMENT_PORT DIO_enuPORTD_Pin0

#define SSEGMENT_NUMBER_0_VALUE 0x3F
#define SSEGMENT_NUMBER_1_VALUE 0x06
#define SSEGMENT_NUMBER_2_VALUE 0x5B
#define SSEGMENT_NUMBER_3_VALUE 0x4F
#define SSEGMENT_NUMBER_4_VALUE 0x66
#define SSEGMENT_NUMBER_5_VALUE 0x6D
#define SSEGMENT_NUMBER_6_VALUE 0x7D
#define SSEGMENT_NUMBER_7_VALUE 0x07
#define SSEGMENT_NUMBER_8_VALUE 0x7F
#define SSEGMENT_NUMBER_9_VALUE 0x6F

typedef DIO_tenuPins SSEGMENT_tPorts;
 
 typedef enum
 {
	 SSEGMENT_enuNumber0 = 0,
	 SSEGMENT_enuNumber1,
	 SSEGMENT_enuNumber2,
	 SSEGMENT_enuNumber3,
	 SSEGMENT_enuNumber4,
	 SSEGMENT_enuNumber5,
	 SSEGMENT_enuNumber6,
	 SSEGMENT_enuNumber7,
	 SSEGMENT_enuNumber8,
	 SSEGMENT_enuNumber9,
	 SSEGMENT_enuMaxNumber = 100
 }SSEGMENT_tenuNumbers;
 
 typedef enum
 {
	 SSEGMENT_enuSSegment0 = 0,
	 SSEGMENT_enuSSegment1,
	 SSEGMENT_enuSSegmentMaxNumber
 }SSEGMENT_tenuSevenSegments;
 
typedef enum
{
	SSEGMENT_enuActiveLow = 0,
	SSEGMENT_enuActiveHigh
}SSEGMENT_tenuActiveStatus;

 typedef struct 
 {
	SSEGMENT_tPorts SSEGMENT_Port; 
	SSEGMENT_tenuActiveStatus SSEGMENT_ActiveStatus;
 }SSEGMENT_strNumbers_t;
 
 extern const SSEGMENT_strNumbers_t SSEGMENT_strSSEGMENTNumbers [SSEGMENT_enuSSegmentMaxNumber];
 extern const SSEGMENT_tenuNumbers SSEGMENT_arrayPortsValue[SSEGMENT_enuMaxNumber];
 
#endif /*SSEGMENT_CFG_H*/ 
