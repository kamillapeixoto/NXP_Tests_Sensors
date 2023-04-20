################################################################################
# Automatically-generated file. Do not edit!
################################################################################

#Progress monitor hint: 6
first : all
-include ../makefile.init

# This file contains definitions of environment variables used in the makefiles and .args files if exist.
-include makefile.local

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include Project_Settings/Linker_Files/subdir.mk
-include Project_Settings/Startup_Code/subdir.mk
-include src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
LPSPI.elf \

EXECUTABLES_QUOTED += \
"LPSPI.elf" \

EXECUTABLES_OS_FORMAT += \
LPSPI.elf \

SECONDARY_SIZE += \
LPSPI.siz \

SECONDARY_SIZE_QUOTED += \
"LPSPI.siz" \

SECONDARY_SIZE_OS_FORMAT += \
LPSPI.siz \


# All Target
all: warning-messages explicit-dependencies LPSPI.elf secondary-outputs

# Tool invocations
LPSPI.elf: $(OBJS) C:/Users/kamil/OneDrive/Documents/GitHub/NXP_Tests_Scaleo/SDK32S144/LPSPI/Project_Settings/Linker_Files/S32K1xx_flash.ld $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Executing target #7 $@'
	@echo 'Invoking: Standard S32DS C Linker'
	arm-none-eabi-gcc -o "LPSPI.elf" "@LPSPI.args"  $(USER_OBJS_QUOTED) $(LIBS_QUOTED)
	@echo 'Finished building target: $@'
	@echo ' '

LPSPI.siz: $(EXECUTABLES)
	@echo 'Executing target #8 $@'
	@echo 'Invoking: Standard S32DS Print Size'
	arm-none-eabi-size --format=berkeley $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) ./*/*.d ./*/*/*.d  ./*/*.o ./*/*/*.o  $(SECONDARY_SIZE_QUOTED) $(EXECUTABLES_QUOTED)
	-@echo ' '

secondary-outputs: $(SECONDARY_SIZE)

.PHONY: all clean dependents explicit-dependencies warning-messages
.SECONDARY:

-include ../makefile.targets

explicit-dependencies: 

warning-messages: 

