/*
 * DIO_AUTOSAR_Interface.h
 *
 *  Created on: 15 Dec 2023
 *      Author: MR.X
 */

#ifndef DIO_PORT_INTERFACE_H_
#define DIO_PORT_INTERFACE_H_

#define CONC(b7,b6,b5,b4,b3,b2,b1,b0)         CONC_HELPER(b7,b6,b5,b4,b3,b2,b1,b0)

#define CONC_HELPER(b7,b6,b5,b4,b3,b2,b1,b0)  0b##b7##b6##b5##b4##b3##b2##b1##b0
#endif /* DIO_PORT_INTERFACE_H_ */
