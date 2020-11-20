
MakeFile
========
The MakeFile has been upgraded to function properly in the three main O.S. (Windows, Mac, Linux) in this MD you will find documentation pertaining the use, configuration and options of it.

## Configuring the makefile
Use the config option of the makefile to show the current routes and device identifier / COM port of your raise, you will have to alter this configurations in the makefile so that it points to the desired devices / folders / tool paths / etc...

### Path configuration
Change the following configuration to suit your needs in the makefile
```MakeFile
# Makefile Operative System detection for multi-OS compilation and path adjustment
ARDUINO_PATH=%ProgramFiles(x86)%\Arduino # Default path for Win, change it in your O.S. section
ARDUINO=${ARDUINO_PATH}\arduino # Actual executable file to be launched

# Arduino path configuration
ifndef ARDUINO_PATH
    ARDUINO=arduino # if you set up arduino in the environment (default for Linux) just remove the ARDUINO_PATH Path.
endif
```
### Device configuration
Change the following configuration to suit your needs in the makefile
```MakeFile
#device configuration (WIN uses COM ports, MAC&LIN \dev\tty, MAC additionaly uses \dev\cu)
DEVICE_PORT =COM4 # Set here your device address, change it in your O.S. section
BACKUP_PORT =COM4 # Put here the same information unless you are in MAC, then use the cu file
```
### Library & build target configuration
```MakeFile
# Library & build target configuration Make the changes in your O.S. section
    BOARD_HARDWARE_PATH=%USERPROFILE%\documents\Arduino\hardware\dygma\samd # Path to the Arduino libraries
    FOCUS_TOOL=${BOARD_HARDWARE_PATH}\libraries\Kaleidoscope\bin\focus-test # Specific Path to the Focus Tool
    BOSSAC=%LOCALAPPDATA%\Arduino15\packages\arduino\tools\bossac\1.7.0-arduino3\bossac.exe # Bossac
	BUILD_PATH= .\output # Location to save the compilation output
    FIRMWARE=\Raise-Firmware.ino # Firmware .ino file to be compiled
    FIRMWARE_SHA="$(shell git describe --tags --always --dirty)" # Latest commit to the Firmware repo as SHA
    KALEIDOSCOPE_SHA="$(shell cd ${BOARD_HARDWARE_PATH}\libraries\Kaleidoscope && git rev-parse --short HEAD)" # Latest commit to the Kaleidoscope library repo as SHA
```

### User configuration
```MakeFile
# User configurations
BACKUP_FILE=eeprom.dump
BAZECOR_VERSION=v0.2.5
```

## Options available
- **help**
  > A general help text to aid on the use of the MakeFile, shows the same as this section.
- **config** 
  > View your detected O.S., current configuration, Paths, etc.. so that you can review for needed changes.
- **build**
  > Launches the build process using the BUILD_PATH as target, the ARDUINO_PATH as tool and FIRMWARE_SHA, KALEIDOSCOPE_SHA & BAZECOR_VERSION as flags for the custom compiled firmware.
- **flash**
  > This commands launches the backup, prompt, do_flash and restore commands consecutively to automate the flash process (only Unix).
- **win_flash** 
  > Launches win_prompt and do_flash removing the backup/restore process due to not being yet compatible with Windows O.S.
- **backup** 
  > Uses the FOCUS_TOOL to back up the current Raise layer configuration.
- **prompt** 
  > Asks the user to put the Raise keyboard in bootloader mode.
- **win_prompt** 
  > Same as prompt but adding another message for Windows users.
- **do_flash** 
  > The actual flashing process using Bossac.
- **restore** 
  > Restores the previous configuration using the BACKUP_FILE.
- **size** 
  > Command not yet functional, arm-none-eabi-size not working cross-O.S.
- **clean** 
  > Deletes the current BUILD_PATH directory.
- **backup**
  > Uses the FOCUS_TOOL to back up the current Raise layer configuration.

  ## Usage Example
  Following the configuration and options listing, find this examples of the common usage of the makefile for each O.S.
  ### Windows
  ```PowerShell
  make
  make win_flash
  ```
  ### Linux & Mac
  ```sh
  make
  make flash
  ```
  ### Step by Step, all OS
  ```sh
  # Make a layer backup with bazecor before beginning
  make clean
  make
  # Now put you Raise in flashing mode by disconnecting the neuron from the PC, pressing ESC physical key
  # and then reconnecting the keyboard to the PC without releasing ESC, lastly wait for a blue led effect 
  # to appear in the Neuron
  make do_flash
  # Disconnect the keyboard and pluig it again (just to be safe, should not be necessary) and restore your
  # Layers using bazecor.
  ```