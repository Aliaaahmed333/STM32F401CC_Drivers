/*
 * LCD_Interface.h
 *
 *  Created on: ???/???/????
 *      Author: hp
 */

#ifndef LCD_LCD_INTERFACE_H_
#define LCD_LCD_INTERFACE_H_



/* write zero or 1 at each bit in lcd */
#define D7(val)      GPIO_WritePin(d7,val)
#define D6(val)      GPIO_WritePin(d6,val)
#define D5(val)      GPIO_WritePin(d5,val)
#define D4(val)      GPIO_WritePin(d4,val)
#define RS(val)      GPIO_WritePin(rs,val)
#define EN(val)      GPIO_WritePin(en,val)
/* Trigger enable pin */
#define TRIGGER_LCD()  EN(1);SysTick_DelaymS(1);EN(0);SysTick_DelaymS(1);

/* define lcd functions */
void LCD_INIT_PINS(void);
void LCD_Init(void);
void LCD_WriteCommand(u8 cmd);
void LCD_WriteChar(u8 data);
void LCD_WriteString(u8* txt);
void LCD_WriteNumber (s32 number);
void  LCD_SetCursor (u8 row ,u8 col);

#endif /* LCD_LCD_INTERFACE_H_ */
