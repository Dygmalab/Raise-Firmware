/* -*- mode: c++ -*-
 * kaleidoscope::plugin::EEPROMUpgrade -- Raise EEPROM upgrade helper
 * Copyright (C) 2020  Dygma Lab S.L.
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

#include "EEPROMUpgrade.h"

#include <Kaleidoscope-EEPROM-Settings.h>
#include <Kaleidoscope-IdleLEDs.h>
#include <Kaleidoscope-LEDControl.h>
#include <Kaleidoscope-FocusSerial.h>

namespace kaleidoscope {
namespace plugin {

uint16_t EEPROMUpgrade::settings_base_;
uint8_t EEPROMUpgrade::version_;

void EEPROMUpgrade::reserveStorage() {
  settings_base_ = ::EEPROMSettings.requestSlice(sizeof(version_));
  Runtime.storage().get(settings_base_, version_);
  if (version_ == 0xff)
    version_ = 0x00;

  version_ = 0;
}

void EEPROMUpgrade::upgrade() {
  switch (version_) {
    case 0:
      /*
       * For some odd reason, the IdleLEDs timeout setting gets misread, even
       * when the EEPROM is correct. We always read 10176 in this case, so set
       * it back to the default 600 then.
       */
      if (::PersistentIdleLEDs.idleTimeoutSeconds() == 10176) {
        ::PersistentIdleLEDs.setIdleTimeoutSeconds(600);
      }

      /*
       * With the 0->1 upgrade, we removed a number of LED effects. For simplicity's sake, set the mode to Colormap.
       */
      ::LEDControl.set_mode(0);

      version_++;
      break;
  }
  Runtime.storage().put(settings_base_, version_);
}

EventHandlerResult EEPROMUpgrade::onFocusEvent(const char *command) {
  if (::Focus.handleHelp(command, PSTR("_raise.eepromVersion")))
    return EventHandlerResult::OK;

  if (strcmp_P(command, PSTR("_raise.eepromVersion")) != 0)
    return EventHandlerResult::OK;

  if (::Focus.isEOL()) {
    ::Focus.send(version_);
    return EventHandlerResult::EVENT_CONSUMED;
  }

  ::Focus.read(version_);
  upgrade();

  return EventHandlerResult::EVENT_CONSUMED;
}

}
}

kaleidoscope::plugin::EEPROMUpgrade EEPROMUpgrade;
