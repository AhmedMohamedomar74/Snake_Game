/*
 * SPI_private.h
 *
 *  Created on: Oct 21, 2024
 *      Author: Ahmed Ali
 */

#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_


typedef struct {
    volatile u32 CR1;   // Control register 1
    volatile u32 CR2;   // Control register 2
    volatile u32 SR;    // Status register
    volatile u32 DR;    // Data register
    volatile u32 CRCPR; // CRC polynomial register
    volatile u32 RXCRCR;// RX CRC register
    volatile u32 TXCRCR;// TX CRC register
} SPI_TypeDef;

#define SPI1_BASE_ADDRESS (0x40013000UL)

#define SPI1 ((SPI_TypeDef *) SPI1_BASE_ADDRESS)


#define SPI_CR1_CPHA  0  // Clock phase
#define SPI_CR1_CPOL  1  // Clock Polarity
#define SPI_CR1_MSTR  2  // Master mode
#define SPI_CR1_SPE   6  // SPI Enable

#define SPI_CR1_SSI   8  // Internal slave select
#define SPI_CR1_SSM   9  // Software slave management




#define SPI_CR1
#define SPI_CR1

#define SPI_SR_TXE   1  // Transmit buffer empty
#define SPI_SR_RXNE  0  // Receive buffer not empty



#define SPI_MOSI   GPIOA,PIN7
#define SPI_MISO   GPIOA,PIN6
#define SPI_SCK    GPIOA,PIN5
#endif /* SPI_PRIVATE_H_ */
