################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include generate/src/subdir.mk
-include board/subdir.mk
-include RTD/src/subdir.mk
-include Project_Settings/Startup_Code/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_SIZE += \
S32K344_MQFP172_DEMO_GPIO.siz \


# All Target
all: S32K344_MQFP172_DEMO_GPIO.elf secondary-outputs

# Tool invocations
S32K344_MQFP172_DEMO_GPIO.elf: $(OBJS) D:/Users/Jinhui/Documents/Projects/NXP/S32DesignStudio/S32K344EHT1VPBST/S32K344_MQFP172_DEMO_GPIO/Project_Settings/Linker_Files/linker_flash_s32k344.ld $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Standard S32DS C Linker'
	arm-none-eabi-gcc -o "S32K344_MQFP172_DEMO_GPIO.elf" "@S32K344_MQFP172_DEMO_GPIO.args"  $(USER_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

S32K344_MQFP172_DEMO_GPIO.siz: S32K344_MQFP172_DEMO_GPIO.elf
	@echo 'Invoking: Standard S32DS Print Size'
	arm-none-eabi-size --format=berkeley S32K344_MQFP172_DEMO_GPIO.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) ./*
	-@echo ' '

secondary-outputs: $(SECONDARY_SIZE)

.PHONY: all clean dependents

-include ../makefile.targets
