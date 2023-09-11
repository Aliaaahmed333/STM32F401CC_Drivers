


#include "../LIB/STD_Types.h"
#include "../LIB/BIT_MATH.h"
#include "GPIO_Interface.h"
#include "GPIO_Private.h"



/******************************************************************************
* Api Name       :   GPIO_SetPinDirection                                     *
* Parameters in  :   port_id  Mpin_num, direction                             *
* Parameters out :    void                                                    *
* Description    :  this function detect direction of pin (input ,output      *
*                :  analog, alternative fun ) by set direction mode in  pines *
*                :  that are detected to each pin                             *
*******************************************************************************/

void  GPIO_SetPinDirection (u8 Port_Id , u8 Pin_Num , u8 Dir)
{
	if (Port_Id > PORTH ||  Pin_Num > PIN15 || Dir > ANALOG_M)
		{
		    /*eror*/
		}
	else
	{
		switch(Port_Id)
			{
			   case PORTA : GPIOA -> MODER &= (~(0b11 << (Pin_Num*2)));
				            GPIOA -> MODER |= (Dir << (Pin_Num *2));
				             break;
			   case PORTB : GPIOB -> MODER &= (~(0b11 << (Pin_Num*2)));
			  		        GPIOB -> MODER |= (Dir << (Pin_Num *2));
			  		             break;
			   case PORTC : GPIOC -> MODER &= (~(0b11 << (Pin_Num*2)));
			  		        GPIOC -> MODER |= (Dir << (Pin_Num *2));
			  		             break;
			   case PORTD : GPIOD-> MODER &= (~(0b11 << (Pin_Num*2)));
			  		        GPIOD-> MODER |= (Dir << (Pin_Num *2));
			  		             break;
			   case PORTE : GPIOE -> MODER &= (~(0b11 << (Pin_Num*2)));
			  		        GPIOA -> MODER |= (Dir << (Pin_Num *2));
			  		             break;
			   case PORTH : GPIOA -> MODER &= (~(0b11 << (Pin_Num*2)));
			  		        GPIOA -> MODER |= (Dir << (Pin_Num *2));
			  		             break;
			   default : break;
			}
	}

}

