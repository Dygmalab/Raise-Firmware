// -*- mode: c++ -*-
// Copyright 2019 DygmaLab, SE. <matt@dygma.com>
// See "LICENSE" for license details

#ifndef BUILD_INFORMATION
#define BUILD_INFORMATION "locally built"
#endif

//#define CHRYSALIS_EEPROM_VERSION 0xa1

/**
 * These #include directives pull in the Kaleidoscope firmware core,
 * as well as the Kaleidoscope plugins we use in the Raise's firmware
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
#include "Kaleidoscope-Colormap.h"
#include "Kaleidoscope-LED-Palette-Theme.h"
#include "Kaleidoscope-LEDEffect-SolidColor.h"
#include "Kaleidoscope-LEDEffect-Rainbow.h"
#include "Kaleidoscope-LEDEffect-Joint.h"
#include "Kaleidoscope-LED-Stalker.h"
#include "Kaleidoscope-IdleLEDs.h"
#include "Raise-Focus.h"
//#include "Kaleidoscope-AdjustableLatencyJitter.h"


/** This 'enum' is a list of all the macros used by the Raise's firmware
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
     };


/** The Raise's key layouts are defined as 'keymaps'. By default, there are three
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

KEYMAPS(
[QWERTY] = KEYMAP_60 
( Key_Escape, Key_1, Key_2, Key_3, Key_4, Key_5, Key_6,                     Key_7, Key_8, Key_9, Key_0, Key_Minus, Key_Equals, Key_Backspace, 
  Key_Tab, Key_Q, Key_W, Key_E, Key_R, Key_T,                               Key_Y, Key_U, Key_I, Key_O, Key_P, Key_LeftBracket, Key_RightBracket, Key_Enter, 
  Key_CapsLock, Key_A , Key_S, Key_D, Key_F, Key_G,                            Key_H, Key_J, Key_K, Key_L, Key_Semicolon, Key_Quote, Key_Backslash, 
  Key_LeftShift, Key_Backslash, Key_Z, Key_X, Key_C, Key_V, Key_B,                    Key_N, Key_M, Key_Comma, Key_Period, Key_Slash, Key_RightShift,
  Key_LeftControl,Key_LEDEffectNext, Key_LeftAlt,Key_Enter, Key_Spacebar,   Key_Spacebar, Key_RightShift, Key_RightAlt, Key_Keymap1_Momentary, Key_LEDEffectNext, Key_RightControl,
                     Key_Backspace, Key_Delete,                             Key_LeftArrow, Key_RightArrow),

[NUMPAD] = KEYMAP_60 
( Key_Escape, Key_1, Key_2, Key_3, Key_4, Key_5, Key_6,                     Key_7, Key_8, Key_9, Key_Equals, XXX, XXX, ___, 
  Key_Tab, Key_7, Key_8, Key_9, Key_0, Key_Period,                          Key_4, Key_5, Key_6, Key_KeypadAdd, Key_KeypadMultiply, XXX, XXX, ___, 
  Key_Enter, ___, Key_S, Key_V, Key_UpArrow, Key_Comma,                   Key_1, Key_2, Key_3, Key_KeypadSubtract, Key_KeypadDivide, XXX, ___, 
  Key_LeftShift, ___, Key_Z, Key_X, Key_LeftArrow, Key_DownArrow, Key_RightArrow,                    Key_0, XXX, XXX, XXX, Key_UpArrow, Key_RightShift, 
  ___, ___, ___, ___, ___,                                                  XXX, XXX, Key_LeftArrow, Key_DownArrow, Key_RightArrow, ___,  
                       ___, M(MACRO_VERSION_INFO),                                            Key_Period, Key_Comma)
);



/* Re-enable astyle's indent enforcement */
// *INDENT-ON*

/** versionInfoMacro handles the 'firmware version info' macro
 *  When a key bound to the macro is pressed, this macro
 *  prints out the firmware build information as virtual keystrokes
 */

static void versionInfoMacro(uint8_t keyState) {
  if (keyToggledOn(keyState)) {
    Macros.type(PSTR("Dygma Raise - Kaleidoscope "));
    Macros.type(PSTR(BUILD_INFORMATION));
  }
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
  }
  return MACRO_NONE;
}

static kaleidoscope::plugin::LEDSolidColor solidRed(255, 0, 0);
static kaleidoscope::plugin::LEDSolidColor solidBluez(0, 0, 255); // calling it solidBlue prevents the keyboard from even starting!
static kaleidoscope::plugin::LEDSolidColor solidGreen(0, 255, 0);
static kaleidoscope::plugin::LEDSolidColor solidWhite(255, 255, 255);

/** The 'setup' function is one of the two standard Arduino sketch functions.
  * It's called when your keyboard first powers up. This is where you set up
  * Kaleidoscope and any plugins.
  */

KALEIDOSCOPE_INIT_PLUGINS(
  Macros,
  EEPROMSettings,
  EEPROMKeymap,
  FocusSettingsCommand,
  FocusEEPROMCommand,
  LEDControl,
  FocusLEDCommand,
  LEDPaletteTheme,
  solidBluez, solidGreen, solidRed, solidWhite, LEDRainbowEffect, LEDRainbowWaveEffect, LEDJointEffect, StalkerEffect, ColormapEffect,
  IdleLEDs,
  RaiseFocus,
  Focus
  );

void setup() {
  // First, call Kaleidoscope's internal setup function
  SerialUSB.begin(9600);
  Kaleidoscope.setup();

  // Reserve space in the keyboard's EEPROM for the keymaps
  EEPROMKeymap.setup(3);

  // Reserve space for the number of Colormap layers we will use
  ColormapEffect.max_layers(3);
  LEDRainbowEffect.brightness(255);
  LEDRainbowWaveEffect.brightness(255);
  StalkerEffect.variant = STALKER(BlazingTrail);

  IdleLEDs.idle_time_limit = 600; // 10 minutes

//  LEDRainbowEffect.activate();

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
