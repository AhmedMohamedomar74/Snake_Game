################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/EXTI_programm.c \
../Src/GPIO_program.c \
../Src/NVIC_programm.c \
../Src/RCC_program.c \
../Src/SPI_prog.c \
../Src/STk_program.c \
../Src/Snake_Game.c \
../Src/TFT_program.c \
../Src/main.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/EXTI_programm.o \
./Src/GPIO_program.o \
./Src/NVIC_programm.o \
./Src/RCC_program.o \
./Src/SPI_prog.o \
./Src/STk_program.o \
./Src/Snake_Game.o \
./Src/TFT_program.o \
./Src/main.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/EXTI_programm.d \
./Src/GPIO_program.d \
./Src/NVIC_programm.d \
./Src/RCC_program.d \
./Src/SPI_prog.d \
./Src/STk_program.d \
./Src/Snake_Game.d \
./Src/TFT_program.d \
./Src/main.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/EXTI_programm.cyclo ./Src/EXTI_programm.d ./Src/EXTI_programm.o ./Src/EXTI_programm.su ./Src/GPIO_program.cyclo ./Src/GPIO_program.d ./Src/GPIO_program.o ./Src/GPIO_program.su ./Src/NVIC_programm.cyclo ./Src/NVIC_programm.d ./Src/NVIC_programm.o ./Src/NVIC_programm.su ./Src/RCC_program.cyclo ./Src/RCC_program.d ./Src/RCC_program.o ./Src/RCC_program.su ./Src/SPI_prog.cyclo ./Src/SPI_prog.d ./Src/SPI_prog.o ./Src/SPI_prog.su ./Src/STk_program.cyclo ./Src/STk_program.d ./Src/STk_program.o ./Src/STk_program.su ./Src/Snake_Game.cyclo ./Src/Snake_Game.d ./Src/Snake_Game.o ./Src/Snake_Game.su ./Src/TFT_program.cyclo ./Src/TFT_program.d ./Src/TFT_program.o ./Src/TFT_program.su ./Src/main.cyclo ./Src/main.d ./Src/main.o ./Src/main.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su

.PHONY: clean-Src

