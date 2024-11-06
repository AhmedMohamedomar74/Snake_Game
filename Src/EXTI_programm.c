/*
 * EXTI_programm.c
 *
 *  Created on: Oct 29, 2024
 *      Author: ahmed
 */
#include "EXTI_interface.h"

static void (*EXTI_CallBacks[16])(void);  // Array to hold callback functions for each EXTI line

/* Function to configure EXTI */
void EXTI_voidConfigure(u8 copy_u8Line, u8 copy_u8Port, u8 copy_u8Mode, void (*callback)(void)) {

	u8 local_u8RegIndex = copy_u8Line / 4;         // Determine the EXTICR register
    u8 local_u8Position = (copy_u8Line % 4) * 4;   // Determine the position within the EXTICR register

    /* Select the port for the EXTI line */
    AFIO->EXTICR[local_u8RegIndex] &= ~(0b1111 << local_u8Position);
    AFIO->EXTICR[local_u8RegIndex] |= (copy_u8Port << local_u8Position);

    /* Configure the signal latch mode */
    switch(copy_u8Mode) {
        case EXTI_RISING_EDGE:
            SET_BIT(EXTI->RTSR, copy_u8Line);   // Enable rising edge trigger
            CLR_BIT(EXTI->FTSR, copy_u8Line);   // Disable falling edge trigger
            break;
        case EXTI_FALLING_EDGE:
            SET_BIT(EXTI->FTSR, copy_u8Line);   // Enable falling edge trigger
            CLR_BIT(EXTI->RTSR, copy_u8Line);   // Disable rising edge trigger
            break;
        case EXTI_ON_CHANGE:
            SET_BIT(EXTI->RTSR, copy_u8Line);   // Enable both rising and falling edges
            SET_BIT(EXTI->FTSR, copy_u8Line);
            break;
    }
    /* Assign the callback function to the corresponding EXTI line */
    EXTI_CallBacks[copy_u8Line] = callback;

    /* Enable the EXTI line */
    SET_BIT(EXTI->IMR, copy_u8Line);
}

/* Example ISR for EXTI0 */

void EXTI0_IRQHandler(void) {
    /* Execute the assigned callback function */
    EXTI_CallBacks[0]();

    /* Clear the pending flag by writing 1 to it */
    u32 x = EXTI->PR;
    SET_BIT(EXTI->PR, 0);
}


void EXTI1_IRQHandler(void) {
    // Execute the assigned callback function
    if (EXTI_CallBacks[0]!= NULL)
	EXTI_CallBacks[1]();

   // Clear the pending flag by writing 1 to it
    SET_BIT(EXTI->PR, 1);
}


void EXTI2_IRQHandler (void)
{
	// Execute the assigned callback function
	    if (EXTI_CallBacks[1]!= NULL)
		EXTI_CallBacks[2]();

	   // Clear the pending flag by writing 1 to it
	    SET_BIT(EXTI->PR, 2);
}


void EXTI3_IRQHandler (void)
{
	// Execute the assigned callback function
	    if (EXTI_CallBacks[2]!= NULL)
		EXTI_CallBacks[3]();

	   // Clear the pending flag by writing 1 to it
	    SET_BIT(EXTI->PR, 3);
}
