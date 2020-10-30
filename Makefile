# OS specific definitions for windows tools
ifeq ($(OS),Windows_NT)
RM = rmdir /S /Q
CP = copy /Y
ifdef ComSpec
SHELL := $(ComSpec)
endif
ifdef COMSPEC
SHELL := $(COMSPEC)
endif
else
RM = rm -rf
CP = cp -f
endif

# Makefile Operative System detection for multi-OS compilation and path adjustment
ifeq ($(OS),Windows_NT)
    PLATFORM = WIN
    ARDUINO_PATH="C:\Program Files (x86)\Arduino"
	ARDUINO=${ARDUINO_PATH}\arduino
else
    UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S),Linux)
        PLATFORM = LINUX
        ARDUINO_PATH=
		ARDUINO=${ARDUINO_PATH}/arduino
    endif
    ifeq ($(UNAME_S),Darwin)
        PLATFORM = DARWIN
        ARDUINO_PATH=/Applications/Arduino.app/Contents/Resources/Java
		ARDUINO=${ARDUINO_PATH}/arduino
    endif
endif

# Arduino path configuration
ifndef ARDUINO_PATH
    ARDUINO=arduino
endif

#device configuration (WIN uses COM ports, MAC&LIN \dev\tty, MAC additionaly uses \dev\cu)
ifeq ($(PLATFORM),WIN)
    DEVICE_PORT =COM4
    BACKUP_PORT =COM4
endif
ifeq ($(PLATFORM),LINUX)
    DEVICE_PORT =/dev/ttyACM0
    BACKUP_PORT =/dev/ttyACM0
endif
ifeq ($(PLATFORM),DARWIN)
    DEVICE_PORT =/dev/ttyACM0
    BACKUP_PORT =/dev/coACM0
endif

# Library & build target configuration
ifeq ($(PLATFORM),WIN)
    BOARD_HARDWARE_PATH=${HOME}\Arduino\hardware\dygma\samd
    FOCUS_TOOL=${BOARD_HARDWARE_PATH}\libraries\Kaleidoscope\bin\focus-test
    BOSSAC=${HOME}\.arduino15\packages\arduino\tools\bossac\1.7.0*\bossac
	BUILD_PATH= .\output
    FIRMWARE_SHA="$(shell git describe --tags --always --dirty)"
    KALEIDOSCOPE_SHA="$(shell cd ${BOARD_HARDWARE_PATH}\libraries\Kaleidoscope && git rev-parse --short HEAD)"
else
    BOARD_HARDWARE_PATH=${HOME}/Arduino/hardware/dygma/samd
    FOCUS_TOOL=${BOARD_HARDWARE_PATH}/libraries/Kaleidoscope/bin/focus-test
    BOSSAC=${HOME}/.arduino15/packages/arduino/tools/bossac/1.7.0*/bossac
    BUILD_PATH=./output
    FIRMWARE_SHA="$(shell git describe --tags --always --dirty)"
    KALEIDOSCOPE_SHA="$(shell cd ${BOARD_HARDWARE_PATH}/libraries/Kaleidoscope && git rev-parse --short HEAD)"
endif

FIRMWARE=Raise-Firmware.ino
BACKUP_FILE=eeprom.dump

all: build

print_config:
	# TODO: Print all config
	@echo ${PLATFORM}
	@echo ${ARDUINO}
	@echo ${DEVICE_PORT}
	@echo ${BACKUP_PORT}

build:
	${ARDUINO} --pref build.path=${BUILD_PATH} --pref build.version_flags="-DFIRMWARE_SHA=\"${FIRMWARE_SHA}\" -DKALEIDOSCOPE_SHA=\"${KALEIDOSCOPE_SHA}\" -DBAZECOR_VERSION=\"${BAZECOR_VERSION}\"" --preserve-temp-files --verbose --verify --board dygma:samd:raise_native ${FIRMWARE}

flash: backup prompt do_flash restore

backup:
	${FOCUS_TOOL}
	@DEVICE=${DEVICE_PORT} ${FOCUS_TOOL} eeprom.contents >${BACKUP_FILE}

prompt:
	@echo "Please double-press the reset button on the Neuron, then press ENTER"
	@read a

do_flash:
	${BOSSAC} -i -d --port=${DEVICE_PORT} -e -w ${BUILD_PATH}/${FIRMWARE}.bin -R
	sleep 3

restore:
	@DEVICE=${DEVICE_PORT} ${FOCUS_TOOL} "eeprom.contents $(shell cat ${BACKUP_FILE})"
	-$(RM) ${BACKUP_FILE}

size:
	arm-none-eabi-size ${BUILD_PATH}/${FIRMWARE}.elf

clean:
	-$(RM) ${BUILD_PATH}
.PHONY: build clean flash backup prompt do_flash restore size
