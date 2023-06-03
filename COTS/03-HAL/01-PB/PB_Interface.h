/******************************************************/
/*      Author  : Nour                                */
/*      Data    : 20-10-2022                          */
/*      version : V01                                 */
/******************************************************/

#ifndef HAL_PB_PB_INTERFACE_H_
#define HAL_PB_PB_INTERFACE_H_

#if   PB_MODE   ==   PB_ACTIVE_LOW
#define PB_PRESSED            0
#define PB_RELEASED           1
#elif PB_MODE   ==   PB_ACTIVE_HIGH
#define PB_PRESSED            1
#define PB_RELEASED           0
#endif

void H_PB_Void_PBInit();
u8   H_PB_U8_PBRead();

#endif /* HAL_PB_PB_INTERFACE_H_ */
