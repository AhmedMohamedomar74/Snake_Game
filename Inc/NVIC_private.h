/*
 * NVIC_private.h
 *
 *  Created on: Oct 29, 2024
 *      Author: ahmed
 */

#ifndef NVIC_PRIVATE_H_
#define NVIC_PRIVATE_H_

#define NVIC_BASE_ADDRESS      0xE000E100




typedef struct {
    volatile u32 ISER[3];  // Interrupt Set-Enable Registers (96 IRQs)
    u32 RESERVED0[29];     // Reserved space
    volatile u32 ICER[3];  // Interrupt Clear-Enable Registers (96 IRQs)
    u32 RESERVED1[29];     // Reserved space
    volatile u32 ISPR[3];  // Interrupt Set-Pending Registers (96 IRQs)
    u32 RESERVED2[29];     // Reserved space
    volatile u32 ICPR[3];  // Interrupt Clear-Pending Registers (96 IRQs)
    u32 RESERVED3[29];     // Reserved space
    volatile u32 IABR[3];  // Interrupt Active Bit Registers (96 IRQs)
    u32 RESERVED4[61];     // Reserved space
    volatile u8  IPR[240]; // Interrupt Priority Registers (8-bit per IRQ)
} NVIC_Type;

//
#define NVIC ((NVIC_Type*) 0xE000E100)

// SCB_AIRCR
#define SCB_AIRCR       *((volatile u32 *)0xE000ED0C) //  SCB_AIRCR

#endif /* NVIC_PRIVATE_H_ */
