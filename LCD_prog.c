/*
 * LCD_prog.c
 *
 *  Created on: Feb 19, 2018
 *      Author: Michael Tharwat
 */

#include <util/delay.h>
#include "Standard_Type.h"
#include "CommonMacros.h"
#include "DIO_int.h"
#include "LCD_int.h"

void LCD_vidInit(void)
{
	DIO_SetPortDir(LCD_PORT,OUTPUT);
	DIO_SetPinDirection(LCD_CTRLPORT,RS,OUTPUT);
	DIO_SetPinDirection(LCD_CTRLPORT,RW,OUTPUT);
	DIO_SetPinDirection(LCD_CTRLPORT,E,OUTPUT);
	LCD_vidSendCommand(0x38);					// Set 2 lines ,8 bit char,5*7 dots
	_delay_ms(1);
	LCD_vidSendCommand(0x0C);					// Display On
	_delay_ms(1);
	LCD_vidSendCommand(CLR_LCD);				// Clear Display
	_delay_ms(1);
}

void LCD_vidSendCommand(u8 Command)
{
	DIO_WritePinValue(LCD_CTRLPORT,RS,LOG_LOW);
	DIO_WritePinValue(LCD_CTRLPORT,RW,LOG_LOW);
	DIO_WritePortValue(LCD_PORT,Command);
	DIO_WritePinValue(LCD_CTRLPORT,E,LOG_HIGH);
	_delay_ms(2);
	DIO_WritePinValue(LCD_CTRLPORT,E,LOG_LOW);
}

void LCD_vidWriteData(u8 Data)
{
	DIO_WritePinValue(LCD_CTRLPORT,RS,LOG_HIGH);
	DIO_WritePinValue(LCD_CTRLPORT,RW,LOG_LOW);
	DIO_WritePortValue(LCD_PORT,Data);
	DIO_WritePinValue(LCD_CTRLPORT,E,LOG_HIGH);
	_delay_ms(2);
	DIO_WritePinValue(LCD_CTRLPORT,E,LOG_LOW);
}

void LCD_vidWriteString(u8 * Pu8str)
{
	u8 Index=0;
	while (Pu8str[Index]!='\0')
	{
		LCD_vidWriteData(Pu8str[Index]);
		Index++;
		_delay_ms(2);
	}
}

void LCD_vidGOTO(u8 Row,u8 Col)
{
	if (Row==1)
	{
		LCD_vidSendCommand(0x80+Col);
	}
	else if (Row==2)
	{
		LCD_vidSendCommand(0xC0+Col);
	}
}
