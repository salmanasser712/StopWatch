################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/7_segmant.c \
../Src/Delay.c \
../Src/GPIO.c \
../Src/NVIC.c \
../Src/RCC.c \
../Src/Systick.c \
../Src/app.c \
../Src/keypad.c \
../Src/main.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/7_segmant.o \
./Src/Delay.o \
./Src/GPIO.o \
./Src/NVIC.o \
./Src/RCC.o \
./Src/Systick.o \
./Src/app.o \
./Src/keypad.o \
./Src/main.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/7_segmant.d \
./Src/Delay.d \
./Src/GPIO.d \
./Src/NVIC.d \
./Src/RCC.d \
./Src/Systick.d \
./Src/app.d \
./Src/keypad.d \
./Src/main.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/7_segmant.cyclo ./Src/7_segmant.d ./Src/7_segmant.o ./Src/7_segmant.su ./Src/Delay.cyclo ./Src/Delay.d ./Src/Delay.o ./Src/Delay.su ./Src/GPIO.cyclo ./Src/GPIO.d ./Src/GPIO.o ./Src/GPIO.su ./Src/NVIC.cyclo ./Src/NVIC.d ./Src/NVIC.o ./Src/NVIC.su ./Src/RCC.cyclo ./Src/RCC.d ./Src/RCC.o ./Src/RCC.su ./Src/Systick.cyclo ./Src/Systick.d ./Src/Systick.o ./Src/Systick.su ./Src/app.cyclo ./Src/app.d ./Src/app.o ./Src/app.su ./Src/keypad.cyclo ./Src/keypad.d ./Src/keypad.o ./Src/keypad.su ./Src/main.cyclo ./Src/main.d ./Src/main.o ./Src/main.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su

.PHONY: clean-Src

