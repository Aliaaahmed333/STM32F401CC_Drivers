/*
 * EXTI_Program.c
 *
 *  Created on: 15/8/2023
 *      Author: aliaa ahmed
 */


#include "STD_Types.h"
#include "BIT_Math.h"
#include "EXTI_Private.h"
#include "EXTI_Interface.h"
#include "../GPIO/GPIO_Interface.h"

/* pointer to function take void and return void*/
 typedef void(*Fptr)(void) ;
 /* define array[12] element of pointer to function  and inilize them = null*/
 static  Fptr Global_FptrArray[12] = {NULL};
 /*********************************************************************************/
 /* Api Name       :  EXTI_InterruptStatus                                       */
 /* Parameters in  :  EXTINumber , EXTIStatus                                   */
 /* Parameters out : u8 (error or no error)                                    */
 /* Description    : this function mask detect status of interrupt mask or not
 /****************************************************************************/
u8 EXTI_InterruptStatus(u8 EXTINumber , u8 EXTIStatus)
{


	if (EXTINumber >22 ||EXTIStatus )
	{
		return Error ;
	}
	else
	{
		if (EXTIStatus == MASK)
		  {
				CLR_BIT(EXTI->IMR , EXTINumber);
			}
			else
			{
				SET_BIT(EXTI -> IMR , EXTINumber);

			}
		return NOERROR;
	}


}
/*********************************************************************************/
/* Api Name       :  EXTI_SetInterruptEdge                                      */
/* Parameters in  :  EXTINumber , EXTIEdge                                     */
/* Parameters out : u8 (error or no error)                                    */
/* Description    : this function  detect trigger edge when interrupt happen
/****************************************************************************/

u8 EXTI_SetInterruptEdge(u8 EXTINumber , u8 EXTIEdge)
{
      if (EXTINumber > 22 || EXTIEdge > FallingAndRising)
      {
    	  return Error;
      }
      else
      {
    	  if ( EXTIEdge == FallingEdge)
    	  {
    		  SET_BIT ( EXTI ->FTSR,EXTINumber);
    		  CLR_BIT (EXTI ->RTSR,EXTINumber);
    	  }
    	  else if (EXTIEdge ==  RisingEdge)
    	  {
    		  SET_BIT (EXTI -> RTSR,EXTINumber);
    		  CLR_BIT (EXTI -> FTSR,EXTINumber);
    	  }
    	  else
    	  {
    		  SET_BIT (EXTI -> RTSR,EXTINumber);
    		  SET_BIT ( EXTI ->FTSR,EXTINumber);
    	  }
    	  return NOERROR;
      }
}
/*********************************************************************************/
/* Api Name       : EXTI_ClearInterruptPending                                   */
/* Parameters in  :  EXTINumber                                                 */
/* Parameters out : u8 (error or no error)                                    */
/* Description    : this function clear pending of interrupt when interrupt
/*                  execute  to prevent interrupt stay in while loop by set
/*                   bit in PR register
/****************************************************************************/
u8 EXTI_ClearInterruptPending (u8 EXTINumber)
{

	 if (EXTINumber > 22 )
	  {
	      return Error;
	  }
	 else
	 {
		 SRT_BIT(EXTI ->PR , EXTINumber);
		 return NOERROR;
	 }

}
/*********************************************************************************/
/* Api Name       : EXTI_IsInterruptActive                                      */
/* Parameters in  : EXTINumber                                                 */
/* Parameters out : u8 (error or no error)                                    */
/* Description    : this function check if interrupt is active or not and
/*                   it's value from register PR
/****************************************************************************/

u8 EXTI_IsInterruptActive (u8 EXTINumber)
{
	if (EXTINumber > 22 )
	 {
		      return Error;
	 }
	else
	{
		return (GET_BIT(EXTI ->PR ,EXTINumber ));
	}
}

