/**********************************************************/
/* Author    : Ahmed Assaf                                */
/* Date      : 19 August 2020                             */
/* Version   : V01                                        */
/**********************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"

void MNVIC_voidInit(void)
{
	SCB_AIRCR = MNVIC_GROUP_SUB_DISTRIBUTION ;
}

void MNVIC_voidEnableInterrupt (u8 Copy_U8_InitPosition)
{
	if ( Copy_U8_InitPosition <= 31)
	{
		NVIC_ISER0 = (1 << Copy_U8_InitPosition);
	}
	
	else if (  Copy_U8_InitPosition <= 59)
	{
		Copy_U8_InitPosition -= 32;
		NVIC_ISER1 = (1 << Copy_U8_InitPosition);
	}
	
	else
	{
		/* Return Error */
	}
	
}



void MNVIC_voidDisableInterrupt (u8 Copy_U8_InitPosition)
{
	if ( Copy_U8_InitPosition <= 31)
	{
		NVIC_ICER0 = (1 << Copy_U8_InitPosition);
	}
	
	else if (  Copy_U8_InitPosition <= 59)
	{
		Copy_U8_InitPosition -= 32;
		NVIC_ICER1 = (1 << Copy_U8_InitPosition);
	}
	
	else
	{
		/* Return Error */
	}
	
}


void MNVIC_voidSetPendingFlag(u8 Copy_U8_InitPosition)
{
	if ( Copy_U8_InitPosition <= 31)
	{
		NVIC_ISPR0 = (1 << Copy_U8_InitPosition);
	}
	
	else if (  Copy_U8_InitPosition <= 59)
	{
		Copy_U8_InitPosition -= 32;
		NVIC_ISPR1 = (1 << Copy_U8_InitPosition);
	}
	
	else
	{
		/* Return Error */
	}
	
}

void MNVIC_voidClearPendingFlag(u8 Copy_U8_InitPosition)
{
	if ( Copy_U8_InitPosition <= 31)
	{
		NVIC_ICPR0 = (1 << Copy_U8_InitPosition);
	}
	
	else if (  Copy_U8_InitPosition <= 59)
	{
		Copy_U8_InitPosition -= 32;
		NVIC_ICPR1 = (1 << Copy_U8_InitPosition);
	}
	
	else
	{
		/* Return Error */
	}
	
}







u8 MNVIC_u8GetActiveFlag(u8 Copy_U8_InitPosition)
{
	u8 Local_u8Result = 0;
	
	if ( Copy_U8_InitPosition <= 31)
	{
		Local_u8Result = GET_BIT(NVIC_IABR0,Copy_U8_InitPosition);
	}
	
	else if (  Copy_U8_InitPosition <= 59)
	{
		Copy_U8_InitPosition -= 32;
		Local_u8Result = GET_BIT(NVIC_IABR1,Copy_U8_InitPosition);
	}
	
	else
	{
		/* Return Error */
	}
	
	return Local_u8Result;
	
}

void MNVIC_voidSetPriority (s8 Copy_S8_InitPosition , u8 Copy_U8_GroupPriority , u8 Copy_U8_SubPriority )
{
	u32 Local_U32_Priority = Copy_U8_SubPriority |( Copy_U8_GroupPriority <<(( MNVIC_GROUP_SUB_DISTRIBUTION - 0x05FA0300) / 256 )) ;

	/* core periphral */
 	/* Extranl periphral */
	if(Copy_S8_InitPosition >= 0)
	{
	    NVIC_IPR[Copy_S8_InitPosition] = (Local_U32_Priority << 4) ;
	}

}


