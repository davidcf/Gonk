################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -f

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include libraries/US/subdir.mk
-include libraries/Servo/src/stm32f4/subdir.mk
-include libraries/Servo/src/samd/subdir.mk
-include libraries/Servo/src/sam/subdir.mk
-include libraries/Servo/src/nrf52/subdir.mk
-include libraries/Servo/src/avr/subdir.mk
-include libraries/Oscillator/subdir.mk
-include libraries/LedMatrix/LedMatrix_Code/subdir.mk
-include libraries/LedMatrix/subdir.mk
-include libraries/Gonk/src/subdir.mk
-include libraries/BatReader/BatReader_Example/subdir.mk
-include libraries/BatReader/subdir.mk
-include core/core/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
AR += \
/Users/destroyer/Documents/arduino-workspace/Gonk/Release/arduino.ar \

ELF += \
Gonk.elf \

HEX += \
Gonk.hex \


# All Target
all: Gonk

# Tool invocations
Gonk: $(HEX)
	@echo 'Building target: $@'
	@echo 'Printing size:'
	"/Applications/sloeber.app/Contents/Eclipse//arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.3-arduino2/bin/avr-size" -A "/Users/destroyer/Documents/arduino-workspace/Gonk/Release/Gonk.elf"
	@echo 'Finished building target: $@'
	@echo ' '

/Users/destroyer/Documents/arduino-workspace/Gonk/Release/arduino.ar: $(AR_OBJ)
	@echo 'Starting archiver'
	"/Applications/sloeber.app/Contents/Eclipse//arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.3-arduino2/bin/avr-gcc-ar" rcs    /Users/destroyer/Documents/arduino-workspace/Gonk/Release/arduino.ar $(AR_OBJ)
	@echo 'Finished building: $@'
	@echo ' '

Gonk.elf: $(LINK_OBJ) $(AR)
	@echo 'Starting combiner'
	"/Applications/sloeber.app/Contents/Eclipse//arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.3-arduino2/bin/avr-gcc" -Wall -Wextra -Os -g -flto -fuse-linker-plugin -Wl,--gc-sections -mmcu=atmega328p -o "/Users/destroyer/Documents/arduino-workspace/Gonk/Release/Gonk.elf"   $(LINK_OBJ) $(AR)   /Users/destroyer/Documents/arduino-workspace/Gonk/Release/arduino.ar  "-L/Users/destroyer/Documents/arduino-workspace/Gonk/Release" -lm
	@echo 'Finished building: $@'
	@echo ' '

Gonk.hex: $(ELF)
	@echo 'Do all objcopy commands'
	${A.RECIPE.OBJCOPY.EEP.PATTERN}
	${A.RECIPE.OBJCOPY.HEX.PATTERN}
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C_UPPER_DEPS)$(PDE_DEPS)$(C_DEPS)$(AR)$(CC_DEPS)$(AR_OBJ)$(C++_DEPS)$(LINK_OBJ)$(CXX_DEPS)$(ASM_DEPS)$(HEX)$(INO_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(ELF)$(CPP_DEPS)
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
