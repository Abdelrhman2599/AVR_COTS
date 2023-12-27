/*
 * KEYPAD_Config.h
 *
 *  Created on: 15 Dec 2023
 *      Author: MR.X
 */

#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

#define COL_NUM 4
#define ROW_NUM 4
#define KEYPAD_BUTTONS {{1,2,3,4},{5,6,7,8},{9,10,11,12,},{13,14,15,16}}

#define KEYPAD_PORT DIO_PORTB

#define ROW1  PIN0
#define ROW2  PIN1
#define ROW3  PIN2
#define ROW4  PIN3

#define COL1  PIN4
#define COL2  PIN5
#define COL3  PIN6
#define COL4  PIN7

#endif /* KEYPAD_CONFIG_H_ */
