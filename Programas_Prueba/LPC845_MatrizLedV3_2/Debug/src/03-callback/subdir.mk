################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/03-callback/callback.cpp 

CPP_DEPS += \
./src/03-callback/callback.d 

OBJS += \
./src/03-callback/callback.o 


# Each subdirectory must supply rules for building sources it contributes
src/03-callback/%.o: ../src/03-callback/%.cpp src/03-callback/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -DDEBUG -D__CODE_RED -D__NEWLIB__ -DCORE_M0PLUS -D__MTB_BUFFER_SIZE=256 -D__USE_ROMDIVIDE -DCPP_USE_HEAP -D__LPC84X__ -I"C:\Users\elias\Desktop\Xpresso\LPC845_MatrizLedV3_2\src" -I"C:\Users\elias\Desktop\Xpresso\LPC845_MatrizLedV3_2\src\01-pin" -I"C:\Users\elias\Desktop\Xpresso\LPC845_MatrizLedV3_2\src\01-pin\in" -I"C:\Users\elias\Desktop\Xpresso\LPC845_MatrizLedV3_2\src\01-pin\out" -I"C:\Users\elias\Desktop\Xpresso\LPC845_MatrizLedV3_2\src\02-gpio" -I"C:\Users\elias\Desktop\Xpresso\LPC845_MatrizLedV3_2\src\03-callback" -I"C:\Users\elias\Desktop\Xpresso\LPC845_MatrizLedV3_2\src\05-SalidasDigitales" -I"C:\Users\elias\Desktop\Xpresso\LPC845_MatrizLedV3_2\src\12-USART" -I"C:\Users\elias\Desktop\Xpresso\LPC845_MatrizLedV3_2\src\aplicacion" -I"C:\Users\elias\Desktop\Xpresso\LPC845_MatrizLedV3_2\src\firmware" -I"C:\Users\elias\Desktop\Xpresso\LPC845_MatrizLedV3_2\src\firmware\CTimer" -I"C:\Users\elias\Desktop\Xpresso\LPC845_MatrizLedV3_2\src\firmware\SWM" -I"C:\Users\elias\Desktop\Xpresso\LPC845_MatrizLedV3_2\src\firmware\Systick" -I"C:\Users\elias\Desktop\Xpresso\LPC845_MatrizLedV3_2\src\Matriz" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fno-rtti -fno-exceptions -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0 -mthumb -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-03-2d-callback

clean-src-2f-03-2d-callback:
	-$(RM) ./src/03-callback/callback.d ./src/03-callback/callback.o

.PHONY: clean-src-2f-03-2d-callback

