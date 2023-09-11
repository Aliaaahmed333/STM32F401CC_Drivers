/* Author  : Aliaa Ahmed
                                                  */
/* Date    : 10/8/2023                                                      */
/* Version : V 1.0                                                          */
/* Description :                                                            */
/****************************************************************************/  

#include   "STD_Types.h"
#include   "BIT_MATH.h"
#include  "RCC_Interface.h"
#include  "RCC_Private.h"
#include  "RCC_Config.h"


/*********************************************************************************/
/* Api Name       :    RCC_voidInitSysClc                                       */
/* Parameters in  :    void                                                    */
/* Parameters out :    void                                                   */
/* Description    :                                                          */
/************************************************************************** **/
void  RCC_voidInitSysClc(void)
{
	#if  RCC_CLK_SRC == HSE
	     CLR_BIT(RCC_CR, CSSON );
	     SET_BIT(RCC_CR , HSEON);
	     while (GET_BIT(RCC_CR ,HSERDY) == 0);
		 SET_BIT(RCC_CFGR ,SW0);
		 CLR_BIT(RCC_CFGR ,SW1);

    #elif RCC_CLK_SRC == HSI
	    SET_BIT(RCC_CR , HSION );
	    while (GET_BIT(RCC_CR ,HSIRDY) == 0);
		CLR_BIT (RCC_CFGR ,SW0);
		CLR_BIT(RCC_CR ,SW1);

	#elif RCC_CLK_SRC == PLL
	    /*  HSI oscillator clock selected as PLL and PLLI2S clock entry*/
		 RCC_PLLCFGR_PIN -> PLLSRC = 0;
        /* we use this equations to generate 80MHZ in output */
		/*f(VCO clock) = f(PLL clock input) × (PLLN / PLLM)
          f(PLL general clock output) = f(VCO clock) / PLLP*/
       /*  we use clock input = HSI = 16MHZ and PLLN = 201 and PLLM = 10*/
		 RCC_PLLCFGR_PIN -> PLLN = 201;
		 RCC_PLLCFGR_PIN -> PLLM = 10;
		 RCC_PLLCFGR_PIN -> PLLP = 4;
		 /* Enable PPLON pin and choose System clock PLL */
	      SET_BIT(RCC_CR , PLLON );
	  //    while (GIT_BIT(RCC_CR ,PLLRDY) == 0);
	      CLR_BIT (RCC_CFGR ,SW0);
		  SET_BIT (RCC_CFGR ,SW1);

   #else
		#error "Configuration parameters is not supported"
#endif
}
/*********************************************************************************/
/* Api Name       :    RCC_voidEnablePeripheral                                  */
/* Parameters in  :    BusId ,  PeripheralId                                    */
/* Parameters out :    void                                                   */
/* Description    :    Enable RCC clock for peripheral uses this bus                                                      */
/************************************************************************** **/
void  RCC_voidEnablePeripheral(u8 Copy_u8BusId, u8 Copy_u8PeripheralId)
{
	if((Copy_u8BusId >APB2) || (Copy_u8PeripheralId > 31))
	{
		/*Do Nothing*/
	}
	
	else
	{
		switch(Copy_u8BusId)
		{
			case AHB1:
				SET_BIT(RCC_AHB1ENR,Copy_u8PeripheralId);
			break;
			
			case AHB2:
				if(Copy_u8PeripheralId != 7)
				{
					/*Do Nothing*/
				}
			break;
			
			case APB1: 
				SET_BIT(RCC_APB1ENR ,Copy_u8PeripheralId);
			break;
			
			case APB2:
				SET_BIT(RCC_APB2ENR ,Copy_u8PeripheralId);
			break;
			
			default:
			break;
			
		}
	}
	
}
