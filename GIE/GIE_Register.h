/*
 * GIE_Register.h
 *
 *  Created on: 22 Dec 2023
 *      Author: MR.X
 */

#ifndef GIE_REGISTER_H_
#define GIE_REGISTER_H_

 #define STATUS_REGISTER					*((volatile uint8*)0x5F)
/*bit responsible for enabling global interrupt*/
#define STATUS_REGISTER_I				7




#endif /* GIE_REGISTER_H_ */
