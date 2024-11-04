/*
 * Snake_game.h
 *
 *  Created on: Nov 3, 2024
 *      Author: ahmed
 */

#ifndef SNAKE_GAME_H_
#define SNAKE_GAME_H_

#include "TFT_interface.h"
#include "Snake_Game_Config.h"

// Define constants
#define WIDTH Grid_Width
#define HEIGHT Grid_Hight
#define MAX_TAIL 10
#define HEAD_SIZE 5

// Enum for direction
typedef enum
{
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
} dir_t;

// Struct for Snake's Head
typedef struct
{
    int x, y;
} SnakeHead_t;

// Struct for Snake's Tail
typedef struct SnakeTail
{
    int x[MAX_TAIL], y[MAX_TAIL];
    int length;
} SnakeTail_t;

// Struct for Food
typedef struct
{
    int x, y;
    dir_t moveDir;
} Food_t;

extern dir_t dir; // Initialize movement to the right
extern SnakeHead_t head;
extern SnakeTail_t tail;
extern Food_t food;

void initializeSnake(int headX, int headY, int tailLength);
void initializeFood(int foodX, int foodY, dir_t foodDirection);
void moveFood();
void moveSnake(dir_t direction);
// Draw game board with snake's head, tail, and food, and generate row array
void draw();

void PoisionInTFT(u8 xpos, u8 ypos, u16 color);

#endif /* SNAKE_GAME_H_ */