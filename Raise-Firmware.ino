// -*- mode: c++ -*-
/* Raise-Firmware -- Factory firmware for the Dygma Raise
 * Copyright (C) 2019, 2020  DygmaLab, SE.
 *
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef BUILD_INFORMATION
#define BUILD_INFORMATION "locally built"
#endif

#include "Kaleidoscope.h"

#include "Kaleidoscope-MouseKeys.h"
#include "Kaleidoscope-LEDControl.h"
#include "Kaleidoscope-PersistentLEDMode.h"
#include "Kaleidoscope-FocusSerial.h"
#include "Kaleidoscope-EEPROM-Settings.h"
#include "Kaleidoscope-EEPROM-Keymap.h"
#include "Kaleidoscope-IdleLEDs.h"
#include "Kaleidoscope-Colormap.h"
#include "Kaleidoscope-LED-Palette-Theme.h"
#include "Kaleidoscope-LEDEffect-Rainbow.h"
#include "Kaleidoscope-LED-Stalker.h"
#include "Kaleidoscope-TapDance.h"
#include "Kaleidoscope-DynamicTapDance.h"
#include "Kaleidoscope-DynamicMacros.h"
#include "Kaleidoscope-MagicCombo.h"
#include "Kaleidoscope-USB-Quirks.h"
#include "Kaleidoscope-LayerFocus.h"
#include "RaiseIdleLEDs.h"
#include "RaiseFirmwareVersion.h"
#include "kaleidoscope/device/dygma/raise/Focus.h"
#include "kaleidoscope/device/dygma/raise/SideFlash.h"

// Support for host power management (suspend & wakeup)
#include "Kaleidoscope-HostPowerManagement.h"

#include "Kaleidoscope-OneShot.h"
#include "Kaleidoscope-Qukeys.h"
#include "Kaleidoscope-Escape-OneShot.h"

#include "LED-CapsLockLight.h"
#include "EEPROMPadding.h"

#include "EEPROMUpgrade.h"

#include "attiny_firmware.h"

enum { QWERTY, NUMPAD, _LAYER_MAX }; // layers

/* This comment temporarily turns off astyle's indent enforcement so we can make
 * the keymaps actually resemble the physical key layout better
 */
// *INDENT-OFF*

KEYMAPS(
[QWERTY] = KEYMAP_STACKED
(
    Key_Escape      ,Key_1         ,Key_2       ,Key_3         ,Key_4     ,Key_5 ,Key_6
   ,Key_Tab         ,Key_Q         ,Key_W       ,Key_E         ,Key_R     ,Key_T
   ,Key_CapsLock    ,Key_A         ,Key_S       ,Key_D         ,Key_F     ,Key_G
   ,Key_LeftShift   ,Key_Backslash ,Key_Z       ,Key_X         ,Key_C     ,Key_V ,Key_B
   ,Key_LeftControl ,Key_LeftGui   ,Key_LeftAlt ,Key_Space     ,Key_Space
                                                ,Key_Backspace ,Key_Enter

   ,Key_7               ,Key_8      ,Key_9        ,Key_0        ,Key_Minus         ,Key_Equals       ,Key_Backspace
   ,Key_Y               ,Key_U      ,Key_I        ,Key_O        ,Key_P             ,Key_LeftBracket  ,Key_RightBracket ,Key_Enter
   ,Key_H               ,Key_J      ,Key_K        ,Key_L        ,Key_Semicolon     ,Key_Quote        ,Key_Backslash
   ,Key_N               ,Key_M      ,Key_Comma    ,Key_Period   ,Key_Slash         ,Key_RightShift
   ,Key_Space           ,Key_Space  ,Key_RightAlt ,Key_RightGui ,Key_LEDEffectNext ,Key_RightControl
   ,MoveToLayer(NUMPAD) ,Key_Delete
),

[NUMPAD] = KEYMAP_STACKED
(
    Key_Escape      ,Key_F1        ,Key_F2        ,Key_F3         ,Key_F4 ,Key_F5 ,Key_F6
   ,Key_Tab         ,XXX           ,Key_UpArrow   ,XXX            ,XXX    ,XXX
   ,Key_CapsLock    ,Key_LeftArrow ,Key_DownArrow ,Key_RightArrow ,XXX    ,XXX
   ,Key_LeftShift   ,Key_Backslash ,XXX           ,XXX            ,XXX    ,XXX    ,XXX
   ,Key_LeftControl ,Key_LeftGui   ,Key_LeftAlt   ,Key_Space      ,Key_Space
                                                  ,Key_Backspace  ,Key_Enter

   ,Key_F7              ,Key_F8    ,Key_F9        ,Key_F10       ,Key_F11            ,Key_F12 ,Key_Backspace
   ,Key_KeypadSubtract  ,Key_7     ,Key_8         ,Key_9         ,Key_KeypadDivide   ,XXX     ,XXX, Key_Enter
   ,Key_KeypadAdd       ,Key_4     ,Key_5         ,Key_6         ,Key_KeypadMultiply ,XXX     ,Key_Backslash
   ,Key_KeypadDot       ,Key_1     ,Key_2         ,Key_3         ,Key_UpArrow        ,Key_RightShift
   ,Key_0               ,Key_Space ,Key_LeftArrow ,Key_DownArrow ,Key_RightArrow     ,Key_RightControl
   ,MoveToLayer(QWERTY) ,Key_Delete
 )
);

