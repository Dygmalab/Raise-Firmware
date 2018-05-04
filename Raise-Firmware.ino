// -*- mode: c++ -*-
// Copyright 2016 Keyboardio, inc. <jesse@keyboard.io>
// See "LICENSE" for license details

#ifndef BUILD_INFORMATION
#define BUILD_INFORMATION "locally built"
#endif

#define CHRYSALIS_EEPROM_VERSION 0xa1

/**
 * These #include directives pull in the Kaleidoscope firmware core,
 * as well as the Kaleidoscope plugins we use in the Model 01's firmware
 */


// The Kaleidoscope core
#include "Kaleidoscope.h"

// Support for keys that move the mouse
//#include "Kaleidoscope-MouseKeys.h"

// Support for macros
#include "Kaleidoscope-Macros.h"

// Support for controlling the keyboard's LEDs
#include "Kaleidoscope-LEDControl.h"

// Support for "Numlock" mode, which is mostly just the Numlock specific LED mode
#include "Kaleidoscope-Numlock.h"

// Support for an "LED off mode"
#include "LED-Off.h"

// Support for the "Boot greeting" effect, which pulses the 'LED' button for 10s
// when the keyboard is connected to a computer (or that computer is powered on)
#include "Kaleidoscope-LEDEffect-BootGreeting.h"

// Support for LED modes that set all LEDs to a single color
#include "Kaleidoscope-LEDEffect-SolidColor.h"

// Support for an LED mode that makes all the LEDs 'breathe'
#include "Kaleidoscope-LEDEffect-Breathe.h"

// Support for an LED mode that makes a red pixel chase a blue pixel across the keyboard
#include "Kaleidoscope-LEDEffect-Chase.h"

// Support for LED modes that pulse the keyboard's LED in a rainbow pattern
#include "Kaleidoscope-LEDEffect-Rainbow.h"

// Support for an LED mode that lights up the keys as you press them
#include "Kaleidoscope-LED-Stalker.h"

// Support for an LED mode that prints the keys you press in letters 4px high
#include "Kaleidoscope-LED-AlphaSquare.h"

// Support for Keyboardio's internal keyboard testing mode
//#include "Kaleidoscope-Model01-TestMode.h"

// Support for setting the key layout and LEDs over the Serial port
// This is what allows Chrysalis to work
#include "Kaleidoscope-Focus.h"
#include "Kaleidoscope-EEPROM-Settings.h"
#include "Kaleidoscope-EEPROM-Keymap.h"
//#include "Kaleidoscope-Colormap.h"
//#include "Kaleidoscope-LED-Palette-Theme.h"


/** This 'enum' is a list of all the macros used by the Model 01's firmware
  * The names aren't particularly important. What is important is that each
  * is unique.
  *
  * These are the names of your macros. They'll be used in two places.
  * The first is in your keymap definitions. There, you'll use the syntax
  * `M(MACRO_NAME)` to mark a specific keymap position as triggering `MACRO_NAME`
  *
  * The second usage is in the 'switch' statement in the `macroAction` function.
  * That switch statement actually runs the code associated with a macro when
  * a macro key is pressed.
  */

enum { MACRO_VERSION_INFO,
       MACRO_ANY
     };



