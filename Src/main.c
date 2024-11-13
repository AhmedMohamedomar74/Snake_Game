
#include "Snake_game.h"
#include "EXTI_interface.h"
#define test_game_over 1
int main()
{
	TFT_voidInit();
	int initialX = 1, initialY = 1, initialLength = 0;
	initializeSnake(initialX, initialY, initialLength);
	GPIO_voidSetHalfPortDirection(GPIOB, FIRST_HALF, INPUT_FLOUTING);
	initializeFood();
	NVIC_Init();
	ControlEXT(NVIC_EXTI0, MoveSnakeUp);
	ControlEXT(NVIC_EXTI1, MoveSnakeLeft);
	ControlEXT(NVIC_EXTI2, MoveSnakeDown);
	ControlEXT(NVIC_EXTI3, MoveSnakeRight);
#if (test_game_over == 1)
	TFT_voidFillColor(BACKGROUND_COLOR);
	TFT_voidDrawString(16, 150, "Score", SCORE_TEXT_COLOR);
	TFT_voidDrawNumber(Score, 80, 150, SCORE_TEXT_COLOR);
#endif
	while (1)
	{

#if (test_game_over == 1)
		CheckGamOver();
		draw();
		moveSnake(dir);

		if (gameOver == 1) {
			break;
		}

#elif (test_game_over == 0)
	TFT_voidDrawString(1, 80, "Game Over!", GAME_OVER_TEXT_COLOR);
	        TFT_voidDrawNumber(100, 100, 80, GAME_OVER_TEXT_COLOR);
#endif
	}
}
