
#include "Snake_game.h"
#include "EXTI_interface.h"
#include <stdbool.h>


#define TEST_EXT 0

#if (TEST_EXT == 0)
int main()
{
	TFT_voidInit();
	int initialX = 1, initialY = 1, initialLength = 0;
	initializeSnake(initialX, initialY, initialLength);
	initializeFood(2, 2, DOWN); // Initial food position and direction
	NVIC_Init();
	ControlEXT(NVIC_EXTI0,MoveSnakeUp);
	ControlEXT(NVIC_EXTI1,MoveSnakeLeft);
	ControlEXT(NVIC_EXTI2,MoveSnakeDown);
	ControlEXT(NVIC_EXTI3,MoveSnakeRight);
	// TFT_voidDrawRect(0, 32, 128, 160, TFT_BLACK);
	TFT_voidDrawString(16,150,"Snake Game",TFT_BLACK);
	while (1)
	{
		draw();
		moveSnake(dir);
	}
}

#endif


#if (TEST_EXT == 1)

void main ()
{
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2,RCC_GPIOA);
	RCC_voidEnableClock(RCC_APB2,RCC_GPIOB);
	RCC_voidEnableClock(RCC_APB2,RCC_AFIO);

	GPIO_voidSetPinDirection(GPIOA,PIN7,OUTPUT_SPEED_10MHZ_PP);
	GPIO_voidSetPinDirection(GPIOA,PIN8,OUTPUT_SPEED_10MHZ_PP);

	NVIC_Init();
	ControlEXT(NVIC_EXTI0,ahmed);
	ControlEXT(NVIC_EXTI1,ahmed_2);
	ControlEXT(NVIC_EXTI2,ahmed_3);
	ControlEXT(NVIC_EXTI3,ahmed_4);
	while(1)
	{
	}
}


#endif