/** The Model 01's key layouts are defined as 'keymaps'. By default, there are three
  * keymaps: The standard QWERTY keymap, the "Function layer" keymap and the "Numpad"
  * keymap.
  *
  * Each keymap is defined as a list using the 'KEYMAP_STACKED' macro, built
  * of first the left hand's layout, followed by the right hand's layout.
  *
  * Keymaps typically consist mostly of `Key_` definitions. There are many, many keys
  * defined as part of the USB HID Keyboard specification. You can find the names
  * (if not yet the explanations) for all the standard `Key_` defintions offered by
  * Kaleidoscope in these files:
  *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/key_defs_keyboard.h
  *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/key_defs_consumerctl.h
  *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/key_defs_sysctl.h
  *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/key_defs_keymaps.h
  *
  * Additional things that should be documented here include
  *   using ___ to let keypresses fall through to the previously active layer
  *   using XXX to mark a keyswitch as 'blocked' on this layer
  *   using ShiftToLayer() and LockLayer() keys to change the active keymap.
  *   the special nature of the PROG key
  *   keeping NUM and FN consistent and accessible on all layers
  *
  *
  * The "keymaps" data structure is a list of the keymaps compiled into the firmware.
  * The order of keymaps in the list is important, as the ShiftToLayer(#) and LockLayer(#)
  * macros switch to key layers based on this list.
  *
  *

  * A key defined as 'ShiftToLayer(FUNCTION)' will switch to FUNCTION while held.
  * Similarly, a key defined as 'LockLayer(NUMPAD)' will switch to NUMPAD when tapped.
  */

/**
  * Layers are "0-indexed" -- That is the first one is layer 0. The second one is layer 1.
  * The third one is layer 2.
  * This 'enum' lets us use names like QWERTY, FUNCTION, and NUMPAD in place of
  * the numbers 0, 1 and 2.
  */

enum { QWERTY, NUMPAD, _LAYER_MAX }; // layers

/* This comment temporarily turns off astyle's indent enforcement
 *   so we can make the keymaps actually resemble the physical key layout better
 */
// *INDENT-OFF*

const Key keymaps[][ROWS][COLS] PROGMEM = {
[QWERTY] = KEYMAP_60 
( Key_Escape, Key_1, Key_2, Key_3, Key_4, Key_5, Key_6,                     Key_LEDEffectNext, Key_8, Key_9, Key_0, Key_Minus, Key_Equals, Key_Delete, 
  Key_Tab, Key_Q, Key_W, Key_E, Key_R, Key_T,                               Key_Y, Key_U, Key_I, Key_O, Key_P, Key_LeftBracket, Key_Backspace, Key_1, 
  Key_CapsLock, Key_LEDEffectNext , Key_S, Key_D, Key_F, Key_G,                           Key_H, Key_J, Key_K, Key_L, Key_Semicolon, Key_Quote, Key_Enter, 
  Key_LeftShift, Key_Z, Key_X, Key_C, Key_V, Key_B,             Key_N, Key_M, Key_Comma, Key_Period, Key_Slash, Key_RightShift,
  Key_LeftControl,Key_LeftGui, Key_LeftAlt,Key_Keymap1, Key_Spacebar,  Key_Spacebar, Key_RightAlt, Key_RightGui, Key_Menu, Key_RightControl, Key_1,
                     Key_LEDEffectNext, Key_Enter,                  Key_A, Key_B),

[NUMPAD] = KEYMAP_60 
( Key_Escape, Key_1, Key_2, Key_3, Key_4, Key_5, Key_6,             Key_7, Key_8, Key_9, Key_0, Key_A, Key_A, Key_Delete, 
  Key_Tab, Key_Q, Key_UpArrow, Key_E, Key_R, Key_T,                       Key_Y, Key_U, Key_I, Key_O, Key_P, Key_M, Key_Backspace, Key_1, 
  Key_LeftControl, Key_LeftArrow, Key_DownArrow, Key_RightArrow, Key_F, Key_G,               Key_H, Key_J, Key_K, Key_L, Key_L, Key_M, Key_Enter, 
  Key_LeftShift, Key_Z, Key_X, Key_C, Key_V, Key_B,          Key_N, Key_M, Key_Semicolon, Key_Comma, Key_Minus, Key_RightShift, 
  Key_LeftControl, Key_CapsLock, ___, Key_Keymap1, Key_Spacebar,    Key_Spacebar, Key_RightAlt, Key_Keymap1, ___, Key_RightControl, Key_1,  
                       Key_Backspace, Key_Enter,            Key_Backspace, Key_Keymap1)
};



/* Re-enable astyle's indent enforcement */
// *INDENT-ON*

