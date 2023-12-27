/*
 * GIE_Program.c
 *
 *  Created on: 22 Dec 2023
 *      Author: MR.X
 */
#include "DIO/bitmath.h"
#include "DIO/stdTypes.h"

#include"GIE_Register.h"
#include "GIE_Interface.h"


void GIE_enableGlobalInterrupt(void)
{
	SET_BIT(STATUS_REGISTER,STATUS_REGISTER_I);
}
void GIE_disableGlobalInterrupt(void)
{
	CLEAR_BIT(STATUS_REGISTER,STATUS_REGISTER_I);

}


