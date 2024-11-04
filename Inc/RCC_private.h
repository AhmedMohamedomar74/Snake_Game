/************************************/
/*Author   :  Ahmed Ali             */
/*Date     :  8 AUG 2020            */
/*Version  :  V01                   */
/************************************/

#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

/* Register Definitions*/

#define RCC_CR *((u32 *)0x40021000)
#define RCC_CFGR *((u32 *)0x40021004)
#define RCC_CIR *((u32 *)0x40021008)
#define RCC_APB2RSTR *((u32 *)0x4002100C)
#define RCC_APB1RSTR *((u32 *)0x40021010)
#define RCC_AHBENR *((u32 *)0x40021014)
#define RCC_APB2ENR *((u32 *)0x40021018)
#define RCC_APB1ENR *((u32 *)0x4002101C)
#define RCC_BDCR *((u32 *)0x40021020)
#define RCC_CSR *((u32 *)0x40021024)

/* Clock Types */
#define RCC_HSI 0
#define RCC_HSE 1
#define RCC_PLL 2

/* HSE Bypass options */
#define RCC_HSE_NOBYPASS 0
#define RCC_HSE_BYPASS 1

/* PLL Options */
#define RCC_PLL_IN_HSI_DIV_2 0
#define RCC_PLL_IN_HSE 1
#define RCC_PLL_IN_HSE_DIV_2 3

/***********************************************/
/******************bits Positions***************/
/***********************************************/

/* Clock control register (RCC_CR) bits */
#define RCC_CR_HSION 0   // HSI clock enable
#define RCC_CR_HSIRDY 1  // HSI clock ready flag
#define RCC_CR_HSITRIM 3 // HSI trimming bits (3 to 7)
#define RCC_CR_HSICAL 8  // HSI calibration bits (8 to 15)
#define RCC_CR_HSEON 16  // HSE clock enable
#define RCC_CR_HSERDY 17 // HSE clock ready flag
#define RCC_CR_HSEBYP 18 // HSE bypass
#define RCC_CR_CSSON 19  // Clock security system enable
#define RCC_CR_PLLON 24  // PLL enable
#define RCC_CR_PLLRDY 25 // PLL clock ready flag

/* Clock configuration register (RCC_CFGR) */
#define RCC_CFGR_SW 0        // System clock switch (bits 0-1)
#define RCC_CFGR_SWS 2       // System clock switch status (bits 2-3)
#define RCC_CFGR_HPRE 4      // AHB prescaler (bits 4-7)
#define RCC_CFGR_PPRE1 8     // APB1 prescaler (bits 8-10)
#define RCC_CFGR_PPRE2 11    // APB2 prescaler (bits 11-13)
#define RCC_CFGR_ADCPRE 14   // ADC prescaler (bits 14-15)
#define RCC_CFGR_PLLSRC 16   // PLL entry clock source (bit 16)
#define RCC_CFGR_PLLXTPRE 17 // HSE divider for PLL entry (bit 17)
#define RCC_CFGR_PLLMUL 18   // PLL multiplication factor (bits 18-21)
#define RCC_CFGR_USBPRE 22   // USB prescaler (bit 22)
#define RCC_CFGR_MCO 24      // Microcontroller clock output (bits 24-26)

#endif
