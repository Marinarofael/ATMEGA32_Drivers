/********************************* 
    LCD Configuration File   
*********************************/ 
 
#ifndef LCD_CFG_H 
#define LCD_CFG_H 
 
 
 /************** configuration for data pins ***************/
 #define LCD_DATA_PORT DIO_enuPORTD_Pin0
 
 /********** configuration for control pins ****************/
 #define LCD_CONTROL_RS DIO_enuPORTA_Pin0
 #define LCD_CONTROL_RW DIO_enuPORTA_Pin1
 #define LCD_CONTROL_E DIO_enuPORTA_Pin2 
 
 /********** configuration  for initialization *************/
 
 /* LCD_ONE_LINE 
 	LCD_TWO_LINES*/
 #define LCD_LINES_NO LCD_TWO_LINES
 
 /* LCD_FONT_5x8 
 	LCD_FONT_5x11 */ 
 #define LCD_FONT LCD_FONT_5x8
 
 /* LCD_CURSOR_ENABLE
    LCE_CURSOR_DISABLE */
 #define LCD_CURSOR LCD_CURSOR_ENABLE
 
 /* LCD_CURSOR_BLINK 
 	LCD_CURSOR_UNBLINK */
 #define LCD_CURSOR_BLINK_STATE LCD_CURSOR_UNBLINK
 
#endif /*LCD_CFG_H*/ 
