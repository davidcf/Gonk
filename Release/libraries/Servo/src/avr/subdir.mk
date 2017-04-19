################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/Applications/sloeber.app/Contents/Eclipse/arduinoPlugin/libraries/Servo/1.1.2/src/avr/Servo.cpp 

LINK_OBJ += \
./libraries/Servo/src/avr/Servo.cpp.o 

CPP_DEPS += \
./libraries/Servo/src/avr/Servo.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
libraries/Servo/src/avr/Servo.cpp.o: /Applications/sloeber.app/Contents/Eclipse/arduinoPlugin/libraries/Servo/1.1.2/src/avr/Servo.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/Applications/sloeber.app/Contents/Eclipse//arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"/Applications/sloeber.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.6.17/cores/arduino" -I"/Applications/sloeber.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.6.17/variants/eightanaloginputs" -I"/Applications/sloeber.app/Contents/Eclipse/arduinoPlugin/libraries/Servo/1.1.2" -I"/Applications/sloeber.app/Contents/Eclipse/arduinoPlugin/libraries/Servo/1.1.2/src" -I"/Users/destroyer/Documents/Arduino/libraries/US" -I"/Users/destroyer/Documents/Arduino/libraries/Oscillator" -I"/Applications/sloeber.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.6.17/libraries/EEPROM" -I"/Applications/sloeber.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.6.17/libraries/EEPROM/src" -I"/Users/destroyer/Documents/Arduino/libraries/BatReader" -I"/Users/destroyer/Documents/Arduino/libraries/LedMatrix" -I"/Users/destroyer/Documents/Arduino/libraries/Gonk" -I"/Users/destroyer/Documents/Arduino/libraries/Gonk/src" -I"/Users/destroyer/Documents/Arduino/libraries/Adafruit_SSD1306" -I"/Applications/sloeber.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.6.17/libraries/SPI" -I"/Applications/sloeber.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.6.17/libraries/SPI/src" -I"/Applications/sloeber.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.6.17/libraries/Wire" -I"/Applications/sloeber.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.6.17/libraries/Wire/src" -I"/Users/destroyer/Documents/Arduino/libraries/Adafruit_GFX_Library" -I"/Users/destroyer/Documents/Arduino/libraries/U8glib" -I"/Users/destroyer/Documents/Arduino/libraries/U8glib/utility" -I"/Users/destroyer/Documents/Arduino/libraries/PS2X_lib" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '


