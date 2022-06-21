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

#ifdef ARDUINO_SAMD_RAISE

#include "RaiseIdleLEDs.h"
#include <Kaleidoscope-IdleLEDs.h>

namespace kaleidoscope {
namespace plugin {

EventHandlerResult RaiseIdleLEDs::onKeyswitchEvent(Key &mapped_key, KeyAddr key_addr, uint8_t key_state) {
  return ::PersistentIdleLEDs.onKeyswitchEvent(mapped_key, key_addr, key_state);
}

}
}

kaleidoscope::plugin::RaiseIdleLEDs RaiseIdleLEDs;

#endif
