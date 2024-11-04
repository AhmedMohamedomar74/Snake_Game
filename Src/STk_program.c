/************************************/
/*Author   :  Ahmed Ali             */
/*Date     :  25 AUG 2020           */
/*Version  :  V01                   */
/************************************/



#include "STK_interface.h"
#include "RCC_interface.h"


#if STK_CLK_SRC == STK_SRC_AHB
    #define STK_TIMER_FREQ    SYSTEM_FREQ
#elif STK_CLK_SRC == STK_SRC_AHB_8
    #define STK_TIMER_FREQ   (SYSTEM_FREQ / 8)
#endif


/* Define Callback Global Variable */
static void(*STK_CallBack)(void);

/* Define Variable for interval mode */
u8 STK_u8ModeOfInterval;




void STK_voidInit() {

    STK->CTRL &= ~(1 << STK_CTRL_ENABLE);

    #if STK_CLK_SRC == STK_SRC_AHB
        STK->CTRL |= (1 << STK_CTRL_CLKSEL); // AHB
    #elif STK_CLK_SRC == STK_SRC_AHB_8
        STK->CTRL &= ~(1 << STK_CTRL_CLKSEL); //AHB/8
    #endif


    STK->VAL = 0;
}




void STK_delay(u32 time, u32 unit) {

	f32 ratio = STK_TIMER_FREQ / unit;  //TICKS = ( TIME IN SEC/ UNIT) * TIMER FREQ.
	u32 ticks = time * ratio;


    STK->LOAD = ticks & STK_LOAD_MASK;



    STK->CTRL |= (1 << STK_CTRL_ENABLE); //start timer

    while (!(STK->CTRL & (1 << STK_CTRL_COUNTFLAG)));  //waiting flag

    STK->CTRL &= ~(1 << STK_CTRL_ENABLE);  //stop timer
}



void STK_voidRunFunOnceAfter(u32 time, u32 unit, void(*callback)(void)) {
	/* Disable Timer */
	CLR_BIT(STK->CTRL,0);
	STK -> VAL = 0;

	f32 ratio = STK_TIMER_FREQ / unit;
	u32 ticks = time * ratio;

	STK->LOAD = ticks & STK_LOAD_MASK;

    STK_CallBack = callback;

    STK->CTRL |= (1 << STK_CTRL_TICKINT);

    STK_u8ModeOfInterval = STK_ONEC;

    STK->CTRL |= (1 << STK_CTRL_ENABLE);
}

void STK_voidRunFunPeriodicEvery(u32 time, u32 unit, void(*callback)(void)) {
	f32 ratio = STK_TIMER_FREQ / unit;
	u32 ticks = time * ratio;


        STK->LOAD = ticks & STK_LOAD_MASK;

        STK->VAL = 0;

        STK_CallBack = callback;

        STK->CTRL |= (1 << STK_CTRL_TICKINT);

        STK_u8ModeOfInterval = STK_PERIODIC;

        STK->CTRL |= (1 << STK_CTRL_ENABLE);

}



void STK_voidStopTimer(void) {
    STK->CTRL &= ~(1 << STK_CTRL_ENABLE);

    STK->VAL = 0;
    STK->LOAD = 0;
}


u32 STK_u32GetElapsedTime(u32 unit) {

	u32 elapsed_ticks = STK->LOAD - STK->VAL;

    u32 time;
    f32 ratio = (f32)unit / STK_TIMER_FREQ;

    time = elapsed_ticks * ratio;

    return time;
}


u32 STK_u32GetRemainingTime(u32 unit) {
    u32 remaining_ticks = STK->VAL;

    u32 time;
    f32 ratio = (f32)unit / STK_TIMER_FREQ;


    time = remaining_ticks * ratio;

    return time;
}


void SysTick_Handler(void) {

    STK_CallBack();


    volatile u32 temp = STK->CTRL; //flag clear

    if (STK_u8ModeOfInterval == STK_ONEC) {
        STK->CTRL &= ~(1 << STK_CTRL_ENABLE);
    }
}
