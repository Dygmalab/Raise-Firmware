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

#include "LED-CapsLockLight.h"

namespace kaleidoscope {
namespace plugin {

KeyAddr LEDCapsLockLight::caps_address_ = UnknownKeyswitchLocation;
uint8_t LEDCapsLockLight::highlight_hue_ = 170;
bool LEDCapsLockLight::caps_was_on_;

EventHandlerResult LEDCapsLockLight::onSetup() {
  return findCapsLock();
}

EventHandlerResult LEDCapsLockLight::onLayerChange() {
  return findCapsLock();
}

EventHandlerResult LEDCapsLockLight::beforeReportingState() {
  if (!caps_address_.isValid())
    return EventHandlerResult::OK;

  //bool caps_is_on = !!(kaleidoscope::hid::getKeyboardLEDs() & LED_CAPS_LOCK);
  bool caps_is_on = !!(Runtime.hid().keyboard().getKeyboardLEDs() & LED_CAPS_LOCK);

  if (!caps_is_on && caps_was_on_) {
    ::LEDControl.refreshAt(caps_address_);
  }
  if (caps_is_on) {
    cRGB color = breath_compute(highlight_hue_);
    ::LEDControl.setCrgbAt(caps_address_, color);
  }
  caps_was_on_ = caps_is_on;
  return EventHandlerResult::OK;
}

EventHandlerResult LEDCapsLockLight::findCapsLock() {
  caps_address_ = UnknownKeyswitchLocation;

  for (auto key_addr: KeyAddr::all()) {
    Key k = Layer.lookup(key_addr);
    if (k == Key_CapsLock) {
      caps_address_ = key_addr;
      break;
    }
  }

  return EventHandlerResult::OK;
}

}
}

kaleidoscope::plugin::LEDCapsLockLight LEDCapsLockLight;
