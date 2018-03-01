/*
 * DIO_int.h
 *
 *  Created on: Feb 14, 2018
 *      Author: Michael Tharwat
 */

#ifndef DIO_INT_H_
#define DIO_INT_H_
#include "CommonMacros.h"
#include "Standard_Type.h"

#define F_CPU	8000000		// define CPU Freq

#define A	'A'
#define B	'B'
#define C	'C'
#define D	'D'
#define	INPUT	0
#define OUTPUT	1
#define LOG_HIGH	1
#define LOG_LOW		0

typedef struct
{
	u8 port;
	u8 pin_number;
	u8 direction;
	u8 value;

}DIO_Config;

void Set_Direction (DIO_Config * S_config);
void Write_Value(DIO_Config * S_config);
u8 Read_Value(DIO_Config * S_config);
void DIO_SetPinDirection(u8 Port,u8 PinNumber,u8 Direction);
void DIO_WritePinValue(u8 Port,u8 PinNumber,u8 Value);
u8 DIO_ReadPinValue(u8 Port,u8 PinNumber);
void DIO_SetPortDir(u8 Port, u8 Direction);
void DIO_WritePortValue(u8 Port, u8 Value);
u8 DIO_ReadPortValue(u8 Port);



#endif /* DIO_INT_H_ */
