
#include "Snake_game.h"
#include "EXTI_interface.h"

#define TEST_EXT 0

#if (TEST_EXT == 0)
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
	TFT_voidDrawString(16, 150, "Score", TFT_BLACK);
	TFT_voidDrawNumber(Score, 80, 150, TFT_BLUE);
	while (1)
	{
		CheckGamOver();
		draw();
		CheckGamOver();
		moveSnake(dir);
		TFT_voidDrawNumber(Score, 80, 150, TFT_BLUE);
	}
}

#endif

#if (TEST_EXT == 2)
int main()
{
	TFT_voidInit();
	GPIO_voidSetHalfPortDirection(GPIOB, FIRST_HALF, INPUT_FLOUTING);

	while (1)
	{
		u8 rand_val = GPIO_u8ReadPins0to7();
		TFT_voidDrawNumber(rand_val, 80, 150, TFT_BLUE);
		STK_delay(500, MS_UNIT);
	}
}

#endif

#if (TEST_EXT == 1)

void main()
{
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2, RCC_GPIOA);
	RCC_voidEnableClock(RCC_APB2, RCC_GPIOB);
	RCC_voidEnableClock(RCC_APB2, RCC_AFIO);

	GPIO_voidSetPinDirection(GPIOA, PIN7, OUTPUT_SPEED_10MHZ_PP);
	GPIO_voidSetPinDirection(GPIOA, PIN8, OUTPUT_SPEED_10MHZ_PP);

	NVIC_Init();
	ControlEXT(NVIC_EXTI0, ahmed);
	ControlEXT(NVIC_EXTI1, ahmed_2);
	ControlEXT(NVIC_EXTI2, ahmed_3);
	ControlEXT(NVIC_EXTI3, ahmed_4);
	while (1)
	{
	}
}

#endif
