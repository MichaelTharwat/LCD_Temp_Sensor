/*
 * DIO_prog.c
 *
 *  Created on: Feb 14, 2018
 *      Author: Michael Tharwat
 */
#include<avr/io.h>
#include"DIO_int.h"
#include "CommonMacros.h"

void Set_Direction (DIO_Config * S_config)
{
	u8 *DDR_Ptr;
	switch (S_config->port)
	{
	case 'A':
		DDR_Ptr=&DDRA;
		break;
	case 'B':
		DDR_Ptr=&DDRB;
		break;
	case 'C':
		DDR_Ptr=&DDRC;
		break;
	case 'D':
		DDR_Ptr=&DDRD;
		break;
	}
	if (S_config->direction==INPUT)
	{
		CLR_BIT(*DDR_Ptr,S_config->pin_number);
	}
	else
	{
		SET_BIT(*DDR_Ptr,S_config->pin_number);
	}
}

void Write_Value(DIO_Config * S_config)
{
	u8 *PORT_Ptr;

	switch (S_config->port)
	{
	case 'A':
		PORT_Ptr=&PORTA;
		break;
	case 'B':
		PORT_Ptr=&PORTB;
		break;
	case 'C':
		PORT_Ptr=&PORTC;
		break;
	case 'D':
		PORT_Ptr=&PORTD;
		break;
	}
	if (S_config->value==LOG_LOW)
	{
		CLR_BIT(*PORT_Ptr,S_config->pin_number);
	}
	else
	{
		SET_BIT(*PORT_Ptr,S_config->pin_number);
	}

}
u8 Read_Value(DIO_Config * S_config)
{
	u8 *PIN_Ptr;
	switch (S_config->port)
	{
	case 'A':
		PIN_Ptr=&PINA;
		break;
	case 'B':
		PIN_Ptr=&PINB;
		break;
	case 'C':
		PIN_Ptr=&PINC;
		break;
	case 'D':
		PIN_Ptr=&PIND;
		break;
	}

	if (GET_BIT(*PIN_Ptr,S_config->pin_number)==LOG_HIGH)
		return LOG_HIGH;
	else
		return LOG_LOW;
}

void DIO_SetPinDirection(u8 Port,u8 PinNumber,u8 Direction)
{
	DIO_Config Pin_Config;
	Pin_Config.port=Port;
	Pin_Config.pin_number=PinNumber;
	Pin_Config.direction=Direction;
	Set_Direction(&Pin_Config);

}
void DIO_WritePinValue(u8 Port,u8 PinNumber,u8 Value)
{
	DIO_Config Pin_Config;
	Pin_Config.port=Port;
	Pin_Config.pin_number=PinNumber;
	Pin_Config.value=Value;
	Write_Value(&Pin_Config);
}
u8 DIO_ReadPinValue(u8 Port,u8 PinNumber)
{
	DIO_Config Pin_Config;
	Pin_Config.port=Port;
	Pin_Config.pin_number=PinNumber;
	return Read_Value(&Pin_Config);
}

void DIO_SetPortDir(u8 Port, u8 Direction)
{
	switch (Port)
	{
	case A:
		if (Direction==OUTPUT)
		{
			SET_REG(DDRA);
		}
		else
		{
			CLR_REG(DDRA);
		}
		break;
	case B:
		if (Direction==OUTPUT)
		{
			SET_REG(DDRB);
		}
		else
		{
			CLR_REG(DDRB);
		}
		break;
	case C:
		if (Direction==OUTPUT)
		{
			SET_REG(DDRC);
		}
		else
		{
			CLR_REG(DDRC);
		}
		break;
	case D:
		if (Direction==OUTPUT)
		{
			SET_REG(DDRD);
		}
		else
		{
			CLR_REG(DDRD);
		}
		break;
	}

}

void DIO_WritePortValue(u8 Port, u8 Value)
{
	switch (Port)
	{
	case A:
		PORTA=Value;
		break;
	case B:
		PORTB=Value;
		break;
	case C:
		PORTC=Value;
		break;
	case D:
		PORTD=Value;
		break;
	}

}

u8 DIO_ReadPortValue(u8 Port)
{
	u8 PIN_Value;
	switch (Port)
	{
	case A:
		PIN_Value=PINA;
		break;
	case B:
		PIN_Value=PINB;
		break;
	case C:
		PIN_Value=PINC;
		break;
	case D:
		PIN_Value=PIND;
		break;
	}

	return PIN_Value;
}
