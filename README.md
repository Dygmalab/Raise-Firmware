# Dygma Raise Firmware

[![Build Status](https://api.travis-ci.org/Dygmalab/Raise-Firmware.svg?branch=master)](https://travis-ci.org/Dygmalab/Raise-Firmware)

The default firmware for the Dygma Raise.

# Download and install

## Set up the Arduino IDE

Setup the Arduino IDE on your system. Make sure you install at least version 1.8.10, since older version may not support all required features.

### macOS

On macOS, install the Arduino IDE using [homebrew](http://brew.sh/) [cask](https://caskroom.github.io/) with `brew cask install arduino` or download the application from [the official website](https://www.arduino.cc/en/Main/Software) and move it to your `/Applications` folder.

### Linux

On Linux, your distribution's package manager probably includes the Arduino IDE, but it may be an out of date version. If your distribution installs a version of Arduino before 1.8.10 or so, you'll need to install the Arduino IDE following the instructions [on the wiki](https://github.com/keyboardio/Kaleidoscope/wiki/Arduino-Setup-Linux).

If you install Arduino into some place that's /not/ `/usr/local/arduino`, you'll need to set the `$ARDUINO_PATH` environment variable to the directory containing the `arduino` and `arduino-builder` binaries.

## Create and navigate to the Arduino Sketchbook directory

### MacOS
```sh
mkdir -p $HOME/Documents/Arduino
cd $HOME/Documents/Arduino
```

### Linux

```sh
mkdir -p $HOME/Arduino
cd $HOME/Arduino
```

## Download hardware platform, including library source code

```sh
arduino --install-boards arduino:samd

mkdir -p hardware/dygma

## then clone the hardware definitions to make them available to the arduino environment
git clone --recursive https://github.com/Dygmalab/Kaleidoscope-Bundle-Dygma.git hardware/dygma/samd
````

Remember to keep updated the Kaleidoscope Bundle by running the following GIT commands in the samd folder before compiling each new version, not all the changes will be made in the Raise-FW repo.

To do so, just run:

```sh
git pull
git submodule sync
git submodule update
```

## Download the Raise Firmware

```sh
git clone https://github.com/Dygmalab/Raise-Firmware.git
```

# Build and flash the firmware

Before you begin, make sure your Raise is connected to your computer.

## Option 1: From the command line
### The MakeFile
The updated makefile now supports Windows, Mac & Linux

#### Previous steps for Windows
First install dependencies with [chocolately](https://chocolatey.org/install) using:
```powershell
choco install make
```
#### Configure the MakeFile
```sh
make config
```
Will show the current configuration of the makefile.

Modify it to fit your current environment.

#### Run the make file
```sh
cd Raise-Firmware
make flash
```
## Option 2: From the Arduino IDE

Open the sketch you wish to flash (for example, `Raise-Firmware.ino`).

Click the Upload button or press `Ctrl-U`.

Hold down the key in the top left corner of your keyboard (`Esc` by default), until the compile finishes and the upload begins.

# Additional information
[Focus API KeyMap](https://github.com/Dygmalab/Raise-Firmware/blob/master/FOCUS_API.MD)

[MakeFile documentation](https://github.com/Dygmalab/Raise-Firmware/blob/master/MAKEFILE.MD)