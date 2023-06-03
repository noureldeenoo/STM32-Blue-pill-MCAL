/*****************************************/
/* Author  :  Ahmed Assaf                */
/* Version :  V01                        */
/* Date    : 26 August 2020              */
/*****************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_config.h"
#include "EXTI_private.h"


void MEXTI_voidInit(void)
{
#if EXTI_MODE == RISING_EDGE
    SET_BIT(EXTI->RTSR, EXTI_LINE );
#elif EXTI_MODE == FALLING_EDGE
    SET_BIT(EXTI->FTSR, EXTI_LINE );
#elif EXTI_MODE == ON_CHANGE
    SET_BIT(EXTI->RTSR, EXTI_LINE );
    SET_BIT(EXTI->FTSR, EXTI_LINE );
#else
	#error "wronge MODE choices"
#endif

    MEXTI_voidEnableEXTI( EXTI_LINE);
}
void MEXTI_voidSetSignalLatch(u8 Copy_u8EXTILine , u8 Copy_u8EXTISenseMode )
{
	switch(Copy_u8EXTISenseMode)
    {

    case RISING_EDGE    : SET_BIT(EXTI->RTSR, Copy_u8EXTILine );   break;
    case FALLING_EDGE   : SET_BIT(EXTI->FTSR, Copy_u8EXTILine );   break;
    case ON_CHANGE      : SET_BIT(EXTI->RTSR, Copy_u8EXTILine );
                          SET_BIT(EXTI->FTSR, Copy_u8EXTILine );   break;
	default :	                                                   break;
	}
	MEXTI_voidEnableEXTI( Copy_u8EXTILine);
}

void MEXTI_voidEnableEXTI(u8 Copy_u8EXTILine)
{
	SET_BIT(EXTI->IMR, Copy_u8EXTILine );
}
void MEXTI_voidDisableEXTI(u8 Copy_u8EXTILine)
{
	CLR_BIT(EXTI->IMR, Copy_u8EXTILine );
}
void MEXTI_voidSoftwareTriger(u8 Copy_u8EXTILine)
{
    CLR_BIT(EXTI->SWIER, Copy_u8EXTILine );
}
void MEXTI_voidSetCallBack_0( void (*Copy_voidPtr)(void) )
{
	EXTI0_CallBack = Copy_voidPtr ;
}

void MEXTI_voidSetCallBack_1( void (*Copy_voidPtr)(void) )
{
	EXTI0_CallBack = Copy_voidPtr ;
}
void EXTI0_IRQHandler(void)
{
	EXTI0_CallBack();
	SET_BIT(EXTI->PR ,EXTI_LINE0);
}

void EXTI1_IRQHandler(void)
{
	EXTI1_CallBack();
	SET_BIT(EXTI->PR ,EXTI_LINE1);
}
