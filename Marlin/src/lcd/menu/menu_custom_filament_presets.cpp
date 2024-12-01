#include "../../inc/MarlinConfigPre.h"

#if HAS_MARLINUI_MENU

#include "menu_item.h"
#include "../../MarlinCore.h"

void menu_filament_preset_settings() {
    #define _MINTEMP_ITEM(N) HEATER_##N##_MINTEMP,
    #define _MAXTEMP_ITEM(N) HEATER_##N##_MAXTEMP,
    #define MINTEMP_ALL _MIN(REPEAT(HOTENDS, _MINTEMP_ITEM) 999)
    #define MAXTEMP_ALL _MAX(REPEAT(HOTENDS, _MAXTEMP_ITEM) 0)
    const uint8_t m = MenuItemBase::itemIndex;
    START_MENU();
    STATIC_ITEM_F(ui.get_preheat_label(m), SS_DEFAULT|SS_INVERT);
    BACK_ITEM(MSG_CUSTOM_FILAMENT_PRESETS);
    #if HAS_FAN
      editable.uint8 = uint8_t(ui.material_preset[m].fan_speed);
      EDIT_ITEM_N(percent, m, MSG_FAN_SPEED, &editable.uint8, 0, 255, []{ ui.material_preset[MenuItemBase::itemIndex].fan_speed = editable.uint8; });
    #endif
    #if HAS_TEMP_HOTEND
      EDIT_ITEM(int3, MSG_NOZZLE, &ui.material_preset[m].hotend_temp, MINTEMP_ALL, MAXTEMP_ALL - (HOTEND_OVERSHOOT));
    #endif
    #if HAS_HEATED_BED
      EDIT_ITEM(int3, MSG_BED, &ui.material_preset[m].bed_temp, BED_MINTEMP, BED_MAX_TARGET);
    #endif
    #if ENABLED(EEPROM_SETTINGS)
      ACTION_ITEM(MSG_STORE_EEPROM, ui.store_settings);
    #endif
    END_MENU();
}


void menu_custom_filament_presets() {
  START_MENU();
  BACK_ITEM(MSG_CUSTOM_BACK);
    LOOP_L_N(m, PREHEAT_COUNT)
      SUBMENU_N_f(m, ui.get_preheat_label(m), MSG_PREHEAT_M_SETTINGS, menu_filament_preset_settings);
  END_MENU();
}

#endif // HAS_MARLINUI_MENU