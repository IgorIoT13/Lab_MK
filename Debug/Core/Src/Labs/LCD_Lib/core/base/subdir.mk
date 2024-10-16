################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Labs/LCD_Lib/core/base/baseLcd.c 

OBJS += \
./Core/Src/Labs/LCD_Lib/core/base/baseLcd.o 

C_DEPS += \
./Core/Src/Labs/LCD_Lib/core/base/baseLcd.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Labs/LCD_Lib/core/base/%.o Core/Src/Labs/LCD_Lib/core/base/%.su Core/Src/Labs/LCD_Lib/core/base/%.cyclo: ../Core/Src/Labs/LCD_Lib/core/base/%.c Core/Src/Labs/LCD_Lib/core/base/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-Labs-2f-LCD_Lib-2f-core-2f-base

clean-Core-2f-Src-2f-Labs-2f-LCD_Lib-2f-core-2f-base:
	-$(RM) ./Core/Src/Labs/LCD_Lib/core/base/baseLcd.cyclo ./Core/Src/Labs/LCD_Lib/core/base/baseLcd.d ./Core/Src/Labs/LCD_Lib/core/base/baseLcd.o ./Core/Src/Labs/LCD_Lib/core/base/baseLcd.su

.PHONY: clean-Core-2f-Src-2f-Labs-2f-LCD_Lib-2f-core-2f-base

