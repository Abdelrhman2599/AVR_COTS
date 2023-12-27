/*
 * DIO_Interface.h
 *
 *  Created on: 8 Dec 2023
 *      function prototypes for DIO Driver
 */


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_
/* Macros for*/
#define DIO_PORTA   0
#define DIO_PORTB   1
#define DIO_PORTC   2
#define DIO_PORTD   3

#define PIN0    0
#define PIN1    1
#define PIN2    2
#define PIN3    3
#define PIN4    4
#define PIN5    5
#define PIN6    6
#define PIN7    7

#define OUTPUT  0
#define INPUT   1

#define OUTPUT_HIGH 1
#define OUTPUT_LOW  0


#define PORT_OUTPUT  0xff
#define PORT_INPUT   0x00

#define PORT_OUTPUT_HIGH 0xff
#define PORT_OUTPUT_LOW  0x00




/*function prototype for DIO Driver*/
uint8 DIO_setPinDirection(uint8 copy_port,
		              uint8 copy_pin,
					  uint8 copy_direction);

uint8 DIO_setPinValue(uint8 copy_port,
		              uint8 copy_pin,
					  uint8 copy_value);

uint8 DIO_setPortDirection(uint8 copy_port,
					  uint8 copy_direction);

uint8 DIO_setPortValue(uint8 copy_port,
					  uint8 copy_value);

uint8 DIO_getPinValue(uint8 copy_port,
		              uint8 copy_pin,
					  uint8* copy_value);

void DIO_setInternalPullup(uint8 copy_port,
		                    uint8 copy_pin);



#endif /* DIO_INTERFACE_H_ */
