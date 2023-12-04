################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/02-gpio/gpio.cpp 

CPP_DEPS += \
./src/02-gpio/gpio.d 

OBJS += \
./src/02-gpio/gpio.o 


# Each subdirectory must supply rules for building sources it contributes
src/02-gpio/%.o: ../src/02-gpio/%.cpp src/02-gpio/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -DDEBUG -D__CODE_RED -D__NEWLIB__ -DCORE_M0PLUS -D__MTB_BUFFER_SIZE=256 -D__USE_ROMDIVIDE -DCPP_USE_HEAP -D__LPC84X__ -I"C:\Users\elias\Desktop\Xpresso\LPC845_MatrizLedV3_5\src" -I"C:\Users\elias\Desktop\Xpresso\LPC845_MatrizLedV3_5\src\01-pin" -I"C:\Users\elias\Desktop\Xpresso\LPC845_MatrizLedV3_5\src\01-pin\in" -I"C:\Users\elias\Desktop\Xpresso\LPC845_MatrizLedV3_5\src\01-pin\out" -I"C:\Users\elias\Desktop\Xpresso\LPC845_MatrizLedV3_5\src\02-gpio" -I"C:\Users\elias\Desktop\Xpresso\LPC845_MatrizLedV3_5\src\03-callback" -I"C:\Users\elias\Desktop\Xpresso\LPC845_MatrizLedV3_5\src\05-SalidasDigitales" -I"C:\Users\elias\Desktop\Xpresso\LPC845_MatrizLedV3_5\src\12-USART" -I"C:\Users\elias\Desktop\Xpresso\LPC845_MatrizLedV3_5\src\aplicacion" -I"C:\Users\elias\Desktop\Xpresso\LPC845_MatrizLedV3_5\src\firmware" -I"C:\Users\elias\Desktop\Xpresso\LPC845_MatrizLedV3_5\src\firmware\CTimer" -I"C:\Users\elias\Desktop\Xpresso\LPC845_MatrizLedV3_5\src\firmware\SWM" -I"C:\Users\elias\Desktop\Xpresso\LPC845_MatrizLedV3_5\src\firmware\Systick" -I"C:\Users\elias\Desktop\Xpresso\LPC845_MatrizLedV3_5\src\Matriz" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fno-rtti -fno-exceptions -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0 -mthumb -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-02-2d-gpio

clean-src-2f-02-2d-gpio:
	-$(RM) ./src/02-gpio/gpio.d ./src/02-gpio/gpio.o

.PHONY: clean-src-2f-02-2d-gpio