/******************************************************************************
* Api Name       :    GPIO_SetInputState                                      *
* Parameters in  :    port_id,pin_num,inputState                              *
* Parameters out :    void                                                    *
* Description    :    this api set input state                                *
*******************************************************************************/
void GPIO_SetInputState (u8 port_Id, u8 Pin_Num, u8 inputState)
{
	if (port_Id > PORTH || Pin_Num > PIN15 || inputState > PullDown)
	{
	    /*eror*/
	}
	else
	{
		switch (port_Id)
			{
				   case PORTA : GPIOA -> PUPDR &= (~(0b11 << (Pin_Num*2)));
					            GPIOA -> PUPDR |= (inputState << (Pin_Num *2));
					             break;
				   case PORTB : GPIOB -> PUPDR &= (~(0b11 << (Pin_Num*2)));
				  		        GPIOB -> PUPDR |= (inputState << (Pin_Num *2));
				  		             break;
				   case PORTC : GPIOC -> PUPDR &= (~(0b11 << (Pin_Num*2)));
				  		        GPIOC -> PUPDR |= (inputState << (Pin_Num *2));
				  		             break;
				   case PORTD : GPIOD-> PUPDR &= (~(0b11 << (Pin_Num*2)));
				  		        GPIOD-> PUPDR |= (inputState << (Pin_Num *2));
				  		             break;
				   case PORTE : GPIOE -> PUPDR &= (~(0b11 << (Pin_Num*2)));
				  		        GPIOA -> PUPDR |= (inputState << (Pin_Num *2));
				  		             break;
				   case PORTH : GPIOA -> PUPDR &= (~(0b11 << (Pin_Num*2)));
				  		        GPIOA -> PUPDR |= (inputState << (Pin_Num *2));
				  		             break;
				   default : break;
				}

	}

}
/**********************************************************************************
* Api Name       :  GPIO_SetAlternativeFunction                                   *
* Parameters in  :  port_id,pin_num,  AlternativeNum                              *
* Parameters out :  void                                                          *
* Description    :  this api set right alternative fun in right register by       *
*                   checking number of pin if pin <= pin7 it will be low register *
*                   else it will be in high reg every pin has for bit to set      *
*                   it's alternative fun so we have 2 registers high,low          *
*********************************************************************************/
void GPIO_SetAlternativeFunction (u8 Port_Id, u8 Pin_Num, u8 AlternativeNum)
{
	if (Port_Id > PORTH || Pin_Num > PIN15 || AlternativeNum > AF15)
			{
			    /*eror*/
			}
    else
	{
		if (Pin_Num <= PIN7)
		{
			switch (Port_Id)
			{
				 case PORTA: GPIOA->AFRL &= (~(0b1111 << ( Pin_Num * 4)));
				             GPIOA->AFRL |= (AlternativeNum << (Pin_Num * 4));
				             break;
				 case PORTB: GPIOB->AFRL &= (~(0b1111 << ( Pin_Num * 4)));
		                     GPIOB->AFRL |= (AlternativeNum << (Pin_Num * 4));
		                     break;
				 case PORTC: GPIOC->AFRL &= (~(0b1111 << ( Pin_Num * 4)));
                             GPIOC->AFRL |= (AlternativeNum << (Pin_Num * 4));
                             break;
			      case PORTD: GPIOD->AFRL &= (~(0b1111 << ( Pin_Num * 4)));
                              GPIOD->AFRL |= (AlternativeNum << (Pin_Num * 4));
                              break;
				  case PORTE: GPIOE->AFRL &= (~(0b1111 << ( Pin_Num * 4)));
                              GPIOE->AFRL |= (AlternativeNum << (Pin_Num * 4));
                              break;
				  case PORTH: GPIOH->AFRL &= (~(0b1111 << ( Pin_Num * 4)));
                              GPIOH->AFRL |= (AlternativeNum << (Pin_Num * 4));
                              break;

				}
		}
			else
			{
				switch (Port_Id)
				 {
				   case PORTA: GPIOA->AFRH &= (~(0b1111 << ( (Pin_Num %8) * 4)));
							   GPIOA->AFRH |= (AlternativeNum << ((Pin_Num %8) * 4));
								             break;
				   case PORTB: GPIOB->AFRH &= (~(0b1111 << ( (Pin_Num %8) * 4)));
						       GPIOB->AFRH |= (AlternativeNum << ((Pin_Num %8) * 4));
						       break;
				   case PORTC: GPIOC->AFRH &= (~(0b1111 << ( (Pin_Num %8) * 4)));
				                GPIOC->AFRH |= (AlternativeNum << ((Pin_Num %8) * 4));
				                             break;
				    case PORTD: GPIOD->AFRH &= (~(0b1111 << ( (Pin_Num %8) * 4)));
				                GPIOD->AFRH |= (AlternativeNum << ((Pin_Num %8) * 4));
				                break;
				    case PORTE: GPIOE->AFRH &= (~(0b1111 << ( (Pin_Num %8) * 4)));
				                GPIOE->AFRH |= (AlternativeNum << ((Pin_Num %8) * 4));
				                break;
			        case PORTH: GPIOH->AFRH &= (~(0b1111 << ( (Pin_Num %8) * 4)));
				                GPIOH->AFRH |= (AlternativeNum << ((Pin_Num %8) * 4));
				                break;

				}
			}

		}

}
/**************************************************************************
* Api Name       : GPIO_WritePin                                          *
* Parameters in  : port_id,pin_num,state                                  *
* Parameters out :  void                                                  *
* Description    :  this api write on pin state high or low               *
**************************************************************************/
void  GPIO_WritePin  (u8 port_Id, u8 Pin_Num , u8 OutputState)
{
	if (port_Id > PORTH || Pin_Num > PIN15 || OutputState > PullDown)
		{
		    /*eror*/
		}
	else
	{
		switch (port_Id)
			{
			    case PORTA : if (OutputState == HIGH) SET_BIT(GPIOA -> ODR , Pin_Num);
			                else                      CLR_BIT(GPIOA -> ODR , Pin_Num);
			                break;
			    case PORTB : if (OutputState == HIGH) SET_BIT(GPIOB -> ODR , Pin_Num);
			    	                else              CLR_BIT(GPIOB -> ODR , Pin_Num);
			    	                break;
			    case PORTC : if (OutputState == HIGH) SET_BIT(GPIOC -> ODR , Pin_Num);
			    	                else        CLR_BIT(GPIOC -> ODR , Pin_Num);
			    	                break;
			    case PORTD : if (OutputState == HIGH) SET_BIT(GPIOD -> ODR , Pin_Num);
			    	                else              CLR_BIT(GPIOD -> ODR , Pin_Num);
			    	                break;
			    case PORTE : if (OutputState == HIGH) SET_BIT(GPIOE -> ODR , Pin_Num);
			    	                else               CLR_BIT(GPIOE -> ODR , Pin_Num);
			    	                break;
			    case PORTH : if (OutputState == HIGH) SET_BIT(GPIOH -> ODR , Pin_Num);
			    	                else              CLR_BIT(GPIOH -> ODR , Pin_Num);
			    	                break;

			}
	}


}

void GPIO_WritePort (u8 Port_Id ,u32 Value )
{
	if (Port_Id > PORTH)
	{
		/* error */
	}
	else
	{
		 switch (Port_Id)
		    {
				 case PORTA : GPIOA ->ODR =  Value; break;

				 case PORTB : GPIOB ->ODR =  Value; break;

				 case PORTC : GPIOC ->ODR =  Value; break;

				 case PORTD : GPIOD ->ODR =  Value; break;

				 case PORTE : GPIOE ->ODR =  Value; break;

				 case PORTH : GPIOH ->ODR =  Value; break;
				 default : break;
	   }
	}

}

/***********************************************************************************
* Api Name       :  GPIO_GetPin_NumValue                                           *
* Parameters in  :  port_Id_id  , Pin_Num_num                                      *
* Parameters out :  u8 (return_val)                                                *
* Description    :  get Pin_Num value in a specific port_Id  and return it's value *
***********************************************************************************/

u8 GPIO_GetPinValue  (u8 port_Id , u8 Pin_Num)
{

  if(port_Id > PORTH || Pin_Num > PIN15)
  {
	  /* error */
  }
  else
  {
	  u8 return_val;
	   switch (port_Id)
	   {
	       case PORTA: return_val = GET_BIT(GPIOA -> IDR,Pin_Num); break;
	       case PORTB: return_val = GET_BIT(GPIOB -> IDR,Pin_Num); break;
	       case PORTC: return_val = GET_BIT(GPIOC -> IDR,Pin_Num); break;
	       case PORTD: return_val = GET_BIT(GPIOD -> IDR,Pin_Num); break;
	       case PORTE: return_val = GET_BIT(GPIOE -> IDR,Pin_Num); break;
	       case PORTH: return_val = GET_BIT(GPIOH -> IDR,Pin_Num); break;
	       default : break;
	   }
	 return  return_val ;
  }

}

