/* -*- mode: c++ -*-
 * kaleidoscope::plugin::RaiseEEPROM -- Raise EEPROM upgrade helper
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

namespace kaleidoscope {
namespace plugin {

class EEPROMUpgrade: public Plugin {
 public:
  EventHandlerResult onFocusEvent(const char *command);

  static void reserveStorage();
  static void upgrade();

 private:
  static uint16_t settings_base_;
  static uint8_t version_;
};

}
}

extern kaleidoscope::plugin::EEPROMUpgrade EEPROMUpgrade;
