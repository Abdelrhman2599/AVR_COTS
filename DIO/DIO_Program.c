/*
 * DIO_Program.c
 *
 *  Created on: 8 Dec 2023
 *      Author: MR.X
 */

#include "stdTypes.h"
#include "bitmath.h"

#include"DIO_Config.h"
#include"DIO_Private.h"
#include"DIO_Registers.h"
#include"DIO_Interface.h"


#ifndef DIO_PROGRAM_C_
#define DIO_PROGRAM_C_

uint8 DIO_setPinDirection(uint8 copy_port, uint8 copy_pin, uint8 copy_direction)
{
	uint8 local_errorStatus=0;

 if(copy_pin <= PIN7)
 {
	if(copy_direction == OUTPUT)
	{
		switch(copy_port)
    	{
		  case DIO_PORTA: SET_BIT(DDRA,copy_pin); break;
		  case DIO_PORTB: SET_BIT(DDRB,copy_pin); break;
		  case DIO_PORTC: SET_BIT(DDRC,copy_pin); break;
		  case DIO_PORTD: SET_BIT(DDRD,copy_pin); break;
		  default:local_errorStatus=1; break;
	    }
	}
	else if(copy_direction == INPUT)
	{
		switch(copy_port)
		{
           case DIO_PORTA: CLEAR_BIT(DDRA, copy_pin); break;
           case DIO_PORTB: CLEAR_BIT(DDRB, copy_pin); break;
           case DIO_PORTC: CLEAR_BIT(DDRC, copy_pin); break;
           case DIO_PORTD: CLEAR_BIT(DDRD, copy_pin); break;
           default:local_errorStatus=1; break;
		}

	}
	else
	{
		local_errorStatus=1;


	}


 }
 else
 {
	 local_errorStatus=1;

 }
 return local_errorStatus;

}


uint8 DIO_setPinValue(uint8 copy_port,uint8 copy_pin,uint8 copy_value)
{

	uint8 local_errorStatus=0;

	 if(copy_pin <= PIN7)
	 {
		if(copy_value == OUTPUT_HIGH)
		{
			switch(copy_port)
	    	{
			  case DIO_PORTA: SET_BIT(PORTA, copy_pin); break;
			  case DIO_PORTB: SET_BIT(PORTB, copy_pin); break;
			  case DIO_PORTC: SET_BIT(PORTC, copy_pin); break;
			  case DIO_PORTD: SET_BIT(PORTD, copy_pin); break;
			  default:local_errorStatus=1; break;
		    }
		}
		else if(copy_value == OUTPUT_LOW)
		{
			switch(copy_port)
			{
	           case DIO_PORTA: CLEAR_BIT(PORTA, copy_pin); break;
	           case DIO_PORTB: CLEAR_BIT(PORTB, copy_pin); break;
	           case DIO_PORTC: CLEAR_BIT(PORTC, copy_pin); break;
	           case DIO_PORTD: CLEAR_BIT(PORTD, copy_pin); break;
	           default:local_errorStatus=1; break;
			}
		}
		else
		{
			local_errorStatus=1;


		}


	 }
	 else
	 {
		 local_errorStatus=1;

	 }
	 return local_errorStatus;


}

uint8 DIO_setPortDirection(uint8 copy_port,uint8 copy_direction)
{
	uint8 local_errorStatus=OK;

	if (copy_direction == PORT_OUTPUT || copy_direction == PORT_INPUT )
	{

		switch(copy_port)
					{
			           case DIO_PORTA: DDRA = copy_direction; break;
			           case DIO_PORTB: DDRB = copy_direction; break;
			           case DIO_PORTC: DDRC = copy_direction; break;
			           case DIO_PORTD: DDRD = copy_direction; break;
			           default:local_errorStatus=NOK; break;
					}
	}
	else
	{
		local_errorStatus=NOK;
	}


	return local_errorStatus;


}



uint8 DIO_setPortValue(uint8 copy_port,uint8 copy_value)
{
	uint8 local_errorStatus=OK;


		switch(copy_port)
					{
			           case DIO_PORTA: PORTA = copy_value; break;
			           case DIO_PORTB: PORTB = copy_value; break;
			           case DIO_PORTC: PORTC = copy_value; break;
			           case DIO_PORTD: PORTD = copy_value; break;
			           default:local_errorStatus=NOK; break;
					}


	return local_errorStatus;


}

uint8 DIO_getPinValue(uint8 copy_port, uint8 copy_pin, uint8* copy_value)
{
	uint8 local_errorStatus=OK;

	if((copy_pin <= PIN7) && (copy_value != NULL))
	{
		switch(copy_port)
					{
			           case DIO_PORTA: * copy_value = GET_BIT(PINA, copy_pin); break;
			           case DIO_PORTB: * copy_value = GET_BIT(PINB, copy_pin); break;
			           case DIO_PORTC: * copy_value = GET_BIT(PINC, copy_pin); break;
			           case DIO_PORTD: * copy_value = GET_BIT(PIND, copy_pin); break;
			           default:local_errorStatus=NOK; break;
					}

	}
	else
	{
		 local_errorStatus=NOK;
	}


	return local_errorStatus;

}

void DIO_setInternalPullup(uint8 copy_port, uint8 copy_pin)
{
	DIO_setPinDirection(copy_port, copy_pin, INPUT);

	DIO_setPinValue(copy_port,copy_pin,OUTPUT_HIGH);


}




#endif /* DIO_PROGRAM_C_ */
