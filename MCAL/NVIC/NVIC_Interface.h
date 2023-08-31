/*
 * NVIC_Interface.h
 *
 *  Created on: 14/8/2023
 *  Author: Aliaa Ahmed
 */

#ifndef NVIC_NVIC_INTERFACE_H_
#define NVIC_NVIC_INTERFACE_H_

#include "STD_Types.h"

#define  NVIC_GROUB_4BIT_SUBGROUB_0BIT     0b011
#define  NVIC_GROUB_3BIT_SUBGROUB_1BIT     0b100
#define  NVIC_GROUB_2BIT_SUBGROUB_2BIT     0b101
#define  NVIC_GROUB_1BIT_SUBGROUB_3BIT     0b110
#define  NVIC_GROUB_0BIT_SUBGROUB_4BIT     0b111

/*********************************************************************************/
/* Api Name       :  NVIC_EnableInterrupt                                     */
/* Parameters in  :  Interrupt nuber                                          */
/* Parameters out :   void                                                   */
/* Description    :  this function enable interrupt preipheral by detecting
 *                   ISER register and it's pen in this peripheral by using
 *                     two equation                                          */
/****************************************************************************/
void NVIC_EnableInterrupt  (u8 Interrupt_Number);
/*******************************************************************************/
/* Api Name       : NVIC_DisableInterrupt                                     */
/* Parameters in  : Interrupt number                                          */
/* Parameters out :   void                                                   */
/* Description    :  this function disable interrupt preipheral by detecting
 *                   ICER register and it's pin in this peripheral  by using
 *                       two equation                                       */
/****************************************************************************/
void NVIC_DisableInterrupt (u8 Interrupt_Number);
/*******************************************************************************/
/* Api Name       : NVIC_SetPendingFlag                                       */
/* Parameters in  : Interrupt number                                          */
/* Parameters out :   void                                                   */
/* Description    :  this function set pending status interrupt preipheral by
 *                   detecting ISPR register and it's pin in this peripheral
 *                   by using  two equation                                  */
/****************************************************************************/

void NVIC_SetPendingFlag   (u8 Interrupt_Number);
/*******************************************************************************/
/* Api Name       : NVIC_ClearPendingFlag                                      */
/* Parameters in  : Interrupt number                                          */
/* Parameters out :   void                                                   */
/* Description    :  this function clear pending status interrupt preipheral
 *                  by detecting ICPR register and it's pin in this peripheral
 *                   by using  two equation                                  */
/****************************************************************************/

void NVIC_ClearPendingFlag (u8 Interrupt_Number);
/*******************************************************************************/
/* Api Name       : NVIC_SetPriorityConfig                                     */
/* Parameters in  : priority                                                  */
/* Parameters out : void                                                     */
/* Description    : this function config priority to interrupt peripheral
 *                  by setting passward of  register AIRCR and put the
 *                  priority number in grouping bits priority               */
/****************************************************************************/
u8  NVIC_GetInterruptState (u8 Interrupt_Number);

void NVIC_SetPriority (u8 Interrupt_Number , u8 priority);
/*******************************************************************************/
/* Api Name       : NVIC_SetPriorityConfig                                     */
/* Parameters in  : priority                                                  */
/* Parameters out : void                                                     */
/* Description    : this function config priority to interrupt peripheral
 *                  by setting passward of  register AIRCR and put the
 *                  priority number in grouping bits priority               */
void NVIC_SetPriorityConfig (u8 priority);
/**************************************************************************************/
/* Api Name       : NVIC_SetInterruptPriority                                        */
/* Parameters in  : interrupt_number , group_id, subgroub_id                        */
/* Parameters out : void                                                           */
/* Description    : this function set priority to interrupt peripheral in  IPR    */
/*                  register by detect group and sub group and put this priority */
/*                  in IPR pins from [4:7] pins                                 */
/*******************************************************************************/
void NVIC_SetInterruptPriority(u8 Interrupt_Num,u8 Group_Id,u8 Subgroub_Id);








#endif /* NVIC_NVIC_INTERFACE_H_ */
