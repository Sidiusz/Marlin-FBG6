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

#include "../../inc/MarlinConfigPre.h"

#if HAS_GRAPHICAL_TFT

#include "tft_image.h"
#include "ui_common.h"

const tImage NoLogo                 = { nullptr, 0, 0, NOCOLORS };

#if ENABLED(SHOW_BOOTSCREEN)
  const tImage MarlinLogo112x38x1   = { (void *)marlin_logo_112x38x1, 112, 38, GREYSCALE1 };
  const tImage MarlinLogo228x255x2  = { (void *)marlin_logo_228x255x2, 228, 255, GREYSCALE2 };
  const tImage MarlinLogo228x255x4  = { (void *)marlin_logo_228x255x4, 228, 255, GREYSCALE4 };
  const tImage MarlinLogo195x59x16  = { (void *)marlin_logo_195x59x16,  195,  59, HIGHCOLOR };
  const tImage MarlinLogo320x240x16 = { (void *)marlin_logo_320x240x16, 320, 240, HIGHCOLOR };
  const tImage MarlinLogo480x320x16 = { (void *)marlin_logo_480x320x16, 480, 320, HIGHCOLOR };

  const tImage FBLogo200x220x4      = { (void *)fb_logo_200x220x4, 200, 220, GREYSCALE4 };

#endif
const tImage Background320x30x16    = { (void *)background_320x30x16, 320, 30, HIGHCOLOR };

const tImage HotEnd_64x64x4         = { (void *)hotend_64x64x4, 64, 64, GREYSCALE4 };
const tImage Bed_64x64x4            = { (void *)bed_64x64x4, 64, 64, GREYSCALE4 };
const tImage Bed_Heated_64x64x4     = { (void *)bed_heated_64x64x4, 64, 64, GREYSCALE4 };
const tImage Chamber_64x64x4        = { (void *)chamber_64x64x4, 64, 64, GREYSCALE4 };
const tImage Chamber_Heated_64x64x4 = { (void *)chamber_heated_64x64x4, 64, 64, GREYSCALE4 };
const tImage Fan0_64x64x4           = { (void *)fan0_64x64x4, 64, 64, GREYSCALE4 };
const tImage Fan1_64x64x4           = { (void *)fan1_64x64x4, 64, 64, GREYSCALE4 };
const tImage Fan_Slow0_64x64x4      = { (void *)fan_slow0_64x64x4, 64, 64, GREYSCALE4 };
const tImage Fan_Slow1_64x64x4      = { (void *)fan_slow1_64x64x4, 64, 64, GREYSCALE4 };
const tImage Fan_Fast0_64x64x4      = { (void *)fan_fast0_64x64x4, 64, 64, GREYSCALE4 };
const tImage Fan_Fast1_64x64x4      = { (void *)fan_fast1_64x64x4, 64, 64, GREYSCALE4 };
const tImage SD_64x64x4             = { (void *)sd_64x64x4, 64, 64, GREYSCALE4 };
const tImage Home_64x64x4           = { (void *)home_64x64x4, 64, 64, GREYSCALE4 };
const tImage BtnRounded_64x52x4     = { (void *)btn_rounded_64x52x4, 64, 52, GREYSCALE4 };
const tImage BtnRounded_42x39x4     = { (void *)btn_rounded_42x39x4, 42, 39, GREYSCALE4 };
const tImage BtnRounded_90x64x4     = { (void *)btn_rounded_90x64x4, 90, 64, GREYSCALE4 };
const tImage BtnRounded_120x64x4    = { (void *)btn_rounded_120x64x4, 120, 64, GREYSCALE4 };
const tImage Menu_64x64x4           = { (void *)menu_64x64x4, 64, 64, GREYSCALE4 };
const tImage Settings_64x64x4       = { (void *)settings_64x64x4, 64, 64, GREYSCALE4 };
const tImage Confirm_80x40x4        = { (void *)confirm_80x40x4, 80, 40, GREYSCALE4 };
const tImage Cancel_80x40x4         = { (void *)cancel_80x40x4, 80, 40, GREYSCALE4 };
const tImage Increase_80x40x4       = { (void *)increase_80x40x4, 80, 40, GREYSCALE4 };
const tImage Decrease_80x40x4       = { (void *)decrease_80x40x4, 80, 40, GREYSCALE4 };
const tImage Pause_64x64x4          = { (void *)pause_64x64x4, 64, 64, GREYSCALE4 };
const tImage Resume_64x64x4         = { (void *)resume_64x64x4, 64, 64, GREYSCALE4 };
const tImage Stop_64x64x4           = { (void *)stop_64x64x4, 64, 64, GREYSCALE4 };
const tImage Babystep_64x64x4       = { (void *)babystep_64x64x4, 64, 64, GREYSCALE4 };
const tImage Tune_64x64x4           = { (void *)tune_64x64x4, 64, 64, GREYSCALE4 };
const tImage Tramming_64x64x4       = { (void *)tramming_64x64x4, 64, 64, GREYSCALE4 };
const tImage Point_40x40x4          = { (void *)point_40x40x4, 40, 40, GREYSCALE4 };
const tImage Power_64x64x4          = { (void *)power_64x64x4, 64, 64, GREYSCALE4 };
const tImage Move_64x64x4           = { (void *)move_64x64x4, 64, 64, GREYSCALE4 };
const tImage Wifi_64x64x4           = { (void *)wifi_64x64x4, 64, 64, GREYSCALE4 };
const tImage Feedrate_32x32x4       = { (void *)feedrate_32x32x4, 32, 32, GREYSCALE4 };
const tImage Feedrate_64x64x4       = { (void *)feedrate_64x64x4, 64, 64, GREYSCALE4 };
const tImage Flowrate_32x32x4       = { (void *)flowrate_32x32x4, 32, 32, GREYSCALE4 };
const tImage Flowrate_64x64x4       = { (void *)flowrate_64x64x4, 64, 64, GREYSCALE4 };
const tImage Directory_32x32x4      = { (void *)directory_32x32x4, 32, 32, GREYSCALE4 };
const tImage Back_32x32x4           = { (void *)back_32x32x4, 32, 32, GREYSCALE4 };
const tImage Back_Big_80x40x4       = { (void *)back_big_80x40x4, 80, 40, GREYSCALE4 };
const tImage Up_32x32x4             = { (void *)up_32x32x4, 32, 32, GREYSCALE4 };
const tImage Up_Big_80x40x4         = { (void *)up_big_80x40x4, 80, 40, GREYSCALE4 };
const tImage Down_32x32x4           = { (void *)down_32x32x4, 32, 32, GREYSCALE4 };
const tImage Down_Big_80x40x4       = { (void *)down_big_80x40x4, 80, 40, GREYSCALE4 };
const tImage Left_32x32x4           = { (void *)left_32x32x4, 32, 32, GREYSCALE4 };
const tImage Right_32x32x4          = { (void *)right_32x32x4, 32, 32, GREYSCALE4 };
const tImage Refresh_32x32x4        = { (void *)refresh_32x32x4, 32, 32, GREYSCALE4 };
const tImage Leveling_32x32x4       = { (void *)leveling_32x32x4, 32, 32, GREYSCALE4 };
const tImage Zoffset_64x64x4        = { (void *)zoffset_64x64x4, 64, 64, GREYSCALE4 };
const tImage Zoffset_32x32x4        = { (void *)zoffset_32x32x4, 32, 32, GREYSCALE4 };
const tImage Light_64x64x4          = { (void *)light_64x64x4, 64, 64, GREYSCALE4 };
const tImage Next_64x64x4           = { (void *)next_64x64x4, 64, 64, GREYSCALE4 };
const tImage Prevous_64x64x4        = { (void *)prevous_64x64x4, 64, 64, GREYSCALE4 };
const tImage Fila_64x64x4           = { (void *)fila_64x64x4, 64, 64, GREYSCALE4 };
const tImage Language_64x64x4       = { (void *)language_64x64x4, 64, 64, GREYSCALE4 };
const tImage Info_64x64x4           = { (void *)info_64x64x4, 64, 64, GREYSCALE4 };
const tImage Save_64x64x4           = { (void *)save_64x64x4, 64, 64, GREYSCALE4 };
const tImage Is_64x64x4             = { (void *)is_64x64x4, 64, 64, GREYSCALE4 };
const tImage La_64x64x4             = { (void *)la_64x64x4, 64, 64, GREYSCALE4 };
const tImage Slider8x16x4           = { (void *)slider_8x16x4, 8, 16, GREYSCALE4 };

