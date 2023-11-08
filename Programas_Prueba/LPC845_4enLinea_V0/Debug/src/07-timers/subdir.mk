################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/07-timers/timers.cpp 

CPP_DEPS += \
./src/07-timers/timers.d 

OBJS += \
./src/07-timers/timers.o 


# Each subdirectory must supply rules for building sources it contributes
src/07-timers/%.o: ../src/07-timers/%.cpp src/07-timers/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -DDEBUG -D__CODE_RED -D__NEWLIB__ -DCORE_M0PLUS -D__MTB_BUFFER_SIZE=256 -D__USE_ROMDIVIDE -DCPP_USE_HEAP -D__LPC84X__ -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_4enLinea_V0\src" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_4enLinea_V0\src\01-pin" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_4enLinea_V0\src\01-pin\in" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_4enLinea_V0\src\01-pin\out" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_4enLinea_V0\src\02-gpio" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_4enLinea_V0\src\03-callback" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_4enLinea_V0\src\04-EntradasDigitales" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_4enLinea_V0\src\05-SalidasDigitales" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_4enLinea_V0\src\06-timer" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_4enLinea_V0\src\07-timers" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_4enLinea_V0\src\08-teclado" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_4enLinea_V0\src\09-display_de_segmentos" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_4enLinea_V0\src\09-display_de_segmentos\09A-barrido" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_4enLinea_V0\src\09-display_de_segmentos\09A-barrido\barrido-interfaz" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_4enLinea_V0\src\09-display_de_segmentos\09B-segmentos" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_4enLinea_V0\src\09-display_de_segmentos\09B-segmentos\segmentos-interfaz" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_4enLinea_V0\src\09-display_de_segmentos\09C-display" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_4enLinea_V0\src\11-adc" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_4enLinea_V0\src\12-USART" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_4enLinea_V0\src\aplicacion" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_4enLinea_V0\src\firmware" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fno-rtti -fno-exceptions -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0 -mthumb -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-07-2d-timers

clean-src-2f-07-2d-timers:
	-$(RM) ./src/07-timers/timers.d ./src/07-timers/timers.o

.PHONY: clean-src-2f-07-2d-timers

