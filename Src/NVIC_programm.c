/*
 * NVIC_programm.c
 *
 *  Created on: Oct 29, 2024
 *      Author: ahmed
 */


#include "NVIC_interface.h"

void NVIC_Init()
{

	SCB_AIRCR = (NVIC_PRIORITY_DISTRIBUTION<<8) | (0x05FA0000);
}

void NVIC_EnableInterrupt(u8 int_Id) {
    NVIC->ISER[int_Id / 32] = (1 << (int_Id % 32));
}

void NVIC_DisableInterrupt(u8 int_Id) {
    NVIC->ICER[int_Id / 32] = (1 << (int_Id % 32));
}

void NVIC_SetPendingFlag(u8 int_Id) {
    NVIC->ISPR[int_Id / 32] = (1 << (int_Id % 32));
}

void NVIC_ClearPendingFlag(u8 int_Id) {
    NVIC->ICPR[int_Id / 32] = (1 << (int_Id % 32));
}

u8 NVIC_GetActiveFlag(u8 int_Id) {
    return (NVIC->IABR[int_Id / 32] & (1 << (int_Id % 32))) ? 1 : 0;
}

void NVIC_SetPriority(u8 int_Id, u8 group_priority, u8 subgroup_priority) {

	if( NVIC_PRIORITY_DISTRIBUTION <= 7)
		if (group_priority > ((1 << (NVIC_PRIORITY_DISTRIBUTION - 7))-1) || subgroup_priority > ( (1 << (NVIC_PRIORITY_DISTRIBUTION - 3))-1))
		{
			return;
		}

    u8 priority = (group_priority <<( NVIC_PRIORITY_DISTRIBUTION-3)) | subgroup_priority;

    NVIC->IPR[int_Id] = (NVIC->IPR[int_Id] & 0x0F) | (priority << 4);
}
