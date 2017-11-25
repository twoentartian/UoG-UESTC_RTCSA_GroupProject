###############################################################################
# Makefile for the project AT45DBXXX_LCD12864
###############################################################################

## General Flags
PROJECT = AT45DBXXX_LCD12864
MCU = atmega64
TARGET = AT45DBXXX_LCD12864.elf
CC = avr-gcc

CPP = avr-g++

## Options common to compile, link and assembly rules
COMMON = -mmcu=$(MCU)

## Compile options common for all C compilation units.
CFLAGS = $(COMMON)
CFLAGS += -Wall -gdwarf-2 -std=gnu99       -DF_CPU=7372800UL -Os -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums
CFLAGS += -MD -MP -MT $(*F).o -MF dep/$(@F).d 

## Assembly specific flags
ASMFLAGS = $(COMMON)
ASMFLAGS += $(CFLAGS)
ASMFLAGS += -x assembler-with-cpp -Wa,-gdwarf2

## Linker flags
LDFLAGS = $(COMMON)
LDFLAGS +=  -Wl,-Map=AT45DBXXX_LCD12864.map


## Intel Hex file production flags
HEX_FLASH_FLAGS = -R .eeprom -R .fuse -R .lock -R .signature

HEX_EEPROM_FLAGS = -j .eeprom
HEX_EEPROM_FLAGS += --set-section-flags=.eeprom="alloc,load"
HEX_EEPROM_FLAGS += --change-section-lma .eeprom=0 --no-change-warnings


## Include Directories
INCLUDES = -I"E:\Program_CD\CD\CD_AVR\data\Program\M128+ EX\M128+ EX V1.0\GCC\DVK501\AT45DBXXX\AT45DBXXX_LCD12864\..\..\..\..\..\..\..\ws_lib\GCC_H" 

## Objects that must be built in order to link
OBJECTS = AT45DBXXX_LCD12864.o 

## Objects explicitly added by the user
LINKONLYOBJECTS = 

## Build
all: $(TARGET) AT45DBXXX_LCD12864.hex AT45DBXXX_LCD12864.eep AT45DBXXX_LCD12864.lss size

## Compile
AT45DBXXX_LCD12864.o: ../AT45DBXXX_LCD12864.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

##Link
$(TARGET): $(OBJECTS)
	 $(CC) $(LDFLAGS) $(OBJECTS) $(LINKONLYOBJECTS) $(LIBDIRS) $(LIBS) -o $(TARGET)

%.hex: $(TARGET)
	avr-objcopy -O ihex $(HEX_FLASH_FLAGS)  $< $@

%.eep: $(TARGET)
	-avr-objcopy $(HEX_EEPROM_FLAGS) -O ihex $< $@ || exit 0

%.lss: $(TARGET)
	avr-objdump -h -S $< > $@

size: ${TARGET}
	@echo
	@avr-size -C --mcu=${MCU} ${TARGET}

## Clean target
.PHONY: clean
clean:
	-rm -rf $(OBJECTS) AT45DBXXX_LCD12864.elf dep/* AT45DBXXX_LCD12864.hex AT45DBXXX_LCD12864.eep AT45DBXXX_LCD12864.lss AT45DBXXX_LCD12864.map


## Other dependencies
-include $(shell mkdir dep 2>/dev/null) $(wildcard dep/*)

