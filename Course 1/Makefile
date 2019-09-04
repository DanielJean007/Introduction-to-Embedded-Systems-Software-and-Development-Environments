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
# Make File For The Final Assesment
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


PLATFORM = HOST

include sources.mk
COURSE = COURSE1
VERBOSE = VERBOSE

LINKER_FILE = msp432p401r.lds
CPU = cortex-m4
ARCH = armv7e-m
SPECS = nosys.specs


TARGET = FinalAss

CC = gcc
LD = ld

COMMON_FLAGS = -Wall -g -O0 -std=c99 $(INCLUDES) -D$(COURSE) -D$(VERBOSE)

ifeq ($(PLATFORM),HOST)
  CC = gcc
  LD = ld
  OBJDUMP = objdump
  SIZE = size
  MY_CPPFLAGS = $(COMMON_FLAGS) -E -DHOST
  CFLAGS = $(COMMON_FLAGS) -MD -MP -DHOST
  LDFLAGS = -Wl,-Map=$(TARGET).map
endif

ifeq ($(PLATFORM),MSP432)
  CC = arm-none-eabi-gcc
  LD = arm-none-eabi-ld
  OBJDUMP = arm-none-eabi-objdump
  SIZE = arm-none-eabi-size
  MY_CPPFLAGS = $(COMMON_FLAGS) -E -DMSP432
  CFLAGS = $(COMMON_FLAGS) -mcpu=$(CPU) -march=$(ARCH) -mthumb -mfloat-abi=hard\
   -mfpu=fpv4-sp-d16 --specs=$(SPECS) -MD -MP -DMSP432
  LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE) -mfloat-abi=hard --specs=$(SPECS)
endif

PRES = $(SOURCES:.c=.i)
OBJS = $(SOURCES:.c=.o)

%.i : src/%.c
	$(CC) $(MY_CPPFLAGS) -o src/$@ $<

%.asm : src/%.o
	$(OBJDUMP) -S $< > src/$@

$(TARGET).out.asm: $(TARGET).out
	$(OBJDUMP) -S $< > src/$@

.PHONY: compile-all
compile-all: $(OBJS)
	echo $(OBJS)

%.o : src/%.c
	$(CC) -c $< $(CFLAGS) -o src/$@

.PHONY: build
build: all

.PHONY: all
all: $(TARGET).out

$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $@ && $(SIZE) -Atd $(TARGET).out

.PHONY: clean
clean:
	rm -f src/*.o src/*.i *.out *.map src/*.d src/*.asm

