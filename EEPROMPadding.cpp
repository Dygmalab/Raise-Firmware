/* -*- mode: c++ -*-
 * kaleidoscope::plugin::EEPROMPadding -- EEPROM padding helper
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

#include "EEPROMPadding.h"

#include <Kaleidoscope-EEPROM-Settings.h>

namespace kaleidoscope {
namespace plugin {

EventHandlerResult EEPROMPadding::onSetup() {
  ::EEPROMSettings.requestSlice(size_);
  return EventHandlerResult::OK;
}

}
}
