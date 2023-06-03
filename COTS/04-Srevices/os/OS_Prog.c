/******************************************************/
/*      Author  : Nour                                */
/*      Data    : 20-10-2022                          */
/*      version : V01                                 */
/******************************************************/

 
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"

#include "OS_Interface.h"
#include "OS_Config.h"
#include "OS_private.h"


/*Array of tasks  Array of strcats */
static Task OS_Tasks[NUMBER_OF_TASKES] = {NULL};

void SOS_voidCreateTask( u8 Copy_u8Priority  , u16 Copy_u16Priodicity  ,void (*ptr)(void)   ,u8 Copy_u8FristDelay )
{
	OS_Tasks[Copy_u8Priority].priodicity = Copy_u8Priority ;
	OS_Tasks[Copy_u8Priority].Fptr = ptr ;
	
}

void SOS_voidStart(void)
{
	MSTK_voidInit();
	MSTK_voidSetIntervalPeriodic( 1000 , SOS_voidScheduler );

}

volatile u16 Global_u16TickCounts = 0 ;

/*
void SOS_voidScheduler(void)
{
	for(u8 i =0 ; i< NUMBER_OF_TASKES ;i++)
	{
		if( (Global_u16TickCounts % OS_Tasks[i].priodicity )== 0)
		{
			OS_Tasks[i].Fptr() ; 
		}
	}
	Global_u16TickCounts++
}
*/

void SOS_voidScheduler(void)
{
	for(u8 i =0 ; i< NUMBER_OF_TASKES ;i++)
	{
		 ((Global_u16TickCounts % OS_Tasks[i].priodicity )== 0)  &&
		if( (OS_Tasks[i].Fptr != NULL ) &&  (OS_Tasks[i].State == TASK_READY ) )
		{
			if((OS_Tasks[i].FristDelay == 0))
			{
				
				OS_Tasks[i].FristDelay = OS_Tasks[i].priodicity - 1 ;
				OS_Tasks[i].Fptr () ;
			}
			else
			{
				OS_Tasks[i].FristDelay-- ;
			}
		}
	}
	Global_u16TickCounts++
}




