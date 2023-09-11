/*
 * RTC_Program.c
 *
 *  Created on: 7/9/2023
 *      Author: Aliaa Ahmed
 */

#include "../LIB/STD_Types.h"
#include "../LIB/BIT_MATH.h"
#include "../RCC/RCC_Interface.h"
#include "RTC_Interface.h"
#include "RTC_Private.h"


/******************************************************************************
* Api Name       : RTC_UnLock                                                 *
* Parameters in  :  void                                                      *
* Parameters out :  void                                                      *
* Description    :  this function enable clock for PWEER Periphera  and       *
*                :  access RTC regiseter and set rtc clock using LSI CLK ,    *
*                :  Write passward in WPR register                            *
*******************************************************************************/
static void RTC_UnLock(void)
{
	/* Enable Power peripheral clock  */
	 RCC_voidEnablePeripheral(APB1,PWREN);

	/* set DBP bit in pwr_cr register to access rtc registers*/
	SET_BIT(PWR_CR , 8);

	/* Init clock for rtc using lsi */
    RCC_InitForRTC_Clk();

	/* write protection keyes in rtc_wpr register*/
	RTC->RTC_WPR |= 0xCA;
	RTC->RTC_WPR |= 0x53;
}
/*******************************************************************************
* Api Name       :  RTC_CalenderInit                                           *
* Parameters in  :  hour,minutes,seconds,year,month,date                       *
* Parameters out :  void                                                       *
* Description    :  this function enable initialization mode and adjust        *
*                :  prescaler to generate 1hz as output then load inital value *
*                   of calender in TR, DR registers then lock rtc register     *
*******************************************************************************/
void RTC_CalenderInit (u8 Hours,u8 Minutes , u8 Seconds,u8 Year,u8 Month,u8 Date)
{
	/* unlock RTC register */
	RTC_UnLock();

	/*set INT bit in RTC_ISR to enter initalization mode */
	SET_BIT(RTC->RTC_ISR,INIT);

	/* POLLING in INTF in RTC_ISR reg to sure rtc enter in initialization mode*/
	while(!GET_BIT(RTC->RTC_ISR,INITF));

	/* To generate 1hz clock for calende program first synchronous prescaler factor = 256
	 * then program asynchronous division  factor = 128 */
	  RTC->RTC_PRER |= 0xF9; // 249
	  RTC->RTC_PRER |= (0x7F << 16);

     /* load inital time in rtc_tr reg (hour,min,sec) */
	  if (Seconds < 60)
	  {
		  RTC->RTC_TR |= (Seconds % 10);
		  RTC->RTC_TR |= ((Seconds / 10) << 4);
	  }
	  else
	  {
		  Minutes += Seconds / 60;
		  Seconds %= 60;
		  RTC->RTC_TR |= (Seconds % 10);
		  RTC->RTC_TR |= ((Seconds / 10) << 4);

	  }
	  if (Minutes < 60)
	  {
	 	  RTC->RTC_TR |= ((Minutes % 10) << 8);
	 	  RTC->RTC_TR |= ((Minutes / 10) << 12);
	  }
	  else
	  {
          Hours += (Minutes / 60);
          Minutes %=  60;
          RTC->RTC_TR |= ((Minutes % 10) << 8);
          RTC->RTC_TR |= ((Minutes / 10) << 12);

	  }

	  if (Hours < 24)
	  {
		  RTC->RTC_TR |= ( (Hours %10) << 16);
		  RTC->RTC_TR |= ( (Hours /10) << 20);
	  }
	  else
	  {

		  Date +=  Hours / 24;
		  Hours %= 24;
		  RTC->RTC_TR |= ( (Hours %10) << 16);
		  RTC->RTC_TR |= ( (Hours /10) << 20);
	  }



	  /* load initial date to rtc_dr register */
	  /* check for data ,month ,year */
	  if (Date <= 31)
	  {
	 	  RTC->RTC_DR |= (Date % 10) ;
	 	  RTC->RTC_DR |= ((Date /10) << 4);
	  }
	  else
	  {
		  Month += (Date / 30);
		  Date /= 30;
		  RTC->RTC_DR |= (Date % 10) ;
		  RTC->RTC_DR |= ((Date /10) << 4);
	  }

	  if (Month < 13)
	  {
		  RTC->RTC_DR |= ((Month %10) << 8);
		  RTC->RTC_DR |= ((Month /10) << 12);
	  }
	  else
	  {
		  Year += (Month /12);
		  Month %= 12;
		  RTC->RTC_DR |= ((Month %10) << 8);
		  RTC->RTC_DR |= ((Month /10) << 12);

	  }
	  RTC->RTC_DR |= ((Year% 100) << 16);
	  RTC->RTC_DR |= ((Year/ 100) << 20);

	  /* Set pypsshad bit */
	   SET_BIT(RTC->RTC_CR,BYPSHAD );

	  /* Configure the format 12/24 hours format we choose 12 hours mode */
	  SET_BIT(RTC->RTC_CR,FMT);


	  /*Exit initialization by clearing INIT bit */
	  CLR_BIT(RTC->RTC_ISR,INIT);

	  /*Disable access to rtc register */
	  CLR_BIT(PWR_CR,8);
}

/******************************************************************************
* Api Name       :  RTC_ReadigCalender                                        *
* Parameters in  :  void                                                      *
* Parameters out :  void                                                      *
* Description    :  this function get calender values (time, date )and return *
*                :  them in struct calender                                   *
*******************************************************************************/

void RTC_ReadigCalender  (void)
{
     if (GET_BIT (RTC->RTC_ISR,RSF) == 1)
     {

		Calender.hour = ((RTC->RTC_TR  & 0x7F0000 )>> 16);
		Calender.hour = (((Calender.hour & 0x7F) >> 4)*10) + (Calender.hour & 0xF);

		Calender.minutes = ((RTC->RTC_TR & 0x7F00) >> 8);
		Calender.minutes = (((Calender.minutes & 0x7F) >> 4) *10) + (Calender.minutes & 0xF);

		Calender.seconds = (((RTC->RTC_TR & 0x7F) >> 4)*10) + (RTC->RTC_TR & 0xF) ;


		Calender.year = ((RTC->RTC_DR >> 20)*10) + ((RTC->RTC_DR >> 16) & 0xF);
		Calender.month = (((RTC->RTC_DR >> 12) & 1) *10) + ((RTC->RTC_DR >> 8) & 0xF);
		Calender.date =  (((RTC->RTC_DR >> 4) & 3) * 10) + (RTC->RTC_DR & 0xF) ;

	}
	else
	{
		/* error in initialization mode*/
	}

}
