// -*- mode: c++ -*-
// Copyright 2016 Keyboardio, inc. <jesse@keyboard.io>
// See "LICENSE" for license details

#define DEBUG_SERIAL false

#ifndef BUILD_INFORMATION
#define BUILD_INFORMATION "locally built"
#endif


#include "Kaleidoscope-MouseKeys.h"
#include "Kaleidoscope-Macros.h"
#include "Kaleidoscope-LEDControl.h"
#include "Kaleidoscope-Numlock.h"
#include "Kaleidoscope.h"

#include "LED-Off.h"
#include "Kaleidoscope-LEDEffect-BootGreeting.h"
#include "Kaleidoscope-LEDEffect-SolidColor.h"
#include "Kaleidoscope-LEDEffect-Breathe.h"
#include "Kaleidoscope-LEDEffect-Chase.h"
#include "Kaleidoscope-LEDEffect-Rainbow.h"
#include "Kaleidoscope-LED-Stalker.h"
#include "Kaleidoscope-LED-AlphaSquare.h"
#include "Kaleidoscope-Model01-TestMode.h"
#include "Kaleidoscope-LEDEffect-DigitalRain.h"
#include "Kaleidoscope-Underglow-LEDEffect-Chase.h"

// Chrysalis support
#include "Kaleidoscope-Focus.h"
#include "Kaleidoscope-EEPROM-Settings.h"
#include "Kaleidoscope-EEPROM-Keymap.h"
#include "Kaleidoscope-Colormap.h"

#define MACRO_VERSION_INFO 1
#define Macro_VersionInfo M(MACRO_VERSION_INFO)
#define MACRO_ANY 2
#define Macro_Any M(MACRO_ANY)
#define NUMPAD_KEYMAP 2

enum { QWERTY, NUMPAD, _LAYER_MAX }; // layers

const Key keymaps[][ROWS][COLS] PROGMEM = {
[NUMPAD] = KEYMAP_60 ( \
  Key_Escape, Key_1, Key_2, Key_3, Key_4, Key_5, Key_6,             Key_7, Key_8, Key_9, Key_0, Key_A, Key_A, Key_Delete, \
  Key_Tab, Key_Q, Key_UpArrow, Key_E, Key_R, Key_T,                       Key_Y, Key_U, Key_I, Key_O, Key_P, Key_M, Key_Backspace, Key_1, \
  Key_LeftControl, Key_LeftArrow, Key_DownArrow, Key_RightArrow, Key_F, Key_G,               Key_H, Key_J, Key_K, Key_L, Key_L, Key_M, Key_Enter, \
  Key_LeftShift, Key_Z, Key_X, Key_C, Key_V, Key_B,          Key_N, Key_M, Key_Semicolon, Key_Comma, Key_Minus, Key_RightShift, \
  Key_LeftControl, Key_CapsLock, ___, Key_Keymap1, Key_Spacebar,    Key_Spacebar, Key_RightAlt, Key_Keymap1, ___, Key_RightControl, Key_1,  \
                       Key_Backspace, Key_Enter,            Key_Backspace, Key_Keymap1),

[QWERTY] = KEYMAP_60 ( \
Key_Escape, Key_1, Key_2, Key_3, Key_4, Key_5, Key_6,                     Key_LEDEffectNext, Key_8, Key_9, Key_0, Key_Minus, Key_Equals, Key_Delete, \
Key_Tab, Key_Q, Key_W, Key_E, Key_R, Key_T,                               Key_Y, Key_U, Key_I, Key_O, Key_P, Key_LeftBracket, Key_Backspace, Key_1, \
Key_CapsLock, Key_LEDEffectNext , Key_S, Key_D, Key_F, Key_G,                           Key_H, Key_J, Key_K, Key_L, Key_Semicolon, Key_Quote, Key_Enter, \
Key_LeftShift, Key_Z, Key_X, Key_C, Key_V, Key_B,             Key_N, Key_M, Key_Comma, Key_Period, Key_Slash, Key_RightShift,\
Key_LeftControl,Key_LeftGui, Key_LeftAlt,Key_Keymap1, Key_Spacebar,  Key_Spacebar, Key_RightAlt, Key_RightGui, Key_Menu, Key_RightControl, Key_1,\
                     Key_LEDEffectNext, Key_Enter,                  Key_A, Key_B)

};

static kaleidoscope::LEDSolidColor solidRed(255, 0, 0);
static kaleidoscope::LEDSolidColor solidOrange(140, 70, 0);
static kaleidoscope::LEDSolidColor solidYellow(130, 100, 0);
static kaleidoscope::LEDSolidColor solidGreen(0, 255, 0);
static kaleidoscope::LEDSolidColor solidBlue(0, 0, 255);
static kaleidoscope::LEDSolidColor solidIndigo(0, 0, 170);
static kaleidoscope::LEDSolidColor solidViolet(130, 0, 120);
static kaleidoscope::LEDSolidColor solidWhite(255, 255, 255);

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


static Key getKey(uint8_t layer, byte row, byte col) {
  if (layer >= _LAYER_MAX) {
    return EEPROMKeymap.getKey(layer, row, col);
  }
  return EEPROMKeymap.getKeyOverride(layer, row, col);
}

void setup() {
  Kaleidoscope.setup(KEYMAP_SIZE);
  BootKeyboard.begin();
  Kaleidoscope.use(
//    &BootGreetingEffect,
//    &TestMode,
    &LEDControl,
    //&LEDOff,
    &LEDRainbowEffect, &LEDRainbowWaveEffect, 
    &LEDChaseEffect,
    &solidRed, &solidOrange, &solidYellow, &solidGreen, &solidBlue, &solidIndigo, &solidViolet, &solidWhite,
    &LEDBreatheEffect,
    //&AlphaSquareEffect,
    &StalkerEffect,
    &LEDDigitalRainEffect,
    //&LEDUnderglowChaseEffect,
    &NumLock,
    &Macros,
    &MouseKeys,
    // The EEPROM Keymap lets the key layout be read from EEPROM, which is where
    // Chrysalis will write your keymap to
    &EEPROMKeymap,

    // The Colormap LED effect is the effect that you control view Chrysalis
    &ColormapEffect,

    // The Focus plugin is what allows the keyboard to communicate with Chrysalis and
    // make the above two plugins work
    &Focus
    );

  EEPROMKeymap.max_layers(5);

// Let the keyboard know we're done with adding EEPROM plugins
  EEPROMSettings.seal();

  // Tell the keyboard to listen for Focus events that Chrysalis will send
  Focus.addHook(FOCUS_HOOK_KEYMAP);
  Focus.addHook(FOCUS_HOOK_KEYMAP_LAYER);
  Focus.addHook(FOCUS_HOOK_LEDPALETTETHEME);
  Focus.addHook(FOCUS_HOOK_COLORMAP);

  // If the settings have changed, re-transfer the keymap to EEPROM
  if (EEPROMSettings.version() != CHRYSALIS_EEPROM_VERSION) {
    EEPROMKeymap.focusKeymapTransfer("keymap.transfer");
    EEPROMSettings.version(CHRYSALIS_EEPROM_VERSION);
  }

  // Use the EEPROM keymap that Chrysalis modifies
Layer.getKey = getKey;
  NumLock.numPadLayer = NUMPAD_KEYMAP;
//  AlphaSquare.color = { 255, 0, 0 };
//  LEDRainbowEffect.brightness(150);
//  LEDRainbowWaveEffect.brightness(150);
  StalkerEffect.variant = STALKER(BlazingTrail);
//  StalkerEffect.activate();
    StalkerEffect.activate();
}


void loop() {
  Kaleidoscope.loop();
}
