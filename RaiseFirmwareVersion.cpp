/* -*- mode: c++ -*-
 * kaleidoscope::plugin::wiredFirmwareVersion -- Tell the firmware version via Focus
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

#include "Kaleidoscope.h"
#include "Kaleidoscope-FocusSerial.h"
#include "RaiseFirmwareVersion.h"

#ifndef BAZECOR_VERSION
//#define BAZECOR_VERSION "<unknown>"
#define BAZECOR_VERSION "v1.0.9beta"
#endif

#ifndef KALEIDOSCOPE_SHA
//#define KALEIDOSCOPE_SHA "<unknown>"
#define KALEIDOSCOPE_SHA "5ecc2faf"
#endif

#ifndef FIRMWARE_SHA
//#define FIRMWARE_SHA "<unknown>"
#define FIRMWARE_SHA "6f2ca51"
#endif

namespace kaleidoscope {
namespace plugin {

EventHandlerResult FirmwareVersion::onFocusEvent(const char *command) {
  const char *cmd = PSTR("version");
  if (::Focus.handleHelp(command, cmd))
    return EventHandlerResult::OK;

  if (strcmp_P(command, cmd) != 0)
    return EventHandlerResult::OK;

  ::Focus.sendRaw(F(BAZECOR_VERSION " " KALEIDOSCOPE_SHA " " FIRMWARE_SHA));

  return EventHandlerResult::EVENT_CONSUMED;
}


}
}

kaleidoscope::plugin::FirmwareVersion FirmwareVersion;