/* Re-enable astyle's indent enforcement */
// *INDENT-ON*

kaleidoscope::device::dygma::raise::SideFlash<ATTinyFirmware> SideFlash;

void tapDanceAction(uint8_t tap_dance_index, KeyAddr key_addr,
                    uint8_t tap_count,
                    kaleidoscope::plugin::TapDance::ActionType tap_dance_action) {
  DynamicTapDance.dance(tap_dance_index, key_addr, tap_count, tap_dance_action);
}

/** toggleLedsOnSuspendResume toggles the LEDs off when the host goes to sleep,
 * and turns them back on when it wakes up.
 */
void toggleLedsOnSuspendResume(kaleidoscope::plugin::HostPowerManagement::Event event) {
  switch (event) {
  case kaleidoscope::plugin::HostPowerManagement::Suspend:
    LEDControl.disable();
    break;
  case kaleidoscope::plugin::HostPowerManagement::Resume:
    LEDControl.enable();
    break;
  case kaleidoscope::plugin::HostPowerManagement::Sleep:
    break;
  }
}

/** hostPowerManagementEventHandler dispatches power management events (suspend,
 * resume, and sleep) to other functions that perform action based on these
 * events.
 */
void hostPowerManagementEventHandler(kaleidoscope::plugin::HostPowerManagement::Event event) {
  toggleLedsOnSuspendResume(event);
}

enum {
  COMBO_TOGGLE_NKRO_MODE
};

static uint32_t protocol_toggle_start = 0;

static void toggleKeyboardProtocol(uint8_t combo_index)
{
  USBQuirks.toggleKeyboardProtocol();
  protocol_toggle_start = Kaleidoscope.millisAtCycleStart();
}

static void protocolBreathe()
{
  if (Kaleidoscope.hasTimeExpired(protocol_toggle_start, uint16_t(10000)))
  {
    protocol_toggle_start = 0;
  }
  if (protocol_toggle_start == 0)
    return;

  uint8_t hue = 120;
  if (Kaleidoscope.hid().keyboard().getProtocol() == HID_BOOT_PROTOCOL)
  {
    hue = 0;
  }

  cRGB color = breath_compute(hue);
  ::LEDControl.setCrgbAt(KeyAddr(4, 0), color);
  ::LEDControl.setCrgbAt(KeyAddr(3, 0), color);
  ::LEDControl.setCrgbAt(KeyAddr(4, 2), color);
  ::LEDControl.setCrgbAt(KeyAddr(0, 6), color);
  ::LEDControl.syncLeds();
}

USE_MAGIC_COMBOS(
    {.action = toggleKeyboardProtocol,
     // Left Ctrl + Left Shift + Left Alt + 6
     .keys = {R4C0, R3C0, R4C2, R0C6}});

kaleidoscope::plugin::EEPROMPadding JointPadding(8);

