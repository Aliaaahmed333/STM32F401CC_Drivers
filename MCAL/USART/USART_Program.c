/*
 * USART_Program.c
 *
 *  Created on: 23/8/2023
 *      Author:aliaa
 */


#include "../LIB/STD_Types.h"
#include "../LIB/BIT_MATH.h"
#include "../RCC/RCC_Interface.h"
#include "../GPIO/GPIO_Interface.h"
#include "USART_Interface.h"
#include "USART_Private.h"
#include "USART_Config.h"

/**********************************************************************************
* Api Name       :  USART1_Init                                                   *
* Parameters in  :  void                                                          *
* Parameters out :  void                                                          *
* Description    : this api int usart peripheral by check if usart_used is(usart1,*
*                  usart2,usart6) and enable rcc for each usart peripheral and    *
*                 then put DIV Value in BRR register ,enable tx,rx,usart_enable   *
**********************************************************************************/



void USART_Init(void)
{
	/* calculate value that should be in BRR register for any usart periphrral */
	 f32 DIV_Mantissa = 0;
	 f32 DIV_Fraction = 0;
	 f32 LocalUsartDIV = 0;
	/* Calculate Constant Equation from USART DataSheet*/
	 LocalUsartDIV  = (((f32)USART_CLK)/(8*(2 -OVERDATA_SAMPLE) * (BAUDRATE)));
	 /*save mantissa value in local var*/
	 DIV_Mantissa = (u32) LocalUsartDIV ;
	 /*save fraction value in local var*/
	 DIV_Fraction =  LocalUsartDIV  -  DIV_Mantissa;
	 /* checking for fraction value to put right value in BRR reg*/
	 if ( DIV_Fraction >= 0.97)
	 {
		 DIV_Mantissa++;
		 DIV_Fraction = 0;
	 }
	 else
	 {
		 /* number we need to multiply on it depend on if used 16 sample on date or 8 sample
		  * and this depond on over8 bit in CR reg */
		 DIV_Fraction *=  (8*(2 -OVERDATA_SAMPLE));
	 }
	 /* after multiply div fraction we check to put neerest value for it */
	 if  ( DIV_Fraction != 0.00 && ((DIV_Fraction - (u32)DIV_Fraction) >= 0,5))
	 {
		 DIV_Fraction = ((u32)DIV_Fraction);
		 DIV_Fraction++;

	 }
	 else if (DIV_Fraction != 0.00 && ((DIV_Fraction - (u32)DIV_Fraction) < 0,5))
	 {
		 DIV_Fraction = ((u32)DIV_Fraction);
	 }

/* check what is usart peripheral is used */
     #if (USART_USED == USART_1)

	   /* config RCC CLK for usart1 , GPIOA  */
	   RCC_voidEnablePeripheral(APB2,USART1EN);
	   RCC_voidEnablePeripheral(AHB1,GPIOA_EN);
	   /*  end confog of RCC CLK peripheral */

	   /* config pins of tx(PIN9) , rx(PIN10)  for usart1 by set their alternative num*/
	   GPIO_SetPinDirection(PORTA,PIN9,ALTERNATIVE_M);
	   GPIO_SetPinDirection(PORTA,PIN10,ALTERNATIVE_M);
	   GPIO_SetAlternativeFunction(PORTA,PIN9,AF7);
	   GPIO_SetAlternativeFunction(PORTA,PIN10,AF7);
	   /*   END Config of pins  */

	   /*config of usart1 reg */
       USART1->USART_BRR= ((u32)DIV_Mantissa << 4 |(u32) DIV_Fraction);
       /* enable usart pins rx,tx, enable peripheral */
	   	SET_BIT(USART1->USART_CR1 , UE);
	   	SET_BIT(USART1->USART_CR1 , TE);
	   	SET_BIT(USART1->USART_CR1 , RE);
	   	/* define number of stop bits , number of data samble , number of data bit(9bit or 8 bit*/
	   	CLR_BIT(USART1->USART_CR1, OVER8);
	   	CLR_BIT(USART1->USART_CR1, M);
	   	CLR_BIT(USART1->USART_CR2, STOP0);
	   	CLR_BIT(USART1->USART_CR2, STOP1);

#elif USART_USED == USART_2

	    /* config RCC CLK for usart1 */
	  	   RCC_voidEnablePeripheral(APB1,USART2EN);
	    USART2->USART_BRR= ((u32)DIV_Mantissa << 4 |(u32) DIV_Fraction);

	  	   	SET_BIT(USART2->USART_CR1 , UE);
	  	   	SET_BIT(USART2->USART_CR1 , TE);
	  	   	SET_BIT(USART2->USART_CR1 , RE);
	  	   	CLR_BIT(USART2->USART_CR1, OVER8);
	  	   	CLR_BIT(USART2->USART_CR1, M);
	  	   	CLR_BIT(USART2->USART_CR2, STOP0);
	  	   	CLR_BIT(USART2->USART_CR2, STOP1);

#elif USART_USED == USART_6
	  	  /* config RCC CLK for usart1 */
	      RCC_voidEnablePeripheral(APB2,USART6EN);
	      USART6->USART_BRR= ((u32)DIV_Mantissa << 4 |(u32) DIV_Fraction);

	  	   	SET_BIT(USART6->USART_CR1 , UE);
	  	   	SET_BIT(USART6->USART_CR1 , TE);
	  	   	SET_BIT(USART6->USART_CR1 , RE);
	  	   	CLR_BIT(USART6->USART_CR1, OVER8);
	  	   	CLR_BIT(USART6->USART_CR1, M);
	  	   	CLR_BIT(USART6->USART_CR2, STOP0);
	  	   	CLR_BIT(USART6->USART_CR2, STOP1);

#endif

}
/**********************************************************************************
* Api Name       : USART1_SendData                                                *
* Parameters in  :  data                                                          *
* Parameters out :  void                                                          *
* Description    : this api send data to usart DR_Register and stuck in loop      *
*                  to sure that transmission of data complete                     *
**********************************************************************************/

