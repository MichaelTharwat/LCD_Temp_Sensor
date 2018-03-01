/*
 * main.c
 *
 *  Created on: Feb 24, 2018
 *      Author: Michael Tharwat
 */
#include "ADC_int.h"
#include "CommonMacros.h"
#include "Standard_Type.h"
#include "DIO_int.h"
#include "LCD_int.h"

int main (void)
{
	u8 Digital , Analog, Temp;
	LCD_vidInit();
	ADC_vidInit();
	while(1)
	{
	Digital=ADC_u8GetResult();
	Analog=(Digital*5000)/256;
	Temp=Analog/10;
	LCD_vidGOTO(1,0);
	LCD_vidWriteString("Temp=");
	LCD_vidWriteData((Temp/10)+0x30);
	LCD_vidWriteData((Temp%10)+0x30);
	}
	return 0;
}

