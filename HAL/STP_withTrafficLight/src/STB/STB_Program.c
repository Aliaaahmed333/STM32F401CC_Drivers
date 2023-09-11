/*
 * STB_Program.c
 *
 *  Created on: ???/???/????
 *      Author: hp
 */

#include "../LIB/STD_Types.h"
#include "../LIB/BIT_MATH.h"
#include "../GPIO/GPIO_Interface.h"
#include "../SysTic/SysTic_Interface.h"
#include "STB_Interface.h"

void STP_Init(void)
{
	/* for first 7segment*/
	GPIO_SetPinDirection(STP_PORT,STP_PIN,OUTPUT_M);
	GPIO_SetPinDirection(STP_PORT,STP_SHIFT_CLK,OUTPUT_M);
	GPIO_SetPinDirection(STP_PORT,STP_LATCHCLK,OUTPUT_M);
	/* for second  7segment*/
	GPIO_SetPinDirection(STP_PORT,STP_PIN2,OUTPUT_M);
    GPIO_SetPinDirection(STP_PORT,STP_SHIFT_CLK2,OUTPUT_M);
    GPIO_SetPinDirection(STP_PORT,STP_LATCHCLK2,OUTPUT_M);

}

void STP_SendData(u8 data)
{

		GPIO_WritePin(STP_PORT,STP_LATCHCLK ,LOW);

	    for (s8 i = 7; i >= 0; i--)
		{

			GPIO_WritePin(STP_PORT,STP_PIN, !GET_BIT(data,i));

			GPIO_WritePin(STP_PORT,STP_SHIFT_CLK ,HIGH);
			SysTick_DelaymS(1);
			GPIO_WritePin(STP_PORT ,STP_SHIFT_CLK ,LOW);
			SysTick_DelaymS(1);

		}

	 GPIO_WritePin(STP_PORT,STP_LATCHCLK,HIGH);


}

void STP_SendData2(u8 data)
{

		GPIO_WritePin(STP_PORT,STP_LATCHCLK2 ,LOW);

	    for (s8 i = 7; i >= 0; i--)
		{

			GPIO_WritePin(STP_PORT,STP_PIN2, !GET_BIT(data,i));

			GPIO_WritePin(STP_PORT,STP_SHIFT_CLK2 ,HIGH);
			SysTick_DelaymS(1);
			GPIO_WritePin(STP_PORT ,STP_SHIFT_CLK2 ,LOW);
			SysTick_DelaymS(1);

		}

	 GPIO_WritePin(STP_PORT,STP_LATCHCLK2,HIGH);


}


