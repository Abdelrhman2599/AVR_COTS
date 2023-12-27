/*
 * EXITI_Register.h
 *
 *  Created on: 25 Dec 2023
 *      Author: MR.X
 */

#ifndef EXITI_REGISTER_H_
#define EXITI_REGISTER_H_

#define GICR (*(volatile uint8*)0x5b)   //Global interrupt control register

#define INT1 7 /*bit 7 to enable interrupt 1*/
#define INT0 6 /*bit 7 to enable interrupt 1*/
#define INT2 5 /*bit 7 to enable interrupt 1*/

#define MCUCR (*(volatile uint8*)0x55)  //MCU control register

#define ISC11 3
#define ISC10 2

#define ISC01 1
#define ISC00 0

#define MCUCSR (*(volatile uint8*)0x54) //MCU control and status register

#define ISC2  6

#endif /* EXITI_REGISTER_H_ */
