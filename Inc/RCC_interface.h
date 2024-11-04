/************************************/
/*Author   :  Ahmed Ali             */
/*Date     :  8 AUG 2020            */
/*Version  :  V01                   */
/************************************/

#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_private.h"
#include "RCC_config.h"


void RCC_voidInitSysClock();
void RCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PerId);
void RCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PerId);
u8 RCC_u8GetClockSource();


#define RCC_AHB       0
#define RCC_APB1      1
#define RCC_APB2      2

/* APB1 Peripheral Bit Positions */
#define RCC_TIM2          0  // TIM2 Enable
#define RCC_TIM3          1  // TIM3 Enable
#define RCC_TIM4          2  // TIM4 Enable
#define RCC_USART2        17 // USART2 Enable
#define RCC_I2C1          21 // I2C1 Enable
#define RCC_WWDG          11 // Window Watchdog Enable
#define RCC_SPI2          14 // SPI2 Enable

/* APB2 Peripheral Bit Positions */
#define RCC_AFIO          0  // AFIO Enable
#define RCC_GPIOA         2  // GPIOA Enable
#define RCC_GPIOB         3  // GPIOB Enable
#define RCC_GPIOC         4  // GPIOC Enable
#define RCC_GPIOD         5  // GPIOD Enable
#define RCC_GPIOE         6  // GPIOE Enable
#define RCC_USART1        14 // USART1 Enable
#define RCC_SPI1          12 // SPI1 Enable
#define RCC_ADC1          9  // ADC1 Enable
#define RCC_TIM1          11 // TIM1 Enable

/* AHB Peripheral Bit Positions */
#define RCC_DMA1          0  // DMA1 Enable
#define RCC_SRAM          2  // SRAM Enable
#define RCC_FLITF         4  // FLITF Enable
#define RCC_CRC           6  // CRC Enable




/* Calculate the System Frequency */

#if CLOCK_TYPE == RCC_HSI
    #define SYSTEM_FREQ         8000000UL
#elif CLOCK_TYPE == RCC_HSE
    #define SYSTEM_FREQ         HSE_VALUE
#elif CLOCK_TYPE == RCC_PLL
	#if PLL_SOURCE ==RCC_PLL_IN_HSE
    	#define SYSTEM_FREQ         (HSE_VALUE * (PLL_MULTIPLIER))
	#elif PLL_SOURCE ==RCC_PLL_IN_HSE_DIV_2
		#define SYSTEM_FREQ         (HSE_VALUE/2 * (PLL_MULTIPLIER))
	#endif
#endif

#endif 
