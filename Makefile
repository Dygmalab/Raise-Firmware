DEVICE_PORT=/dev/ttyACM0
ARDUINO_PATH=~/work/shortcut/arm/arduino-1.8.2
EDBG=~/work/shortcut/arm/edbg/edbg
DYGMADIR=/home/matt/Arduino/hardware/dygma/samd
BOOTLOADER=${DYGMADIR}/bootloaders/zero/samd21_sam_ba.bin
ICECFG=${DYGMADIR}/variants/arduino_zero/openocd_scripts/arduino_zero.cfg
LAST_PROG=$(shell \ls /tmp/arduino_*/*.ino.hex --sort=time  | head -1)
BUILD_PATH=./output
FIRMWARE=Raise-Firmware.ino

# arduino command line arguments
# https://github.com/arduino/Arduino/blob/master/build/shared/manpage.adoc

read-fuse:
	${EDBG} -b -c 48000 -t atmel_cm0p -F r,6:4
	# default should read Fuses: 0x7 (7), after saving flash for eeprom emulation - 0x4

fuse:
	${EDBG} -b -c 48000 -t atmel_cm0p -F w,6:4,0x04

bootloader:
	openocd -f ${ICECFG} -c "telnet_port disabled; init; halt; at91samd bootloader 0; program {{${BOOTLOADER}}} verify reset; shutdown"

build:
	${ARDUINO_PATH}/arduino --pref build.path=${BUILD_PATH} --preserve-temp-files --verify --board dygma:samd:raise_native ${FIRMWARE} 

flash:
	${ARDUINO_PATH}/arduino --pref build.path=${BUILD_PATH} --preserve-temp-files --upload --board dygma:samd:raise_native ${FIRMWARE} --port ${DEVICE_PORT}

flash-ice:
	openocd -f ${ICECFG} -c "telnet_port disabled; init; halt; at91samd bootloader 0; program {{${BUILD_PATH}/${FIRMWARE}.hex}} verify reset; shutdown"

debug:
	openocd -f ${ICECFG}

gdb:
	arm-none-eabi-gdb ${BUILD_PATH}/${FIRMWARE}.elf

clean:
	rm -rf ${BUILD_PATH}/*