/** versionInfoMacro handles the 'firmware version info' macro
 *  When a key bound to the macro is pressed, this macro
 *  prints out the firmware build information as virtual keystrokes
 */

static void versionInfoMacro(uint8_t keyState) {
  if (keyToggledOn(keyState)) {
    Macros.type(PSTR("Keyboardio Model 01 - Kaleidoscope "));
    Macros.type(PSTR(BUILD_INFORMATION));
  }
}

/** anyKeyMacro is used to provide the functionality of the 'Any' key.
 *
 * When the 'any key' macro is toggled on, a random alphanumeric key is
 * selected. While the key is held, the function generates a synthetic
 * keypress event repeating that randomly selected key.
 *
 */

static void anyKeyMacro(uint8_t keyState) {
  static Key lastKey;
  if (keyToggledOn(keyState))
    lastKey.keyCode = Key_A.keyCode + (uint8_t)(millis() % 36);

  if (keyIsPressed(keyState))
    kaleidoscope::hid::pressKey(lastKey);
}


/** macroAction dispatches keymap events that are tied to a macro
    to that macro. It takes two uint8_t parameters.

    The first is the macro being called (the entry in the 'enum' earlier in this file).
    The second is the state of the keyswitch. You can use the keyswitch state to figure out
    if the key has just been toggled on, is currently pressed or if it's just been released.

    The 'switch' statement should have a 'case' for each entry of the macro enum.
    Each 'case' statement should call out to a function to handle the macro in question.

 */

const macro_t *macroAction(uint8_t macroIndex, uint8_t keyState) {
  switch (macroIndex) {

  case MACRO_VERSION_INFO:
    versionInfoMacro(keyState);
    break;

  case MACRO_ANY:
    anyKeyMacro(keyState);
    break;
  }
  return MACRO_NONE;
}



// These 'solid' color effect definitions define a rainbow of
// LED color modes calibrated to draw 500mA or less on the
// Keyboardio Model 01.


static kaleidoscope::LEDSolidColor solidRed(255, 0, 0);
static kaleidoscope::LEDSolidColor solidOrange(140, 70, 0);
static kaleidoscope::LEDSolidColor solidYellow(130, 100, 0);
static kaleidoscope::LEDSolidColor solidGreen(0, 255, 0);
static kaleidoscope::LEDSolidColor solidBlue(0, 70, 130);
static kaleidoscope::LEDSolidColor solidIndigo(0, 0, 170);
static kaleidoscope::LEDSolidColor solidViolet(130, 0, 120);
static kaleidoscope::LEDSolidColor solidWhite(255, 255, 255);

static Key getKey(uint8_t layer, byte row, byte col) {
  if (layer >= _LAYER_MAX) {
    return EEPROMKeymap.getKey(layer, row, col);
  }
  return EEPROMKeymap.getKeyOverride(layer, row, col);
}

/** The 'setup' function is one of the two standard Arduino sketch functions.
  * It's called when your keyboard first powers up. This is where you set up
  * Kaleidoscope and any plugins.
  */

