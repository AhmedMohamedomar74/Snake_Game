/*
 * NVIC_interface.h
 *
 *  Created on: Oct 29, 2024
 *      Author: ahmed
 */

#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_private.h"
#include "NVIC_config.h"

#define NVIC_WWDG         0   // Window WatchDog
#define NVIC_PVD          1   // PVD through EXTI Line detection
#define NVIC_TAMPER       2   // Tamper
#define NVIC_RTC          3   // RTC
#define NVIC_FLASH        4   // Flash
#define NVIC_RCC          5   // RCC
#define NVIC_EXTI0        6   // EXTI Line0
#define NVIC_EXTI1        7   // EXTI Line1
#define NVIC_EXTI2        8   // EXTI Line2
#define NVIC_EXTI3        9   // EXTI Line3
#define NVIC_EXTI4        10  // EXTI Line4
#define NVIC_DMA1_Channel1 11 // DMA1 Channel 1
#define NVIC_DMA1_Channel2 12 // DMA1 Channel 2
#define NVIC_DMA1_Channel3 13 // DMA1 Channel 3
#define NVIC_DMA1_Channel4 14 // DMA1 Channel 4
#define NVIC_DMA1_Channel5 15 // DMA1 Channel 5
#define NVIC_DMA1_Channel6 16 // DMA1 Channel 6
#define NVIC_DMA1_Channel7 17 // DMA1 Channel 7
#define NVIC_ADC1_2       18  // ADC1 and ADC2
#define NVIC_USB_HP_CAN_TX 19 // USB High Priority or CAN TX
#define NVIC_USB_LP_CAN_RX0 20 // USB Low Priority or CAN RX0
#define NVIC_CAN_RX1      21  // CAN RX1
#define NVIC_CAN_SCE      22  // CAN SCE
#define NVIC_EXTI9_5      23  // EXTI Line[9:5]
#define NVIC_TIM1_BRK     24  // TIM1 Break
#define NVIC_TIM1_UP      25  // TIM1 Update
#define NVIC_TIM1_TRG_COM 26  // TIM1 Trigger and Commutation
#define NVIC_TIM1_CC      27  // TIM1 Capture Compare
#define NVIC_TIM2         28  // TIM2
#define NVIC_TIM3         29  // TIM3
#define NVIC_TIM4         30  // TIM4
#define NVIC_I2C1_EV      31  // I2C1 Event
#define NVIC_I2C1_ER      32  // I2C1 Error
#define NVIC_SPI1         35  // SPI1
#define NVIC_USART1       37  // USART1
#define NVIC_USART2       38  // USART2
#define NVIC_USART3       39  // USART3
#define NVIC_EXTI15_10    40  // EXTI Line[15:10]
#define NVIC_RTC_ALARM    41  // RTC Alarm
#define NVIC_USB_WAKEUP   42  // USB WakeUp
#define NVIC_TIM8_BRK     43  // TIM8 Break
#define NVIC_TIM8_UP      44  // TIM8 Update
#define NVIC_TIM8_TRG_COM 45  // TIM8 Trigger and Commutation
#define NVIC_TIM8_CC      46  // TIM8 Capture Compare
#define NVIC_ADC3         47  // ADC3
#define NVIC_FSMC         48  // FSMC
#define NVIC_SDIO         49  // SDIO
#define NVIC_TIM5         50  // TIM5
#define NVIC_SPI3         51  // SPI3
#define NVIC_UART4        52  // UART4
#define NVIC_UART5        53  // UART5
#define NVIC_TIM6         54  // TIM6
#define NVIC_TIM7         55  // TIM7
#define NVIC_DMA2_Channel1 56 // DMA2 Channel 1
#define NVIC_DMA2_Channel2 57 // DMA2 Channel 2
#define NVIC_DMA2_Channel3 58 // DMA2 Channel 3
#define NVIC_DMA2_Channel4 59 // DMA2 Channel 4
#define NVIC_DMA2_Channel5 60 // DMA2 Channel 5
#define NVIC_DMA2_Channel6 61 // DMA2 Channel 6
#define NVIC_DMA2_Channel7 62 // DMA2 Channel 7
#define NVIC_ETH          63  // ETH
#define NVIC_ETH_WKUP     64  // ETH WakeUp
#define NVIC_CAN2_RX0     65  // CAN2 RX0
#define NVIC_CAN2_RX1     66  // CAN2 RX1
#define NVIC_CAN2_SCE     67  // CAN2 SCE


void NVIC_Init();
void NVIC_EnableInterrupt(u8 int_Id);
void NVIC_DisableInterrupt(u8 int_Id);
void NVIC_SetPendingFlag(u8 int_Id);
void NVIC_ClearPendingFlag(u8 int_Id);
u8 NVIC_GetActiveFlag(u8 int_Id);
void NVIC_SetPriority(u8 int_Id, u8 group_priority, u8 subgroup_priority);

#endif /* NVIC_INTERFACE_H_ */
