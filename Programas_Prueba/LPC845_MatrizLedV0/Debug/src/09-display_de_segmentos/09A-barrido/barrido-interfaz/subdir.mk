################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/09-display_de_segmentos/09A-barrido/barrido-interfaz/barrido.cpp 

CPP_DEPS += \
./src/09-display_de_segmentos/09A-barrido/barrido-interfaz/barrido.d 

OBJS += \
./src/09-display_de_segmentos/09A-barrido/barrido-interfaz/barrido.o 


# Each subdirectory must supply rules for building sources it contributes
src/09-display_de_segmentos/09A-barrido/barrido-interfaz/%.o: ../src/09-display_de_segmentos/09A-barrido/barrido-interfaz/%.cpp src/09-display_de_segmentos/09A-barrido/barrido-interfaz/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -DDEBUG -D__CODE_RED -D__NEWLIB__ -DCORE_M0PLUS -D__MTB_BUFFER_SIZE=256 -D__USE_ROMDIVIDE -DCPP_USE_HEAP -D__LPC84X__ -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_MatrizLedV0\src" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_MatrizLedV0\src\01-pin" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_MatrizLedV0\src\01-pin\in" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_MatrizLedV0\src\01-pin\out" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_MatrizLedV0\src\02-gpio" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_MatrizLedV0\src\03-callback" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_MatrizLedV0\src\04-EntradasDigitales" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_MatrizLedV0\src\05-SalidasDigitales" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_MatrizLedV0\src\06-timer" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_MatrizLedV0\src\07-timers" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_MatrizLedV0\src\08-teclado" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_MatrizLedV0\src\09-display_de_segmentos" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_MatrizLedV0\src\09-display_de_segmentos\09A-barrido" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_MatrizLedV0\src\09-display_de_segmentos\09A-barrido\barrido-interfaz" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_MatrizLedV0\src\09-display_de_segmentos\09B-segmentos" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_MatrizLedV0\src\09-display_de_segmentos\09B-segmentos\segmentos-interfaz" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_MatrizLedV0\src\09-display_de_segmentos\09C-display" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_MatrizLedV0\src\11-adc" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_MatrizLedV0\src\12-USART" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_MatrizLedV0\src\aplicacion" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_MatrizLedV0\src\firmware" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_MatrizLedV0\src\firmware\CTimer" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_MatrizLedV0\src\firmware\SWM" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_MatrizLedV0\src\firmware\Systick" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fno-rtti -fno-exceptions -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0 -mthumb -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-09-2d-display_de_segmentos-2f-09A-2d-barrido-2f-barrido-2d-interfaz

clean-src-2f-09-2d-display_de_segmentos-2f-09A-2d-barrido-2f-barrido-2d-interfaz:
	-$(RM) ./src/09-display_de_segmentos/09A-barrido/barrido-interfaz/barrido.d ./src/09-display_de_segmentos/09A-barrido/barrido-interfaz/barrido.o

.PHONY: clean-src-2f-09-2d-display_de_segmentos-2f-09A-2d-barrido-2f-barrido-2d-interfaz

