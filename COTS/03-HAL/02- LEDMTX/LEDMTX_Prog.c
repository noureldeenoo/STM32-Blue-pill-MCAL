/******************************************************/
/*      Author  : Nour                                */
/*      Data    : 20-10-2022                          */
/*      version : V01                                 */
/******************************************************/

 
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "LEDMTX_Interface.h"
#include "LEDMTX_private.h"
#include "LEDMTX_Config.h"

#include "DIO_interface.h"
#include "STK_interface.h"



void HLEDMTX_voidInit()
{

	MGPIO_VoidSetPinDirection( LEDMTX_ROW0_PIN , OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection( LEDMTX_ROW1_PIN , OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection( LEDMTX_ROW2_PIN , OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection( LEDMTX_ROW3_PIN , OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection( LEDMTX_ROW4_PIN , OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection( LEDMTX_ROW5_PIN , OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection( LEDMTX_ROW6_PIN , OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection( LEDMTX_ROW7_PIN , OUTPUT_SPEED_2MHZ_PP);

	MGPIO_VoidSetPinDirection( LEDMTX_COL0_PIN , OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection( LEDMTX_COL1_PIN , OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection( LEDMTX_COL2_PIN , OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection( LEDMTX_COL3_PIN , OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection( LEDMTX_COL4_PIN , OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection( LEDMTX_COL5_PIN , OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection( LEDMTX_COL6_PIN , OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection( LEDMTX_COL7_PIN , OUTPUT_SPEED_2MHZ_PP);
	
	
}


void HLEDMTX_voidDisplay(u8 *Copy_u8Data)
{

while(1)
{	
	/*Enable ROW 0 */
	HLEDMTX_voidDisableAllRows();
	HLEDMTX_voidSetColValues(Copy_u8Data[0]);
	MGPIO_VoidSetPinValue( LEDMTX_ROW0_PIN ,HIGH);
	MSTK_voidSetBusyWait(2500);
	
	/*Enable ROW 1 */
	HLEDMTX_voidDisableAllRows();
	HLEDMTX_voidSetColValues(Copy_u8Data[1]);
	MGPIO_VoidSetPinValue( LEDMTX_ROW1_PIN , HIGH);
	MSTK_voidSetBusyWait(2500);
	
	/*Enable ROW 2 */
	HLEDMTX_voidDisableAllRows();
	HLEDMTX_voidSetColValues(Copy_u8Data[2]);
	MGPIO_VoidSetPinValue( LEDMTX_ROW2_PIN , HIGH);
	MSTK_voidSetBusyWait(2500);
	
	/*Enable ROW 3 */
	HLEDMTX_voidDisableAllRows();
	HLEDMTX_voidSetColValues(Copy_u8Data[3]);
	MGPIO_VoidSetPinValue( LEDMTX_ROW3_PIN , HIGH);
	MSTK_voidSetBusyWait(2500);
	
	/*Enable ROW 4 */
	HLEDMTX_voidDisableAllRows();
	HLEDMTX_voidSetColValues(Copy_u8Data[4]);
	MGPIO_VoidSetPinValue( LEDMTX_ROW4_PIN , HIGH);
	MSTK_voidSetBusyWait(2500);
	
	/*Enable ROW 5 */
	HLEDMTX_voidDisableAllRows();
	HLEDMTX_voidSetColValues(Copy_u8Data[5]);
	MGPIO_VoidSetPinValue( LEDMTX_ROW5_PIN , HIGH);
	MSTK_voidSetBusyWait(2500);
	
	/*Enable ROW 6 */
	HLEDMTX_voidDisableAllRows();
	HLEDMTX_voidSetColValues(Copy_u8Data[6]);
	MGPIO_VoidSetPinValue( LEDMTX_ROW6_PIN , HIGH);
	MSTK_voidSetBusyWait(2500);
	
	/*Enable ROW 7 */
	HLEDMTX_voidDisableAllRows();
	HLEDMTX_voidSetColValues(Copy_u8Data[7]);
	MGPIO_VoidSetPinValue( LEDMTX_ROW7_PIN , HIGH);
	MSTK_voidSetBusyWait(2500);	

}
}


static void HLEDMTX_voidDisableAllRows()
{
	/*Disable all ROW */
	MGPIO_VoidSetPinValue( LEDMTX_ROW0_PIN , LOW);
	MGPIO_VoidSetPinValue( LEDMTX_ROW1_PIN , LOW);  /* GPIO B*/
	MGPIO_VoidSetPinValue( LEDMTX_ROW2_PIN , LOW);
	MGPIO_VoidSetPinValue( LEDMTX_ROW3_PIN , LOW);
	MGPIO_VoidSetPinValue( LEDMTX_ROW4_PIN , LOW);
	MGPIO_VoidSetPinValue( LEDMTX_ROW5_PIN , LOW);
	MGPIO_VoidSetPinValue( LEDMTX_ROW6_PIN , LOW);
	MGPIO_VoidSetPinValue( LEDMTX_ROW7_PIN , LOW);
}

static void HLEDMTX_voidSetColValues(u8 Copy_u8Values)
{
	u8 Local_u8Bit = 0;

	Local_u8Bit =  GET_BIT(Copy_u8Values,0);
	MGPIO_VoidSetPinValue( LEDMTX_COL0_PIN , Local_u8Bit);
	
	Local_u8Bit =  GET_BIT(Copy_u8Values,1);
	MGPIO_VoidSetPinValue( LEDMTX_COL1_PIN , Local_u8Bit);
	
	Local_u8Bit =  GET_BIT(Copy_u8Values,2);
	MGPIO_VoidSetPinValue( LEDMTX_COL2_PIN , Local_u8Bit);
	
	Local_u8Bit =  GET_BIT(Copy_u8Values,3);
	MGPIO_VoidSetPinValue( LEDMTX_COL3_PIN , Local_u8Bit);
	
	Local_u8Bit =  GET_BIT(Copy_u8Values,4);
	MGPIO_VoidSetPinValue( LEDMTX_COL4_PIN , Local_u8Bit);
	
	Local_u8Bit =  GET_BIT(Copy_u8Values,5);
	MGPIO_VoidSetPinValue( LEDMTX_COL5_PIN , Local_u8Bit);
	
	Local_u8Bit =  GET_BIT(Copy_u8Values,6);
	MGPIO_VoidSetPinValue( LEDMTX_COL6_PIN , Local_u8Bit);
	
	Local_u8Bit =  GET_BIT(Copy_u8Values,7);
	MGPIO_VoidSetPinValue( LEDMTX_COL7_PIN , Local_u8Bit);
}




