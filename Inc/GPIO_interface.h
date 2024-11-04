/************************************/
/*Author   :  Ahmed Ali             */
/*Date     :  12 AUG 2020           */
/*Version  :  V01                   */
/************************************/


#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_private.h"
#include "GPIO_config.h"

#define GPIOA  0
#define GPIOB  1
#define GPIOC  2

#define PIN0   0
#define PIN1   1
#define PIN2   2
#define PIN3   3
#define PIN4   4
#define PIN5   5
#define PIN6   6
#define PIN7   7
#define PIN8   8
#define PIN9   9
#define PIN10  10
#define PIN11  11
#define PIN12  12
#define PIN13  13
#define PIN14  14
#define PIN15  15

#define OUTPUT_SPEED_10MHZ_PP   0b0001  // 10MHZ OUTPUT & PUSH/PULL
#define OUTPUT_SPEED_10MHZ_OD   0b0101  // 10MHZ OUTPUT & OPEN DRAIN
#define OUTPUT_SPEED_10MHZ_AFPP 0b1001  // 10MHZ OUTPUT & ALTERNATIVE MODE & PUSH/PULL
#define OUTPUT_SPEED_10MHZ_AFOD 0b1101  // 10MHZ OUTPUT & ALTERNATIVE MODE & OPEN DRAIN

#define OUTPUT_SPEED_2MHZ_PP   0b0010  // 2MHZ OUTPUT & PUSH/PULL
#define OUTPUT_SPEED_2MHZ_OD   0b1010  // 2MHZ OUTPUT & OPEN DRAIN
#define OUTPUT_SPEED_2MHZ_AFPP 0b1010  // 2MHZ OUTPUT & ALTERNATIVE MODE & PUSH/PULL
#define OUTPUT_SPEED_2MHZ_AFOD 0b1110  // 2MHZ OUTPUT & ALTERNATIVE MODE & OPEN DRAIN

#define OUTPUT_SPEED_50MHZ_PP   0b0011  // 10MHZ OUTPUT & PUSH/PULL
#define OUTPUT_SPEED_50MHZ_OD   0b0111  // 10MHZ OUTPUT & OPEN DRAIN
#define OUTPUT_SPEED_50MHZ_AFPP 0b1011  // 10MHZ OUTPUT & ALTERNATIVE MODE & PUSH/PULL
#define OUTPUT_SPEED_50MHZ_AFOD 0b1111  // 10MHZ OUTPUT & ALTERNATIVE MODE & OPEN DRAIN

#define INPUT_ANALOG            0b0000
#define INPUT_FLOUTING          0b0100
#define INPUT_PULL_UP_DOWEN     0b1000

#define GPIO_LOW      0
#define GPIO_HIGH     1

#define FIRST_HALF    0
#define SECOND_HALF   1

void GPIO_voidSetPinDirection( u8 copy_u8PORT, u8 copy_u8PIN , u8 copy_u8Mode);
void GPIO_voidSetPinValue( u8 copy_u8PORT, u8 copy_u8PIN , u8 copy_u8Value);
u8   GPIO_u8GetPinValue( u8 copy_u8PORT, u8 copy_u8PIN);
void GPIO_voidTogPinValue( u8 copy_u8PORT, u8 copy_u8PIN);
void GPIO_voidSetFullPortDirection( u8 copy_u8PORT , u16 copy_u8Mode);
void GPIO_voidSetHalfPortDirection( u8 copy_u8PORT ,u8 Position, u16 copy_u8Mode);
void GPIO_voidSetFullPortValue( u8 copy_u8PORT , u16 copy_u16Value);
void GPIO_voidSetHalfPortValue(u8 copy_u8PORT,u8 Position ,u16 copy_u16Value);

#endif
