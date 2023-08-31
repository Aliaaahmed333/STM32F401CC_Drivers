/*
 * SysTic_Program.c
 *
 *  Created on: ???/???/????
 *      Author: hp
 */


#include "../LIB/STD_Types.h"
#include "../LIB/BIT_MATH.h"
#include "SysTic_Interface.h"
#include "SysTic_Private.h"
#include "SysTic_Config.h"

u8 INTFlag = 0;
 void (*SysTic_Pf)(void);


/*********************************************************************************/
/* Api Name       :  SysTick_Init                                              */
/* Parameters in  :  void                                                     */
/* Parameters out :  void                                                    */
/* Description    : this function initialize Systick by enable AHB clock    */
/*                    by setting clocksource in CTLR register               */
/****************************************************************************/
void SysTick_Init  (void)
{
	 CLR_BIT(SYSTICK ->CTRL,ENABLE);
	 CLR_BIT(SYSTICK ->CTRL,TICKINT);
	 SYSTICK ->LOAD = 0;
	 SYSTICK ->VAL = 0;
#if SYSTIC_CLKSOURCE == AHB_CLK
	SET_BIT (SYSTICK ->CTRL,CLKSOURCE);
#elif SYSTIC_CLKSOURCE == AHB_DEVIDEBY8
		CLR_BIT (SYSTICK ->CTRL,CLKSOURCE);
#endif
}

/*****************************************************************************************/
/* Api Name       :  SysTick_DelaymS                                                    */
/* Parameters in  :  number of melli seconds                                           */
/* Parameters out :  void                                                             */
/* Description    : this function load in load register number of melli seconds      */
/*                the user want to delay  by loading (mS_Number *freq of system     */
/*                   = 25MHZ ) and enable systic  and get countflag when counte     */
/*                   = zero  and clear TickInterrupt                               */
/**********************************************************************************/
void SysTick_DelaymS(u32 mS_Number)
{
   CLR_BIT(SYSTICK ->CTRL,ENABLE);
   SYSTICK ->LOAD = 0;
   SYSTICK ->VAL = 0;
   SYSTICK ->LOAD = ((mS_Number * 25000) - 1);
   SET_BIT(SYSTICK ->CTRL,ENABLE);
   while (GET_BIT(SYSTICK ->CTRL , COUNTFLAG) == 0);
   CLR_BIT(SYSTICK ->CTRL,TICKINT);


}
/*****************************************************************************************/
/* Api Name       : SysTick_GetRemainingTime                                            */
/* Parameters in  : void                                                               */
/* Parameters out : void                                                              */
/* Description    : this function get remaining time by subtract current from load   */
/************************************************************************************/
u32 SysTick_GetRemainingTime (void)
{
	return  (SYSTICK ->LOAD - SYSTICK ->VAL);
}

/*

void SysTick_IntervalPeriodic(u32 NoCounts,void (*Lpf)(void)){
	SysTic_Pf  = Lpf;
	SYSTICK ->LOAD = NoCounts;
	SET_BIT(SYSTICK ->CTRL,ENABLE);
	SET_BIT(SYSTICK ->CTRL,TICKINT);
	INTFlag = 0;

}

void SysTick_Handler(void){

	if(SysTic_Pf != NULL){
		SysTic_Pf();
	}
	u8 Local_TempVariable = GET_BIT(SYSTICK ->CTRL,COUNTFLAG);
}

*/
