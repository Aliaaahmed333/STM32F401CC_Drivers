/*
 * NVIC_Program.c
 *
 *  Created on: 14/8/2023
 *      Author: Aliaa Ahmed
 */

#include "STD_Types.h"
#include "BIT_MATH.h"
#include "NVIC_Interface.h"
#include "NVIC_Private.h"


static u8 G_priorityGrouping;

/*********************************************************************************/
/* Api Name       :  NVIC_EnableInterrupt                                     */
/* Parameters in  :  Interrupt nuber                                          */
/* Parameters out :   void                                                   */
/* Description    :  this function enable interrupt preipheral by detecting
 *                   ISER register and it's pen in this peripheral by using
 *                     two equation                                          */
/****************************************************************************/

void NVIC_EnableInterrupt  (u8 Interrupt_Number)
{
	/* Interrupt_Number / 32 = number of ISER register (ISER0,...ISER7)
	 * Interrupt_Number % 32 = NUMBER of bit in the register i need to enable it
	 * */
	SET_BIT (NVIC -> ISER[Interrupt_Number / 32], (Interrupt_Number % 32));
}
/*******************************************************************************/
/* Api Name       : NVIC_DisableInterrupt                                     */
/* Parameters in  : Interrupt number                                          */
/* Parameters out :   void                                                   */
/* Description    :  this function disable interrupt preipheral by detecting
 *                   ICER register and it's pin in this peripheral  by using
 *                       two equation                                       */
/****************************************************************************/

void NVIC_DisableInterrupt (u8 Interrupt_Number)
{
	SET_BIT (NVIC -> ICER[Interrupt_Number / 32], (Interrupt_Number % 32));
}
/*******************************************************************************/
/* Api Name       : NVIC_SetPendingFlag                                       */
/* Parameters in  : Interrupt number                                          */
/* Parameters out :   void                                                   */
/* Description    :  this function set pending status interrupt preipheral by
 *                   detecting ISPR register and it's pin in this peripheral
 *                   by using  two equation                                  */
/****************************************************************************/

void NVIC_SetPendingFlag   (u8 Interrupt_Number)
{
	SET_BIT (NVIC -> ISPR[Interrupt_Number / 32], (Interrupt_Number % 32));
}
/*******************************************************************************/
/* Api Name       : NVIC_ClearPendingFlag                                      */
/* Parameters in  : Interrupt number                                          */
/* Parameters out :   void                                                   */
/* Description    :  this function clear pending status interrupt preipheral
 *                  by detecting ICPR register and it's pin in this peripheral
 *                   by using  two equation                                  */
/****************************************************************************/

void NVIC_ClearPendingFlag (u8 Interrupt_Number)
{
	SET_BIT (NVIC -> ICPR[Interrupt_Number / 32], (Interrupt_Number % 32));
}

/*******************************************************************************/
/* Api Name       : NVIC_GetInterruptState                                     */
/* Parameters in  : Interrupt number                                          */
/* Parameters out : u8 (return if interrupt is active or not                 */
/* Description    :  this function get interrupt  status  preipheral by reading
 *                   IAPR register and detecting it (iapr0 ...iapr7) and it's
 *                    pin in this register   by using  two equation          */
/****************************************************************************/

u8  NVIC_GetInterruptState (u8 Interrupt_Number)
{
	u8 Return_State = 0;
	Return_State = GET_BIT (NVIC ->IABR[Interrupt_Number / 32], (Interrupt_Number % 32));
	return  Return_State;
}
/*******************************************************************************/
/* Api Name       : NVIC_SetPriorityConfig                                     */
/* Parameters in  : priority                                                  */
/* Parameters out : void                                                     */
/* Description    : this function config priority to interrupt peripheral
 *                  by setting passward of  register AIRCR and put the
 *                  priority number in grouping bits priority               */
/****************************************************************************/

void  NVIC_SetPriorityConfig (u8 priority)
{
	/* to access this register we should enter his password  0xFA05 = vectkey
	 *
	*/
	u32 LocalTempReg = (AIRCR_VECTKEY << 16) |(priority << 8);
	SCB_AIRCR &= ( (AIRCR_VECTKEY << 16)  | ~(priority << 8));
	SCB_AIRCR  |= LocalTempReg;

	G_priorityGrouping = priority;
}
/**************************************************************************************/
/* Api Name       : NVIC_SetInterruptPriority                                        */
/* Parameters in  : interrupt_number , group_id, subgroub_id                        */
/* Parameters out : void                                                           */
/* Description    : this function set priority to interrupt peripheral in  IPR    */
/*                  register by detect group and sub group and put this priority */
/*                  in IPR pins from [4:7] pins                                 */
/*******************************************************************************/

void NVIC_SetInterruptPriority(u8 Interrupt_Number,u8 Group_Id,u8 Subgroub_Id)
{
	u8 localTemp = 0;
	/*
	switch(G_priorityGrouping)
	{
	   case NVIC_GROUB_4BIT_SUBGROUB_0BIT :localTemp|= (Group_Id << 4);
	         break;
	   case NVIC_GROUB_3BIT_SUBGROUB_1BIT :localTemp |= ((Group_Id << 5)|(Subgroub_Id << 1));
	        break;
	   case NVIC_GROUB_2BIT_SUBGROUB_2BIT :localTemp |=( (Group_Id << 6)|(Subgroub_Id << 2));
	         break;
	   case NVIC_GROUB_1BIT_SUBGROUB_3BIT :localTemp |= ((Group_Id << 7)| (Subgroub_Id << 3));
	        break;
	   case NVIC_GROUB_0BIT_SUBGROUB_4BIT :localTemp |= (Subgroub_Id << 4);
	        break;
	}
	*/
	localTemp = ((Group_Id << (7 - G_priorityGrouping )) | (Subgroub_Id << (G_priorityGrouping - 3)));

	NVIC ->IPR[Interrupt_Number] = localTemp;


}