void setup() {
  // First, call Kaleidoscope's internal setup function
  SerialUSB.begin(9600);
  Kaleidoscope.setup();

  // Next, tell Kaleidoscope which plugins you want to use.
  // The order can be important. For example, LED effects are
  // added in the order they're listed here.
  Kaleidoscope.use(
    // The boot greeting effect pulses the LED button for 10 seconds after the keyboard is first connected
    &BootGreetingEffect,

    // The hardware test mode, which can be invoked by tapping Prog, LED and the left Fn button at the same time.
//    &TestMode,

    // LEDControl provides support for other LED modes
    &LEDControl,

    // We start with the LED effect that turns off all the LEDs.
    &LEDOff,

    // The rainbow effect changes the color of all of the keyboard's keys at the same time
    // running through all the colors of the rainbow.
    &LEDRainbowEffect,

    // The rainbow wave effect lights up your keyboard with all the colors of a rainbow
    // and slowly moves the rainbow across your keyboard
    &LEDRainbowWaveEffect,

    // The chase effect follows the adventure of a blue pixel which chases a red pixel across
    // your keyboard. Spoiler: the blue pixel never catches the red pixel
    &LEDChaseEffect,

    // These static effects turn your keyboard's LEDs a variety of colors
    &solidRed, &solidOrange, &solidYellow, &solidGreen, &solidBlue, &solidIndigo, &solidViolet, &solidWhite,

    // The breathe effect slowly pulses all of the LEDs on your keyboard
    &LEDBreatheEffect,

    // The stalker effect lights up the keys you've pressed recently
    &StalkerEffect,

    // The numlock plugin is responsible for lighting up the 'numpad' mode
    // with a custom LED effect

    // The macros plugin adds support for macros
    &Macros,

    // The MouseKeys plugin lets you add keys to your keymap which move the mouse.
//    &MouseKeys,

    // The EEPROM Keymap lets the key layout be read from EEPROM, which is where
    // Chrysalis will write your keymap to
    &EEPROMKeymap,

    // The Colormap LED effect is the effect that you control view Chrysalis
//    &ColormapEffect,

    // The Focus plugin is what allows the keyboard to communicate with Chrysalis and
    // make the above two plugins work
    &Focus
  );

  // Reserve space in the keyboard's EEPROM for the keymaps
  EEPROMKeymap.max_layers(3);

  // Reserve space for the number of Colormap layers we will use
//  ColormapEffect.max_layers(3);

  // If you want to add more plugins using EEPROM, add their config steps here

  // Let the keyboard know we're done with adding EEPROM plugins
  EEPROMSettings.seal();

  // Tell the keyboard to listen for Focus events that Chrysalis will send
  Focus.addHook(FOCUS_HOOK_HELP);
  Focus.addHook(FOCUS_HOOK_VERSION);
  Focus.addHook(FOCUS_HOOK_KEYMAP);
  Focus.addHook(FOCUS_HOOK_KEYMAP_LAYER);
  Focus.addHook(FOCUS_HOOK_EEPROM);
  Focus.addHook(FOCUS_HOOK_SETTINGS);
//  Focus.addHook(FOCUS_HOOK_LEDPALETTETHEME);
//  Focus.addHook(FOCUS_HOOK_COLORMAP);
//  Focus.addHook(FOCUS_HOOK_COLORMAP_LAYER);

/*
  // If the settings have changed, re-transfer the keymap to EEPROM
  if (EEPROMSettings.version() != CHRYSALIS_EEPROM_VERSION) {
    EEPROMKeymap.focusKeymapTransfer("keymap.transfer");
    EEPROMSettings.version(CHRYSALIS_EEPROM_VERSION);
  }
  */

  // Use the EEPROM keymap that Chrysalis modifies
  Layer.getKey = getKey;


  // We set the brightness of the rainbow effects to 150 (on a scale of 0-255)
  // This draws more than 500mA, but looks much nicer than a dimmer effect
  LEDRainbowEffect.brightness(255);
  LEDRainbowWaveEffect.brightness(255);

  // The LED Stalker mode has a few effects. The one we like is
  // called 'BlazingTrail'. For details on other options,
  // see https://github.com/keyboardio/Kaleidoscope-LED-Stalker
  StalkerEffect.variant = STALKER(BlazingTrail);

  // We want to make sure that the firmware starts with LED effects off
  // This avoids over-taxing devices that don't have a lot of power to share
  // with USB devices
  LEDRainbowWaveEffect.activate();
  //LEDOff.activate();
  //StalkerEffect.activate();
}

/** loop is the second of the standard Arduino sketch functions.
  * As you might expect, it runs in a loop, never exiting.
  *
  * For Kaleidoscope-based keyboard firmware, you usually just want to
  * call Kaleidoscope.loop(); and not do anything custom here.
  */

void loop() {
  Kaleidoscope.loop();
}
