/*
 * LCD_Program.c
 *
 *  Created on: 14 Dec 2023
 *      Author: MR.X
 */

#include <util/delay.h>

#include "DIO/stdTypes.h"
#include "DIO/bitmath.h"

#include "DIO/DIO_Registers.h"
#include"DIO/DIO_Interface.h"

#include "LCD_Config.h"
#include"LCD_Interface.h"

void LCD_sendCommand_8bit(uint8 copy_command)
{
	/* Set RS */
	DIO_setPinValue(LCD_CONTROL_PORT,RS,LOW);

	/* Set RW */
	DIO_setPinValue(LCD_CONTROL_PORT,RW,LOW);

	/* Write command*/
	DIO_setPortValue(LCD_DATA_PORT,copy_command);

	/*Set enable*/
	DIO_setPinValue(LCD_CONTROL_PORT,Enable,HIGH);

	_delay_ms(2);

	/*Reset enable*/
	DIO_setPinValue(LCD_CONTROL_PORT,Enable,LOW);


}


void LCD_sendData_8bit(uint8 copy_command)
{
	/* Set RS */
	DIO_setPinValue(LCD_CONTROL_PORT,RS,HIGH);

	/* Set RW */
	DIO_setPinValue(LCD_CONTROL_PORT,RW,LOW);

	/* Write command*/
	DIO_setPortValue(LCD_DATA_PORT,copy_command);

	/*Set enable*/
	DIO_setPinValue(LCD_CONTROL_PORT,Enable,HIGH);

	_delay_ms(2);

	/*Reset enable*/
	DIO_setPinValue(LCD_CONTROL_PORT,Enable,LOW);


}

void LCD_init_8bit(void)
{
	DIO_setPortDirection(LCD_DATA_PORT, OUTPUT);
	DIO_setPortValue(LCD_DATA_PORT, HIGH);
	DIO_setPinDirection(LCD_CONTROL_PORT, RS, OUTPUT);
	DIO_setPinDirection(LCD_CONTROL_PORT, RW, OUTPUT);
	DIO_setPinDirection(LCD_CONTROL_PORT, Enable, OUTPUT);
	_delay_ms(35);


	LCD_sendCommand_8bit(FUNCTION_SET);
	_delay_ms(1);

	LCD_sendCommand_8bit(DIS_ON_OFF);
	_delay_ms(1);

	LCD_sendCommand_8bit(DIS_CLEAR);
	_delay_ms(1.53);

	LCD_sendCommand_8bit(ENTRY_MOOD);
	_delay_ms(1);

}


