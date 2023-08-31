/*
 * EXTI_Interface.h
 *
 *  Created on: 15/8/2023
 *      Author: aliaa ahmed
 */

#ifndef EXTI_EXTI_INTERFACE_H_
#define EXTI_EXTI_INTERFACE_H_

#define NULL  0
 typedef enum
 {
	 MASK,
	 NOTMASK
 }Interrupt_Status_t;

 typedef enum
 {
	 FallingEdge,
	 RisingEdge,
	 FallingAndRising

 }Interrupt_Trigger_t;

typedef enum
{
	EXTI_LIN0 ,
	EXTI_LIN1,
	EXTI_LIN2,
	EXTI_LIN3,
	EXTI_LIN4,
	EXTI_LIN9_5 ,
	EXTI_LIN15_10
}EXTI_LINES_t ;

/*********************************************************************************/
/* Api Name       :  EXTI_InterruptStatus                                       */
/* Parameters in  :  EXTINumber , EXTIStatus                                   */
/* Parameters out : u8 (error or no error)                                    */
/* Description    : this function mask detect status of interrupt mask or not
/****************************************************************************/

u8 EXTI_InterruptStatus(u8 EXTINumber , u8 EXTIStatus);
/*********************************************************************************/
/* Api Name       :  EXTI_SetInterruptEdge                                      */
/* Parameters in  :  EXTINumber , EXTIEdge                                     */
/* Parameters out : u8 (error or no error)                                    */
/* Description    : this function  detect trigger edge when interrupt happen
/****************************************************************************/
u8 EXTI_SetInterruptEdge(u8 EXTINumber , u8 EXTIEdge);
/*********************************************************************************/
/* Api Name       : EXTI_ClearInterruptPending                                   */
/* Parameters in  :  EXTINumber                                                 */
/* Parameters out : u8 (error or no error)                                    */
/* Description    : this function clear pending of interrupt when interrupt
/*                  execute  to prevent interrupt stay in while loop by set
/*                   bit in PR register
/****************************************************************************/
u8 EXTI_ClearInterruptPending (u8 EXTINumber);
/*********************************************************************************/
/* Api Name       : EXTI_IsInterruptActive                                      */
/* Parameters in  : EXTINumber                                                 */
/* Parameters out : u8 (error or no error)                                    */
/* Description    : this function check if interrupt is active or not and
/*                   it's value from register PR
/****************************************************************************/

u8 EXTI_IsInterruptActive (u8 EXTINumber);


void EXTI_ChangeEXTISource (u8 EXTINumber , u8 port_id);
/**********************************************************************************/
/* Api Name       : EXTI_SetInterruptCallback                                      */
/* Parameters in  : EXTINumber  , pointer to function of ISR handler              */
/* Parameters out : u8 (error or no error)                                       */
/* Description    : this function check which  external interrupt line is active */
/*                  and excute ISR Handler of this interrupt by using pointer   */
/*                    to function points to ISR handler of this interrupt      */
/*******************************************************************************/

u8 EXTI_SetInterruptCallback (u8 EXTINumber , void (*PCallbackFunc) (void));

#endif /* EXTI_EXTI_INTERFACE_H_ */
