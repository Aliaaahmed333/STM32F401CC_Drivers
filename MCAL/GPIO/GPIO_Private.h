/* Author  : Aliaa Ahmed                                                    */
/* Date    : 12/8/2023                                                      */
/* Version : V 1.0                                                          */
/* Description : GPIO_Private                                                       */
/****************************************************************************/



#ifndef  GPIO_PRIVATE_H_
#define  GPIO_PRIVATE_H_



#include "STD_Types.h"



#define    GPIOA_BASE_ADDRESS     0x40020000
#define    GPIOB_BASE_ADDRESS     0x40020400
#define    GPIOC_BASE_ADDRESS     0x40020800
#define    GPIOD_BASE_ADDRESS     0x40020C00
#define    GPIOE_BASE_ADDRESS     0x40021000
#define    GPIOH_BASE_ADDRESS     0x40021C00


#define    GPIOA     ((volatile GPIO_MemMap_t*)GPIOA_BASE_ADDRESS)
#define    GPIOB     ((volatile GPIO_MemMap_t*)GPIOB_BASE_ADDRESS)
#define    GPIOC     ((volatile GPIO_MemMap_t*)GPIOC_BASE_ADDRESS)
#define    GPIOD     ((volatile GPIO_MemMap_t*)GPIOD_BASE_ADDRESS)
#define    GPIOE     ((volatile GPIO_MemMap_t*)GPIOE_BASE_ADDRESS)
#define    GPIOH     ((volatile GPIO_MemMap_t*)GPIOH_BASE_ADDRESS)







typedef struct
{

	Vu32  MODER     ;
	Vu32  OTYPER    ;
	Vu32  OSPEEDR   ;
	Vu32  PUPDR     ;
	Vu32  IDR       ;
	Vu32  ODR       ;
	Vu32  BSRR      ;
	Vu32  LCKR      ;
	Vu32  AFRL      ;
	Vu32  AFRH      ;

}GPIO_MemMap_t;





#endif







