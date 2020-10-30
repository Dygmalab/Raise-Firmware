# OS specific definitions for windows tools
ifeq ($(OS),Windows_NT)
RM = rmdir /S /Q
CP = copy /Y
PS = pause
ifdef ComSpec
SHELL := $(ComSpec)
endif
ifdef COMSPEC
SHELL := $(COMSPEC)
endif
else
RM = rm -rf
CP = cp -f
PS = read a
endif

# Makefile Operative System detection for multi-OS compilation and path adjustment
ifeq ($(OS),Windows_NT)
    PLATFORM = WIN
    ARDUINO_PATH=%ProgramFiles(x86)%\Arduino
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
        ARDUINO_PATH=/Applications/Arduino.app/Contents/MacOS
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
    DEVICE_PORT =/dev/tty.usbmodem14201
    BACKUP_PORT =/dev/cu.usbmodem14201
endif

# Library & build target configuration
ifeq ($(PLATFORM),WIN)
    BOARD_HARDWARE_PATH=%USERPROFILE%\documents\Arduino\hardware\dygma\samd
    FOCUS_TOOL=${BOARD_HARDWARE_PATH}\libraries\Kaleidoscope\bin\focus-test
    BOSSAC=%LOCALAPPDATA%\Arduino15\packages\arduino\tools\bossac\1.7.0-arduino3\bossac.exe
	BUILD_PATH= .\output
    FIRMWARE=\Raise-Firmware.ino
    FIRMWARE_SHA="$(shell git describe --tags --always --dirty)"
    KALEIDOSCOPE_SHA="$(shell cd ${BOARD_HARDWARE_PATH}\libraries\Kaleidoscope && git rev-parse --short HEAD)"
endif
ifeq ($(PLATFORM),LINUX)
    BOARD_HARDWARE_PATH=${HOME}/Arduino/hardware/dygma/samd
    FOCUS_TOOL=${BOARD_HARDWARE_PATH}/libraries/Kaleidoscope/bin/focus-test
    BOSSAC=${HOME}/.arduino15/packages/arduino/tools/bossac/1.7.0*/bossac
    BUILD_PATH=./output
    FIRMWARE=/Raise-Firmware.ino
    FIRMWARE_SHA="$(shell git describe --tags --always --dirty)"
    KALEIDOSCOPE_SHA="$(shell cd ${BOARD_HARDWARE_PATH}/libraries/Kaleidoscope && git rev-parse --short HEAD)"
endif
ifeq ($(PLATFORM),DARWIN)
    BOARD_HARDWARE_PATH=${HOME}/Documents/Arduino/hardware/dygma/samd
    FOCUS_TOOL=${BOARD_HARDWARE_PATH}/libraries/Kaleidoscope/bin/focus-test
    BOSSAC=${HOME}/Library/Arduino15/packages/arduino/tools/bossac/1.7.0-arduino3/bossac
    BUILD_PATH=./output
    FIRMWARE=/Raise-Firmware.ino
    FIRMWARE_SHA="$(shell git describe --tags --always --dirty)"
    KALEIDOSCOPE_SHA="$(shell cd ${BOARD_HARDWARE_PATH}/libraries/Kaleidoscope && git rev-parse --short HEAD)"
endif

# User configurations
BACKUP_FILE=eeprom.dump
BAZECOR_VERSION=CustomFW

# Build Commands
all: build

help:
	@echo.
	@echo Help for Dygma's Raise Firmware's Makefile [Made By NeoDygma]
	@echo.
	@echo This Makefile is O.S. agnostic, working for Windows and Unix based O.S. "Linux & MacOS"
	@echo It uses GNU Makefile, Arduino command line tools and extra scripts to build, flash and
	@echo backup/restore Dygma's Raise Keyboard.
	@echo.
	@echo The supported commands are:
	@echo.
	@echo config           :  View your detected O.S., current configuration, Paths, etc.. so
	@echo                     that you can review for needed changes.
	@echo build            :  Launches the build process using the BUILD_PATH as target, the
	@echo                     ARDUINO_PATH as tool and FIRMWARE_SHA, KALEIDOSCOPE_SHA &
	@echo                     BAZECOR_VERSION as flags for the custom compiled firmware.
	@echo flash            :  This commands launches the backup, prompt, do_flash and restore
	@echo                     commands consecutively to automate the flash process (only Unix).
	@echo win_flash        :  Launches win_prompt and do_flash removing the backup/restore
	@echo                     process due to not being yet compatible with Windows O.S.
	@echo backup           :  Uses the FOCUS_TOOL to back up the current Raise layer configuration.
	@echo prompt           :  Asks the user to put the Raise keyboard in bootloader mode.
	@echo win_prompt       :  Same as prompt but adding another message for Windows users.
	@echo do_flash         :  The actual flashing process using Bossac.
	@echo restore          :  Restores the previous configuration using the BACKUP_FILE.
	@echo size             :  Command not yet functional, arm-none-eabi-size not working cross-O.S.
	@echo clean            :  Deletes the current BUILD_PATH directory.
	@echo backup           :  Uses the FOCUS_TOOL to back up the current Raise layer configuration.
	@echo.
	@echo Have a great Hacking time!, -=(Dygma)=-.
	@echo.

config:
	@echo.
	@echo Current Makefile Configuration
	@echo.
	@echo Platform         :  ${PLATFORM}
	@echo Bossac Path      :  ${BOSSAC}
	@echo Arduino Path     :  ${ARDUINO}
	@echo Build Path       :  ${BUILD_PATH}
	@echo Device Port      :  ${DEVICE_PORT}
	@echo Backup Port      :  ${BACKUP_PORT}
	@echo Focus-tool Path  :  ${FOCUS_TOOL}
	@echo Firmware SHA     :  ${FIRMWARE_SHA}
	@echo Kaleidoscope SHA :  ${KALEIDOSCOPE_SHA}
	@echo Firmware Name    :  ${BAZECOR_VERSION}
	@echo.

build:
	${ARDUINO} --pref build.path=${BUILD_PATH} --pref build.version_flags="-DFIRMWARE_SHA=\"${FIRMWARE_SHA}\" -DKALEIDOSCOPE_SHA=\"${KALEIDOSCOPE_SHA}\" -DBAZECOR_VERSION=\"${BAZECOR_VERSION}\"" --preserve-temp-files --verbose --verify --board dygma:samd:raise_native ${FIRMWARE}

flash: backup prompt do_flash restore

win_flash: win_prompt do_flash

backup:
	@DEVICE=${DEVICE_PORT} ${FOCUS_TOOL} eeprom.contents >${BACKUP_FILE}

prompt:
	@echo "Please double-press the reset button on the Neuron, then press ENTER"
	-$(PS)

win_prompt:
	@echo "First save your current layers with Bazecor using the export tool, the current backup/restore tools don't work properly on Windows"
	@echo "Please double-press the reset button on the Neuron to enter Bootloader mode, then press ENTER"
	-$(PS)

do_flash:
	${BOSSAC} -i -d --port=${DEVICE_PORT} -e -w ${BUILD_PATH}${FIRMWARE}.bin -R
	sleep 3

restore:
	@DEVICE=${DEVICE_PORT} ${FOCUS_TOOL} "eeprom.contents $(shell cat ${BACKUP_FILE})"
	-$(RM) ${BACKUP_FILE}

size:
	arm-none-eabi-size ${BUILD_PATH}/${FIRMWARE}.elf

clean:
	-$(RM) ${BUILD_PATH}
.PHONY: build clean flash backup prompt do_flash restore size
