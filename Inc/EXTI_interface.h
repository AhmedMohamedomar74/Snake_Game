/*
 * EXTI_interface.h
 *
 *  Created on: Oct 29, 2024
 *      Author: ahmed
 */

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_private.h"
#include "EXTI_config.h"
#include "NVIC_interface.h"

/* Function Prototypes */
void EXTI_voidConfigure(u8 copy_u8Line, u8 copy_u8Port, u8 copy_u8Mode, void (*callback)(void));

/* Define the ports for EXTI */
#define PORTA    0
#define PORTB    1
#define PORTC    2


/* Define EXTI Lines */
#define EXTI_LINE0           0
#define EXTI_LINE1           1
#define EXTI_LINE2           2
#define EXTI_LINE3           3
#define EXTI_LINE4           4
#define EXTI_LINE5           5
#define EXTI_LINE6           6
#define EXTI_LINE7           7
#define EXTI_LINE8           8
#define EXTI_LINE9           9
#define EXTI_LINE10          10
#define EXTI_LINE11          11
#define EXTI_LINE12          12
#define EXTI_LINE13          13
#define EXTI_LINE14          14
#define EXTI_LINE15          15

/* EXTI Modes */
#define EXTI_RISING_EDGE     0
#define EXTI_FALLING_EDGE    1
#define EXTI_ON_CHANGE       2

#endif /* EXTI_INTERFACE_H_ */
