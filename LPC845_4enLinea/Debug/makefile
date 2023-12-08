################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/firmware/Systick/subdir.mk
-include src/firmware/SWM/subdir.mk
-include src/firmware/Flash/subdir.mk
-include src/firmware/subdir.mk
-include src/aplicacion/subdir.mk
-include src/Modulos/12-USART/subdir.mk
-include src/Modulos/08-teclado/subdir.mk
-include src/Modulos/06-timer/subdir.mk
-include src/Modulos/05-SalidasDigitales/subdir.mk
-include src/Modulos/03-callback/subdir.mk
-include src/Modulos/02-gpio/subdir.mk
-include src/Librerias_externas/Tablero/subdir.mk
-include src/Librerias_externas/MatrizLed_Neopixel/subdir.mk
ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := LPC845_4enLinea
BUILD_ARTIFACT_EXTENSION := axf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all:
	+@$(MAKE) --no-print-directory main-build && $(MAKE) --no-print-directory post-build

# Main-build Target
main-build: LPC845_4enLinea.axf

# Tool invocations
LPC845_4enLinea.axf: $(OBJS) $(USER_OBJS) makefile $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU C++ Linker'
	arm-none-eabi-c++ -nostdlib -Xlinker -Map="LPC845_4enLinea.map" -Xlinker --cref -Xlinker --gc-sections -Xlinker -print-memory-usage -mcpu=cortex-m0 -mthumb -T LPC845_4enLinea_Debug.ld -o "LPC845_4enLinea.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) LPC845_4enLinea.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "LPC845_4enLinea.axf"; # arm-none-eabi-objcopy -v -O binary "LPC845_4enLinea.axf" "LPC845_4enLinea.bin" ; # checksum -p LPC845 -d "LPC845_4enLinea.bin";
	-@echo ' '

.PHONY: all clean dependents main-build post-build

-include ../makefile.targets
