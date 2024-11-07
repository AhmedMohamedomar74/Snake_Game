/*
 * Snake_Game.c
 *
 *  Created on: Nov 3, 2024
 *      Author: ahmed
 */

#include "Snake_game.h"
#define FilledWithColor 1
#define Empty 0

u8 Score = 0;

dir_t dir = STOP; // Initialize movement to the right
SnakeHead_t head;
SnakeTail_t tail;
Food_t food;

static u8 gameOver = 0;

static u8 GPIO_u8ReadPins0to7();
static Rand_val = 0;

u8 GridFlags[(HEIGHT + 1)][(WIDTH + 1)] = {Empty};

// Initialize snake position, tail length, and initial food position
void initializeSnake(int headX, int headY, int tailLength)
{
    head.x = headX;
    head.y = headY;
    tail.length = tailLength;
    for (int i = 0; i < tail.length; i++)
    {
        tail.x[i] = headX - (i + 1);
        tail.y[i] = headY;
    }
}

// Initialize food position and direction
void initializeFood()
{
    Rand_val = GPIO_u8ReadPins0to7();
    food.x = Rand_val % WIDTH;
    food.y = Rand_val % HEIGHT;
}

// Move food in a fixed direction when eaten
void moveFood()
{
    Rand_val = GPIO_u8ReadPins0to7();
    food.x = Rand_val % WIDTH;
    food.y = Rand_val % HEIGHT;
    // Wrap food position around boundaries
    if (food.x >= WIDTH)
        food.x = 1;
    else if (food.x < 1)
        food.x = WIDTH - 1;
    if (food.y >= HEIGHT)
        food.y = 1;
    else if (food.y < 1)
        food.y = HEIGHT - 1;
}

void CheckGamOver()
{
    for (int i = 0; i <=tail.length; i++)
    {
        if (tail.x[i] == head.x && tail.y[i] == head.y)
        {
            gameOver = 1;
        }
    }
}

// Move snake in specified direction and update tail
void moveSnake(dir_t direction)
{
    int prevX = head.x;
    int prevY = head.y;

    // Update head position based on direction
    switch (direction)
    {
    case LEFT:
        head.x--;
        break;
    case RIGHT:
        head.x++;
        break;
    case UP:
        head.y--;
        break;
    case DOWN:
        head.y++;
        break;
    default:
        break;
    }

    // Update tail positions
    int prev2X, prev2Y;
    for (int i = 0; i < tail.length; i++)
    {
        prev2X = tail.x[i];
        prev2Y = tail.y[i];
        tail.x[i] = prevX;
        tail.y[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    // Boundary wrapping for snake
    if (head.x >= WIDTH)
        head.x = 0;
    else if (head.x < 0)
        head.x = WIDTH - 1;
    if (head.y >= HEIGHT)
        head.y = 0;
    else if (head.y < 0)
        head.y = HEIGHT - 1;

    // Check if snake has eaten the food
    if (head.x == food.x && head.y == food.y)
    {
        tail.length++;
        moveFood(); // Move food to new position
        Score += 10;
    }
}

// Draw game board with snake's head, tail, and food, and generate row array
void draw()
{
    if (gameOver == 0)
    {
        for (int i = 1; i <= HEIGHT; i++)
        {
            for (int j = 1; j <= WIDTH; j++)
            {
                if (i == head.y && j == head.x)
                {
                    PoisionInTFT(head.x, head.y, TFT_BLUE); // Draw snake head
                    GridFlags[i][j] = FilledWithColor;
                }
                else if (i == food.y && j == food.x)
                {
                    PoisionInTFT(food.x, food.y, TFT_GRAY);
                    GridFlags[i][j] = FilledWithColor;
                }
                else
                {
                    int isTail = 0;
                    for (int k = 0; k < tail.length; k++)
                    {
                        if (i == tail.y[k] && j == tail.x[k])
                        {
                            PoisionInTFT(tail.x[k], tail.y[k], TFT_GREEN);
                            isTail = 1;
                            GridFlags[i][j] = FilledWithColor;
                            break;
                        }
                    }
                    if ((!isTail) && (GridFlags[i][j] == FilledWithColor))
                    {
                        PoisionInTFT(j, i, TFT_WHITE);
                        GridFlags[i][j] = Empty;
                    }
                }
            }
        }
    }
    else
    {
        TFT_voidFillColor(TFT_RED);
    }
}

void PoisionInTFT(u8 xpos, u8 ypos, u16 color)
{
    u8 x2 = xpos * Slected_Size;
    u8 x1 = x2 - Slected_Size;
    u8 y2 = ypos * Slected_Size;
    u8 y1 = y2 - Slected_Size;
    TFT_voidDrawRect(x1, x2, y1, y2, color);
}

void MoveSnakeUp()
{
    dir = UP;
}

void MoveSnakeDown()
{
    dir = DOWN;
}

void MoveSnakeLeft()
{
    dir = LEFT;
}

void MoveSnakeRight()
{
    dir = RIGHT;
}

void ControlEXT(u8 NVIC_NUMBER, void *callBackFun())
{
    GPIO_voidSetPinDirection(GPIOA, (NVIC_NUMBER - 6), OUTPUT_SPEED_10MHZ_PP);
    NVIC_EnableInterrupt(NVIC_NUMBER); // EXTI0
    NVIC_SetPriority(NVIC_NUMBER, (NVIC_NUMBER - 6), 0);
    EXTI_voidConfigure((NVIC_NUMBER - 6), PORTA, EXTI_RISING_EDGE, callBackFun);
}

static u8 GPIO_u8ReadPins0to7()
{
    u8 pinValues = 0;

    // Read each pin from PIN0 to PIN7 and store in respective bit positions
    for (u8 pin = 0; pin <= 7; pin++)
    {
        u8 pinValue = GPIO_u8GetPinValue(GPIOB, pin);
        pinValues |= (pinValue << pin);
    }

    return pinValues;
}
