/* Author  : Aliaa Ahmed                                                    */
/* Date    : 12/8/2023                                                      */
/* Version : V 1.0                                                          */
/* Description :   GPIO_Interface                                                         */
/****************************************************************************/
#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H



typedef enum
{
	INPUT_M,
	OUTPUT_M,
	ALTERNATIVE_M,
	ANALOG_M
}Direction_Modes_t;


typedef enum
{
	LowSpeed,
	MediumSpeed,
	HighSpeed,
	VeryHighSpeed
}Output_Speed_t;

typedef enum
{
	Floating_M,
	PullUP,
	PullDown


}Input_Modes_t;


typedef enum {

	PORTA,
	PORTB,
	PORTC,
	PORTD,
	PORTE,
	PORTH

}GPIO_PORTS_t;


typedef enum
{
	PIN0   ,
	PIN1   ,
	PIN2   ,
	PIN3   ,
	PIN4   ,
	PIN5   ,
	PIN6   ,
	PIN7   ,
	PIN8   ,
	PIN9   ,
	PIN10  ,
	PIN11  ,
	PIN12  ,
	PIN13  ,
	PIN14  ,
	PIN15

}PINS_t;

typedef enum
{
	HIGH,
	LOW
}PIN_State_t;

typedef enum
{
	AFO,
	AF1,
	AF2,
	AF3,
	AF4,
	AF5,
	AF6,
	AF7,
	AF8,
	AF9,
	AF10,
	AF11,
	AF12,
	AF13,
	AF14,
	AF15

} ALTERNATIVE_NUM_t;
void  GPIO_SetPinDirection (u8 Port_Id , u8 Pin_Num , u8 Dir);
void GPIO_SetInputState (u8 port_Id, u8 Pin_Num, u8 inputState);
void GPIO_SetAlternativeFunction (u8 Port_Id, u8 Pin_Num, u8 AlternativeNum);
void  GPIO_WritePin  (u8 port, u8 pin , u8 state);
void GPIO_WritePort (u8 Port_Id ,u32 Value );
u8 GPIO_GetPinValue  (u8 port , u8 pin);

#endif


