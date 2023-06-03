/******************************************************/
/*      Author  : Nour                                */
/*      Data    : 20-10-2022                          */
/*      version : V01                                 */
/******************************************************/

 
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "PB_Interface.h"
#include "PB_Config.h"
#include "PB_private.h"
#include "DIO_interface.h"

void H_PB_Void_PBInit()
{
    MGPIO_VidSetPinDirection(PB1_PORT, PB1_PIN, INPUT_PULLUP_PULLDOWN);
#if(PB_MODE == PB_ACTIVE_LOW)
	MGPIO_voidSetInputPull(PB1_PORT ,PB1_PIN ,UP);
#elif(PB_MODE == PB_ACTIVE_HIGH) 
	MGPIO_voidSetInputPull(PB1_PORT ,PB1_PIN ,DOWN);
#endif
}

u8 H_PB_U8_PBRead()
{
	u8 Local_U8_Reading = PB_RELEASED;

		if(MGPIO_u8GetPinValue(PB1_PORT,PB1_PIN) == PB_PRESSED)
		{
			
			MSTK_voidSetBusyWait( 100000 );
		
			if(MGPIO_u8GetPinValue(PB1_PORT,PB1_PIN) == PB_PRESSED)
			{
				while(MGPIO_u8GetPinValue(PB1_PORT,PB1_PIN) == PB_PRESSED);
				Local_U8_Reading = PB_PRESSED;
			}
		}
	
	return Local_U8_Reading;
}






