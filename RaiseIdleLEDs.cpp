/* -*- mode: c++ -*-
 * kaleidoscope::plugin::RaiseIdleLeds -- IdleLEDs with a workaround for the Raise
 * Copyright (C) 2019  Dygma Lab S.L.
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

#ifdef ARDUINO_SAMD_RAISE

#include "RaiseIdleLEDs.h"
#include <Kaleidoscope-EEPROM-Settings.h>
#include <Kaleidoscope-FocusSerial.h>

namespace kaleidoscope {
namespace plugin {

uint16_t RaiseIdleLEDs::settings_base_;

void RaiseIdleLEDs::setup() {
  settings_base_ = ::EEPROMSettings.requestSlice(sizeof(uint16_t));

  // If idleTime is max, assume that EEPROM is uninitialized, and store the
  // defaults.
  uint16_t idle_time;
  Kaleidoscope.storage().get(settings_base_, idle_time);
  if (idle_time == 0xffff) {
    idle_time = idle_time_limit;
  }
  setIdleTimeoutSeconds(idle_time);
}

void RaiseIdleLEDs::setIdleTimeoutSeconds(uint32_t new_limit) {
  IdleLEDs::setIdleTimeoutSeconds(new_limit);

  uint16_t stored_limit = (uint16_t)new_limit;
  Kaleidoscope.storage().put(settings_base_, stored_limit);
  Kaleidoscope.storage().commit();
}

EventHandlerResult RaiseIdleLEDs::onFocusEvent(const char *command) {
  const char *cmd = PSTR("idleleds.time_limit");

  if (::Focus.handleHelp(command, cmd))
    return EventHandlerResult::OK;

  if (strcmp_P(command, cmd) != 0)
    return EventHandlerResult::OK;

  if (::Focus.isEOL()) {
    ::Focus.send(idleTimeoutSeconds());
  } else {
    uint16_t idle_time;
    ::Focus.read(idle_time);
    setIdleTimeoutSeconds(idle_time);
  }
  return EventHandlerResult::EVENT_CONSUMED;
}

}
}

kaleidoscope::plugin::RaiseIdleLEDs RaiseIdleLEDs;

#endif
