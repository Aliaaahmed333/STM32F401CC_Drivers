/*
 * lcd.c
 *
 * Created: 9/4/2021 11:16:13 AM
 *  Author: safifi
 */
#include "../LIB/STD_Types.h"
#include "../LIB/BIT_MATH.h"
#include "../SysTic/SysTic_Interface.h"
#include "../GPIO/GPIO_Interface.h"
#include "LCD_Interface.h"
#include "LCD_Config.h"

/*******************************************************************
Function Name : LCD_INIT_PINS
Purpose       : Initalize lcd PORT,PINS as output mode
parameter     : void
Return Value  : void
*********************************************************************/
void LCD_INIT_PINS(void)
{
	GPIO_SetPinDirection(rs,OUTPUT_M);
	GPIO_SetPinDirection(en,OUTPUT_M);
	GPIO_SetPinDirection(d4,OUTPUT_M);
	GPIO_SetPinDirection(d5,OUTPUT_M);
	GPIO_SetPinDirection(d6,OUTPUT_M);
	GPIO_SetPinDirection(d7,OUTPUT_M);

}
/*******************************************************************
Function Name : LCD_Init
Purpose       : Initalize lcd to make it work at 4_bit mode
parameter     : void
Return Value  : void
*********************************************************************/
void LCD_Init(void)
{
	LCD_INIT_PINS();
	LCD_WriteCommand(0x2); // return home or function set
	LCD_WriteCommand(LCD_FOUR_BIT_MODE); // four bit mode
    SysTick_DelaymS(1);
    LCD_WriteCommand(CURSOR_OFF); //Display ON/OFF Control
	SysTick_DelaymS(1);
	LCD_WriteCommand( CLEAR_SCREEN ); //Display Clear
	SysTick_DelaymS(3);
	LCD_WriteCommand(CURSOR_INCREMENT); //Display entry mode (make curser increment to right)
	SysTick_DelaymS(3);

}
// 0x28 ---- 2= 0010 (D7,D6,D5,D4) EN(1) SysTick_DelaymS(1) EN(0) SysTick_DelaymS(1)
/*******************************************************************
Function Name : LCD_Write_Comd
Purpose       : to make lcd do aspecific command from datasheet
parameter     : comd
Return Value  : void
*********************************************************************/
void LCD_WriteCommand(u8 cmd)
{
	RS(0);
	D7(GET_BIT(cmd,7));
	D6(GET_BIT(cmd,6));
	D5(GET_BIT(cmd,5));
	D4(GET_BIT(cmd,4));

	TRIGGER_LCD();

	D7(GET_BIT(cmd,3));
	D6(GET_BIT(cmd,2));
	D5(GET_BIT(cmd,1));
	D4(GET_BIT(cmd,0));

	TRIGGER_LCD();
}
/*******************************************************************
Function Name : LCD_WriteChar
Purpose       : to make lcd display only one char on screen by using
                4_bit_mode
parameter     : data
Return Value  : void
*********************************************************************/
void LCD_WriteChar(u8 data){
	RS(1);
	D7(GET_BIT(data,7));
	D6(GET_BIT(data,6));
	D5(GET_BIT(data,5));
	D4(GET_BIT(data,4));

	TRIGGER_LCD();

	D7(GET_BIT(data,3));
	D6(GET_BIT(data,2));
	D5(GET_BIT(data,1));
	D4(GET_BIT(data,0));

	TRIGGER_LCD();

}
/*******************************************************************
Function Name : LCD_Write_String
Purpose       : to make lcd display a text on lcd by using
                4_bit_mode
parameter     : pointer to text(*text)
Return Value  : void
*********************************************************************/
void LCD_WriteString(u8* txt)
{
	u8 i = 0;
	while(txt[i] != '\0'){
		LCD_WriteChar(txt[i]);
		i++;
	}
}
/* 1234 % 10 --- 4
   123 %  10 ----3
   12  %  10 ----2
   1   %  10 ----1
   0
*/
/*******************************************************************
Function Name : LCD_WriteNumber
Purpose       : to make lcd display a number on lcd  and this number contain
                one more digit by using  4_bit_mode
parameter     : pointer to text(*text)
Return Value  : void
*********************************************************************/
void LCD_WriteNumber (s32 number)
{
	u8 arr[12]	;
	s8 index = 0;
	if (number != 0)
	{
		while (number != 0)
		{
			arr[index] = number%10;
			number/=10;
			index++;
		}
		index --;
		for (s8 i = index; i >= 0; i--)
		{
			LCD_WriteChar(arr[i]+'0');
		}
	}
	else
	{
		LCD_WriteChar('0');
	}
}

void  LCD_SetCursor (u8 row ,u8 col)
 {

  u16 The_Address =0;

  if ( row ==0)
	  The_Address=FIRST_LINE;  // first line

  else if (row ==1)
	  The_Address= SECOND_LINE;       // second line

	if (col <16)
	{
		The_Address += col;
	}

	LCD_write_command(The_Address);



 }
