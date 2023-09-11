/*
 * RTC_Interface.h
 *
 *  Created on: ???/???/????
 *      Author: hp
 */

#ifndef RTC_RTC_INTERFACE_H_
#define RTC_RTC_INTERFACE_H_

typedef struct
{
	u8 hour;
	u8 minutes;
	u8 seconds;
	u8 year;
	u8 month;
	u8 date;
}Return_Calender_t;
Return_Calender_t Calender  ;

void RTC_Init(void);
void RTC_CalenderInit (u8 Hours,u8 Minutes , u8 Seconds,u8 Year,u8 Month,u8 Date);
void RTC_ReadigCalender  (void);



#endif /* RTC_RTC_INTERFACE_H_ */
