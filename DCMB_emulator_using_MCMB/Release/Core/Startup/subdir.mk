################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Core/Startup/startup_stm32h753bitx.s 

OBJS += \
./Core/Startup/startup_stm32h753bitx.o 

S_DEPS += \
./Core/Startup/startup_stm32h753bitx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Startup/startup_stm32h753bitx.o: ../Core/Startup/startup_stm32h753bitx.s
	arm-none-eabi-gcc -mcpu=cortex-m7 -c -x assembler-with-cpp -MMD -MP -MF"Core/Startup/startup_stm32h753bitx.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

