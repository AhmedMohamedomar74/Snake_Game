
#include "Snake_game.h"
#include <stdbool.h>

int main()
{
	TFT_voidInit();
	int initialX = 5, initialY = 5, initialLength = 3;
	initializeSnake(initialX, initialY, initialLength);
	initializeFood(5, 4, RIGHT); // Initial food position and direction

	// TFT_voidDrawRect(0, 32, 128, 160, TFT_BLACK);
	while (1)
	{
		draw();
		moveSnake(UP);
		// STK_delay(MS_UNIT, 50);
	}
}