void USART_SendData(u8 data)
{
#if USART_USED == USART_1
    	 USART1->USART_DR =  data;
    	 while (GET_BIT(USART1->USART_SR,TC) == 0);

#elif USART_USED == USART_2
    	 USART2->USART_DR =  data;
    	 while (GET_BIT(USART2->USART_SR,TC) == 0);
#elif  USART_USED == USART_6
    	 USART6->USART_DR =  data;
    	 while (GET_BIT(USART6->USART_SR,TC) == 0);
#endif
}

/**********************************************************************************
* Api Name       : USART1_SendData                                                *
* Parameters in  :  data                                                          *
* Parameters out :  void                                                          *
* Description    : this api send string to usart DR_Register and wait in loop     *
*                  untill transmission of string complete                         *
**********************************************************************************/

void USART_SendString(char* data )
{
    u8 i = 0;
    while (data[i] != '\0')
    {
       #if( USART_USED == USART_1)
    	   USART1->USART_DR =  data[i];
    	   while (GET_BIT(USART1->USART_SR,TC) == 0);
      #elif (USART_USED == USART_2)
    	     USART2->USART_DR =  data[i];
    	     while (GET_BIT(USART2->USART_SR,TC) == 0);
      #elif  (USART_USED == USART_6)
    	     USART6->USART_DR =  data[i];
    	     while (GET_BIT(USART6->USART_SR,TC) == 0);
     #endif
    	i++;
    }
}
/**********************************************************************************
* Api Name       : USART1_ReciveData                                              *
* Parameters in  : *data                                                          *
* Parameters out :  void                                                          *
* Description    : this api recive data from usart DR_Register and wait in loop   *
*                  untill recive of data complete                                 *
**********************************************************************************/
void  USART_ReciveData(u8* data)
{
#if( USART_USED == USART_1)
	 while (GET_BIT(USART1->USART_SR,RXNE) == 0);
	 * data =  USART1->USART_DR ;
#elif (USART_USED == USART_2)
	   while (GET_BIT(USART2->USART_SR,RXNE) == 0);
	   * data =  USART2->USART_DR ;
#elif (USART_USED == USART_6)
	   while (GET_BIT(USART6->USART_SR,RXNE) == 0);
	   * data =  USART6->USART_DR ;
#endif
}
