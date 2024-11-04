/************************************/
/*Author   :  Ahmed Ali             */
/*Date     :  8 AUG 2020            */
/*Version  :  V01                   */
/************************************/

#include "RCC_interface.h"  


void RCC_voidInitSysClock()
{


	    // 1. Enable HSI if selected
	#if CLOCK_TYPE == RCC_HSI
	    RCC_CR |= (1 << RCC_CR_HSION);  // Enable HSI

	// 2. Enable HSE if selected
	#elif CLOCK_TYPE == RCC_HSE
	    #if HSE_BYPASS == RCC_HSE_BYPASS
	        RCC_CR |= (1 << RCC_CR_HSEBYP);  // Enable HSE Bypass
	    #endif
	    RCC_CR |= (1 << RCC_CR_HSEON);  // Enable HSE

	// 3. Configure PLL if selected
	#elif CLOCK_TYPE == RCC_PLL
	    // Configure HSE or HSI as input source for PLL
	    #if PLL_SOURCE == RCC_PLL_IN_HSI_DIV_2
	        RCC_CFGR &= ~(1 << RCC_CFGR_PLLSRC);  // Set PLL to HSI divided by 2
	    #elif PLL_SOURCE == RCC_PLL_IN_HSE
	        RCC_CFGR |= (1 << RCC_CFGR_PLLSRC);  // Set PLL to HSE
	    #elif PLL_SOURCE == RCC_PLL_IN_HSE_DIV_2
	        RCC_CFGR |= (1 << RCC_CFGR_PLLSRC);  // Set PLL to HSE divided by 2
	    #endif

	    // Set the PLL multiplication factor
	    RCC_CFGR |= ((PLL_MULTIPLIER - 2) << RCC_CFGR_PLLMUL);  // Set multiplication factor minus 2

	    // Enable PLL
	    RCC_CR |= (1 << RCC_CR_PLLON);  // Enable PLL
	#endif

	    // 4. Set the main system clock source
	    RCC_CFGR &= ~(0x3 << RCC_CFGR_SW);  // Clear previous values
	    RCC_CFGR |= (CLOCK_TYPE << RCC_CFGR_SW);  // Set main clock source
}



void RCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PerId) {
    switch (Copy_u8BusId)
    {
        case RCC_AHB:
            RCC_AHBENR |= (1 << Copy_u8PerId);
            break;

        case RCC_APB1:
            RCC_APB1ENR |= (1 << Copy_u8PerId);
            break;

        case RCC_APB2:
            RCC_APB2ENR |= (1 << Copy_u8PerId);
            break;

    }
}

void RCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PerId)
{
    switch (Copy_u8BusId) {
        case RCC_AHB:
            RCC_AHBENR &= ~(1 << Copy_u8PerId); 
            break;

        case RCC_APB1:
            RCC_APB1ENR &= ~(1 << Copy_u8PerId); 
            break;

        case RCC_APB2:
            RCC_APB2ENR &= ~(1 << Copy_u8PerId);
            break;

    }
}


u8 RCC_u8GetClockSource() {
    u32 clock_source;


    clock_source = (RCC_CFGR >> 2) & 0x03;

    return clock_source;
}
