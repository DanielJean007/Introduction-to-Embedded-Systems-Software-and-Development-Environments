#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# Make File For Assesment 2
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#	<FILE>.o - Builds <File>.o object file
#	<FILE>.out - Builds <File>.out file
#	<FILE>.d - Builds <File>.d dependency file
#	<FILE>.asm - Builds <File>.asm assembly file
#	build - Builds and links all source files
#	all - Same as build
#	clean - Removes all generated files      
#
# Platform Overrides:
#      CPU - ARM Cortex Arch (cortex-m4)
#      ARCH - ARM Arch (arm,thumb)
#      SPECS - Specs file to give the linker
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM ?= HOST

LINKER_FILE = ../msp432p401r.lds
LDFLAGS = -Wl,-Map=$(BASENAME).map -T -$(LINKER_FILE)
CPPFLAGs = -MD -MP
CPU = cortex-m4
ARCH = armv7e-m
BASENAME = c1m2
SPECS = nosys.specs
ARCHFLAGS = -mcpu=$(CPU) -mthumb -march$(ARCH) -mfloat-abi=hard -mfpu=fpv4-sp-d16 --specs=$(SPECS)

ifeq ($(PLATFORM),HOST)
	INCLUDES = -I../include/common
	CC = gcc
	LDFLAGS = -Xlinker -Map=$(BASENAME).map
	CFLAGS = -DHOST -Wall -g -O0 -std=c99 $(INCLUDES)
	SOURCES = main.c memory.c
	OBJDUMP = objdump -d

else
	# Architectures Specific Flags
	CC = arm-none-eabi-gcc
	OBJDUMP = arm-none-eabi-objdump -d
	CFLAGS = $(ARCHFLAGS) -DMSP432 -Wall -Werror -g -O0 -std=c99 $(INCLUDES) -nonstdlib 

endif

OBJS =$(SOURCES:.c=.o)
DEPS = $(SOURCE:.c=.d)

.PHONY: compile-all
compile-all: $(OBJS)

.PHONY: build
build: $(OBJS) $(DEPS)
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $(BASENAME).out
	size $(OBJS)

.PHONY: clean
clean:
	rm *.o *.d *.i *.asm *.out *.map

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@

%.asm : %.c
	$(CC) -E $< $(CFLAGS) -o $@
	$(CC) $(SOURCES) $(CFLAGS) $(LDFLAGS) -o $(BASENAME).out
	$(OBJDUMP) $(BASENAME).out

%.d : %.c
	$(CC) -MM $(CFLAGS) $*.c > $*.d

%.map: $(OBJS)
	$(CC) -T $(OBJS) $(LDFLAGS) $(BASENAME).map
	

