/* -*- mode: c++ -*-
 * kaleidoscope::plugin::LEDCapsLockLight -- Highlight CapsLock when active
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

#pragma once

#include <Kaleidoscope.h>
#include <Kaleidoscope-LEDControl.h>

namespace kaleidoscope {
namespace plugin {

class LEDCapsLockLight: public Plugin {
 public:
  EventHandlerResult onSetup();
  EventHandlerResult onLayerChange();
  EventHandlerResult beforeReportingState(const KeyEvent &event);

 private:
  static KeyAddr caps_address_;
  static uint8_t highlight_hue_;
  static bool caps_was_on_;

  static EventHandlerResult findCapsLock();
};

}
}

extern kaleidoscope::plugin::LEDCapsLockLight LEDCapsLockLight;
