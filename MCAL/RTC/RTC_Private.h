/*
 * RTC_Private.h
 *
 *  Created on: ???/???/????
 *      Author: hp
 */

#ifndef RTC_RTC_PRIVATE_H_
#define RTC_RTC_PRIVATE_H_

#define RTC_BASEADDRESS      0x40002800
#define RTC                  ((RTC_MemMap_t*)RTC_BASEADDRESS)
#define PWR_CR               *((volatile u32*)0x40007000)

#define KEY1                  0xCA
#define KEY2                  0x53
#define FMT                   6
#define BYPSHAD               5

typedef struct
{

	u32  RTC_TR;
	u32  RTC_DR;
	u32  RTC_CR;
	u32  RTC_ISR;
	u32  RTC_PRER;
	u32  RTC_WUTR;
	u32  RTC_CALIBR;
	u32  RTC_ALRMAR;
	u32  RTC_ALRMBR;
	u32  RTC_WPR;
	u32  RTC_SSR;
	u32  RTC_TSTR;
	u32  RTC_TSSSR;
	u32  RTC_CALR;
	u32  RTC_TAFCR;
	u32  RTC_ALRMASSR;
	u32  RTC_ALRMBSSR;
	u32  RTC_BKPR[20];

}RTC_MemMap_t;

typedef enum
{
	ALRAWF,
	ALRBWF,
	WUTWF,
	SHPF,
	INITS,
	RSF,
	INITF,
	INIT,
	ALRAF,
	ALRBF,
	WUTF,
	TSF,
	TSOVF,
	TAMP1F,

}RTC_ISRPINS_t;


static void RTC_UnLock(void);
#endif /* RTC_RTC_PRIVATE_H_ */
