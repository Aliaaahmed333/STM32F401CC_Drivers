#include "RCC/RCC_Interface.h"
#include "GPIO/GPIO_Interface.h"
#include "SysTic/SysTic_Interface.h"
#include "STB/STB_Interface.h"
#include "NVIC/NVIC_Interface.h"
#include "EXTI/EXTI_Interface.h"
#define GREEN_LED     PIN0
#define RED_LED       PIN1
#define YELLOW_LED    PIN2
#define Button_PIN    PIN3

const u8 seven_seg[10] = {0b0111111,0b0000110,0b1011011 ,0b1001111 ,0b1100110,0b1101101,
		0b1111101,0b0000111,0b1111111,0b1101111};

void Traffic_Light (void);
void ResetTraffic(void) ;
int main()
{
	RCC_voidInitSysClc();
	RCC_voidEnablePeripheral(AHB1,GPIOA_EN);
	RCC_voidEnablePeripheral(AHB1,GPIOB_EN);
	RCC_voidEnablePeripheral(APB2,SYSCFGRST);
	SysTick_Init();
    STP_Init();
    /*config traffic pins*/
    GPIO_SetPinDirection(PORTB , GREEN_LED, OUTPUT_M);
    GPIO_SetPinDirection(PORTB , RED_LED, OUTPUT_M);
    GPIO_SetPinDirection(PORTB , YELLOW_LED, OUTPUT_M);
    GPIO_SetPinDirection(PORTB , Button_PIN, INPUT_M);
    GPIO_SetInputState(PORTB,Button_PIN,PullUP);
    /* cofig on exti */
      EXTI_InterruptStatus (3, NOTMASK);
      EXTI_ChangeEXTISource (EXTI_LIN3 , PORTB);
      EXTI_SetInterruptEdge (EXTI_LIN3 , FallingEdge);
      EXTI_SetInterruptCallback (EXTI_LIN3 , ResetTraffic );

      NVIC_EnableInterrupt (9);
      NVIC_SetPriorityConfig (NVIC_GROUB_2BIT_SUBGROUB_2BIT);
      NVIC_SetInterruptPriority(9 , 1,2);


	while(1)
	{


		Traffic_Light();

	}
	return 0;
}


void Traffic_Light (void)
{

	u8 i ,j;
	for ( i = 0 , j = 0; i <= 20 ; i++,j++)
	{
		 GPIO_WritePin(PORTB , GREEN_LED,HIGH);
		 STP_SendData2(seven_seg[i / 10]);
		if (j < 10)
		{
			STP_SendData(seven_seg[j]);
			 SysTick_DelaymS(1000);
		}
		else
		{
			j = 0;
			 GPIO_WritePin(PORTB , YELLOW_LED,HIGH);

		}

	}
	 GPIO_WritePin(PORTB , GREEN_LED,LOW);
	 GPIO_WritePin(PORTB , YELLOW_LED,LOW);
	 for ( i = 0 , j = 0; i <= 20; i++,j++)
	 	{
	 		 GPIO_WritePin(PORTB , RED_LED,HIGH);
	 		 STP_SendData2(seven_seg[i/ 10]);
	 		if (j < 10)
	 		{
	 			STP_SendData(seven_seg[j]);
	 			 SysTick_DelaymS(1000);

	 		}
	 		else
	 		{
	 			j = 0;
	 			 GPIO_WritePin(PORTB , YELLOW_LED,HIGH);

	 		}

	 	}
	 GPIO_WritePin(PORTB , RED_LED,LOW);
     GPIO_WritePin(PORTB , YELLOW_LED,LOW);


}

void ResetTraffic(void)
{
	if (GPIO_GetPinValue(PORTB,Button_PIN) == 0)
	{
				Traffic_Light();
	}
}
