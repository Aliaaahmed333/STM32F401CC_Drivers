/*
 * SysTic_Private.h
 *
 *  Created on: ???/???/????
 *      Author: hp
 */

#ifndef SYSTIC_SYSTIC_PRIVATE_H_
#define SYSTIC_SYSTIC_PRIVATE_H_



#define  SYSTICK_BASEADDRESS    0xE000E010
#define  SYSTICK                ((SysTick_MemMap_t*)SYSTICK_BASEADDRESS)
/* pins in CTRL register */
#define  ENABLE      0
#define  TICKINT     1
#define  CLKSOURCE   2
#define  COUNTFLAG   16

/* define number of clock*/
#define AHB_CLK          0
#define AHB_DEVIDEBY8    1
/* define register of systick*/
typedef struct
{
	Vu32 CTRL;
	Vu32 LOAD ;
	Vu32 VAL;
	Vu32 CALIB;

}SysTick_MemMap_t;

#endif /* SYSTIC_SYSTIC_PRIVATE_H_ */
