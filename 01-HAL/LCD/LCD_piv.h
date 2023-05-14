/********************************* 
    LCD Private File   
*********************************/ 
 
#ifndef LCD_PIV_H 
#define LCD_PIV_H 
 
 
 /********************************************************************************************************/
 /********************************************* DEFINES **************************************************/
 #define LCD_ONE_LINE 0x00
 #define LCD_TWO_LINES 0x08

 #define LCD_FONT_5x8 0x00
 #define LCD_FONT_5x11 0x04

 #define LCD_FUNC_SET_MASK 0x30
 #define LCD_COMMAND_FUNCTION_SET ( LCD_FUNC_SET_MASK | LCD_LINES_NO | LCD_FONT)
 
 #define LCD_CURSOR_ENABLE 0x02
 #define LCD_CURSOR_DISABLE 0x00
 
 #define LCD_CURSOR_BLINK 0x01
 #define LCD_CURSOR_UNBLINK 0x00
 
 #define LCD_DISPLAY_MASK 0x0C
 #define LCD_COMMAND_DISPLAY ( LCD_DISPLAY_MASK | LCD_CURSOR_BLINK_STATE | LCD_CURSOR)
 
 
 
#endif /*LCD_PIV_H*/ 
