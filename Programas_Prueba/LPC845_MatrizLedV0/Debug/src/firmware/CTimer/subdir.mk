################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/firmware/CTimer/ctimer.cpp 

CPP_DEPS += \
./src/firmware/CTimer/ctimer.d 

OBJS += \
./src/firmware/CTimer/ctimer.o 


# Each subdirectory must supply rules for building sources it contributes
src/firmware/CTimer/%.o: ../src/firmware/CTimer/%.cpp src/firmware/CTimer/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -DDEBUG -D__CODE_RED -D__NEWLIB__ -DCORE_M0PLUS -D__MTB_BUFFER_SIZE=256 -D__USE_ROMDIVIDE -DCPP_USE_HEAP -D__LPC84X__ -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_MatrizLedV0\src" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_MatrizLedV0\src\01-pin" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_MatrizLedV0\src\01-pin\in" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_MatrizLedV0\src\01-pin\out" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_MatrizLedV0\src\02-gpio" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_MatrizLedV0\src\03-callback" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_MatrizLedV0\src\05-SalidasDigitales" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_MatrizLedV0\src\12-USART" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_MatrizLedV0\src\aplicacion" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_MatrizLedV0\src\firmware" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_MatrizLedV0\src\firmware\CTimer" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_MatrizLedV0\src\firmware\SWM" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_MatrizLedV0\src\firmware\Systick" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_MatrizLedV0\src\Matriz" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fno-rtti -fno-exceptions -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0 -mthumb -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-firmware-2f-CTimer

clean-src-2f-firmware-2f-CTimer:
	-$(RM) ./src/firmware/CTimer/ctimer.d ./src/firmware/CTimer/ctimer.o

.PHONY: clean-src-2f-firmware-2f-CTimer

