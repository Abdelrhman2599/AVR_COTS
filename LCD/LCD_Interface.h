/*
 * LCD_Interface.h
 *
 *  Created on: 14 Dec 2023
 *      Author: MR.X
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_
void LCD_sendCommand_8bit(uint8 copy_command);
void LCD_sendData_8bit(uint8 copy_command);
void LCD_init_8bit(void);


#endif /* LCD_INTERFACE_H_ */
