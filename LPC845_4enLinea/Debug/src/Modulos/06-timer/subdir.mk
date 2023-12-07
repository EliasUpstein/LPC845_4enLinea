################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Modulos/06-timer/timer.cpp 

CPP_DEPS += \
./src/Modulos/06-timer/timer.d 

OBJS += \
./src/Modulos/06-timer/timer.o 


# Each subdirectory must supply rules for building sources it contributes
src/Modulos/06-timer/%.o: ../src/Modulos/06-timer/%.cpp src/Modulos/06-timer/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -DDEBUG -D__CODE_RED -D__NEWLIB__ -DCORE_M0PLUS -D__MTB_BUFFER_SIZE=256 -D__USE_ROMDIVIDE -DCPP_USE_HEAP -D__LPC84X__ -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_4enLinea\src" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_4enLinea\src\aplicacion" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_4enLinea\src\firmware" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_4enLinea\src\firmware\Flash" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_4enLinea\src\firmware\SWM" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_4enLinea\src\firmware\Systick" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_4enLinea\src\Librerias_externas" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_4enLinea\src\Librerias_externas\MatrizLed_Neopixel" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_4enLinea\src\Librerias_externas\Tablero" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_4enLinea\src\Modulos" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_4enLinea\src\Modulos\01-pin" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_4enLinea\src\Modulos\01-pin\in" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_4enLinea\src\Modulos\01-pin\out" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_4enLinea\src\Modulos\02-gpio" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_4enLinea\src\Modulos\03-callback" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_4enLinea\src\Modulos\05-SalidasDigitales" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_4enLinea\src\Modulos\06-timer" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_4enLinea\src\Modulos\08-teclado" -I"C:\Users\Casa\Desktop\Eli\Archivos\Xpresso\LPC845_4enLinea\src\Modulos\12-USART" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fno-rtti -fno-exceptions -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0 -mthumb -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-Modulos-2f-06-2d-timer

clean-src-2f-Modulos-2f-06-2d-timer:
	-$(RM) ./src/Modulos/06-timer/timer.d ./src/Modulos/06-timer/timer.o

.PHONY: clean-src-2f-Modulos-2f-06-2d-timer

