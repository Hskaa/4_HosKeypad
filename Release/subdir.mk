################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_Prog.c \
../KPD_Prog.c \
../LCD_Prog.c \
../PORT_Prog.c \
../main.c 

OBJS += \
./DIO_Prog.o \
./KPD_Prog.o \
./LCD_Prog.o \
./PORT_Prog.o \
./main.o 

C_DEPS += \
./DIO_Prog.d \
./KPD_Prog.d \
./LCD_Prog.d \
./PORT_Prog.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