const tImage Images[imgCount] = {
  FBLogo200x220x4,
  //TERN(SHOW_BOOTSCREEN, TERN(BOOT_MARLIN_LOGO_SMALL, MarlinLogo195x59x16, MARLIN_LOGO_FULL_SIZE), NoLogo),
  HotEnd_64x64x4,
  Bed_64x64x4,
  Bed_Heated_64x64x4,
  Chamber_64x64x4,
  Chamber_Heated_64x64x4,
  Fan0_64x64x4,
  Fan_Slow0_64x64x4,
  Fan_Slow1_64x64x4,
  Fan_Fast0_64x64x4,
  Fan_Fast1_64x64x4,
  Feedrate_32x32x4,
  Feedrate_64x64x4,
  Flowrate_32x32x4,
  Flowrate_64x64x4,
  SD_64x64x4,
  Menu_64x64x4,
  Settings_64x64x4,
  Directory_32x32x4,
  Confirm_80x40x4,
  Cancel_80x40x4,
  Increase_80x40x4,
  Decrease_80x40x4,
  Back_32x32x4,
  Back_Big_80x40x4,
  Up_32x32x4,
  Up_Big_80x40x4,
  Down_32x32x4,
  Down_Big_80x40x4,
  Left_32x32x4,
  Right_32x32x4,
  Refresh_32x32x4,
  Leveling_32x32x4,
  Slider8x16x4,
  Home_64x64x4,
  BtnRounded_64x52x4,
  BtnRounded_42x39x4,
  BtnRounded_90x64x4,
  BtnRounded_120x64x4,
  Wifi_64x64x4,
  Pause_64x64x4,
  Move_64x64x4,  
  Resume_64x64x4,
  Stop_64x64x4,
  Babystep_64x64x4,
  Tune_64x64x4,
  Tramming_64x64x4,
  Point_40x40x4,
  Power_64x64x4,
  Zoffset_64x64x4,
  Zoffset_32x32x4, 
  Light_64x64x4,
  Next_64x64x4,
  Prevous_64x64x4,
  Fila_64x64x4,
  Language_64x64x4,
  Info_64x64x4,
  Save_64x64x4,
  Is_64x64x4,
  La_64x64x4,
};

#endif // HAS_GRAPHICAL_TFT
