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

/*
 * NOTE: This plugin is a workaround, do not use it for anything but the Dygma
 * Raise!
 *
 * The single reason this exists is because the firmware the first Raises will
 * ship with have a variant of IdleLEDs that stores its settings in EEPROM, but
 * the plugin is at the end of the plugin list. Kaleidoscope has
 * PersistentIdleLEDs, which does the same thing. The problem is, that we need
 * to move IdleLEDs to the top of the list, but that would rearrange the EEPROM
 * layout. Since we want to remain compatible with the initial version of the
 * factory firmware, we can't do that.
 *
 * So this plugin is here as a workaround: it allocates EEPROM when
 * `RaiseIdleLEDs.setup()` is called from the firmware sketch, instead of doing
 * so in `onSetup()`. This allows us to place the plugin early, but allocate
 * space later, without having to resort to allocating in a per-cycle hook.
 */

#pragma once

#ifdef ARDUINO_SAMD_RAISE

#include <Kaleidoscope.h>
#include <Kaleidoscope-IdleLEDs.h>

namespace kaleidoscope {
namespace plugin {

class RaiseIdleLEDs : public IdleLEDs {
 public:
  void setup();
  EventHandlerResult onFocusEvent(const char *command);

  static void setIdleTimeoutSeconds(uint32_t new_limit);
 private:
  static uint16_t settings_base_;
};

}
}

extern kaleidoscope::plugin::RaiseIdleLEDs RaiseIdleLEDs;

#endif
