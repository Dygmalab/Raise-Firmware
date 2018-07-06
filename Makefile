DEVICE_PORT=/dev/ttyACM0
ARDUINO_PATH=~/work/shortcut/arm/arduino-1.8.2
EDBG=~/work/shortcut/arm/edbg/edbg
DYGMADIR=/home/matt/Arduino/hardware/dygma/samd
BACKUP=${DYGMADIR}/libraries/Kaleidoscope-Focus/extras/backup.py
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

read-all-fuse:
	${EDBG} -b -c 48000 -t atmel_cm0p -F r,31:0
	${EDBG} -b -c 48000 -t atmel_cm0p -F r,63:32

reset-all-fuse:
	${EDBG} -b -c 48000 -t atmel_cm0p -F w,31:0,0xD8E0C7FF
	${EDBG} -b -c 48000 -t atmel_cm0p -F w,63:32,0xFFFFFC5D

fuse:
	${EDBG} -b -c 48000 -t atmel_cm0p -F w,6:4,0x04

fuse-openocd:
	at91samd nvmuserrow 0xFFFFFC5DD8E0C7FF

bootloader:
	openocd -f ${ICECFG} -c "telnet_port disabled; init; halt; at91samd bootloader 0; program {{${BOOTLOADER}}} verify reset; shutdown"

build:
	${ARDUINO_PATH}/arduino  --pref build.path=${BUILD_PATH} --preserve-temp-files --verbose --verify --board dygma:samd:raise_native ${FIRMWARE} 


flash: 
	/home/matt/.arduino15/packages/arduino/tools/bossac/1.7.0/bossac -i -d --port=${DEVICE_PORT} -e -w ${BUILD_PATH}/${FIRMWARE}.bin -R
	# wait for device to settle
#	sleep 10
#	${BACKUP} --restore --port ${DEVICE_PORT}

flash-ice:
	openocd -f ${ICECFG} -c "telnet_port disabled; init; halt; at91samd bootloader 0; program {{${BUILD_PATH}/${FIRMWARE}.hex}} verify reset; shutdown"

backup:
	${BACKUP} --backup --port ${DEVICE_PORT}

restore:
	${BACKUP} --restore --port ${DEVICE_PORT}

size:
	arm-none-eabi-size ${BUILD_PATH}/${FIRMWARE}.elf


debug:
	openocd -f ${ICECFG}

gdb:
	arm-none-eabi-gdb ${BUILD_PATH}/${FIRMWARE}.elf

clean:
	rm -rf ${BUILD_PATH}/*

.PHONY: clean
