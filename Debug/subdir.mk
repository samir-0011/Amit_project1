################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC_Program.c \
../DIO_Pro.c \
../EEPROM_Program.c \
../EXTI_Program.c \
../GIE_Program.c \
../SEVEN_SEGMENT_PROGRAM.c \
../TIMER2_Program.c \
../Test.c \
../Timer_Program.c 

OBJS += \
./ADC_Program.o \
./DIO_Pro.o \
./EEPROM_Program.o \
./EXTI_Program.o \
./GIE_Program.o \
./SEVEN_SEGMENT_PROGRAM.o \
./TIMER2_Program.o \
./Test.o \
./Timer_Program.o 

C_DEPS += \
./ADC_Program.d \
./DIO_Pro.d \
./EEPROM_Program.d \
./EXTI_Program.d \
./GIE_Program.d \
./SEVEN_SEGMENT_PROGRAM.d \
./TIMER2_Program.d \
./Test.d \
./Timer_Program.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

EEPROM_Program.o: ../EEPROM_Program.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O2 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"EEPROM_Program.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


