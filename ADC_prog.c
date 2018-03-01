/*
 * ADC_prog.c
 *
 *  Created on: Feb 24, 2018
 *      Author: Michael Tharwat
 */
#include "ADC_int.h"
#include "DIO_int.h"
#include "CommonMacros.h"
#include "Standard_Type.h"
#include <avr/io.h>

void ADC_vidInit(void)
{
	SET_BIT(ADCSRA,7);			// Enable ADC Module
	/* Voltage REF is VCC*/
	SET_BIT(ADMUX,6);
	CLR_BIT(ADMUX,7);
	/* ADC FOSC = 8MHz/64*/
	SET_BIT(ADCSRA,2);
	SET_BIT(ADCSRA,1);
	CLR_BIT(ADCSRA,0);
	/* CLEAR FLAG */
	SET_BIT(ADCSRA,4);
	/* ADC Channel 0 */
	CLR_BIT(ADMUX,4);
	CLR_BIT(ADMUX,3);
	CLR_BIT(ADMUX,2);
	CLR_BIT(ADMUX,1);
	CLR_BIT(ADMUX,0);
	DIO_SetPinDirection(A,0,INPUT);
	/* Adjust Data Right ADCH*/
	SET_BIT(ADMUX,5);
	/********************/
	CLR_BIT(ADCSRA,3);
	CLR_BIT(ADCSRA,6);
	CLR_BIT(ADCSRA,5);

}
u8 ADC_u8GetResult(void)
{
	SET_BIT(ADCSRA,6);				// Start Conversion
	while ((GET_BIT(ADCSRA,4))==0);	// Polling till conversion end
	SET_BIT(ADCSRA,4);				// Clear Flag
	return ADCH;
}
