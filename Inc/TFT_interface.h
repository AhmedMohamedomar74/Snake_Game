/************************************/
/*Author   :  Ahmed Ali             */
/*Date     :  21 SEP 2020           */
/*Version  :  V01                   */
/************************************/


#ifndef TFT_INTERFACE_H
#define TFT_INTERFACE_H

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "STK_interface.h"
#include "SPI_interface.h"
#include "TFT_config.h"
#include "TFT_private.h"
#include "RCC_interface.h"

void TFT_voidInit();
void TFT_voidDisplayImage(const u16* Image);
void TFT_voidFillColor( u16 Color);
void TFT_voidDrawRect( u8 x1, u8 x2 , u8 y1 , u8 y2, u16 Color);
void TFT_voidDrawSQ( u8 xpos, u8 ypos,u16 Color);
void TFT_voidDrawLetter( u8 xpos, u8 ypos,const u8 *letter , u16 Color);
void TFT_voidDrawString(u8 xpos, u8 ypos,u8 * PtrStr,u16 Color);
void TFT_voidDrawSQSize( u8 xpos, u8 ypos,u16 req_size ,u16 Color);
void TFT_voidDrawNumber (u16 Number,u8 xpos, u8 ypos,u16 Color);

#define TFT_SLEEP_OUT_CMD   0x11
#define TFT_COLOR_MODE_CMD  0x3A
#define TFT_DISPLAY_ON_CMD  0x29
#define TFT_SET_X_ADDR_CMD  0x2A
#define TFT_SET_Y_ADDR_CMD  0x2B
#define TFT_RAM_WRITE_CMD   0x2C

#define TFT_WIGHT   0XFFFF
#define TFT_BLACK   0X0000
#define TFT_WHITE   0xFFFF
#define TFT_RED     0xF800
#define TFT_GREEN   0x07E0
#define TFT_BLUE    0x001F
#define TFT_YELLOW  0xFFE0
#define TFT_CYAN    0x07FF
#define TFT_MAGENTA 0xF81F
#define TFT_GRAY    0x7BEF

#define TFT_RGB_565 0x05
/******************************/
#endif
