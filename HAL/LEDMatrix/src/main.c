/*
 *
 */

#include "RCC/RCC_Interface.h"
#include "SysTic/SysTic_Interface.h"
#include "LedMatrix/LedMatrix_Interface.h"


u8 arr_A[] = {8, 20, 34, 127, 65, 65, 65, 65};
u8 arr_L[] = {2, 2, 2, 2, 2, 2, 254, 0};
u8 arr_I[] = {8, 8, 8, 8, 8, 8, 8, 8};
#define delay 500
int main()
{
    RCC_voidInitSysClc();
    RCC_voidEnablePeripheral(AHB1,GPIOA_EN);
    RCC_voidEnablePeripheral(AHB1,GPIOB_EN);
    SysTick_Init();
    LedMatrix_Init();

    u8 c = 0;

	while(1)
	{

   while ( c < delay){ LedMatrix_Display(arr_A); c++;} c = 0;
   while ( c < delay){ LedMatrix_Display(arr_L) ; c++;} c = 0;
   while ( c < delay){ LedMatrix_Display(arr_I) ; c++;} c = 0;
   while ( c < delay){ LedMatrix_Display(arr_A) ; c++;} c = 0;
   while ( c < delay){ LedMatrix_Display(arr_A) ; c++;} c = 0;
}
}
