################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/firmware/cr_cpp_config.cpp \
../src/firmware/cr_startup_lpc84x.cpp \
../src/firmware/dr_pll.cpp 

C_SRCS += \
../src/firmware/crp.c \
../src/firmware/mtb.c 

S_SRCS += \
../src/firmware/aeabi_romdiv_patch.s 

CPP_DEPS += \
./src/firmware/cr_cpp_config.d \
./src/firmware/cr_startup_lpc84x.d \
./src/firmware/dr_pll.d 

C_DEPS += \
./src/firmware/crp.d \
./src/firmware/mtb.d 

OBJS += \
./src/firmware/aeabi_romdiv_patch.o \
./src/firmware/cr_cpp_config.o \
./src/firmware/cr_startup_lpc84x.o \
./src/firmware/crp.o \
./src/firmware/dr_pll.o \
./src/firmware/mtb.o 


# Each subdirectory must supply rules for building sources it contributes
src/firmware/%.o: ../src/firmware/%.s src/firmware/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU Assembler'
	arm-none-eabi-gcc -c -x assembler-with-cpp -D__NEWLIB__ -DDEBUG -D__CODE_RED -DCORE_M0PLUS -D__USE_ROMDIVIDE -D__LPC84X__ -g3 -mcpu=cortex-m0 -mthumb -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/firmware/%.o: ../src/firmware/%.cpp src/firmware/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -DDEBUG -D__CODE_RED -D__NEWLIB__ -DCORE_M0PLUS -D__MTB_BUFFER_SIZE=256 -D__USE_ROMDIVIDE -DCPP_USE_HEAP -D__LPC84X__ -I"C:\Users\elias\Desktop\Xpresso\LPC845_MatrizLedV3_3\src" -I"C:\Users\elias\Desktop\Xpresso\LPC845_MatrizLedV3_3\src\01-pin" -I"C:\Users\elias\Desktop\Xpresso\LPC845_MatrizLedV3_3\src\01-pin\in" -I"C:\Users\elias\Desktop\Xpresso\LPC845_MatrizLedV3_3\src\01-pin\out" -I"C:\Users\elias\Desktop\Xpresso\LPC845_MatrizLedV3_3\src\02-gpio" -I"C:\Users\elias\Desktop\Xpresso\LPC845_MatrizLedV3_3\src\03-callback" -I"C:\Users\elias\Desktop\Xpresso\LPC845_MatrizLedV3_3\src\05-SalidasDigitales" -I"C:\Users\elias\Desktop\Xpresso\LPC845_MatrizLedV3_3\src\12-USART" -I"C:\Users\elias\Desktop\Xpresso\LPC845_MatrizLedV3_3\src\aplicacion" -I"C:\Users\elias\Desktop\Xpresso\LPC845_MatrizLedV3_3\src\firmware" -I"C:\Users\elias\Desktop\Xpresso\LPC845_MatrizLedV3_3\src\firmware\CTimer" -I"C:\Users\elias\Desktop\Xpresso\LPC845_MatrizLedV3_3\src\firmware\SWM" -I"C:\Users\elias\Desktop\Xpresso\LPC845_MatrizLedV3_3\src\firmware\Systick" -I"C:\Users\elias\Desktop\Xpresso\LPC845_MatrizLedV3_3\src\Matriz" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fno-rtti -fno-exceptions -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0 -mthumb -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/firmware/%.o: ../src/firmware/%.c src/firmware/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -D__NEWLIB__ -DCORE_M0PLUS -D__MTB_BUFFER_SIZE=256 -D__USE_ROMDIVIDE -DCPP_USE_HEAP -D__LPC84X__ -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0 -mthumb -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-firmware

clean-src-2f-firmware:
	-$(RM) ./src/firmware/aeabi_romdiv_patch.o ./src/firmware/cr_cpp_config.d ./src/firmware/cr_cpp_config.o ./src/firmware/cr_startup_lpc84x.d ./src/firmware/cr_startup_lpc84x.o ./src/firmware/crp.d ./src/firmware/crp.o ./src/firmware/dr_pll.d ./src/firmware/dr_pll.o ./src/firmware/mtb.d ./src/firmware/mtb.o

.PHONY: clean-src-2f-firmware

