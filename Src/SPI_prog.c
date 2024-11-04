/*
 * SPI_prog.c
 *
 *  Created on: Oct 21, 2024
 *      Author: Ahmed Ali
 */


#include "SPI_interface.h"
#include "GPIO_interface.h"

void SPI_Init(void) {
   #if (SPI_MODE == SPI_MODE_MASTER)
        SPI1->CR1 |= (1 << SPI_CR1_MSTR); // MASTER mode

    	GPIO_voidSetPinDirection(SS1_PIN  ,OUTPUT_SPEED_10MHZ_PP);
    	GPIO_voidSetPinDirection(SPI_MOSI ,OUTPUT_SPEED_10MHZ_AFPP);
    	GPIO_voidSetPinDirection(SPI_MISO ,INPUT_FLOUTING);
    	GPIO_voidSetPinDirection(SPI_SCK  ,OUTPUT_SPEED_10MHZ_AFPP);
    #else
        SPI1->CR1 &= ~(1 << SPI_CR1_MSTR); // SLAVE mode
    	GPIO_voidSetPinDirection(SS_PIN  ,INPUT_FLOUTING);
    	GPIO_voidSetPinDirection(SPI_MOSI ,INPUT_FLOUTING);
    	GPIO_voidSetPinDirection(SPI_MISO ,OUTPUT_SPEED_10MHZ_AFPP);
    	GPIO_voidSetPinDirection(SPI_SCK  ,INPUT_FLOUTING);

	#endif

    SPI1->CR1 |= (SPI_CLOCK_PHASE    << SPI_CR1_CPHA);
    SPI1->CR1 |= (SPI_CLOCK_POLARITY << SPI_CR1_CPOL);
    SPI1->CR1 |= (SPI_SSM            << SPI_CR1_SSI);
    SPI1->CR1 |= (SPI_SSM            << SPI_CR1_SSM);

    SPI1->CR1 |= (1 << SPI_CR1_SPE);
}

void SPI_Send(u8 data) {

	while (!(SPI1->SR & (1 << SPI_SR_TXE)));

	SPI1->DR = data;
}

u8 SPI_Receive(void) {

    while (!(SPI1->SR & (1 << SPI_SR_RXNE)));

    return SPI1->DR;
}
