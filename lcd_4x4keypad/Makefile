MCU=atmega32
F_CPU=14745600  #clock frequency
CC=avr-gcc
OBJCOPY=avr-objcopy
CFLAGS=-std=c99 -pedantic -Wall -g -Os -mmcu=${MCU} -DF_CPU=${F_CPU} -I.
TARGET=keypad_4x4
SRCS=keypad_4x4.c

all:
		@echo "building target ${target.o}\n"
		${CC} ${CFLAGS} -o ${TARGET}.bin ${TARGET}.c
		@echo "creating hex file of  ${TARGET}\n"
		${OBJCOPY} -j .text -j .data -O ihex ${TARGET}.bin ${TARGET}.hex

flash:
		avrdude -p ${MCU} -c usbasp -U flash:w:${TARGET}.hex:i  -F -P usb

clean:
		@echo "Cleaning workspace:"
		rm -f *.bin *.hex

memory:
		@echo "Memory usage checking:"
		avr-size -C --mcu=${MCU} ${TARGET}.bin

