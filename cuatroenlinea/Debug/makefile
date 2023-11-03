################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/firmware/subdir.mk
-include src/aplicacion/subdir.mk
-include src/12-USART/subdir.mk
-include src/11-adc/subdir.mk
-include src/09-display_de_segmentos/09C-display/subdir.mk
-include src/09-display_de_segmentos/09B-segmentos/segmentos-interfaz/subdir.mk
-include src/09-display_de_segmentos/09B-segmentos/subdir.mk
-include src/09-display_de_segmentos/09A-barrido/barrido-interfaz/subdir.mk
-include src/09-display_de_segmentos/09A-barrido/subdir.mk
-include src/08-teclado/subdir.mk
-include src/07-timers/subdir.mk
-include src/06-timer/subdir.mk
-include src/05-SalidasDigitales/subdir.mk
-include src/04-EntradasDigitales/subdir.mk
-include src/03-callback/subdir.mk
-include src/02-gpio/subdir.mk
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


BUILD_ARTIFACT_NAME := cuatroenlinea
BUILD_ARTIFACT_EXTENSION := axf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all:
	+@$(MAKE) --no-print-directory main-build && $(MAKE) --no-print-directory post-build

# Main-build Target
main-build: cuatroenlinea.axf

# Tool invocations
cuatroenlinea.axf: $(OBJS) $(USER_OBJS) makefile $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU C++ Linker'
	arm-none-eabi-c++ -nostdlib -Xlinker -Map="cuatroenlinea.map" -Xlinker --cref -Xlinker --gc-sections -Xlinker -print-memory-usage -mcpu=cortex-m0 -mthumb -T "cuatroenlinea_Debug.ld" -o "cuatroenlinea.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) cuatroenlinea.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "cuatroenlinea.axf"; # arm-none-eabi-objcopy -v -O binary "cuatroenlinea.axf" "cuatroenlinea.bin" ; # checksum -p LPC845 -d "cuatroenlinea.bin";
	-@echo ' '

.PHONY: all clean dependents main-build post-build

-include ../makefile.targets
