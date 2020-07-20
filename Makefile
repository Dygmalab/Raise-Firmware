DEVICE_PORT =/dev/ttyACM0
BUILD_PATH=./output
FIRMWARE=Raise-Firmware.ino

ARDUINO_PATH=
ifdef ARDUINO_PATH
ARDUINO=${ARDUINO_PATH}/arduino
else
ARDUINO=arduino
endif

BOARD_HARDWARE_PATH=${HOME}/Arduino/hardware/dygma/samd
FOCUS_TOOL=${BOARD_HARDWARE_PATH}/libraries/Kaleidoscope/bin/focus-test
BOSSAC=${HOME}/.arduino15/packages/arduino/tools/bossac/1.7.0*/bossac

BACKUP_FILE=eeprom.dump

all: build

FIRMWARE_SHA="$(shell git describe --tags --always --dirty)"
KALEIDOSCOPE_SHA="$(shell cd ${BOARD_HARDWARE_PATH}/libraries/Kaleidoscope && git rev-parse --short HEAD)"

build:
	${ARDUINO} --pref build.path=${BUILD_PATH} --pref build.version_flags="-DFIRMWARE_SHA=\"${FIRMWARE_SHA}\" -DKALEIDOSCOPE_SHA=\"${KALEIDOSCOPE_SHA}\" -DBAZECOR_VERSION=\"${BAZECOR_VERSION}\"" --preserve-temp-files --verbose --verify --board dygma:samd:raise_native ${FIRMWARE}

flash: backup prompt do_flash restore

backup:
	@DEVICE=${DEVICE_PORT} ${FOCUS_TOOL} eeprom.contents >${BACKUP_FILE}

prompt:
	@echo "Please double-press the reset button on the Neuron, then press ENTER"
	@read a

do_flash:
	${BOSSAC} -i -d --port=${DEVICE_PORT} -e -w ${BUILD_PATH}/${FIRMWARE}.bin -R
	sleep 3

restore:
	@DEVICE=${DEVICE_PORT} ${FOCUS_TOOL} "eeprom.contents $(shell cat ${BACKUP_FILE})"
	@rm -f ${BACKUP_FILE}

size:
	arm-none-eabi-size ${BUILD_PATH}/${FIRMWARE}.elf

clean:
	rm -rf "${BUILD_PATH}"

.PHONY: build clean flash backup prompt do_flash restore size
