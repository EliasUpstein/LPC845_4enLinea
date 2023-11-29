################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/firmware/SWM/swm.cpp 

CPP_DEPS += \
./src/firmware/SWM/swm.d 

OBJS += \
./src/firmware/SWM/swm.o 


# Each subdirectory must supply rules for building sources it contributes
src/firmware/SWM/%.o: ../src/firmware/SWM/%.cpp src/firmware/SWM/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -DDEBUG -D__CODE_RED -D__NEWLIB__ -DCORE_M0PLUS -D__MTB_BUFFER_SIZE=256 -D__USE_ROMDIVIDE -DCPP_USE_HEAP -D__LPC84X__ -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_MatrizLedV3_1\src" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_MatrizLedV3_1\src\01-pin" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_MatrizLedV3_1\src\01-pin\in" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_MatrizLedV3_1\src\01-pin\out" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_MatrizLedV3_1\src\02-gpio" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_MatrizLedV3_1\src\03-callback" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_MatrizLedV3_1\src\05-SalidasDigitales" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_MatrizLedV3_1\src\12-USART" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_MatrizLedV3_1\src\aplicacion" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_MatrizLedV3_1\src\firmware" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_MatrizLedV3_1\src\firmware\CTimer" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_MatrizLedV3_1\src\firmware\SWM" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_MatrizLedV3_1\src\firmware\Systick" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_MatrizLedV3_1\src\Matriz" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fno-rtti -fno-exceptions -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0 -mthumb -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-firmware-2f-SWM

clean-src-2f-firmware-2f-SWM:
	-$(RM) ./src/firmware/SWM/swm.d ./src/firmware/SWM/swm.o

.PHONY: clean-src-2f-firmware-2f-SWM

