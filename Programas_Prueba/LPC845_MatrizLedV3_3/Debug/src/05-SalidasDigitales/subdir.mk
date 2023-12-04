################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/05-SalidasDigitales/digital_outputs.cpp 

CPP_DEPS += \
./src/05-SalidasDigitales/digital_outputs.d 

OBJS += \
./src/05-SalidasDigitales/digital_outputs.o 


# Each subdirectory must supply rules for building sources it contributes
src/05-SalidasDigitales/%.o: ../src/05-SalidasDigitales/%.cpp src/05-SalidasDigitales/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -DDEBUG -D__CODE_RED -D__NEWLIB__ -DCORE_M0PLUS -D__MTB_BUFFER_SIZE=256 -D__USE_ROMDIVIDE -DCPP_USE_HEAP -D__LPC84X__ -I"C:\Users\elias\Desktop\Xpresso\LPC845_MatrizLedV3_3\src" -I"C:\Users\elias\Desktop\Xpresso\LPC845_MatrizLedV3_3\src\01-pin" -I"C:\Users\elias\Desktop\Xpresso\LPC845_MatrizLedV3_3\src\01-pin\in" -I"C:\Users\elias\Desktop\Xpresso\LPC845_MatrizLedV3_3\src\01-pin\out" -I"C:\Users\elias\Desktop\Xpresso\LPC845_MatrizLedV3_3\src\02-gpio" -I"C:\Users\elias\Desktop\Xpresso\LPC845_MatrizLedV3_3\src\03-callback" -I"C:\Users\elias\Desktop\Xpresso\LPC845_MatrizLedV3_3\src\05-SalidasDigitales" -I"C:\Users\elias\Desktop\Xpresso\LPC845_MatrizLedV3_3\src\12-USART" -I"C:\Users\elias\Desktop\Xpresso\LPC845_MatrizLedV3_3\src\aplicacion" -I"C:\Users\elias\Desktop\Xpresso\LPC845_MatrizLedV3_3\src\firmware" -I"C:\Users\elias\Desktop\Xpresso\LPC845_MatrizLedV3_3\src\firmware\CTimer" -I"C:\Users\elias\Desktop\Xpresso\LPC845_MatrizLedV3_3\src\firmware\SWM" -I"C:\Users\elias\Desktop\Xpresso\LPC845_MatrizLedV3_3\src\firmware\Systick" -I"C:\Users\elias\Desktop\Xpresso\LPC845_MatrizLedV3_3\src\Matriz" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fno-rtti -fno-exceptions -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0 -mthumb -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-05-2d-SalidasDigitales

clean-src-2f-05-2d-SalidasDigitales:
	-$(RM) ./src/05-SalidasDigitales/digital_outputs.d ./src/05-SalidasDigitales/digital_outputs.o

.PHONY: clean-src-2f-05-2d-SalidasDigitales

