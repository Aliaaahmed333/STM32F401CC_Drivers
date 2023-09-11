/*
 * LedMatrix_Interface.h
 *
 *  Created on: ???/???/????
 *      Author: hp
 */

#ifndef LEDMATRIX_LEDMATRIX_INTERFACE_H_
#define LEDMATRIX_LEDMATRIX_INTERFACE_H_


#define LEDMATRIX_PORT     PORTA
#define LEDMATRIX_COLPORT  PORTB
#define LEDMATRIX_ROW0     PORTA,PIN0
#define LEDMATRIX_ROW1     PORTA,PIN1
#define LEDMATRIX_ROW2     PORTA,PIN2
#define LEDMATRIX_ROW3     PORTA,PIN3
#define LEDMATRIX_ROW4     PORTA,PIN4
#define LEDMATRIX_ROW5     PORTA,PIN5
#define LEDMATRIX_ROW6     PORTA,PIN6
#define LEDMATRIX_ROW7     PORTA,PIN7

#define LEDMATRIX_COL0     PORTB,PIN0
#define LEDMATRIX_COL1     PORTB,PIN1
#define LEDMATRIX_COL2     PORTB,PIN2
#define LEDMATRIX_COL3     PORTB,PIN3
#define LEDMATRIX_COL4     PORTB,PIN4
#define LEDMATRIX_COL5     PORTB,PIN5
#define LEDMATRIX_COL6     PORTB,PIN6
#define LEDMATRIX_COL7     PORTB,PIN7

void LedMatrix_Init(void);
void LedMatrix_ClearCoulmn(u8 col_num);
void LedMatrix_SetRows(u8 value);
void LedMatrix_Display(u8* frame);
void LedMatrix_DisplayShift(u8* frame);
#endif /* LEDMATRIX_LEDMATRIX_INTERFACE_H_ */
