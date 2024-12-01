/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */
#pragma once

////////////////////////////
// VENDOR VERSION EXAMPLE //
////////////////////////////

#if TEMP_SENSOR_0 == 5
#define THERMISTOR_NAME "104GT"
#elif TEMP_SENSOR_0 == 13
#define THERMISTOR_NAME "3950"
#endif


#if CONFIGURE_FB_G6_BLTOUCH == 1
#define SHORT_BUILD_VERSION "2.0.1 - bltouch"
#else
#define SHORT_BUILD_VERSION "2.0.1"
#endif

#define MACHINE_NAME "FlyingBear Ghost 6"
#define SOURCE_CODE_URL "github.com/Sidiusz/Marlin-FBG6"
#define STRING_DISTRIBUTION_DATE "18-11-2024"
