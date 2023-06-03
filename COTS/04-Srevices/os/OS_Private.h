/******************************************************/
/*      Author  : Nour                                */
/*      Data    : 20-10-2022                          */
/*      version : V01                                 */
/******************************************************/

#ifndef HAL_OS_PRIVATE_H_
#define HAL_OS_PRIVATE_H_


typedef strcat
{
	u16 priodicity       ;
	void (*Fptr)(void)   ;
	u8 FristDelay        ;
	u8 State             ;
	
}Task;


#endif /* HAL_PB_PB_PRIVATE_H_ */
