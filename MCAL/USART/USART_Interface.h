/*
 * USART_Interface.h
 *
 *  Created on: ???/???/????
 *      Author: hp
 */

#ifndef USART_USART_INTERFACE_H_
#define USART_USART_INTERFACE_H_




typedef enum
{
	USART_1,
	USART_2,
	USART_6
}USART_PERIPHERAL_t;
void USART_Init(void) ;

void USART_SendData(u8 data);
void USART_SendString(char* data );
void USART_ReciveData(u8* data);



#endif /* USART_USART_INTERFACE_H_ */
