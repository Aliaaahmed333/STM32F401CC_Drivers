/*
 * DAC_Program.c
 *
 *  Created on: ???/???/????
 *      Author: hp
 */



#include "../LIB/STD_Types.h"
#include "../LIB/BIT_MATH.h"
#include "../GPIO/GPIO_Interface.h"
#include "../SysTic/SysTic_Interface.h"
#include "DAC_Interface.h"
#include "DAC_Config.h"
#include "output.h"

u32 DAC_Counter ;

void DAC_Init(void)
{
	for (u8 i = 0; i < 8; i++)
	{
		GPIO_SetPinDirection(DAC_PORT,i,OUTPUT_M);
	}
	SysTick_Init();
}

void DAC_PlaySong (void)
{
	SysTick_IntervalPeriodic(250,DAC_CallBackFun);
}

static void DAC_CallBackFun(void)
{
	for (u8 i = 0; i < 8; i++)
		{
			GPIO_WritePin(DAC_PORT,i,GET_BIT(song_arr[DAC_Counter],i));
		}
	DAC_Counter++;
	if (DAC_Counter > song_len)
	{
		DAC_Counter = 0;
	}
}
