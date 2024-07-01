################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CLCD.c \
../DIO.c \
../EXTI.c \
../GIE.c \
../keypad.c \
../main.c \
../timer.c 

OBJS += \
./CLCD.o \
./DIO.o \
./EXTI.o \
./GIE.o \
./keypad.o \
./main.o \
./timer.o 

C_DEPS += \
./CLCD.d \
./DIO.d \
./EXTI.d \
./GIE.d \
./keypad.d \
./main.d \
./timer.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


