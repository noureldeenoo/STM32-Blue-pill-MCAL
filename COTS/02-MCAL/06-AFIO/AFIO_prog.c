/******************************************************/
/*      Author  : Nour                                */
/*      Data    : 23-10-2022                          */
/*      version : V01                                 */
/******************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "AFIO_intrface.h"
#include "AFIO_private.h"
#include "AFIO_Config.h"

void MAFIO_void_SetEXTIConfiguration (u8 Copy_u8Pin ,u8 Copy_u8Port )
{
	u8 Local_u8RegIndex = 0 ;
	if ( Copy_u8Pin <= 3 )
	{
		Local_u8RegIndex = 0 ;
	}
	else if ( Copy_u8Pin <= 7 )
	{
		Local_u8RegIndex = 1 ;
		Copy_u8Pin -= 4 ;
	}
	else if ( Copy_u8Pin <= 11 )
	{
		Local_u8RegIndex = 2 ;
		Copy_u8Pin -= 8 ;
	}
	else if ( Copy_u8Pin <= 15 )
	{
		Local_u8RegIndex = 3 ;
		Copy_u8Pin -= 12 ;
	}
	else 
	{
		
	}
	
	AFIO-> EXTICR[Local_u8RegIndex]  &=~ ((0b1111) << (Copy_u8Pin *4)) ;
	AFIO-> EXTICR[Local_u8RegIndex]  |= ((Copy_u8Port) << (Copy_u8Pin *4)) ;
}
