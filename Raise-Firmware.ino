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

#define MACRO_VERSION_INFO 1
#define Macro_VersionInfo M(MACRO_VERSION_INFO)
#define MACRO_ANY 2
#define Macro_Any M(MACRO_ANY)
#define NUMPAD_KEYMAP 2


#define NUMPAD KEYMAP_60 ( \
  Key_Escape, Key_1, Key_2, Key_3, Key_4, Key_5, Key_6,             Key_7, Key_8, Key_9, Key_0, Key_A, Key_A, Key_Delete, \
  Key_Tab, Key_Q, Key_UpArrow, Key_E, Key_R, Key_T,                       Key_Y, Key_U, Key_I, Key_O, Key_P, Key_M, Key_Backspace, Key_1, \
  Key_LeftControl, Key_LeftArrow, Key_DownArrow, Key_RightArrow, Key_F, Key_G,               Key_H, Key_J, Key_K, Key_L, Key_L, Key_M, Key_Enter, \
  Key_LeftShift, Key_Z, Key_X, Key_C, Key_V, Key_B,          Key_N, Key_M, Key_Semicolon, Key_Comma, Key_Minus, Key_RightShift, \
  Key_LeftControl, Key_CapsLock, ___, Key_Keymap1, Key_Spacebar,    Key_Spacebar, Key_RightAlt, Key_Keymap1, ___, Key_RightControl, Key_1,  \
                       Key_Backspace, Key_Enter,            Key_Backspace, Key_Keymap1)

#define QWERTY KEYMAP_60 ( \
Key_Escape, Key_1, Key_2, Key_3, Key_4, Key_5, Key_6,                     Key_LEDEffectNext, Key_8, Key_9, Key_0, Key_Minus, Key_Equals, Key_Delete, \
Key_Tab, Key_Q, Key_W, Key_E, Key_R, Key_T,                               Key_Y, Key_U, Key_I, Key_O, Key_P, Key_LeftBracket, Key_Backspace, Key_1, \
Key_CapsLock, Key_LEDEffectNext , Key_S, Key_D, Key_F, Key_G,                           Key_H, Key_J, Key_K, Key_L, Key_Semicolon, Key_Quote, Key_Enter, \
Key_LeftShift, Key_Z, Key_X, Key_C, Key_V, Key_B,             Key_N, Key_M, Key_Comma, Key_Period, Key_Slash, Key_RightShift,\
Key_LeftControl,Key_LeftGui, Key_LeftAlt,Key_Keymap1, Key_Spacebar,  Key_Spacebar, Key_RightAlt, Key_RightGui, Key_Menu, Key_RightControl, Key_1,\
                     Key_LEDEffectNext, Key_Enter,                  Key_A, Key_B)

const Key keymaps[][ROWS][COLS] PROGMEM = {
  QWERTY,
  NUMPAD
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
  if (macroIndex == TOGGLENUMLOCK && keyToggledOn(keyState)) {
    return NumLock.toggle();
  } else if (macroIndex == 1 && keyToggledOn(keyState)) {
    Macros.type(PSTR("Keyboardio Model 01 - Kaleidoscope "));
    Macros.type(PSTR(BUILD_INFORMATION));
  } else if (macroIndex == MACRO_ANY) {
    static Key lastKey;
    if (keyToggledOn(keyState))
      lastKey.keyCode = Key_A.keyCode + (uint8_t)(millis() % 36);

    if (keyIsPressed(keyState))
      kaleidoscope::hid::pressKey(lastKey);
  }
  return MACRO_NONE;
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
    NULL);

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
