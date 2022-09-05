MCU=atmega328p
F_CPU=16000000  #clock frequency
CC=avr-gcc
OBJCOPY=avr-objcopy
CFLAGS=-std=c99 -pedantic -Wall -g -Os -mmcu=${MCU} -DF_CPU=${F_CPU} -I.
TARGET=led
SRCS=led.c

all:
		@echo "building target ${target.o}\n"
		${CC} ${CFLAGS} -o ${TARGET}.bin ${TARGET}.c
		@echo "creating hex file of  ${TARGET}\n"
		${OBJCOPY} -j .text -j .data -O ihex ${TARGET}.bin ${TARGET}.hex

flash:
		avrdude -p ${MCU} -c usbasp -U flash:w:${TARGET}.hex:i  -F -P usb

clean:
		@echo "Cleaning workspace"
		rm -f *.bin *.hex

memory:
		avr-size -C --mcu=${MCU} ${TARGET}.bin