KALEIDOSCOPE_INIT_PLUGINS(
    FirmwareVersion,
    USBQuirks,
    MagicCombo,
    RaiseIdleLEDs,
    EEPROMSettings,
    EEPROMKeymap,
    FocusSettingsCommand,
    FocusEEPROMCommand,
    LEDCapsLockLight,
    LEDControl,
    PersistentLEDMode,
    FocusLEDCommand,
    LEDPaletteTheme,
    JointPadding,
    ColormapEffect,
    LEDRainbowWaveEffect, LEDRainbowEffect, StalkerEffect,
    PersistentIdleLEDs,
    RaiseFocus,
    TapDance,
    DynamicTapDance,
    DynamicMacros,
    SideFlash,
    Focus,
    MouseKeys,
    OneShot,
    EscapeOneShot,
    Qukeys,
    LayerFocus,
    EEPROMUpgrade,
    HostPowerManagement
  );

void setup()
{
  // First start the serial communications to avoid restarting unnecesarily
  Kaleidoscope.serialPort().begin(9600);

  // Set up the generic clock (GCLK2) used to clock the watchdog timer at 1.024kHz
  REG_GCLK_GENDIV = GCLK_GENDIV_DIV(4) | // Divide the 32.768kHz clock source by divisor 32, where 2^(4 + 1): 32.768kHz/32=1.024kHz
                    GCLK_GENDIV_ID(2);   // Select Generic Clock (GCLK) 2
  while (GCLK->STATUS.bit.SYNCBUSY)
    ; // Wait for synchronization

  REG_GCLK_GENCTRL = GCLK_GENCTRL_DIVSEL |        // Set to divide by 2^(GCLK_GENDIV_DIV(4) + 1)
                     GCLK_GENCTRL_IDC |           // Set the duty cycle to 50/50 HIGH/LOW
                     GCLK_GENCTRL_GENEN |         // Enable GCLK2
                     GCLK_GENCTRL_SRC_OSCULP32K | // Set the clock source to the ultra low power oscillator (OSCULP32K)
                     GCLK_GENCTRL_ID(2);          // Select GCLK2
  while (GCLK->STATUS.bit.SYNCBUSY)
    ; // Wait for synchronization

  // Feed GCLK2 to WDT (Watchdog Timer)
  REG_GCLK_CLKCTRL = GCLK_CLKCTRL_CLKEN |     // Enable GCLK2 to the WDT
                     GCLK_CLKCTRL_GEN_GCLK2 | // Select GCLK2
                     GCLK_CLKCTRL_ID_WDT;     // Feed the GCLK2 to the WDT
  while (GCLK->STATUS.bit.SYNCBUSY)
    ; // Wait for synchronization

  REG_WDT_CONFIG = WDT_CONFIG_PER_1K; // Set the WDT reset timeout to 2 second
  while (WDT->STATUS.bit.SYNCBUSY)
    ;                             // Wait for synchronization
  REG_WDT_CTRL = WDT_CTRL_ENABLE; // Enable the WDT in normal mode
  while (WDT->STATUS.bit.SYNCBUSY)
    ; // Wait for synchronization

  Kaleidoscope.setup();

  // Reserve space in the keyboard's EEPROM for the keymaps
  EEPROMKeymap.setup(10);

  // Reserve space for the number of Colormap layers we will use
  ColormapEffect.max_layers(10);
  LEDRainbowEffect.brightness(255);
  LEDRainbowWaveEffect.brightness(255);
  StalkerEffect.variant = STALKER(BlazingTrail);

  DynamicTapDance.setup(0, 1024);
  DynamicMacros.reserve_storage(2048);

  EEPROMUpgrade.reserveStorage();
  EEPROMUpgrade.upgrade();

  // Custom parameters for Mouse plugin
  MouseKeys.speed = 25;
  MouseKeys.speedDelay = 1;
  MouseKeys.accelSpeed = 75;
  MouseKeys.accelDelay = 400;
  MouseKeys.setSpeedLimit(176);
}

void loop()
{
  if (!WDT->STATUS.bit.SYNCBUSY) // Check if the WDT registers are synchronized
  {
    REG_WDT_CLEAR = WDT_CLEAR_CLEAR_KEY; // Clear the watchdog timer
  }
  // Application code goes here...
  Kaleidoscope.loop();
  protocolBreathe();
}