void EXTI_ChangeEXTISource (u8 EXTINumber , u8 port_id)
{
	if (EXTINumber == EXTI_LIN0 )
	{
		if (port_id == PORTB)
		{
			 SYSCFG_EXTICR3 |= PORTB;
		}
		else if (port_id == PORTC)
		{
			 SYSCFG_EXTICR3 |= PORTC;
		}
	}
	else if (EXTINumber == EXTI_LIN1 )
	{
		if (port_id == PORTA)
		{
			 SYSCFG_EXTICR3 |= (PORTA << 4);
		}
		else if (port_id == PORTB)
		 {
			 SYSCFG_EXTICR3 |= (PORTB << 4);
		 }
		else if (port_id == PORTC)
		{
			SYSCFG_EXTICR3 |= (PORTC << 4);
		}
	}

	else if (EXTINumber == EXTI_LIN2 )
	{
		if (port_id == PORTA)
		{
			 SYSCFG_EXTICR3 |= (PORTA << 8);
		}
		else if (port_id == PORTB)
		 {
			 SYSCFG_EXTICR3 |= (PORTB << 8);
		 }
		else if (port_id == PORTC)
		{
			SYSCFG_EXTICR3 |= (PORTC << 8);
		}
	}
	else if (EXTINumber == EXTI_LIN3 )
	{
		if (port_id == PORTA)
		{
			 SYSCFG_EXTICR3 |= (PORTA << 12);
		}
		else if (port_id == PORTB)
		 {
			 SYSCFG_EXTICR3 |= (PORTB << 12);
		 }
		else if (port_id == PORTC)
		{
			SYSCFG_EXTICR3 |= (PORTC << 12);
		}
	}


}

/*********************************************************************************/
/* Api Name       : EXTI0_IRQHandler                                            */
/* Parameters in  : void                                                        */
/* Parameters out : void                                                       */
/* Description    : this function execute ISR of EXTI0 line
/****************************************************************************/

