/*
 * EXTI_private.h
 *
 *  Created on: Oct 29, 2024
 *      Author: ahmed
 */

#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_



/* Base address of EXTI and SYSCFG */
#define EXTI_BASE_ADDRESS    0x40010400
#define AFIO_BASE_ADDRESS    0x40010000

/* EXTI Registers */
typedef struct {
    volatile u32 IMR;
    volatile u32 EMR;
    volatile u32 RTSR;
    volatile u32 FTSR;
    volatile u32 SWIER;
    volatile u32 PR;
} EXTI_Type;

#define EXTI    ((volatile EXTI_Type *) EXTI_BASE_ADDRESS)

typedef struct {
	volatile u32 EVCR        ;
	volatile u32 MAPR        ;
	volatile u32 EXTICR[4]   ;
	volatile u32 MAPR2       ;
} AFIO_t;

#define AFIO  ((volatile AFIO_t *) AFIO_BASE_ADDRESS)

#endif /* EXTI_PRIVATE_H_ */
