/* Copyright 2021 duoshock 
 * 
 * This program is free software: you can redistribute it and/or modify 
 * it under the terms of the GNU General Public License as published by 
 * the Free Software Foundation, either version 2 of the License, or 
 * (at your option) any later version. 
 * 
 * This program is distributed in the hope that it will be useful, 
 * but WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
 * GNU General Public License for more details. 
 * 
 * You should have received a copy of the GNU General Public License 
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "config_common.h"

#define VENDOR_ID       0x4D65
#define PRODUCT_ID      0x4401
#define DEVICE_VER      0x0001
#define MANUFACTURER    Merge
#define PRODUCT         M-85_Proto_v3

#define MATRIX_ROWS 6
#define MATRIX_COLS 15

#define MATRIX_ROW_PINS { A0, A1, A2, A3, A4, A5 }
#define MATRIX_COL_PINS { C0, C1, C2, C3, C4, C5, C6, C7, F0, F1, F2, F3, F4, F5, F6 }
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

#define RGB_DI_PIN B5
#define RGBLED_NUM 84
#define RGBLIGHT_SLEEP
#define RGBLIGHT_LIMIT_VAL 120

#ifdef RGB_MATRIX_ENABLE
    #define DRIVER_LED_TOTAL RGBLED_NUM
    #define RGB_MATRIX_MAXIMUM_BRIGHTNESS RGBLIGHT_LIMIT_VAL
#endif

#define DEBOUNCE 5

#define AUDIO_PIN B6

#ifdef AUDIO_ENABLE
    #define STARTUP_SONG SONG(STARTUP_SOUND)
#endif

#ifdef OLED_ENABLE
  #define OLED_DISPLAY_128X64
#endif

#define ENCODERS_PAD_A { A6 }
#define ENCODERS_PAD_B { A7 }

#define BOOTMAGIC_LITE_ROW 0
#define BOOTMAGIC_LITE_COLUMN 0