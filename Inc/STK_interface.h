/************************************/
/*Author   :  Ahmed Ali             */
/*Date     :  25 AUG 2020           */
/*Version  :  V01                   */
/************************************/

#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_config.h"
#include "STK_private.h"


#define MS_UNIT 1000
#define US_UNIT 1000000



void STK_voidInit();
void STK_delay(u32 time, u32 unit);

void STK_voidRunFunOnceAfter(u32 time, u32 unit, void(*callback)(void));

void STK_voidRunFunPeriodicEvery(u32 time, u32 unit, void(*callback)(void));

void STK_voidStopTimer(void) ;

void SKT_StartCountfrom(u32 ticks);

u32 STK_u32GetElapsedTime(u32 unit);

u32 STK_u32GetRemainingTime(u32 unit);


#endif
