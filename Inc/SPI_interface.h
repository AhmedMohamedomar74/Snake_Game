/*
 * SPI_interface.h
 *
 *  Created on: Oct 21, 2024
 *      Author: Ahmed Ali
 */

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SPI_private.h"
#include "SPI_config.h"



void SPI_Init(void);


void SPI_Send(u8 data);


u8 SPI_Receive(void);


#endif /* SPI_INTERFACE_H_ */
