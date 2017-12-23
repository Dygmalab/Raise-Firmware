// -*- mode: c++ -*-
// Copyright 2016 Keyboardio, inc. <jesse@keyboard.io>
// See "LICENSE" for license details

#define DEBUG_SERIAL false

#ifndef BUILD_INFORMATION
#define BUILD_INFORMATION "locally built"
#endif

#include <Kaleidoscope-MacrosOnTheFly.h>

#include "Kaleidoscope-LEDControl.h"
#include "Kaleidoscope.h"

#include "LED-Off.h"
#include "Kaleidoscope-LEDEffect-SolidColor.h"
#include "Kaleidoscope-LEDEffect-Breathe.h"
#include "Kaleidoscope-LEDEffect-Chase.h"
#include "Kaleidoscope-LEDEffect-Rainbow.h"
#include "Kaleidoscope-LED-Stalker.h"
#include "Kaleidoscope-LEDEffect-DigitalRain.h"
#include "Kaleidoscope-Underglow-LEDEffect-Chase.h"

#include "Kaleidoscope-Focus.h"

#define MACRO_VERSION_INFO 1
#define Macro_VersionInfo M(MACRO_VERSION_INFO)
#define MACRO_ANY 2
#define Macro_Any M(MACRO_ANY)
#define NUMPAD_KEYMAP 2

enum { QWERTY, NUMPAD, _LAYER_MAX }; // layers
// *INDENT-OFF*
const Key keymaps[][ROWS][COLS] PROGMEM = {
  [QWERTY] = KEYMAP_60(\
  Key_Escape, Key_1, Key_2, Key_3, Key_4, Key_5, Key_6,               Key_7, Key_8, Key_9, Key_0, Key_Minus, Key_Equals, Key_Backspace, \
  Key_Tab, Key_Q, Key_W, Key_E, Key_R, Key_T,                         Key_Y, Key_U, Key_I, Key_O, Key_P, Key_LeftBracket, Key_RightBracket, Key_NonUsBackslashAndPipe, \
  Key_CapsLock, Key_A, Key_S, Key_D, Key_F, Key_G,                    Key_H, Key_J, Key_K, Key_L, Key_Semicolon, Key_Quote, Key_Enter, \
  Key_LeftShift, Key_Z, Key_X, Key_C, Key_V, Key_B,                   Key_N, Key_M, Key_Comma, Key_Period, Key_Slash, Key_RightShift, \
  Key_LeftControl, XXX, Key_LeftAlt, Key_LeftControl, Key_Spacebar, Key_Spacebar, Key_RightControl, Key_RightAlt, Key_LEDEffectNext, Key_NonUsPound, Key_RightControl, \
  Key_Keymap1, Key_Keymap1_Momentary,                  Key_Backtick, Key_LeftGui),

  [NUMPAD] = KEYMAP_60 ( \
  ___, Key_F1, Key_F2, Key_F3, Key_F4, Key_F5, Key_F6,               Key_F7, Key_F8, Key_F9, Key_F10, ___, ___, ___, \
  ___, Key_MacroRec, Key_MacroPlay, ___, ___, ___,             ___, Key_PageDown, Key_PageUp, ___, ___, ___, ___, ___, \
  ___, ___, ___, ___, ___, ___,                  Key_LeftArrow, Key_DownArrow, Key_UpArrow, Key_RightArrow, ___, ___, ___, \
  ___, ___, ___, ___, ___, ___,                       ___, ___, ___, ___, ___, ___, \
  ___, ___, ___, ___, ___,                            ___, ___, ___, ___, ___, ___,  \
                      Key_Keymap1, ___,                 ___, ___)
};
// *INDENT-ON*
static kaleidoscope::LEDSolidColor solidRed(255, 0, 0);


void setup() {
  Kaleidoscope.setup();
  BootKeyboard.begin();
  Kaleidoscope.use(
//    &MacrosOnTheFly,
    &LEDControl,
    &LEDOff,
    &solidRed,
    &LEDRainbowEffect, &LEDRainbowWaveEffect,
    &LEDChaseEffect,
    &LEDBreatheEffect,
    &StalkerEffect,
    &LEDDigitalRainEffect,
    &LEDUnderglowChaseEffect,
    &Focus
  );

  Focus.addHook(FOCUS_HOOK_HELP);
  Focus.addHook(FOCUS_HOOK_VERSION);
  Focus.addHook(FOCUS_HOOK_LEDCONTROL);
   
  LEDRainbowEffect.brightness(255);
  LEDRainbowWaveEffect.brightness(255);
  StalkerEffect.variant = STALKER(BlazingTrail);
  LEDRainbowEffect.activate();
}


void loop() {
  Kaleidoscope.loop();
}
