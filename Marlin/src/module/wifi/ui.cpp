#include "../../inc/MarlinConfigPre.h"


#if ENABLED(MKS_WIFI_MODULE)

#if ENABLED(TFT_320x480) || ENABLED(TFT_320x480_SPI)


#include "../../lcd/tft/tft.h"
#include "../../lcd/tft/tft_color.h"
#include "../../lcd/marlinui.h"
#include "../temperature.h"

#include "ui.h"

extern TFT tft;
extern const uint8_t Helvetica14[], Helvetica14_symbols[];
extern const uint8_t Helvetica18[], Helvetica18_symbols[];

void mks_update_status(uint32_t progress, uint32_t filesize) {
  static uint32_t call_count = 0;
  static uint32_t last_done = 200;
  uint8_t percent_done;
  char str[100];

  percent_done = 100 * progress / filesize;

  if (percent_done != last_done) {
    call_count++;

    sprintf(str, "LCD call %ld CF: %ld  FS: %ld", call_count, progress, filesize);
    SERIAL_ECHOLN(str);

    // DEBUG("LCD call %ld CF: %ld  FS: %ld", call_count, current_filesize, file_size);
    // tft.queue.reset();

    tft.canvas(0, 150, TFT_WIDTH, TFT_HEIGHT);
    tft.set_background(COLOR_BACKGROUND);

    // progress bar
    tft.add_bar(5, 10, (TFT_WIDTH-10)*percent_done/100, 30, COLOR_GREEN);

    // debug text
    // sprintf(str, "%ld: %ld of %ld", call_count, progress, filesize);
    // tft.add_text(20, 100, COLOR_RED, str);
    // SERIAL_ECHOLN(str);


    // progress text
    char str1[8] = "", str2[8] = "";
    if (filesize < 1024)
      sprintf(str, "%ld of %ld B (%d%%)", progress, filesize, percent_done);
    else if (filesize < 1024*1024)
      sprintf(str, "%s of %s KB (%d%%)", dtostrf(progress/1024., 4, 2, str1), dtostrf(filesize/1024., 4, 2, str2), percent_done);
    else if (filesize < 1024*1024*1024)
      sprintf(str, "%s of %s MB (%d%%)", dtostrf(progress/1024./1024., 4, 2, str1), dtostrf(filesize/1024./1024., 4, 2, str2), percent_done);
    else
      sprintf(str, "%s of %s GB (%d%%)", dtostrf(progress/1024./1024./1024., 4, 2, str1), dtostrf(filesize/1024./1024./1024., 4, 2, str2), percent_done);


    // sprintf(str, "%s of %s KB (%d%%)", dtostrf(progress/1024./1024., 4, 2, str1), dtostrf(filesize/1024./1024., 4, 2, str2), percent_done);
    tft.add_text(20, 15, COLOR_WHITE, str);
    // SERIAL_ECHOLN(str);
    // SERIAL_FLUSH();

    // sprintf(str, "%3.2f of %3.2f MB (%d%%)", csize, fsize, (uint8_t)percent_done);

    // char tmpstr1[10], tmpstr2[10];
    // if (file_size >= (1024*1024*1024)) {
    //   fsize /= 1024*1024*1024;
    //   csize /= 1024*1024*1024;
    //   // dtostrf(file_size/(1024*1024*1024), 5, 2, tmpstr1);
    //   // dtostrf(current_filesize/(1024*1024*1024), 5, 2, tmpstr2);
    //   // sprintf(str, "%s of %s GB (%d%%)", tmpstr2, tmpstr1, (uint8_t)percent_done);
    //   sprintf(str, "%.2f of %.2f GB (%d%%)", csize, fsize, (uint8_t)percent_done);
    // }
    // else if (file_size >= (1024*1024)) {
    //   fsize /= 1024*1024;
    //   csize /= 1024*1024;
    //   // dtostrf(file_size/(1024*1024), 5, 2, tmpstr1);
    //   // dtostrf(current_filesize/(1024*1024), 5, 2, tmpstr2);
    //   // sprintf(str, "%s of %s MB (%d%%)", tmpstr2, tmpstr1, (uint8_t)percent_done);
    //   sprintf(str, "%3.2Lf of %3.2Lf MB (%d%%)", csize, fsize, (uint8_t)percent_done);
    // }
    // else if (file_size >= 1024) {
    //   fsize /= 1024;
    //   csize /= 1024;
    //   // dtostrf(file_size/1024, 5, 2, tmpstr1);
    //   // dtostrf(current_filesize/1024, 5, 2, tmpstr2);
    //   // sprintf(str, "%s of %s KB (%d%%)", tmpstr2, tmpstr1, (uint8_t)percent_done);
    //   sprintf(str, "%.2f of %.2f KB (%d%%)", floor(current_filesize)/1024, floor(file_size)/1024, (uint8_t)percent_done);
    // } else sprintf(str, "%ld of %ld B (%d%%)", current_filesize, file_size, (uint8_t)percent_done);

    // sprintf(str, "%ld of %ld (%d%%)", csize, fsize, (uint8_t)percent_done);

    // sprintf(str, "%ld of %ld B (%d%%)", progress, filesize, (uint8_t)percent_done);
    // tft.add_text(20, 15, COLOR_WHITE, str);

    tft.queue.sync();
    last_done = percent_done;
    //ui.update();
  };

}


void mks_upload_screen(char *filename) {
  char str[100];

  thermalManager.disable_all_heaters();
  thermalManager.task();

  tft.queue.reset();
  tft.canvas(0, 0, TFT_WIDTH, TFT_HEIGHT);
  tft.set_background(COLOR_BACKGROUND);
  tft.set_font(Helvetica14);


  tft.add_text(20, 100, COLOR_GREEN, "Uploading");
  sprintf(str, "%s", filename);
  tft.add_text(20, 125, COLOR_WHITE, str);

  sprintf(str, "Upload started: %s", filename);

  SERIAL_ECHOLN(str);
  SERIAL_FLUSH();

  // tft.queue.reset();
  // tft.canvas(0, 0, TFT_WIDTH, TFT_HEIGHT);
  // tft.set_background(COLOR_BACKGROUND);
  // tft.add_text(8, 100, COLOR_WHITE, "Uploading...");
  tft.queue.sync();
}


void mks_end_transmit(void){
  SERIAL_ECHOLN("Upload finished");
  SERIAL_FLUSH();

  tft.queue.reset();
  tft.fill(0, 0, TFT_WIDTH, TFT_HEIGHT, COLOR_BACKGROUND);
  tft.set_font(Helvetica18);
  tft.add_glyphs(Helvetica18_symbols);
  tft.queue.sync();
}

#endif // TFT_320x480
#endif // MKS_WIFI_MODULE
