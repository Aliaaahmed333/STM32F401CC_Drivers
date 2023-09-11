/*
 * STB_Interface.h
 *
 *  Created on: ???/???/????
 *      Author: hp
 */

#ifndef STB_STB_INTERFACE_H_
#define STB_STB_INTERFACE_H_

#define STP_PORT           PORTA
#define STP_PIN            PIN1
#define STP_SHIFT_CLK      PIN0
#define STP_LATCHCLK       PIN2

#define STP_PIN2            PIN4
#define STP_SHIFT_CLK2      PIN3
#define STP_LATCHCLK2       PIN5

void STP_Init(void);
void STP_SendData(u8 data);
void STP_SendData2(u8 data);
#endif /* STB_STB_INTERFACE_H_ */
