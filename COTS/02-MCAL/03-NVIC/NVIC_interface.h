/**********************************************************/
/* Author    : Ahmed Assaf                                */
/* Date      : 19 August 2020                             */
/* Version   : V01                                        */
/**********************************************************/
#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

void MNVIC_voidEnableInterrupt  (u8 Copy_U8_InitPosition);
void MNVIC_voidDisableInterrupt (u8 Copy_U8_InitPosition);
void MNVIC_voidSetPendingFlag   (u8 Copy_U8_InitPosition);
void MNVIC_voidClearPendingFlag (u8 Copy_U8_InitPosition);
u8 MNVIC_u8GetActiveFlag        (u8 Copy_U8_InitPosition);
void MNVIC_voidInit(void);
void MNVIC_voidSetPriority (s8 Copy_S8_InitPosition , u8 Copy_U8_GroupPriority , u8 Copy_U8_SubPriority );


#define GROUP0     0
#define GROUP1     1
#define GROUP2     2
#define GROUP3     3
#define GROUP4     4
#define GROUP5     5
#define GROUP6     6
#define GROUP7     7
#define GROUP8     8
#define GROUP9     9
#define GROUP10    10
#define GROUP11    11
#define GROUP12    12
#define GROUP13    13
#define GROUP14    14
#define GROUP15    15


#define SUB0     0
#define SUB1     1
#define SUB2     2
#define SUB3     3
#define SUB4     4
#define SUB5     5
#define SUB6     6
#define SUB7     7
#define SUB8     8
#define SUB9     9
#define SUB10    10
#define SUB11    11
#define SUB12    12
#define SUB13    13
#define SUB14    14
#define SUB15    15


#define POSITION_WWDG              0
#define POSITION_PVD               1
#define POSITION_TAMPER            2
#define POSITION_RTC               3
#define POSITION_FLASH             4
#define POSITION_RCC               5
#define POSITION_EXTI0             6
#define POSITION_EXTI1             7
#define POSITION_EXTI2             8
#define POSITION_EXTI3             9
#define POSITION_EXTI4             10
#define POSITION_DMA1_CHANNEL1     11
#define POSITION_DMA1_CHANNEL2     12
#define POSITION_DMA1_CHANNEL3     13
#define POSITION_DMA1_CHANNEL4     14
#define POSITION_DMA1_CHANNEL5     15
#define POSITION_DMA1_CHANNEL6     16
#define POSITION_DMA1_CHANNEL7     17



#endif
