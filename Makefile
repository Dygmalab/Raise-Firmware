DEVICE_PORT=/dev/ttyACM0
ARDUINO_PATH=~/arduino-1.8.8
DYGMADIR=/home/matt/Arduino/hardware/dygma/samd
BACKUP=${DYGMADIR}/libraries/Kaleidoscope-Focus/extras/backup.py
FOCUS=${DYGMADIR}/libraries/Kaleidoscope-Focus/extras/kaleidoscope-focus.py
BOOTLOADER=${DYGMADIR}/bootloaders/zero/samd21_sam_ba.bin
ICECFG=${DYGMADIR}/variants/arduino_zero/openocd_scripts/arduino_zero.cfg
LAST_PROG=$(shell \ls /tmp/arduino_*/*.ino.hex --sort=time  | head -1)
BUILD_PATH=./output
FIRMWARE=Raise-Firmware.ino

# arduino command line arguments
# https://github.com/arduino/Arduino/blob/master/build/shared/manpage.adoc

fuse-openocd:
	openocd -f ${ICECFG} -c "telnet_port disabled; init; halt; at91samd nvmuserrow; at91samd nvmuserrow 0xFFFFFC5DD8E0C7FF; shutdown"

bootloader:
	openocd -f ${ICECFG} -c "telnet_port disabled; init; halt; at91samd bootloader 0; program {{${BOOTLOADER}}} verify reset; shutdown"

build:
	#${ARDUINO_PATH}/arduino  --pref build.path=${BUILD_PATH} --preserve-temp-files --verbose --verify --board dygma:samd:raise_native ${FIRMWARE} 
	${ARDUINO_PATH}/arduino  --pref build.path=${BUILD_PATH} --preserve-temp-files --verbose --verify --board keyboardio:samd:raise_native ${FIRMWARE}

flash: 
	echo "hold esc or delete on Raise"
#	python ./reset.py ${DEVICE_PORT}
	/home/matt/.arduino15/packages/arduino/tools/bossac/1.7.0/bossac -i -d --port=${DEVICE_PORT} -e -w ${BUILD_PATH}/${FIRMWARE}.bin -R
	# wait for device to settle

flash-ice:
	openocd -f ${ICECFG} -c "telnet_port disabled; init; halt; at91samd bootloader 0; program {{${BUILD_PATH}/${FIRMWARE}.hex}} verify reset; shutdown"

focus:
	${FOCUS} --port ${DEVICE_PORT}

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
