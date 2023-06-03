/*********************************************************************************/
/* Author    : Ahmed Assaf                                                       */
/* Version   : V01                                                               */
/* Date      : 8 August 2020                                                     */
/*********************************************************************************/
#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

#define RCC_AHB       0 
#define RCC_APB1      1
#define RCC_APB2      2


/*for AHB*/
#define PerId_DMA1          0
#define PerId_DMA2          1
#define PerId_SRAM          2
#define PerId_FLITF         4
#define PerId_CRCE          6
#define PerId_FSMC          8
#define PerId_SDIO          10


/*For APB1 */
#define PerId_TIM2           0
#define PerId_TIM3           1
#define PerId_TIM4           2
#define PerId_TIM5           3
#define PerId_TIM6           4
#define PerId_TIM7           5
#define PerId_TIM12          6
#define PerId_TIM13          7
#define PerId_TIM14          8
#define PerId_WWD            11
#define PerId_SPI2           14
#define PerId_SPI3           15
#define PerId_USART2         17
#define PerId_USART3         18
#define PerId_USART4         19
#define PerId_USART5         20
#define PerId_I2C1           21
#define PerId_I2C2           22
#define PerId_USB            23
#define PerId_CAN            25
#define PerId_BKP            27
#define PerId_PWR            28
#define PerId_DAC            29


/*For APB2 */
#define PerId_AFIO           0
#define PerId_IOPA           2
#define PerId_IOPB           3
#define PerId_IOPC           4
#define PerId_ADC1           9
#define PerId_ADC2           10
#define PerId_TIM1           11
#define PerId_SPI1           12
#define PerId_TIM8           13
#define PerId_USART          14
#define PerId_ADC3           15
#define PerId_TIM9           19
#define PerId_TIM10          20
#define PerId_TIM11          21


void MRCC_voidInitSysClock(void);
void MRCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PerId);
void MRCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PerId);


#endif
