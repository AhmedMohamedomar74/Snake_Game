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

#define CohesiveAndStylish 0
#define ModernLook 1

#define COLOR_SCHEME CohesiveAndStylish

#if (COLOR_SCHEME == CohesiveAndStylish)

#define BACKGROUND_COLOR            0xE7F3  // Pale Mint Green (RGB565: #E0F7E0)
#define SNAKE_HEAD_COLOR            0x05EB  // Bright Teal (RGB565: #00B5B5)
#define SNAKE_BODY_COLOR            0x7FFD  // Light Teal (RGB565: #5FE8E8)
#define FOOD_COLOR                  0xFBE2  // Coral (RGB565: #FF6F61)
#define SCORE_TEXT_COLOR            0x0000  // Black (RGB565: #000000)
#define GAME_OVER_BACKGROUND_COLOR  0xF79E  // Light Pink (RGB565: #FFA07A) for Game Over screen
#define GAME_OVER_TEXT_COLOR        0x0000  // Black (RGB565: #000000) for Game Over text

#elif (COLOR_SCHEME == ModernLook)

#define BACKGROUND_COLOR            0x2128  // Dark Navy Blue (RGB565: #1A1A2E)
#define SNAKE_HEAD_COLOR            0x07FF  // Bright Cyan (RGB565: #00FFFF)
#define SNAKE_BODY_COLOR            0x06D3  // Dark Turquoise (RGB565: #00CED1)
#define FOOD_COLOR                  0xFFE0  // Yellow (RGB565: #FFFF00)
#define SCORE_TEXT_COLOR            0xCE59  // Light Gray (RGB565: #D3D3D3)
#define GAME_OVER_BACKGROUND_COLOR  0xF79E  // Light Pink (RGB565: #FFA07A) for Game Over screen
#define GAME_OVER_TEXT_COLOR        0x0000  // Black (RGB565: #000000) for Game Over text

#endif


#define TFT_RGB_565 0x05
/******************************/
#endif
