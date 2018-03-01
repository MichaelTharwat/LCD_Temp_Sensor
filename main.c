/*
 * main.c
 *
 *  Created on: Feb 19, 2018
 *      Author: Michael Tharwat
 */

#include <avr/io.h>
#include <util/delay.h>
#include "Standard_Type.h"
#include "CommonMacros.h"
#include "DIO_int.h"
#include "LCD_int.h"

int main (void)
{
	LCD_vidInit();
	LCD_vidGOTO(2,5);
	LCD_vidWriteString("Hello");
	while (1);
}
