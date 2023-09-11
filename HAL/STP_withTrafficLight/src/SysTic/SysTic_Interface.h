/*
 * SysTic_Interface.h
 *
 *  Created on: ???/???/????
 *      Author: hp
 */

#ifndef SYSTIC_SYSTIC_INTERFACE_H_
#define SYSTIC_SYSTIC_INTERFACE_H_

#define NULL 0
/*********************************************************************************************/
/* Api Name       :  SysTick_Init                                                            */
/* Parameters in  :  void                                                                   */
/* Parameters out :  void                                                                   */
/* Description    : this function initialize Systick by enable AHB clock                   */
/*                    by setting clocksource in CTLR register                             */
/*****************************************************************************************/
void SysTick_Init (void);
/*****************************************************************************************/
/* Api Name       :  SysTick_DelaymS                                                    */
/* Parameters in  :  number of melli seconds                                           */
/* Parameters out :  void                                                             */
/* Description    : this function load in load register number of melli seconds      */
/*                 the user want to delay  by loading (mS_Number *freq of system     */
/*                   = 25MHZ ) and enable systic  and get countflag when counte     */
/*                   = zero  and clear TickInterrupt                               */
/**********************************************************************************/
void SysTick_DelaymS(u32 mS_Number);
/*****************************************************************************************/
/* Api Name       : SysTick_GetRemainingTime                                            */
/* Parameters in  : void                                                               */
/* Parameters out : void                                                              */
/* Description    : this function get remaining time by subtract current from load   */
/************************************************************************************/
u32 SysTick_GetRemainingTime (void);


void SysTick_IntervalPeriodic(u32 NoCounts,void (*Lpf)(void));
#endif /* SYSTIC_SYSTIC_INTERFACE_H_ */
