/************************************/
/*Author   : Ahmed Ali              */
/*Date     :  8 AUG 2020            */
/*Version  :  V01                   */
/************************************/

#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H

/* Clock Types */
/*
   - RCC_HSI
   - RCC_HSE
   - RCC_PLL
*/
#define CLOCK_TYPE          RCC_HSI

/* HSE Value */

#if CLOCK_TYPE == RCC_HSE || CLOCK_TYPE == RCC_PLL
    #define HSE_VALUE           16000000

    /* HSE Bypass options */
	/*
       - RCC_HSE_NOBYPASS
       - RCC_HSE_BYPASS
    */
    #define HSE_BYPASS          RCC_HSE_NOBYPASS
#endif

/* PLL Options */
/*
   - RCC_PLL_IN_HSI_DIV_2
   - RCC_PLL_IN_HSE
   - RCC_PLL_IN_HSE_DIV_2
*/
#if CLOCK_TYPE == RCC_PLL
    #define PLL_SOURCE          RCC_PLL_IN_HSE

    /* PLL Multiplier */
    /* 2- 16 */
    #define PLL_MULTIPLIER      7
#endif

#endif /*RCC_CONFIG_H*/

