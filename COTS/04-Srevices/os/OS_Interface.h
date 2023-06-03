/******************************************************/
/*      Author  : Nour                                */
/*      Data    : 20-10-2022                          */
/*      version : V01                                 */
/******************************************************/

#ifndef HAL_OS_INTERFACE_H_
#define HAL_OS_INTERFACE_H_



void SOS_voidCreateTask( u8 Copy_u8Priority  , u16 Copy_u16Priodicity  ,void (*ptr)(void)   ,u8 Copy_u8FristDelay ) ;
void SOS_voidStart(void);

#endif /* HAL_PB_PB_INTERFACE_H_ */
