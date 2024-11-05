################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Labs/LCD_Lib/core/pin/pin.c 

OBJS += \
./Core/Src/Labs/LCD_Lib/core/pin/pin.o 

C_DEPS += \
./Core/Src/Labs/LCD_Lib/core/pin/pin.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Labs/LCD_Lib/core/pin/%.o Core/Src/Labs/LCD_Lib/core/pin/%.su Core/Src/Labs/LCD_Lib/core/pin/%.cyclo: ../Core/Src/Labs/LCD_Lib/core/pin/%.c Core/Src/Labs/LCD_Lib/core/pin/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-Labs-2f-LCD_Lib-2f-core-2f-pin

clean-Core-2f-Src-2f-Labs-2f-LCD_Lib-2f-core-2f-pin:
	-$(RM) ./Core/Src/Labs/LCD_Lib/core/pin/pin.cyclo ./Core/Src/Labs/LCD_Lib/core/pin/pin.d ./Core/Src/Labs/LCD_Lib/core/pin/pin.o ./Core/Src/Labs/LCD_Lib/core/pin/pin.su

.PHONY: clean-Core-2f-Src-2f-Labs-2f-LCD_Lib-2f-core-2f-pin

