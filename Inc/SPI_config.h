/*
 * SPI_config.h
 *
 *  Created on: Oct 21, 2024
 *      Author: Ahmed Ali
 */

#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_


#define SPI_MODE_MASTER  1
#define SPI_MODE_SLAVE   0

#define SPI_MODE  SPI_MODE_MASTER



#if (SPI_MODE == SPI_MODE_MASTER)
#define SS1_PIN GPIOA,PIN4
#endif

#if (SPI_MODE == SPI_MODE_SLAVE)
#define SS_PIN GPIOA,PIN4
#endif

/*************CLOCK PHASE *****************/
#define READ_FIRST          0 //ST7735R
#define READ_SECOND         1 //ST7735S

#define SPI_CLOCK_PHASE     READ_FIRST

/*************CLOCK POLARITY **************/


#define CLOCK_IDLE_0        0 //ST7735R
#define CLOCK_IDLE_1        1 //ST7735S

#define SPI_CLOCK_POLARITY  CLOCK_IDLE_0

/****CLOCK Software slave management*******/

#define SSM_DISABLE          0 //ST7735R
#define SSM_ENABLE           1 //ST7735S

#define SPI_SSM              SSM_DISABLE
#endif /* SPI_CONFIG_H_ */

