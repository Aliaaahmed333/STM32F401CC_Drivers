/****************************************************************************/
/* Driver  : RCC Driver                                                     */
/* Author  : Aliaa Ahmed                                                    */
/* Date    : 10/8/2023                                                      */
/* Version : V 1.0                                                          */
/* Description :                                                            */
/****************************************************************************/

#ifndef   RCC_PRIVATE_H_
#define   RCC_PRIVATE_H_ 

#include "STD_Types.h"

 #define   RCC_CR             *((volatile u32*)0x40023800)
 #define   RCC_PLLCFGR        *((volatile u32*)0x40023804)
 #define   RCC_CFGR           *((volatile u32*)0x40023808)
 #define   RCC_BDCR           *((volatile u32*)0x40023870)
 #define   RCC_CSR            *((volatile u32*)0x40023874)
 #define   RCC_AHB1ENR        *((volatile u32*)0x40023830)
 #define   RCC_AHB2ENR        *((volatile u32*)0x40023834)
 #define   RCC_APB1ENR        *((volatile u32*)0x40023840)
 #define   RCC_APB2ENR        *((volatile u32*)0x40023844)
 
#define HSI    0
#define HSE    1
#define PLL    2
#define LSI    3
 
 /*define RCC_CR bin */ 
 #define    HSION     0
 #define    HSIRDY    1
 #define    HSEON     16
 #define    HSERDY    17
 #define    HSEBYP    18
 #define    CSSON     19
 #define    PLLON     24
 
#define LSION    0
#define LSIRDY   1
/**/

 /* define RCC_CFGR bin*/ 
 
 #define       SW0     0
 #define       SW1     1 
 
 /* define RCC_BDCR register that using in rtc */
#define RTCEN     15
#define RTCSEL0   8
#define RTCSEL1   9


/*RCC AHB2 peripheral clock enable register */
#define  OTFGSRST       7
 
 typedef struct
{
	u32 PLLM:6;
	u32 PLLN:9;
	u32 resv:1;
	u32 PLLP:2;
	u32     :4;
	u32 PLLSRC:1;
	u32      :1;
	u32 PLLQ :4 ;
    u32      :4;


}RCC_PLLCFGR_PIN_t;
#define RCC_PLLCFGR_PIN   volatile(RCC_PLLCFGR_PIN_t*)((volatile u32*)0x40023804)

 // RCC_PLLCFGR_PIN_t* RCC_PLLCFGR_PIN  = ((volatile u32*)0x40023804);

#endif
