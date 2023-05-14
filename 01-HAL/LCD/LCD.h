/********************************* 
    LCD Interface File   
*********************************/ 
 
#ifndef LCD_H 
#define LCD_H 
 
 #include "Std_types.h"
 #include "Bit_math.h"
 #include "LCD_piv.h"
 #include "LCD_cfg.h"
 
 #define LCD_CharNumber_0 0
 #define LCD_CharNumber_1 1
 #define LCD_CharNumber_2 2
 #define LCD_CharNumber_3 3
 #define LCD_CharNumber_4 4
 #define LCD_CharNumber_5 5
 #define LCD_CharNumber_6 6
 #define LCD_CharNumber_7 7
 
 #define LCD_FIRST_LINE 0
 #define LCD_SECOND_LINE 1
 
 #define LCD_LOCATION_0  0
 #define LCD_LOCATION_1  1
 #define LCD_LOCATION_2  2
 #define LCD_LOCATION_3  3
 #define LCD_LOCATION_4  4
 #define LCD_LOCATION_5  5
 #define LCD_LOCATION_6  6
 #define LCD_LOCATION_7  7
 #define LCD_LOCATION_8  8
 #define LCD_LOCATION_9  9
 #define LCD_LOCATION_10 10
 #define LCD_LOCATION_11 11
 #define LCD_LOCATION_12 12
 #define LCD_LOCATION_13 13
 #define LCD_LOCATION_14 14
 #define LCD_LOCATION_15 15
 
 #define LCD_COMMAND_CLEAR 0x01

 typedef enum
 {
	 LCD_enuOk = 0,
	 LCD_enuNotOk,
	 LCD_enuNullPtr

 }LCD_tenuErrorStatus;


 /* LCD initialization according to configuration
 input : void
 output : error status */
 LCD_tenuErrorStatus LCD_enuInit(void);
 
 /* to send a command to LCD 
 input : command
 output : error status */
 LCD_tenuErrorStatus LCD_enuWriteCommand (u8 Cpy_u8Command);
 
 /* to write data on LCD 
 input : data (depends on user)
 output : error status */
 LCD_tenuErrorStatus LCD_enuWriteData (u8 Cpy_u8Character);
 
 /* to add special character 
 input : pattern of special character , character number (LCD_CharNumber_X), line number (LCD_FIRST_LINE / LCD_SEC_LINE ) , Y-coordinate (LCD_LOCATION_X) 
 output : error status */
 LCD_tenuErrorStatus LCD_enuWriteSpecialCharacter (u16 Cpy_u16CharPattern, u8 Cpy_u8CharNumber,  u8 Cpy_u8Line, u8 Cpy_u8Location); 
 
 /* to go to specific location on LCD 
 input : line number (LCD_FIRST_LINE / LCD_SEC_LINE ) , Y-coordinate (LCD_LOCATION_X) 
 output : error status */
 LCD_tenuErrorStatus LCD_enuGoToXY ( u8 Cpy_u8Line, u8 Cpy_u8Location);
 
 /* to write string on LCD
 input : data in form of string (depends on user)
 output : error status */
 LCD_tenuErrorStatus LCD_enuWriteString (u8 * Cpy_Pu8String);
 
 /* to write a number on LCD
 input : data (depends on user )
 output : error status */
 LCD_tenuErrorStatus LCD_enuWriteNumber (u8 Cpy_u8Number);
 
 
#endif /*LCD_H*/ 
