/* -*- mode: c++ -*-
 * kaleidoscope::device::dygma::wired -- Kaleidoscope device plugin for Dygma Raise
 * Copyright (C) 2017-2019  Keyboard.io, Inc
 * Copyright (C) 2017-2019  Dygma Lab S.L.
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

// TODO(algernon): This file should be automatically generated.

#pragma once

#ifdef ARDUINO_RASPBERRY_PI_PICO

struct ATTinyFirmware {
  static constexpr uint8_t pages = 46;
  static constexpr uint16_t length = 2944;
  static constexpr uint16_t offsets[pages] PROGMEM =  {0, 64, 128, 192, 256, 320, 384, 448, 512, 576, 640, 704, 768, 832, 896, 960, 1024, 1088, 1152, 1216, 1280, 1344, 1408, 1472, 1536, 1600, 1664, 1728, 1792, 1856, 1920, 1984, 2048, 2112, 2176, 2240, 2304, 2368, 2432, 2496, 2560, 2624, 2688, 2752, 2816, 2880};
  static constexpr uint8_t data[length] PROGMEM = {0xb2, 0xc0, 0xcc, 0xc0, 0xcb, 0xc0, 0xca, 0xc0, 0xc9, 0xc0, 0xc8, 0xc0, 0xc7, 0xc0, 0xc6, 0xc0, 0xc5, 0xc0, 0xae, 0xc2, 0xc3, 0xc0, 0xc2, 0xc0, 0xc1, 0xc0, 0xc0, 0xc0, 0xbf, 0xc0, 0x6c, 0xc3, 0xbd, 0xc0, 0xbc, 0xc0, 0xbb, 0xc0, 0xb3, 0xc2, 0x22, 0xc1, 0x43, 0xc1, 0x4e, 0xc1, 0x76, 0xc1, 0x75, 0xc1, 0x74, 0xc1, 0x4f, 0xc1, 0x72, 0xc1, 0x4f, 0xc1, 0x54, 0xc1, 0x57, 0xc1, 0x66, 0xc1, 0x5f, 0xc1, 0x4d, 0xc1, 0x6b, 0xc1, 0x5f, 0xc1, 0x24, 0xc2, 0xdb, 0xc1, 0xf7, 0xc1, 0xa, 0xc2, 0x84, 0xc2, 0x83, 0xc2, 0x82, 0xc2, 0x21, 0xc2, 0x22, 0xc2, 0x23, 0xc2, 0x18, 0xc2, 0x1b, 0xc2, 0xdb, 0xc1, 0x23, 0xc2, 0x12, 0xc2, 0xff, 0xff, 0x0, 0x3, 0x6, 0x9, 0xc, 0xf, 0x12, 0x15, 0x18, 0x1b, 0x1e, 0x21, 0x24, 0x27, 0xff, 0xff, 0x2, 0x5, 0x8, 0xb, 0xe, 0x11, 0x14, 0x17, 0x1a, 0x1d, 0x20, 0x23, 0x26, 0x29, 0xff, 0xff, 0x1, 0x4, 0x7, 0xa, 0xd, 0x10, 0x13, 0x16, 0x19, 0x1c, 0x1f, 0x22, 0x25, 0x28, 0x2a, 0x2d, 0x30, 0xff, 0xff, 0x33, 0x36, 0x39, 0x3c, 0x3f, 0x42, 0x45, 0x48, 0x4b, 0x4e, 0x51, 0x2c, 0x2f, 0x32, 0xff, 0xff, 0x35, 0x38, 0x3b, 0x3e, 0x41, 0x44, 0x47, 0x4a, 0x4d, 0x50, 0x53, 0x2b, 0x2e, 0x31, 0xff, 0xff, 0x34, 0x37, 0x3a, 0x3d, 0x40, 0x43, 0x46, 0x49, 0x4c, 0x4f, 0x52, 0x54, 0x57, 0x5a, 0x5d, 0x60, 0x63, 0xff, 0xff, 0x66, 0x69, 0x6c, 0x6f, 0x72, 0x75, 0x78, 0x7b, 0x56, 0x59, 0x5c, 0x5f, 0x62, 0x65, 0xff, 0xff, 0x68, 0x6b, 0x6e, 0x71, 0x74, 0x77, 0x7a, 0x7d, 0x55, 0x58, 0x5b, 0x5e, 0x61, 0x64, 0xff, 0xff, 0x67, 0x6a, 0x6d, 0x70, 0x73, 0x76, 0x79, 0x7c, 0x7e, 0x81, 0x84, 0x87, 0x8a, 0x8d, 0x90, 0x93, 0x96, 0xff, 0xff, 0x99, 0x9c, 0x9f, 0xa2, 0xa5, 0x80, 0x83, 0x86, 0x89, 0x8c, 0x8f, 0x92, 0x95, 0x98, 0xff, 0xff, 0x9b, 0x9e, 0xa1, 0xa4, 0xa7, 0x7f, 0x82, 0x85, 0x88, 0x8b, 0x8e, 0x91, 0x94, 0x97, 0xff, 0xff, 0x9a, 0x9d, 0xa0, 0xa3, 0xa6, 0xa8, 0xab, 0xae, 0xb1, 0xb4, 0xb7, 0xba, 0xbd, 0xc0, 0xc3, 0xc6, 0xc9, 0xff, 0xff, 0xcc, 0xcf, 0xaa, 0xad, 0xb0, 0xb3, 0xb6, 0xb9, 0xbc, 0xbf, 0xc2, 0xc5, 0xc8, 0xcb, 0xff, 0xff, 0xce, 0xd1, 0xa9, 0xac, 0xaf, 0xb2, 0xb5, 0xb8, 0xbb, 0xbe, 0xc1, 0xc4, 0xc7, 0xca, 0xff, 0xff, 0xcd, 0xd0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x11, 0x24, 0x1f, 0xbe, 0xcf, 0xef, 0xd2, 0xe0, 0xde, 0xbf, 0xcd, 0xbf, 0x11, 0xe0, 0xa0, 0xe0, 0xb1, 0xe0, 0xe2, 0xe0, 0xfb, 0xe0, 0x2, 0xc0, 0x5, 0x90, 0xd, 0x92, 0xa0, 0x35, 0xb1, 0x7, 0xd9, 0xf7, 0x22, 0xe0, 0xa0, 0xe5, 0xb1, 0xe0, 0x1, 0xc0, 0x1d, 0x92, 0xaa, 0x3a, 0xb2, 0x7, 0xe1, 0xf7, 0x23, 0xd3, 0xb1, 0xc4, 0x31, 0xcf, 0x86, 0x27, 0x8, 0x2e, 0x82, 0x95, 0x80, 0x7f, 0x80, 0x25, 0x9, 0x2e, 0x98, 0x2f, 0x82, 0x95, 0x8f, 0x70, 0x8, 0x26, 0x86, 0x95, 0x98, 0x27, 0x89, 0x27, 0x88, 0xf, 0x88, 0xf, 0x88, 0xf, 0x80, 0x25, 0x8, 0x95, 0x8e, 0xbd, 0xd, 0xb4, 0x7, 0xfe, 0xfd, 0xcf, 0x8, 0x95, 0xcf, 0x93, 0xc8, 0x2f, 0x2a, 0x98, 0x8b, 0xea, 0xf6, 0xdf, 0x8c, 0x2f, 0xf4, 0xdf, 0x80, 0xe0, 0xf2, 0xdf, 0x2a, 0x9a, 0x8e, 0xb5, 0xcf, 0x91, 0x8, 0x95, 0xcf, 0x93, 0xdf, 0x93, 0xd6, 0x2f, 0xc4, 0x2f, 0x2a, 0x98, 0x80, 0x5e, 0xe7, 0xdf, 0x8d, 0x2f, 0xe5, 0xdf, 0x8c, 0x2f, 0xe3, 0xdf, 0x2a, 0x9a, 0xdf, 0x91, 0xcf, 0x91, 0x8, 0x95, 0xcf, 0x93, 0xc8, 0x2f, 0x8c, 0xb5, 0x8f, 0x77, 0x8c, 0xbd, 0x40, 0xe0, 0x6a, 0xe0, 0x8b, 0xe0, 0xe8, 0xdf, 0x4c, 0x2f, 0x4f, 0x73, 0x40, 0x68, 0x6f, 0xe0, 0x8b, 0xe0, 0xe2, 0xdf, 0x8f, 0xe0, 0xd3, 0xdf, 0x8f, 0x73, 0x80, 0x93, 0x77, 0x2, 0x41, 0xe0, 0x6a, 0xe0, 0x8b, 0xe0, 0xd9, 0xdf, 0x8c, 0xb5, 0x80, 0x68, 0x8c, 0xbd, 0xcf, 0x91, 0x8, 0x95, 0xef, 0x92, 0xff, 0x92, 0xf, 0x93, 0x1f, 0x93, 0xcf, 0x93, 0xdf, 0x93, 0xec, 0x1, 0xfb, 0x1, 0x80, 0x81, 0x88, 0x23, 0x9, 0xf4, 0x7d, 0xc0, 0xe0, 0x91, 0x7f, 0x2, 0x8e, 0x2f, 0x90, 0xe0, 0x80, 0x31, 0x91, 0x5, 0x8, 0xf0, 0x5b, 0xc0, 0xfc, 0x1, 0xec, 0x5e, 0xff, 0x4f, 0x9, 0x94, 0x80, 0x91, 0x7e, 0x2, 0x81, 0x11, 0x7, 0xc0, 0x18, 0x82, 0x19, 0x82, 0x1a, 0x82, 0x1b, 0x82, 0x1c, 0x82, 0x1d, 0x82, 0x13, 0xc0, 0x81, 0xe0, 0x88, 0x83, 0x80, 0x91, 0x79, 0x2, 0x89, 0x83, 0x80, 0x91, 0x7a, 0x2, 0x8a, 0x83, 0x80, 0x91, 0x7b, 0x2, 0x8b, 0x83, 0x80, 0x91, 0x7c, 0x2, 0x8c, 0x83, 0x80, 0x91, 0x7d, 0x2, 0x8d, 0x83, 0x10, 0x92, 0x7e, 0x2, 0x86, 0xe0, 0xfb, 0x1, 0x80, 0x83, 0x7, 0xc0, 0x85, 0xe0, 0x88, 0x83, 0x81, 0xe0, 0xfb, 0x1, 0x80, 0x83, 0x10, 0x92, 0x7f, 0x2, 0x8b, 0x1, 0x7e, 0x1, 0x8f, 0xef, 0x9f, 0xef, 0x2c, 0xc0, 0x80, 0x91, 0x88, 0x0, 0x90, 0x91, 0x89, 0x0, 0xf0, 0xcf, 0x84, 0xe0, 0xee, 0xcf, 0x80, 0x91, 0x78, 0x2, 0xeb, 0xcf, 0x80, 0x91, 0x77, 0x2, 0xe8, 0xcf, 0x80, 0xe2, 0xe7, 0xe5, 0xf2, 0xe0, 0x3, 0xc0, 0x80, 0xe2, 0xe7, 0xe3, 0xf2, 0xe0, 0xde, 0x1, 0x1, 0x90, 0xd, 0x92, 0x8a, 0x95, 0xe1, 0xf7, 0x80, 0xe2, 0xdc, 0xcf, 0x80, 0x91, 0x36, 0x2, 0xd7, 0xcf, 0x80, 0x91, 0x35, 0x2, 0xd4, 0xcf, 0x90, 0x91, 0x33, 0x2, 0x80, 0x91, 0x34, 0x2, 0x98, 0x83, 0x89, 0x83, 0x82, 0xe0, 0xce, 0xcf, 0x81, 0xe0, 0x88, 0x83, 0xc5, 0xcf, 0xf8, 0x1, 0x20, 0x81, 0x3e, 0x2d, 0x3c, 0x1b, 0x32, 0x17, 0x28, 0xf4, 0xf7, 0x1, 0x61, 0x91, 0x7f, 0x1, 0x34, 0xdf, 0xf5, 0xcf, 0xfe, 0x1, 0xe2, 0xf, 0xf1, 0x1d, 0x90, 0x83, 0xf8, 0x1, 0x90, 0x81, 0xc9, 0xf, 0xd1, 0x1d, 0x89, 0x83, 0x80, 0x81, 0x8e, 0x5f, 0x80, 0x83, 0xdf, 0x91, 0xcf, 0x91, 0x1f, 0x91, 0xf, 0x91, 0xff, 0x90, 0xef, 0x90, 0x8, 0x95, 0xaf, 0x92, 0xbf, 0x92, 0xcf, 0x92, 0xdf, 0x92, 0xef, 0x92, 0xff, 0x92, 0xf, 0x93, 0x1f, 0x93, 0xcf, 0x93, 0xdf, 0x93, 0xec, 0x1, 0x88, 0x81, 0x98, 0x2f, 0x90, 0x7f, 0x90, 0x38, 0x61, 0xf4, 0x8f, 0x70, 0x90, 0xe0, 0x68, 0xe1, 0x70, 0xe0, 0xaa, 0xd3, 0xdc, 0x1, 0xa5, 0x5a, 0xbe, 0x4f, 0xfe, 0x1, 0x31, 0x96, 0x98, 0xe1, 0x75, 0xc0, 0x62, 0x30, 0x8, 0xf4, 0xdf, 0xc0, 0x16, 0x2f, 0xc6, 0x2e, 0xd1, 0x2c, 0xce, 0x1, 0x8c, 0xd, 0x9d, 0x1d, 0xfc, 0x1, 0x32, 0x97, 0xe0, 0x80, 0xf1, 0x2c, 0xfe, 0x2c, 0xee, 0x24, 0x31, 0x96, 0x80, 0x81, 0xe8, 0xe, 0xf1, 0x1c, 0x5e, 0x1, 0x8f, 0xef, 0x9f, 0xef, 0x22, 0xe0, 0xc2, 0x1a, 0xd1, 0x8, 0x2a, 0x2d, 0x2c, 0x1b, 0x30, 0xe0, 0x2c, 0x15, 0x3d, 0x5, 0x2c, 0xf4, 0xf5, 0x1, 0x61, 0x91, 0x5f, 0x1, 0xe1, 0xde, 0xf5, 0xcf, 0x8e, 0x15, 0x9f, 0x5, 0x9, 0xf0, 0xba, 0xc0, 0x6e, 0xef, 0x61, 0xf, 0xe8, 0x81, 0x8e, 0x2f, 0x90, 0xe0, 0xfc, 0x1, 0x31, 0x97, 0xef, 0x30, 0xf1, 0x5, 0x8, 0xf0, 0xaf, 0xc0, 0xec, 0x5d, 0xff, 0x4f, 0x9, 0x94, 0x62, 0x30, 0x39, 0xf4, 0x89, 0x81, 0x90, 0xe0, 0x90, 0x93, 0x89, 0x0, 0x80, 0x93, 0x88, 0x0, 0xa3, 0xc0, 0x82, 0xe0, 0x46, 0xc0, 0x8d, 0xe0, 0x80, 0x93, 0x7f, 0x2, 0x62, 0x30, 0x9, 0xf0, 0x9b, 0xc0, 0x89, 0x81, 0xdf, 0x91, 0xcf, 0x91, 0x1f, 0x91, 0xf, 0x91, 0xff, 0x90, 0xef, 0x90, 0xdf, 0x90, 0xcf, 0x90, 0xbf, 0x90, 0xaf, 0x90, 0xe4, 0xce, 0x64, 0x30, 0x9, 0xf0, 0x8c, 0xc0, 0x21, 0x96, 0x8b, 0xe5, 0x91, 0xe0, 0x43, 0xe3, 0x52, 0xe0, 0x23, 0xe0, 0xfe, 0x1, 0xdc, 0x1, 0x1, 0x90, 0xd, 0x92, 0x2a, 0x95, 0xe1, 0xf7, 0x3, 0x96, 0x48, 0x17, 0x59, 0x7, 0xa9, 0xf7, 0x7b, 0xc0, 0x65, 0x30, 0x9, 0xf0, 0x78, 0xc0, 0x89, 0x81, 0x90, 0xe0, 0x63, 0xe0, 0x70, 0xe0, 0x34, 0xd3, 0xdc, 0x1, 0xa5, 0x5a, 0xbe, 0x4f, 0xfe, 0x1, 0x32, 0x96, 0x93, 0xe0, 0x1, 0x90, 0xd, 0x92, 0x9a, 0x95, 0xe1, 0xf7, 0x68, 0xc0, 0x8f, 0xe0, 0xb, 0xc0, 0x8b, 0xe0, 0x9, 0xc0, 0x81, 0xe0, 0x7, 0xc0, 0x8c, 0xe0, 0x5, 0xc0, 0x88, 0xe0, 0x3, 0xc0, 0x89, 0xe0, 0x1, 0xc0, 0x8a, 0xe0, 0x80, 0x93, 0x7f, 0x2, 0x58, 0xc0, 0x62, 0x30, 0x9, 0xf0, 0x55, 0xc0, 0xc9, 0x81, 0x8c, 0xb5, 0x8f, 0x77, 0x8c, 0xbd, 0x40, 0xe0, 0x61, 0xe1, 0x8b, 0xe0, 0x93, 0xde, 0x40, 0xe8, 0x4c, 0xf, 0x60, 0xe1, 0x8b, 0xe0, 0x8e, 0xde, 0x81, 0xe1, 0x7f, 0xde, 0x80, 0x38, 0x39, 0xf0, 0x8f, 0xec, 0x97, 0xe0, 0x1, 0x97, 0xf1, 0xf7, 0x0, 0xc0, 0x0, 0x0, 0xf5, 0xcf, 0x2a, 0x98, 0x8c, 0xea, 0x6e, 0xde, 0x80, 0xe0, 0x6c, 0xde, 0x7, 0xe5, 0x12, 0xe0, 0x80, 0xe0, 0x68, 0xde, 0x8e, 0xb5, 0xf8, 0x1, 0x81, 0x93, 0x8f, 0x1, 0xf2, 0xe0, 0x7, 0x37, 0x1f, 0x7, 0xb1, 0xf7, 0x2a, 0x9a, 0x40, 0xe0, 0x61, 0xe1, 0x8b, 0xe0, 0x6d, 0xde, 0x40, 0xe4, 0x4c, 0xf, 0x60, 0xe1, 0x8b, 0xe0, 0x68, 0xde, 0x81, 0xe1, 0x59, 0xde, 0x80, 0x34, 0x39, 0xf0, 0x8f, 0xec, 0x97, 0xe0, 0x1, 0x97, 0xf1, 0xf7, 0x0, 0xc0, 0x0, 0x0, 0xf5, 0xcf, 0x2a, 0x98, 0x8c, 0xea, 0x48, 0xde, 0x80, 0xe2, 0x46, 0xde, 0xc7, 0xe3, 0xd2, 0xe0, 0x80, 0xe0, 0x42, 0xde, 0x8e, 0xb5, 0x89, 0x93, 0x92, 0xe0, 0xc7, 0x35, 0xd9, 0x7, 0xc1, 0xf7, 0x2a, 0x9a, 0x40, 0xe0, 0x61, 0xe1, 0x8b, 0xe0, 0x49, 0xde, 0x8c, 0xb5, 0x80, 0x68, 0x8c, 0xbd, 0xdf, 0x91, 0xcf, 0x91, 0x1f, 0x91, 0xf, 0x91, 0xff, 0x90, 0xef, 0x90, 0xdf, 0x90, 0xcf, 0x90, 0xbf, 0x90, 0xaf, 0x90, 0x8, 0x95, 0x1f, 0x92, 0xf, 0x92, 0xf, 0xb6, 0xf, 0x92, 0x11, 0x24, 0x8f, 0x93, 0x81, 0xe0, 0x80, 0x93, 0xf, 0x1, 0x8f, 0x91, 0xf, 0x90, 0xf, 0xbe, 0xf, 0x90, 0x1f, 0x90, 0x18, 0x95, 0x1f, 0x92, 0xf, 0x92, 0xf, 0xb6, 0xf, 0x92, 0x11, 0x24, 0x2f, 0x93, 0x3f, 0x93, 0x4f, 0x93, 0x5f, 0x93, 0x6f, 0x93, 0x7f, 0x93, 0x8f, 0x93, 0x9f, 0x93, 0xaf, 0x93, 0xbf, 0x93, 0xef, 0x93, 0xff, 0x93, 0x80, 0x91, 0xb9, 0x0, 0x88, 0x39, 0x9, 0xf4, 0x83, 0xc0, 0xc0, 0xf4, 0x88, 0x37, 0x9, 0xf4, 0x5c, 0xc0, 0x50, 0xf4, 0x88, 0x36, 0x9, 0xf4, 0x58, 0xc0, 0x80, 0x37, 0x9, 0xf4, 0x55, 0xc0, 0x80, 0x36, 0x9, 0xf0, 0x79, 0xc0, 0x51, 0xc0, 0x88, 0x38, 0x9, 0xf4, 0x71, 0xc0, 0x80, 0x39, 0x9, 0xf4, 0x4e, 0xc0, 0x80, 0x38, 0x9, 0xf0, 0x6f, 0xc0, 0x4a, 0xc0, 0x88, 0x3b, 0x91, 0xf1, 0x58, 0xf4, 0x88, 0x3a, 0x99, 0xf0, 0x80, 0x3b, 0x89, 0xf0, 0x80, 0x3a, 0x9, 0xf0, 0x64, 0xc0, 0x85, 0xed, 0x80, 0x93, 0xbc, 0x0, 0x4b, 0xc0, 0x88, 0x3c, 0x9, 0xf4, 0x57, 0xc0, 0x88, 0x3f, 0x9, 0xf4, 0x61, 0xc0, 0x80, 0x3c, 0x9, 0xf0, 0x57, 0xc0, 0x50, 0xc0, 0x10, 0x92, 0xa9, 0x2, 0xe0, 0x91, 0xa7, 0x2, 0xf0, 0x91, 0xa8, 0x2, 0x30, 0x97, 0x49, 0xf0, 0x84, 0xe2, 0x80, 0x93, 0xa6, 0x2, 0x66, 0xea, 0x72, 0xe0, 0x82, 0xe8, 0x92, 0xe0, 0x9, 0x95, 0x2, 0xc0, 0x10, 0x92, 0xa6, 0x2, 0x80, 0x91, 0xa6, 0x2, 0x81, 0x11, 0x5, 0xc0, 0x81, 0xe0, 0x80, 0x93, 0xa6, 0x2, 0x10, 0x92, 0x82, 0x2, 0xe0, 0x91, 0xa9, 0x2, 0x81, 0xe0, 0x8e, 0xf, 0x80, 0x93, 0xa9, 0x2, 0xf0, 0xe0, 0xee, 0x57, 0xfd, 0x4f, 0x80, 0x81, 0x80, 0x93, 0xbb, 0x0, 0x90, 0x91, 0xa9, 0x2, 0x80, 0x91, 0xa6, 0x2, 0x98, 0x17, 0x20, 0xf5, 0x21, 0xc0, 0x10, 0x92, 0xa9, 0x2, 0x1e, 0xc0, 0xe0, 0x91, 0xa9, 0x2, 0xe4, 0x32, 0xe0, 0xf4, 0x81, 0xe0, 0x8e, 0xf, 0x80, 0x93, 0xa9, 0x2, 0x80, 0x91, 0xbb, 0x0, 0xf0, 0xe0, 0xee, 0x57, 0xfd, 0x4f, 0x80, 0x83, 0xf, 0xc0, 0x80, 0x91, 0xbc, 0x0, 0x84, 0xfd, 0xfc, 0xcf, 0xe0, 0x91, 0x80, 0x2, 0xf0, 0x91, 0x81, 0x2, 0x30, 0x97, 0x29, 0xf0, 0x60, 0x91, 0xa9, 0x2, 0x82, 0xe8, 0x92, 0xe0, 0x9, 0x95, 0x85, 0xec, 0x1, 0xc0, 0x85, 0xe8, 0x80, 0x93, 0xbc, 0x0, 0x7, 0xc0, 0x85, 0xed, 0x80, 0x93, 0xbc, 0x0, 0x80, 0x91, 0xbc, 0x0, 0x84, 0xfd, 0xfc, 0xcf, 0xff, 0x91, 0xef, 0x91, 0xbf, 0x91, 0xaf, 0x91, 0x9f, 0x91, 0x8f, 0x91, 0x7f, 0x91, 0x6f, 0x91, 0x5f, 0x91, 0x4f, 0x91, 0x3f, 0x91, 0x2f, 0x91, 0xf, 0x90, 0xf, 0xbe, 0xf, 0x90, 0x1f, 0x90, 0x18, 0x95, 0x1f, 0x92, 0xf, 0x92, 0xf, 0xb6, 0xf, 0x92, 0x11, 0x24, 0x8f, 0x93, 0x9f, 0x93, 0xef, 0x93, 0xff, 0x93, 0x80, 0x91, 0x59, 0x1, 0x90, 0x91, 0x5a, 0x1, 0x81, 0x30, 0x91, 0x5, 0x99, 0xf0, 0x48, 0xf0, 0x82, 0x30, 0x91, 0x5, 0xc1, 0xf0, 0x3, 0x97, 0x9, 0xf0, 0x50, 0xc0, 0x1e, 0xbc, 0x2a, 0x9a, 0x4d, 0xc0, 0x2a, 0x98, 0x0, 0x0, 0x80, 0x91, 0x58, 0x1, 0x80, 0x5e, 0x8e, 0xbd, 0x81, 0xe0, 0x90, 0xe0, 0x4, 0xc0, 0x80, 0xe2, 0x8e, 0xbd, 0x82, 0xe0, 0x90, 0xe0, 0x90, 0x93, 0x5a, 0x1, 0x80, 0x93, 0x59, 0x1, 0x3f, 0xc0, 0xe0, 0x91, 0x58, 0x1, 0x80, 0x91, 0x57, 0x1, 0xf0, 0xe0, 0xf6, 0x95, 0xfe, 0x2f, 0xee, 0x27, 0xf7, 0x95, 0xe7, 0x95, 0xe8, 0xf, 0xf1, 0x1d, 0xea, 0x59, 0xff, 0x4f, 0xe4, 0x91, 0xe0, 0x93, 0x56, 0x1, 0x80, 0x91, 0x56, 0x1, 0x8f, 0x3f, 0x11, 0xf4, 0x1e, 0xbc, 0x7, 0xc0, 0xe0, 0x91, 0x56, 0x1, 0xf0, 0xe0, 0xe5, 0x5a, 0xfe, 0x4f, 0x80, 0x81, 0x8e, 0xbd, 0x80, 0x91, 0x57, 0x1, 0x8f, 0x5f, 0x80, 0x93, 0x57, 0x1, 0x80, 0x91, 0x57, 0x1, 0x80, 0x38, 0xc1, 0xf4, 0x83, 0xe0, 0x90, 0xe0, 0x90, 0x93, 0x5a, 0x1, 0x80, 0x93, 0x59, 0x1, 0x10, 0x92, 0x57, 0x1, 0x80, 0x91, 0x58, 0x1, 0x8f, 0x5f, 0x80, 0x93, 0x58, 0x1, 0x80, 0x91, 0x58, 0x1, 0x82, 0x30, 0x39, 0xf4, 0x10, 0x92, 0x58, 0x1, 0x4, 0xc0, 0x10, 0x92, 0x5a, 0x1, 0x10, 0x92, 0x59, 0x1, 0xff, 0x91, 0xef, 0x91, 0x9f, 0x91, 0x8f, 0x91, 0xf, 0x90, 0xf, 0xbe, 0xf, 0x90, 0x1f, 0x90, 0x18, 0x95, 0x8c, 0xe6, 0x84, 0xb9, 0x2e, 0x9a, 0x2a, 0x9a, 0x2a, 0x9a, 0x8f, 0xec, 0x97, 0xe0, 0x1, 0x97, 0xf1, 0xf7, 0x0, 0xc0, 0x0, 0x0, 0x81, 0xe5, 0x8c, 0xbd, 0x9d, 0xb5, 0x81, 0xe0, 0x89, 0x27, 0x8d, 0xbd, 0x40, 0xe0, 0x6a, 0xe0, 0x8b, 0xe0, 0xee, 0xdc, 0x8b, 0xe1, 0xdf, 0xdc, 0x80, 0x93, 0x78, 0x2, 0x87, 0xe1, 0xdb, 0xdc, 0x80, 0x93, 0x35, 0x2, 0x40, 0xe0, 0x60, 0xe0, 0x8b, 0xe0, 0xe2, 0xdc, 0x40, 0xe1, 0x61, 0xe0, 0x8b, 0xe0, 0xde, 0xdc, 0x44, 0xee, 0x6d, 0xe0, 0x8b, 0xe0, 0xda, 0xdc, 0x41, 0xe0, 0x6e, 0xe0, 0x8b, 0xe0, 0xd6, 0xdc, 0x47, 0xe0, 0x64, 0xe1, 0x8b, 0xe0, 0xd2, 0xdc, 0x40, 0xe4, 0x65, 0xe1, 0x8b, 0xe0, 0xce, 0xdc, 0x2a, 0x98, 0x8d, 0xe2, 0xb9, 0xdc, 0x80, 0xe0, 0xb7, 0xdc, 0xc0, 0xe1, 0xd1, 0xe0, 0x0, 0xe5, 0x11, 0xe0, 0x89, 0x91, 0xb1, 0xdc, 0xc, 0x17, 0x1d, 0x7, 0xd9, 0xf7, 0x2a, 0x9a, 0x8f, 0xe3, 0xcc, 0xdc, 0xc0, 0xe2, 0x40, 0xe0, 0x6c, 0x2f, 0x80, 0xe0, 0xb8, 0xdc, 0xcf, 0x5f, 0xc0, 0x3a, 0xc9, 0xf7, 0xc0, 0xe2, 0x40, 0xe0, 0x6c, 0x2f, 0x81, 0xe0, 0xb0, 0xdc, 0xcf, 0x5f, 0xc0, 0x3a, 0xc9, 0xf7, 0xc0, 0xe0, 0x4f, 0xef, 0x6c, 0x2f, 0x80, 0xe0, 0xa8, 0xdc, 0xcf, 0x5f, 0xc0, 0x31, 0xc9, 0xf7, 0xc0, 0xe0, 0x4f, 0xef, 0x6c, 0x2f, 0x81, 0xe0, 0xa0, 0xdc, 0xcf, 0x5f, 0xc0, 0x31, 0xc9, 0xf7, 0x41, 0xe0, 0x6a, 0xe0, 0x8b, 0xe0, 0x99, 0xdc, 0x8c, 0xb5, 0x80, 0x68, 0x8c, 0xbd, 0x78, 0x94, 0x87, 0xb1, 0x8f, 0x68, 0x87, 0xb9, 0x88, 0xb1, 0x8f, 0x68, 0x88, 0xb9, 0x1a, 0xb8, 0x9f, 0xef, 0x9b, 0xb9, 0x80, 0x91, 0x81, 0x0, 0x8c, 0x60, 0x80, 0x93, 0x81, 0x0, 0x10, 0x92, 0x85, 0x0, 0x10, 0x92, 0x84, 0x0, 0x2f, 0xe0, 0x30, 0xe0, 0x30, 0x93, 0x89, 0x0, 0x20, 0x93, 0x88, 0x0, 0x80, 0x91, 0x6f, 0x0, 0x82, 0x60, 0x80, 0x93, 0x6f, 0x0, 0x78, 0x94, 0x21, 0x9a, 0x29, 0x98, 0x21, 0x98, 0x0, 0x0, 0x83, 0xb1, 0x86, 0x95, 0x81, 0x70, 0x80, 0x93, 0x36, 0x2, 0x2c, 0xe0, 0x88, 0xe1, 0xf, 0xb6, 0xf8, 0x94, 0xa8, 0x95, 0x80, 0x93, 0x60, 0x0, 0xf, 0xbe, 0x20, 0x93, 0x60, 0x0, 0x2f, 0xea, 0x31, 0xe0, 0x30, 0x93, 0x81, 0x2, 0x20, 0x93, 0x80, 0x2, 0x2f, 0xe1, 0x31, 0xe0, 0x30, 0x93, 0xa8, 0x2, 0x20, 0x93, 0xa7, 0x2, 0x20, 0x98, 0x28, 0x98, 0x83, 0xb1, 0x81, 0x70, 0x88, 0x65, 0x88, 0xf, 0x80, 0x93, 0xba, 0x0, 0x90, 0x93, 0xbb, 0x0, 0x80, 0x91, 0xb9, 0x0, 0x8e, 0x7f, 0x80, 0x93, 0xb9, 0x0, 0x80, 0x91, 0xb9, 0x0, 0x8d, 0x7f, 0x80, 0x93, 0xb9, 0x0, 0x85, 0xec, 0x80, 0x93, 0xbc, 0x0, 0x78, 0x94, 0x41, 0xe0, 0x50, 0xe0, 0xb7, 0xe4, 0xa6, 0xe8, 0xc1, 0xe0, 0x80, 0x91, 0xf, 0x1, 0x88, 0x23, 0x9, 0xf4, 0xa3, 0xc0, 0xe0, 0xe0, 0xf1, 0xe0, 0x60, 0xe0, 0x70, 0xe0, 0x0, 0xe0, 0xd0, 0xe0, 0xd4, 0x30, 0x11, 0xf4, 0x47, 0x98, 0xb, 0xc0, 0x98, 0xb1, 0x9a, 0x1, 0x6, 0x2e, 0x1, 0xc0, 0x22, 0xf, 0xa, 0x94, 0xea, 0xf7, 0x82, 0x2f, 0x80, 0x95, 0x89, 0x23, 0x88, 0xb9, 0x0, 0x0, 0x29, 0xb1, 0xd4, 0x30, 0x11, 0xf4, 0x47, 0x9a, 0x9, 0xc0, 0x38, 0xb1, 0xca, 0x1, 0x6, 0x2e, 0x1, 0xc0, 0x88, 0xf, 0xa, 0x94, 0xea, 0xf7, 0x83, 0x2b, 0x88, 0xb9, 0x12, 0x81, 0x21, 0x27, 0x90, 0x81, 0x81, 0x81, 0x89, 0x27, 0x38, 0x2f, 0x32, 0x23, 0x31, 0x83, 0x90, 0x95, 0x89, 0x2f, 0x82, 0x23, 0x80, 0x83, 0x83, 0x2b, 0x80, 0x95, 0x82, 0x23, 0x18, 0x27, 0x12, 0x83, 0x8, 0xf, 0xdf, 0x5f, 0x6f, 0x5f, 0x7f, 0x4f, 0x33, 0x96, 0xd5, 0x30, 0x51, 0xf6, 0x1, 0x11, 0x3, 0xc0, 0x10, 0x92, 0xf, 0x1, 0x1d, 0xc0, 0xf8, 0x94, 0x80, 0x91, 0x2, 0x1, 0x80, 0x95, 0x80, 0x93, 0x79, 0x2, 0x80, 0x91, 0x5, 0x1, 0x80, 0x95, 0x80, 0x93, 0x7a, 0x2, 0x80, 0x91, 0x8, 0x1, 0x80, 0x95, 0x80, 0x93, 0x7b, 0x2, 0x80, 0x91, 0xb, 0x1, 0x80, 0x95, 0x80, 0x93, 0x7c, 0x2, 0x80, 0x91, 0xe, 0x1, 0x80, 0x95, 0x80, 0x93, 0x7d, 0x2, 0xc0, 0x93, 0x7e, 0x2, 0x78, 0x94, 0x80, 0x91, 0x52, 0x1, 0x90, 0x91, 0x53, 0x1, 0x90, 0x93, 0x55, 0x1, 0x80, 0x93, 0x54, 0x1, 0x80, 0x91, 0x50, 0x1, 0x90, 0x91, 0x51, 0x1, 0x90, 0x93, 0x53, 0x1, 0x80, 0x93, 0x52, 0x1, 0x80, 0x91, 0x64, 0x0, 0x8e, 0x7f, 0x80, 0x93, 0x64, 0x0, 0xb0, 0x93, 0x7c, 0x0, 0xa0, 0x93, 0x7a, 0x0, 0x80, 0x91, 0x7a, 0x0, 0x80, 0x64, 0x80, 0x93, 0x7a, 0x0, 0x80, 0x91, 0x7a, 0x0, 0x86, 0xfd, 0xfc, 0xcf, 0x80, 0x91, 0x78, 0x0, 0x20, 0x91, 0x79, 0x0, 0x30, 0xe0, 0x32, 0x2f, 0x22, 0x27, 0x28, 0xf, 0x31, 0x1d, 0x30, 0x93, 0x51, 0x1, 0x20, 0x93, 0x50, 0x1, 0x80, 0x91, 0x54, 0x1, 0x90, 0x91, 0x55, 0x1, 0x60, 0x91, 0x52, 0x1, 0x70, 0x91, 0x53, 0x1, 0x62, 0x17, 0x73, 0x7, 0x80, 0xf0, 0x82, 0x17, 0x93, 0x7, 0x50, 0xf0, 0x68, 0x17, 0x79, 0x7, 0x8, 0xf4, 0xcb, 0x1, 0x90, 0x93, 0x34, 0x2, 0x80, 0x93, 0x33, 0x2, 0xa8, 0x95, 0x56, 0xcf, 0x26, 0x17, 0x37, 0x7, 0x18, 0xf0, 0x86, 0x17, 0x97, 0x7, 0x8, 0xf4, 0xcb, 0x1, 0x28, 0x17, 0x39, 0x7, 0x80, 0xf7, 0xc9, 0x1, 0xee, 0xcf, 0x0, 0x24, 0x55, 0x27, 0x4, 0xc0, 0x8, 0xe, 0x59, 0x1f, 0x88, 0xf, 0x99, 0x1f, 0x0, 0x97, 0x29, 0xf0, 0x76, 0x95, 0x67, 0x95, 0xb8, 0xf3, 0x71, 0x5, 0xb9, 0xf7, 0x80, 0x2d, 0x95, 0x2f, 0x8, 0x95, 0xf8, 0x94, 0xff, 0xcf, 0x0, 0x0, 0xff, 0x0, 0x0, 0xff, 0x0, 0x0, 0xff, 0x0, 0x0, 0xff, 0x0, 0x0, 0xff, 0x1, 0x50, 0x55, 0x55, 0x55, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x15, 0x54, 0x55, 0x55, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x55, 0x5, 0x55, 0x55, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x55, 0x55, 0x41, 0x55, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x55, 0x55, 0x55, 0x50, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff };
};

#endif