void EXTI0_IRQHandler(void)
{
	// to disable interrupt to execute it one time in it's edge
      SET_BIT(EXTI->PR , EXTI_LIN0);
      if (Global_FptrArray[0] != NULL)
      {
    	  Global_FptrArray[EXTI_LIN0]();
      }
      else
      {
    	  /* do nothing*/
      }
}
/*********************************************************************************/
/* Api Name       : EXTI1_IRQHandler                                            */
/* Parameters in  : void                                                        */
/* Parameters out : void                                                       */
/* Description    : this function execute ISR of EXTI1 line
/****************************************************************************/
void EXTI1_IRQHandler(void)
{
	// to disable interrupt to execute it one time in it's edge
      SET_BIT(EXTI->PR , EXTI_LIN1);
      if (Global_FptrArray[EXTI_LIN1] != NULL)
      {
    	  Global_FptrArray[EXTI_LIN1]();
      }
      else
      {
    	  /* do nothing*/
      }
}
/*********************************************************************************/
/* Api Name       : EXTI2_IRQHandler                                            */
/* Parameters in  : void                                                        */
/* Parameters out : void                                                       */
/* Description    : this function execute ISR of EXTI2 line
/****************************************************************************/
void EXTI2_IRQHandler(void)
{
      SET_BIT(EXTI->PR , EXTI_LIN2);
      if (Global_FptrArray[EXTI_LIN2] != NULL)
      {
    	  Global_FptrArray[EXTI_LIN2]();
      }
      else
      {
    	  /* do nothing*/
      }
}
/*********************************************************************************/
/* Api Name       : EXTI3_IRQHandler                                            */
/* Parameters in  : void                                                        */
/* Parameters out : void                                                       */
/* Description    : this function execute ISR of EXTI3 line
/****************************************************************************/
void EXTI3_IRQHandler(void)
{
      SET_BIT(EXTI->PR , EXTI_LIN3);
      if (Global_FptrArray[EXTI_LIN3] != NULL)
      {
    	  Global_FptrArray[EXTI_LIN3]();
      }
      else
      {
    	  /* do nothing*/
      }
}
/*********************************************************************************/
/* Api Name       : EXTI4_IRQHandler                                            */
/* Parameters in  : void                                                        */
/* Parameters out : void                                                       */
/* Description    : this function execute ISR of EXTI4 line
/****************************************************************************/
void EXTI4_IRQHandler(void)
{
      SET_BIT(EXTI->PR , EXTI_LIN4);
      if (Global_FptrArray[EXTI_LIN4] != NULL)
      {
    	  Global_FptrArray[EXTI_LIN4]();
      }
      else
      {
    	  /* do nothing*/
      }
}
/*********************************************************************************/
/* Api Name       : EXTI9_5_IRQHandler                                           */
/* Parameters in  : void                                                        */
/* Parameters out : void                                                       */
/* Description    : this function execute ISR of EXTI9_5 line  and check which
/*                  external line is pending
/*
/****************************************************************************/
void EXTI9_5_IRQHandler(void)
{
	// to disable pins external interrupt line in PR reg
	EXTI ->PR |= (0b11111 << 5);
	   if (Global_FptrArray[EXTI_LIN9_5] != NULL)
	      {
	    	  Global_FptrArray[EXTI_LIN9_5]();
	      }
	      else
	      {
	    	  /* do nothing*/
	      }
}
/*********************************************************************************/
/* Api Name       : EXTI15_10_IRQHandler                                         */
/* Parameters in  : void                                                        */
/* Parameters out : void                                                       */
/* Description    : this function execute ISR of EXTI15_10 line  and check which
/*                  external interrupt is active  and  disable this pin
/*
/****************************************************************************/
void EXTI15_10_IRQHandler(void)
{
  if (GET_BIT(EXTI->PR ,10) == 1)
  {
	  SET_BIT(EXTI -> PR , 10);
  }
  if (GET_BIT(EXTI->PR ,11) == 1)
  {
	  SET_BIT(EXTI -> PR , 11);
  }
  if (GET_BIT(EXTI->PR ,12) == 1)
    {
  	  SET_BIT(EXTI -> PR , 12);
    }
  if (GET_BIT(EXTI->PR ,13) == 1)
    {
  	  SET_BIT(EXTI -> PR , 13);
    }
  if (GET_BIT(EXTI->PR ,14) == 1)
    {
  	  SET_BIT(EXTI -> PR , 14);
    }
  if (GET_BIT(EXTI->PR ,15) == 1)
    {
  	  SET_BIT(EXTI -> PR , 15);
    }
  if (Global_FptrArray[EXTI_LIN15_10] != NULL)
  	 {
  	    Global_FptrArray[EXTI_LIN15_10]();
  	 }
   else
  	  {
  	    	  // do nothing
  	  }
	/*
	EXTI ->PR |= (0b11111 << 10);
	   if (Global_FptrArray[EXTI_LIN15_10] != NULL)
	      {
	    	  Global_FptrArray[EXTI_LIN15_10]();
	      }
	      else
	      {
	    	  // do nothing
	      }
     */
}
/**********************************************************************************/
/* Api Name       : EXTI_SetInterruptCallback                                      */
/* Parameters in  : EXTINumber  , pointer to function of ISR handler              */
/* Parameters out : u8 (error or no error)                                       */
/* Description    : this function check which  external interrupt line is active */
/*                  and excute ISR Handler of this interrupt by using pointer   */
/*                    to function points to ISR handler of this interrupt      */
/*******************************************************************************/
u8 EXTI_SetInterruptCallback (u8 EXTINumber , void (*PCallbackFunc) (void))
{
	if (EXTINumber > 22 )
	{
		Error;
	}
	else
	{
		 if (EXTINumber >= EXTI_LIN0 && EXTINumber < EXTI_LIN9_5)
		    {
		    	Global_FptrArray[EXTINumber] = PCallbackFunc;
		    }
		    else if (EXTINumber >= EXTI_LIN9_5 && EXTINumber < EXTI_LIN15_10)
		    {
		    	Global_FptrArray[EXTI_LIN9_5] = PCallbackFunc;
		    }
		    else if (EXTINumber >= EXTI_LIN15_10 && EXTINumber < 16)
		    {
		       Global_FptrArray[EXTI_LIN15_10] = PCallbackFunc;
		    }
		    else if (EXTINumber == 16)
		    {
		    	  Global_FptrArray[7] = PCallbackFunc;
		    }
		    else if (EXTINumber == 17)
		     {
		       	  Global_FptrArray[8] = PCallbackFunc;
		     }
		    else if (EXTINumber == 18)
		    {
		       	  Global_FptrArray[9] = PCallbackFunc;
		    }
		    else if (EXTINumber == 21)
		       {
		       	  Global_FptrArray[10] = PCallbackFunc;
		       }
		    else
		       {
		       	  Global_FptrArray[11] = PCallbackFunc;
		       }
		 return NOERROR;
	}

}

