/*
 * LedMatrix_Program.c
 *
 *  Created on: ???/???/????
 *      Author: hp
 */

#include "../LIB/STD_Types.h"
#include "../LIB/BIT_MATH.h"
#include "../GPIO/GPIO_Interface.h"
#include "../SysTic/SysTic_Interface.h"
#include "LedMatrix_Interface.h"


void LedMatrix_Init(void)
{

	GPIO_SetPinDirection(LEDMATRIX_ROW0,OUTPUT_M);
	GPIO_SetPinDirection(LEDMATRIX_ROW1,OUTPUT_M);
	GPIO_SetPinDirection(LEDMATRIX_ROW2,OUTPUT_M);
	GPIO_SetPinDirection(LEDMATRIX_ROW3,OUTPUT_M);
	GPIO_SetPinDirection(LEDMATRIX_ROW4,OUTPUT_M);
	GPIO_SetPinDirection(LEDMATRIX_ROW5,OUTPUT_M);
	GPIO_SetPinDirection(LEDMATRIX_ROW6,OUTPUT_M);
	GPIO_SetPinDirection(LEDMATRIX_ROW7,OUTPUT_M);

	GPIO_SetPinDirection(LEDMATRIX_COL0,OUTPUT_M);
	GPIO_SetPinDirection(LEDMATRIX_COL1,OUTPUT_M);
	GPIO_SetPinDirection(LEDMATRIX_COL2,OUTPUT_M);
	GPIO_SetPinDirection(LEDMATRIX_COL3,OUTPUT_M);
	GPIO_SetPinDirection(LEDMATRIX_COL4,OUTPUT_M);
	GPIO_SetPinDirection(LEDMATRIX_COL5,OUTPUT_M);
	GPIO_SetPinDirection(LEDMATRIX_COL6,OUTPUT_M);
	GPIO_SetPinDirection(LEDMATRIX_COL7,OUTPUT_M);


}
void LedMatrix_ClearCoulmn(u8 col_num)
{
	    GPIO_WritePin(LEDMATRIX_COLPORT,col_num,HIGH);
	    /*
		GPIO_WritePin(LEDMATRIX_COL1,LOW);
		GPIO_WritePin(LEDMATRIX_COL2,LOW);
		GPIO_WritePin(LEDMATRIX_COL3,LOW);
		GPIO_WritePin(LEDMATRIX_COL4,LOW);
		GPIO_WritePin(LEDMATRIX_COL5,LOW);
		GPIO_WritePin(LEDMATRIX_COL6,LOW);
		GPIO_WritePin(LEDMATRIX_COL7,LOW);*/

}
void LedMatrix_Clear(void)
{

	GPIO_WritePin(LEDMATRIX_ROW0,LOW);
	GPIO_WritePin(LEDMATRIX_ROW1,LOW);
	GPIO_WritePin(LEDMATRIX_ROW2,LOW);
	GPIO_WritePin(LEDMATRIX_ROW3,LOW);
	GPIO_WritePin(LEDMATRIX_ROW4,LOW);
	GPIO_WritePin(LEDMATRIX_ROW5,LOW);
	GPIO_WritePin(LEDMATRIX_ROW6,LOW);
	GPIO_WritePin(LEDMATRIX_ROW7,LOW);

	GPIO_WritePin(LEDMATRIX_COL0,LOW);
	GPIO_WritePin(LEDMATRIX_COL1,LOW);
	GPIO_WritePin(LEDMATRIX_COL2,LOW);
	GPIO_WritePin(LEDMATRIX_COL3,LOW);
	GPIO_WritePin(LEDMATRIX_COL4,LOW);
	GPIO_WritePin(LEDMATRIX_COL5,LOW);
	GPIO_WritePin(LEDMATRIX_COL6,LOW);
	GPIO_WritePin(LEDMATRIX_COL7,LOW);


}
void LedMatrix_SetRows(u8 value)
{
	 LedMatrix_Clear();
	GPIO_WritePin(LEDMATRIX_ROW0,GET_BIT(value,0));
	GPIO_WritePin(LEDMATRIX_ROW1,GET_BIT(value,1));
	GPIO_WritePin(LEDMATRIX_ROW2,GET_BIT(value,2));
	GPIO_WritePin(LEDMATRIX_ROW3,GET_BIT(value,3));
	GPIO_WritePin(LEDMATRIX_ROW4,GET_BIT(value,4));
	GPIO_WritePin(LEDMATRIX_ROW5,GET_BIT(value,5));
	GPIO_WritePin(LEDMATRIX_ROW6,GET_BIT(value,6));
	GPIO_WritePin(LEDMATRIX_ROW7,GET_BIT(value,7));
}
void LedMatrix_Display(u8* frame)
{
	LedMatrix_Clear();
	for (u8 i = 0; i < 8; i++)
	{
		LedMatrix_SetRows(frame[i]);
		SysTick_DelaymS(1);
		LedMatrix_ClearCoulmn(i);

	}




}

void LedMatrix_DisplayShift(u8* frame)
{
	LedMatrix_Display(frame);
	for (u8 i = 0;i < 7; i++)
	{
		frame[i] = frame[i+1];
		LedMatrix_SetRows(frame[i]);
		SysTick_DelaymS(100);
		LedMatrix_ClearCoulmn(i);
	}

}
