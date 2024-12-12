<p align="center"><img src="buildroot/share/pixmaps/logo/flying_bear.svg" height="250" alt="Flying Bear logo" /></p>

<h1 align="center">Flying Bear 3D Printer Custom Firmware</h1>

<p align="center">
    <a href="/LICENSE"><img alt="GPL-V3.0 License" src="https://img.shields.io/github/license/marlinfirmware/marlin.svg"></a>
    <a href="https://github.com/FB-G6/Marlin/releases"><img alt="Last Release Date" src="https://img.shields.io/github/release-date/FB-G6/Marlin"></a>
    <a href="https://github.com/FB-G6/Marlin/actions"><img alt="CI Status" src="https://github.com/FB-G6/Marlin/actions/workflows/release.yml/badge.svg"></a>
</p>

## FB-G6 (Marlin) description:

Custom firmware for FBG6 (ColorUI interface).

## Features / Функциональность

* Based on Marlin 2.1.2
* Linear Advance enabled
* MKS WiFi module
* Prebuild versions for bltouch available
* Languages: 🇬🇧/🇷🇺

#### Changelog
See [releases page](https://github.com/FB-G6/Marlin/releases).

### Supported 3D Printers

  Platform|3D printer
  --------|---
  [STM32F407 - STM32F417](https://www.st.com/en/microcontrollers-microprocessors/stm32f407-417.html) ARM® Cortex-M4|Flying bear Ghost 6

## Firmware installation / Установка прошивки
 🇬🇧
1. Download required version from [releases page](https://github.com/FB-G6/Marlin/releases).
2.  Unpack `firmware.bin` into the root of printer's microsd flash card.
3.  Insert flash card into the printer and turn on the power.
4.  After successful installation, you need to re-initialize the EEPROM: `Settings -> Advanced Settings -> Initialize EEPROM`.

___
 🇷🇺 
1. Скачать со [страницы релизов](https://github.com/FB-G6/Marlin/releases) требуемую версию под нужный термистор.
2. Распаковать `firmware.bin` из скачанного архив в корень microsd-карточки принтера.
3. Вставить microsd в принтер и включить питание.
4. После установки рекомендуется переинициализировать EEPROM: нажать на зеленую галку если принтер предложит это сделать при включении или `Настройки -> Другие настройки -> Инициализ. EEPROM`.

## BLTouch / 3DTouch


Mount adapters:
* [3D Touch mount by Pavletto](https://www.thingiverse.com/thing:5660302/)
* [Back plate 3D Touch mount by Ryoko](https://www.thingiverse.com/thing:5744744/)

 🇬🇧 Install bltouch version of this firmware. Connecting module with board: The 2-pin connector from bltouch should be connected to the printer board in place of the Z endstop (marked `Z-` on the board).  3-pin connector - in the lower left corner (relative to the side of the printer) of the board, next to the bltouch marking. To access the connector, you need to remove the buzzer from the first revision of the printer.  Check wire labels.
 ___
 🇷🇺 **[Документация на Wiki](https://github.com/FB-G6/Marlin/wiki/%D0%A0%D0%B0%D0%B1%D0%BE%D1%82%D0%B0-%D1%81-BLTouch)**
 Требуется установить bltouch-версию этой прошивки. Подключение датчика:
2х контактный разъем от bltouch следует подключать в плату принтера вместо концевика Z (на плате маркировка `Z-`).
3х контактный разъем -- в нижний левый угол (относительно стороны принтера) платы, рядом с маркировкой bltouch. Для доступа к разъему требуется снять пищалку с первой ривизии принтера.
Сверьте маркировку проводов.


## FB-G6 (Marlin) Support

The Issue Queue is reserved for Bug Reports and Feature Requests. To get help with configuration and troubleshooting, please use the following resources:

- [FB-G6 (Marlin)](https://t.me/fbg6_s) - Discuss in Telegram issues with FB-G6 (Marlin) users and developers (russian-speaking community)
- [Marlin Configuration](https://www.youtube.com/results?search_query=marlin+configuration) on YouTube
- [Marlin Documentation](https://marlinfw.org) - Official Marlin documentation

## Administration

Regular users can open and close their own issues, but only the administrators can do project-related things like add labels, merge changes, set milestones, and kick trolls. The current FB-G6 (Marlin) admin team consists of:

FlyingBear Ghost 6 Marlin
FBG6 Marlin
Ghost 6 Marlin

<table align="center">
<tr>
<td>

 🇷🇺  **Kirill**
       [@adequator](https://github.com/adequator)

</td>
<td>

 🇷🇺  **Pavel**
       [@Zar_Asura](https://github.com/Zar-Asura)

</td>
<td>

 🇷🇺  **Vladimir**
       [@big-vl](https://github.com/big-vl)

</td>
</tr>
</table>


## Building FB-G6 (Marlin)

**Install PlatformIO**

Linux:
```
source ~/.platformio/penv/bin/activate
platformio run -e mks_robin_nano_v3
```

Simulator mode (Linux):
```
# Activate virtual env
source ~/.platformio/penv/bin/activate
# Change Configuration.h un comment
# #define MOTHERBOARD BOARD_LINUX_RAMPS  // Config for Simulator mode
# Run and build simulator
platformio run -e simulator_linux_release
# Run simulator mode
.pio/build/simulator_linux_release/MarlinSimulator
```

## License

FB-G6 (Marlin) is published under the [GPL license](/LICENSE) because we believe in open development. The GPL comes with both rights and obligations. Whether you use FB-G6 (Marlin) firmware as the driver for your open or closed-source product, you must keep FB-G6 (Marlin) open, and you must provide your compatible FB-G6 (Marlin) source code to end users upon request. The most straightforward way to comply with the FB-G6 (Marlin) license is to make a fork of FB-G6 (Marlin) on Github, perform your modifications, and direct users to your modified fork.

While we can't prevent the use of this code in products (3D printers, CNC, etc.) that are closed source or crippled by a patent, we would prefer that you choose another firmware or, better yet, make your own.
