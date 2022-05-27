/* -*- mode: c++ -*-
 * kaleidoscope::plugin::wiredIdleLeds -- IdleLEDs with a workaround for the Raise
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
 * to move IdleLEDs to the top of the list, so it can catch all key events
 * before they get consumed by other plugins, but that would rearrange the
 * EEPROM layout. Since we want to remain compatible with the initial version of
 * the factory firmware, we can't do that.
 *
 * So this plugin is here as a workaround: we keep PersistentIdleLEDs at the
 * same position the old IdleLEDs plugin was, but we add this plugin at the top.
 * All it does, is catch key events and proxy them to PersistentIdleLEDs, thus
 * making sure it sees everything. It does mean that PersistentIdleLEDs will act
 * twice on most key presses, but thankfully, that has no ill side effects. At
 * most, we'll set the start time twice, but that's a very cheap operation.
 */

#pragma once

#ifdef ARDUINO_SAMD_RAISE

#include <Kaleidoscope.h>

namespace kaleidoscope {
namespace plugin {

class RaiseIdleLEDs : public kaleidoscope::Plugin {
 public:
  EventHandlerResult onKeyswitchEvent(Key &mapped_key, KeyAddr key_addr, uint8_t key_state);
};

}
}

extern kaleidoscope::plugin::wiredIdleLEDs RaiseIdleLEDs;

#endif
