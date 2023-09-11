/*
 * LCD_Config.h
 *
 *  Created on: ???/???/????
 *      Author: hp
 */

#ifndef LCD_LCD_CONFIG_H_
#define LCD_LCD_CONFIG_H_

#define LCD_PORT    PORTA
#define rs         LCD_PORT,PIN0
#define en         LCD_PORT,PIN1
#define d4         LCD_PORT,PIN5
#define d5         LCD_PORT,PIN4
#define d6         LCD_PORT,PIN3
#define d7         LCD_PORT,PIN2




#define   CLEAR_SCREEN                          0x01
#define   RETURN_HOME                           0x02
#define   CURSOR_DECRMENT                       0x04
#define   DISPLAY_SHIFT_TO_RIGHT                0x05
#define   CURSOR_INCREMENT                      0x06    // Intery mode
#define   DISPLAY_SHIFT_TO_LEFT                 0x07
#define   CURSOR_AND_DISPLAY_OFF                0x08
#define   CURSOR_POSITION_SHIFT_TO_RIGHT        0x10
#define   CURSOR_POSITION_SHIFT_TO_LEFT         0x14
#define   SHIFT_DATA_TO_LEFT_SIDE               0x18   // shift left
#define   SHIFT_DATA_TO_RIGHT_SIDE              0x1C   // shift right
#define   TOW_LIN_LCD_EIGHT_BIT_MODE            0x38    // Function set
#define   FIRST_LINE                            0x80    // first line
#define   SECOND_LINE                           0xC0   // second line
#define   LCD_FOUR_BIT_MODE                     0x28
#define   CURSOR_OFF                            0x0C
#define   MOWE_CURSOR_TO_SECOND_LINE            0xC0
#define   CURSOR_ONN                            0x0A
#define   CURSOR_BLINKING                       0x0E
#define   DIS_ON_OFF                            0x0F



#endif /* LCD_LCD_CONFIG_H_ */
