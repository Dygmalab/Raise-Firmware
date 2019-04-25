// -*- mode: c++ -*-
// Copyright 2016 Keyboardio, inc. <jesse@keyboard.io>
// See "LICENSE" for license details

#ifndef BUILD_INFORMATION
#define BUILD_INFORMATION "locally built"
#endif

//#define CHRYSALIS_EEPROM_VERSION 0xa1

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

// Support for setting the key layout and LEDs over the Serial port
// This is what allows Chrysalis to work
#include "Kaleidoscope-FocusSerial.h"
#include "Kaleidoscope-EEPROM-Settings.h"
#include "Kaleidoscope-EEPROM-Keymap.h"
//#include "Kaleidoscope-Colormap.h"
//#include "Kaleidoscope-LED-Palette-Theme.h"
//#include "Kaleidoscope-AdjustableLatencyJitter.h"


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



/** The 'setup' function is one of the two standard Arduino sketch functions.
  * It's called when your keyboard first powers up. This is where you set up
  * Kaleidoscope and any plugins.
  */

KALEIDOSCOPE_INIT_PLUGINS(
    LEDControl,
    LEDOff,
    Macros,
    EEPROMSettings,
    EEPROMKeymap,
    //AdjustableLatencyJitter,
    Focus
  );
void setup() {
  // First, call Kaleidoscope's internal setup function
  Serial.begin(9600);
  Kaleidoscope.setup();

  // Reserve space in the keyboard's EEPROM for the keymaps
  EEPROMKeymap.max_layers(5);

  // Reserve space for the number of Colormap layers we will use
//  ColormapEffect.max_layers(3);

  // If you want to add more plugins using EEPROM, add their config steps here

#if 0
  // Tell the keyboard to listen for Focus events that Chrysalis will send
  Focus.addHook(FOCUS_HOOK_HELP);
  Focus.addHook(FOCUS_HOOK_VERSION);
  Focus.addHook(FOCUS_HOOK_KEYMAP);
  Focus.addHook(FOCUS_HOOK_KEYMAP_LAYER);
  Focus.addHook(FOCUS_HOOK_EEPROM);
  Focus.addHook(FOCUS_HOOK_SETTINGS);
  Focus.addHook(FOCUS_HOOK_HARDWARE);

  Focus.addHook(FOCUS_HOOK_ADJUSTABLELATENCYJITTER);
//  Focus.addHook(FOCUS_HOOK_LEDPALETTETHEME);
//  Focus.addHook(FOCUS_HOOK_COLORMAP);
//  Focus.addHook(FOCUS_HOOK_COLORMAP_LAYER);

#endif

/*
  // If the settings have changed, re-transfer the keymap to EEPROM
  if (EEPROMSettings.version() != CHRYSALIS_EEPROM_VERSION) {
    EEPROMKeymap.focusKeymapTransfer("keymap.transfer");
    EEPROMSettings.version(CHRYSALIS_EEPROM_VERSION);
  }
  */
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
