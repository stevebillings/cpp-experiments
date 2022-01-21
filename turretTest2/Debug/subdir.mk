################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../ServoWrapper.cpp \
../Turret.cpp \
../main.cpp 

CPP_DEPS += \
./ServoWrapper.d \
./Turret.d \
./main.d 

OBJS += \
./ServoWrapper.o \
./Turret.o \
./main.o 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++2a -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean--2e-

clean--2e-:
	-$(RM) ./ServoWrapper.d ./ServoWrapper.o ./Turret.d ./Turret.o ./main.d ./main.o

.PHONY: clean--2e-

