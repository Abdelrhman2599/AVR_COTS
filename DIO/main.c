/*
 * main.c
 *
 *  Created on: 8 Dec 2023
 *      Author: MR.X
 */
//#include <stdio.h>
#include "stdTypes.h"
#include "bitmath.h"
#include <util/delay.h>

#include"DIO_Config.h"
#include"DIO_Private.h"
#include"DIO_Registers.h"
#include"DIO_Interface.h"


int main(void)
{
	uint8 data = 0;
	DIO_setPinDirection(DIO_PORTD,PIN3,OUTPUT);
	DIO_setPinDirection(DIO_PORTC,PIN2,OUTPUT);
	DIO_setPinDirection(DIO_PORTC,PIN7,OUTPUT);
	DIO_setPinDirection(DIO_PORTB,PIN0,INPUT);
	DIO_setPinDirection(DIO_PORTB,PIN0,INPUT);




	while (1)
	{
		DIO_getPinValue(DIO_PORTB,PIN0,&data);
		_delay_us(50);
		if (data == HIGH)
		{



			DIO_setPinValue(DIO_PORTD,PIN3,HIGH);
			DIO_setPinValue(DIO_PORTC,PIN7,HIGH);
			DIO_setPinValue(DIO_PORTC,PIN2,HIGH);

	}
		else
		{

			DIO_setPinValue(DIO_PORTD,PIN3,LOW);
			DIO_setPinValue(DIO_PORTC,PIN7,LOW);
			DIO_setPinValue(DIO_PORTC,PIN2,LOW);

		}

	}

	return (0);
}
