/*
 * KEYPAD_Program.c
 *
 *  Created on: 15 Dec 2023
 *      Author: MR.X
 */
#include "DIO/bitmath.h"
#include "DIO/stdTypes.h"
#include "DIO/DIO_Interface.h"


#include "KEYPAD_Config.h"
#include "KEYPAD_Interface.h"

const uint8 COL_pin[4]={COL1, COL2, COL3, COL4};
const uint8 ROW_pin[4]={ROW1, ROW2, ROW3, ROW4};

void KEYPAD_init(void)
{
	DIO_setPinDirection(KEYPAD_PORT, COL1,OUTPUT);
	DIO_setPinDirection(KEYPAD_PORT, COL2,OUTPUT);
	DIO_setPinDirection(KEYPAD_PORT, COL3,OUTPUT);
	DIO_setPinDirection(KEYPAD_PORT, COL4,OUTPUT);

	DIO_setPinValue(KEYPAD_PORT, COL1,OUTPUT_HIGH);
	DIO_setPinValue(KEYPAD_PORT, COL2,OUTPUT_HIGH);
	DIO_setPinValue(KEYPAD_PORT, COL3,OUTPUT_HIGH);
	DIO_setPinValue(KEYPAD_PORT, COL4,OUTPUT_HIGH);

	DIO_setPinDirection(KEYPAD_PORT, ROW1,INPUT);
	DIO_setPinDirection(KEYPAD_PORT, ROW2,INPUT);
	DIO_setPinDirection(KEYPAD_PORT, ROW3,INPUT);
	DIO_setPinDirection(KEYPAD_PORT, ROW4,INPUT);

	DIO_setPinValue(KEYPAD_PORT, ROW1,OUTPUT_HIGH);
    DIO_setPinValue(KEYPAD_PORT, ROW2,OUTPUT_HIGH);
	DIO_setPinValue(KEYPAD_PORT, ROW3,OUTPUT_HIGH);
	DIO_setPinValue(KEYPAD_PORT, ROW4,OUTPUT_HIGH);



}

uint8 KEYPAD_pressedKey(void)
{
	    uint8 Local_row= 0;
		uint8 Local_col= 0;
		uint8 buttonStatus=0xff;
		uint8 buttonPressed = 0xff;
		uint8 buttonArray[ROW_NUM][COL_NUM]=KEYPAD_BUTTONS;

		for(Local_col=0; Local_col<COL_NUM; Local_col++)
		{
			DIO_setPinValue(KEYPAD_PORT, COL_pin[Local_col],OUTPUT_LOW);

			for(Local_row=0; Local_row<ROW_NUM; Local_row++)
			{
				DIO_getPinValue(KEYPAD_PORT,ROW_pin[Local_row],&buttonStatus);

				if(buttonStatus== LOW)
				{
					while(buttonStatus== LOW)
					{
						DIO_getPinValue(KEYPAD_PORT,ROW_pin[Local_row],&buttonStatus);
					}


					buttonPressed= buttonArray[Local_row][Local_col];
					DIO_setPinValue(KEYPAD_PORT, COL_pin[Local_col],OUTPUT_HIGH);
					return buttonPressed;

				}

			}
			DIO_setPinValue(KEYPAD_PORT, COL_pin[Local_col],OUTPUT_HIGH);
		}

		return buttonPressed;
}
