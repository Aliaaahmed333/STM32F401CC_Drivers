/*
 * NVIC_Private.h
 *
 *  Created on: ???/???/????
 *      Author: hp
 */

#ifndef NVIC_NVIC_PRIVATE_H_
#define NVIC_NVIC_PRIVATE_H_

#include "STD_Types.h"

#define   NVIC_BASEADDRESS     0xE000E100
#define   NVIC                 ((NVIC_RegMap_t *)NVIC_BASEADDRESS)
#define   SCB_AIRCR           *((volatile u32*) 0xE000ED0C)
#define   AIRCR_VECTKEY         0xFA05
/* define number of priority group and sub group*/





/* define registers of NVIC*/
  typedef struct
{
	u32 ISER[8+24];
	u32 ICER[8+24];
	u32 ISPR[8+24];
	u32 ICPR[8+24];
	u32 IABR[8+56];
	u8  IPR[60*4];
	
}NVIC_RegMap_t;



#endif /* NVIC_NVIC_PRIVATE_H_ */
