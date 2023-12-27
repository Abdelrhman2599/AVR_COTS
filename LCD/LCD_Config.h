/*
 * LCD_Config.h
 *
 *  Created on: 14 Dec 2023
 *      Author: MR.X
 */

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

#define LCD_DATA_PORT     DIO_PORTD

#define LCD_CONTROL_PORT  DIO_PORTC

#define RS  PIN0
#define RW  PIN1
#define Enable PIN2

/*8bit, 2 LINEs, 5*7 MOOD */
#define FUNCTION_SET  0b111000

/*display on, cursor off, blinking off */
#define DIS_ON_OFF    0b1100

#define DIS_CLEAR     0b1

#define ENTRY_MOOD   0b110





#endif /* LCD_CONFIG_H_ */
