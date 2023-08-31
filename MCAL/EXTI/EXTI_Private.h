/*
 * EXTI_Private.h
 *
 *  Created on: 15/8/2023
 *      Author: aliaa ahmed
 */

#ifndef EXTI_EXTI_PRIVATE_H_
#define EXTI_EXTI_PRIVATE_H_

#define  EXTI_BASEADDRESS      0x40010400
#define  EXTI                  ((EXTI_MemMap_t*)EXTI_BASEADDRESS)
#define  SYSCFG_EXTICR3        *((volatile u32 *)0x40013810)
typedef struct
{
	Vu32 IMR;
	Vu32 EMR;
	Vu32 RTSR;
	Vu32 FTSR;
	Vu32 SWIER;
	Vu32 PR;
}EXTI_MemMap_t;


#endif /* EXTI_EXTI_PRIVATE_H_ */
