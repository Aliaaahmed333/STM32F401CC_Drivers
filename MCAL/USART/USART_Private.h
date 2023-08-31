/*
 * USART_Private.h
 *
 *  Created on: ???/???/????
 *      Author: hp
 */

#ifndef USART_USART_PRIVATE_H_
#define USART_USART_PRIVATE_H_



#define USART1_BASEADDRESS       0x40011000
#define USART1                  ((USART_MemMap_t*) USART1_BASEADDRESS)
#define USART6_BASEADDRESS       0x40011400
#define USART6                  ((USART_MemMap_t*) USART6_BASEADDRESS)
#define USART2_BASEADDRESS      0x40004400
#define USART2                  ((USART_MemMap_t*) USART2_BASEADDRESS)

#define RE                      2
#define TE                      3
#define M                       12
#define UE                      13
#define OVER8                   15
#define STOP0                   12
#define STOP1                   13
#define TC                      6
#define RXNE                    5

typedef struct
{
	u32  USART_SR;
	u32  USART_DR;
	u32  USART_BRR;
	u32  USART_CR1;
	u32  USART_CR2;
	u32  USART_CR3;
	u32  USART_GTPR;

}USART_MemMap_t;


#endif /* USART_USART_PRIVATE_H_ */
