################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Labs/Lab-3/Lab-3.c 

OBJS += \
./Core/Src/Labs/Lab-3/Lab-3.o 

C_DEPS += \
./Core/Src/Labs/Lab-3/Lab-3.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Labs/Lab-3/%.o Core/Src/Labs/Lab-3/%.su Core/Src/Labs/Lab-3/%.cyclo: ../Core/Src/Labs/Lab-3/%.c Core/Src/Labs/Lab-3/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-Labs-2f-Lab-2d-3

clean-Core-2f-Src-2f-Labs-2f-Lab-2d-3:
	-$(RM) ./Core/Src/Labs/Lab-3/Lab-3.cyclo ./Core/Src/Labs/Lab-3/Lab-3.d ./Core/Src/Labs/Lab-3/Lab-3.o ./Core/Src/Labs/Lab-3/Lab-3.su

.PHONY: clean-Core-2f-Src-2f-Labs-2f-Lab-2d-3

