
/****************************************************************************/
/* Driver  : RCC Driver                                                     */
/* Author  : Aliaa Ahmed                                                    */
/* Date    : 10/8/2023                                                      */
/* Version : V 1.0                                                          */
/* Description :                                                            */
/****************************************************************************/





#ifndef   RCC_INTERFACE_H_
#define   RCC_INTERFACE_H_ 

#include "STD_Types.h"
//#include "RCC_Private.h"
//#include "RCC_Config.h"

/*define used buses */
typedef enum {
	AHB1,
	AHB2,
	APB1,
	APB2

}Buses_Num_t;

/*RCC AHB1 peripheral clock enable register */
typedef enum
{
	GPIOA_EN ,
	GPIOB_EN ,
	GPIOC_EN ,
	GPIOD_EN ,
	GPIOE_EN,
	GPIOH_EN ,
	CRCEN = 12,
	DMA1EN = 21,
	DMA2EN

}AHB1_peripheral ;


/*RCC APB1 peripheral clock enable register */
typedef enum
{
	TIM2EN,
	TIM3EN,
	TIM4EN,
	TIM5EN,
	WWDGEN = 11,
	SPI2EN = 14,
	SPI3EN,
	USART2EN = 17,
	I2C1EN = 21,
	I2C2EN,
	I2C3EN,
	PWREN = 28
}RCC_APB1_peripheral;

/* peripheral used APB2 bus*/
typedef enum
{
	TIM1EN,
	USART1EN = 4,
	USART6EN ,
	ADC1EN = 8,
	SDIOEN = 11,
	SPI1EN,
	SPI4EN,
	SYSCFGRST,
	TIM9REST = 16,
	TIM10REST,
	TIM11REST
}RCC_APB2_peripheral ;


void  RCC_voidInitSysClc(void);
void  RCC_voidEnablePeripheral(u8 Copy_u8BusId, u8 Copy_u8PeripheralId);
void  RCC_InitForRTC_Clk (void);
#endif



