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

#include "../../inc/MarlinConfig.h"

#if ENABLED(SDSUPPORT)

#include "../gcode.h"
#include "../queue.h"
#include "../../module/planner.h"
#include "../../sd/cardreader.h"
#include "../../module/printcounter.h"
#include "../../lcd/marlinui.h"

#if ENABLED(PARK_HEAD_ON_PAUSE)
  #include "../../feature/pause.h"
#endif

#if ENABLED(HOST_ACTION_COMMANDS)
  #include "../../feature/host_actions.h"
#endif

#if ENABLED(POWER_LOSS_RECOVERY)
  #include "../../feature/powerloss.h"
#endif

#if ENABLED(DGUS_LCD_UI_MKS)
  #include "../../lcd/extui/dgus/DGUSDisplayDef.h"
#endif

#include "../../MarlinCore.h" // for startOrResumeJob

struct  {
  xyze_pos_t pos;
  bool is_relative = false;
  bool is_e_relative = false;
  uint8_t ring_buffer_backup_size = 0;
  char ring_buffer_backup[BUFSIZE][MAX_CMD_SIZE];
} m25_saved_state;

/**
 * M24: Start or Resume SD Print
 */
void GcodeSuite::M24() {
  #if ENABLED(DGUS_LCD_UI_MKS)
    if ((print_job_timer.isPaused() || print_job_timer.isRunning()) && !parser.seen("ST"))
      MKS_resume_print_move();
  #endif

  #if ENABLED(POWER_LOSS_RECOVERY)
    if (parser.seenval('S')) card.setIndex(parser.value_long());
    if (parser.seenval('T')) print_job_timer.resume(parser.value_long());
  #endif

  if (card.isOnM25Pause()) {
    if (! queue.isProcessingInjectedCommand) { // ensure that M24 not in queue
      queue.inject_P(PSTR("M24"));
      return;
    }

    current_position.e = m25_saved_state.pos.e;
    destination.e = current_position.e;
    sync_plan_position_e();

    // Execute custom gcode
    queue.exhaust();
    queue.enqueue_one_now(F("M811"));
    queue.exhaust();
    set_relative_mode(false);
    do_blocking_move_to(m25_saved_state.pos);

    queue.enqueue_one_now(F("M812"));
    queue.exhaust();

    current_position.e = m25_saved_state.pos.e;
    destination.e = current_position.e;
    sync_plan_position_e();

    set_relative_mode(m25_saved_state.is_relative);
    if (m25_saved_state.is_e_relative) {
      set_e_relative();
    } else {
      set_e_absolute();
    }

    planner.synchronize();
    for(uint8_t i=0; i < m25_saved_state.ring_buffer_backup_size; i++) {
      queue.enqueue_one_now(m25_saved_state.ring_buffer_backup[i]);
    }
  }

  card.setOnM25Pause(false);

  #if ENABLED(PARK_HEAD_ON_PAUSE)
    if (did_pause_print) {
      resume_print(); // will call print_job_timer.start()
      return;
    }
  #endif

  if (card.isFileOpen()) {
    card.startOrResumeFilePrinting();            // SD card will now be read for commands
    startOrResumeJob();               // Start (or resume) the print job timer
    TERN_(POWER_LOSS_RECOVERY, recovery.prepare());
  }

  #if ENABLED(HOST_ACTION_COMMANDS)
    #ifdef ACTION_ON_RESUME
      hostui.resume();
    #endif
    TERN_(HOST_PROMPT_SUPPORT, hostui.prompt_open(PROMPT_INFO, F("Resuming SD"), FPSTR(DISMISS_STR)));
  #endif

  ui.reset_status();
}

/**
 * M25: Pause SD Print
 *
 * With PARK_HEAD_ON_PAUSE:
 *   Invoke M125 to store the current position and move to the park
 *   position. M24 will move the head back before resuming the print.
 */
void GcodeSuite::M25() {
  if (! queue.isProcessingInjectedCommand) { // ensure that M25 not in queue
    queue.inject_P(PSTR("M25"));
    return;
  }
  #if ENABLED(PARK_HEAD_ON_PAUSE)
    M125();
  #else
    // Set initial pause flag to prevent more commands from landing in the queue while we try to pause
    #if ENABLED(SDSUPPORT)
      if (IS_SD_PRINTING()) card.pauseSDPrint();
    #endif

    #if ENABLED(POWER_LOSS_RECOVERY) && DISABLED(DGUS_LCD_UI_MKS)
      if (recovery.enabled) recovery.save(true);
    #endif

    print_job_timer.pause();

    TERN_(DGUS_LCD_UI_MKS, MKS_pause_print_move());

    IF_DISABLED(DWIN_CREALITY_LCD, ui.reset_status());

    #if ENABLED(HOST_ACTION_COMMANDS)
      TERN_(HOST_PROMPT_SUPPORT, hostui.prompt_open(PROMPT_PAUSE_RESUME, F("Pause SD"), F("Resume")));
      #ifdef ACTION_ON_PAUSE
        hostui.pause();
      #endif
    #endif

    m25_saved_state.ring_buffer_backup_size = 0;
    while(queue.ring_buffer.occupied()) {
      char *res = queue.ring_buffer.pop_next_command_string();
      strcpy(m25_saved_state.ring_buffer_backup[m25_saved_state.ring_buffer_backup_size++], res);
    }
    queue.ring_buffer.clear();

    planner.synchronize();
    m25_saved_state.is_e_relative = axis_is_relative(E_AXIS);
    m25_saved_state.is_relative = axis_is_relative(X_AXIS);
    m25_saved_state.pos = current_position;
    set_relative_mode(false);
    set_e_relative();
    process_subcommands_now(F("M810"));
  #endif
  card.setOnM25Pause(true);
}

#endif // SDSUPPORT
