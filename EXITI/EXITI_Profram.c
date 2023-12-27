/*
 * EXITI_Profram.c
 *
 *  Created on: 25 Dec 2023
 *      Author: MR.X
 */
#include"bitmath.h"
#include"stdTypes.h"

#include "EXITI_Register.h"
#include "EXITI_Config.h"
#include "EXITI_Interface.h"

void External_INT1INIT(void)
{
#if INT1_CONTROL_LEVEL == LOW_LEVEL
	SET_BIT(GICR,INT1);
	CLEAR_BIT(MCUCR,ISC10);
	CLEAR_BIT(MCUCR,ISC11);


#elif INT1_CONTROL_LEVEL == ON_CHANGE
	SET_BIT(GICR,INT1);
	SET_BIT(MCUCR,ISC10);
	CLEAR_BIT(MCUCR,ISC11);

#elif  INT1_CONTROL_LEVEL == FALLING_EDGE
	SET_BIT(GICR,INT1);
	CLEAR_BIT(MCUCR,ISC10);
	SET_BIT(MCUCR,ISC11);

#elif INT1_CONTROL_LEVEL == RISING_EDGE

	SET_BIT(GICR,INT1);
	SET_BIT(MCUCR,ISC11);
	SET_BIT(MCUCR,ISC10);
#else
#error "wrong EXTI INT1 sense control configuration, please choose the right one"
#endif

}

void External_INT0INIT(void)
{
#if INT0_CONTROL_LEVEL == LOW_LEVEL
	SET_BIT(GICR,INT1);
	CLEAR_BIT(MCUCR,ISC00);
	CLEAR_BIT(MCUCR,ISC01);


#elif INT0_CONTROL_LEVEL == ON_CHANGE
	SET_BIT(GICR,INT1);
	SET_BIT(MCUCR,ISC00);
	CLEAR_BIT(MCUCR,ISC01);

#elif  INT0_CONTROL_LEVEL == FALLING_EDGE
	SET_BIT(GICR,INT1);
	CLEAR_BIT(MCUCR,ISC00);
	SET_BIT(MCUCR,ISC01);

#elif INT0_CONTROL_LEVEL == RISING_EDGE

	SET_BIT(GICR,INT1);
	SET_BIT(MCUCR,ISC00);
	SET_BIT(MCUCR,ISC01);
#else
#error "wrong EXTI INT0 sense control configuration, please choose the right one"
#endif


}
void External_INT2INIT(void)
{

#if  INT2_CONTROL_LEVEL == FALLING_EDGE
	SET_BIT(GICR,INT1);
	CLEAR_BIT(MCUCSR,ISC2);


#elif INT0_CONTROL_LEVEL == RISING_EDGE

	SET_BIT(GICR,INT1);
	SET_BIT(MCUCSR,ISC2);
#else
#error "wrong EXTI INT2 sense control configuration, please choose the right one"

#endif


}

