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


/* Pin PB2 is used by BOOT1, and is unusable
* Pins PA9 is meant for VBUS sense, and has an internal pulldown resistor. A 5.1k pullup resistor can work (but should be avoided)
* Pins PA11 and A12 are not useable because they're used for USB connection, and can't be shared. 
*/

#include "config_common.h"

#define VENDOR_ID       0x4D65
#define PRODUCT_ID      0x4001
#define DEVICE_VER      0x0001
#define MANUFACTURER    Merge_proto
#define PRODUCT         M-70

#define MATRIX_ROWS 9
#define MATRIX_COLS 8

#define MATRIX_ROW_PINS { B12, B13, B14, B15, A8, B3, B4, B5, B6 }
#define MATRIX_COL_PINS { A0, A1, A2, A3, A4, A5, A6, A7 }
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* RGB */
#define RGB_DI_PIN B10
#define RGBLED_NUM 72
#define RGBLIGHT_SLEEP
// Split spacebar + split backspace + no encoder + macro = 72 (Full set)
// 6u space bar: -2 / 2u spacebar: -1 / encoder: -1 / no macro: -3
#ifdef RGB_MATRIX_ENABLE
    #define DRIVER_LED_TOTAL RGBLED_NUM
    #define RGB_MATRIX_MAXIMUM_BRIGHTNESS RGBLIGHT_LIMIT_VAL
#endif

#define RGBLIGHT_LIMIT_VAL 120
#define RGBLIGHT_ANIMATIONS

#define WS2812_PWM_DRIVER PWMD2
#define WS2812_PWM_CHANNEL 3
#define WS2812_PWM_PAL_MODE 1
#define WS2812_DMA_STREAM STM32_DMA1_STREAM1
#define WS2812_DMA_CHANNEL 3
//#define WS2812_EXTERNAL_PULLUP

/* i2c config for oleds */
#define I2C_DRIVER        I2CD1
#define I2C1_SCL_PIN      B8
#define I2C1_SDA_PIN      B9
#define I2C1_SCL_PAL_MODE 4
#define I2C1_SDA_PAL_MODE 4

#define DEBOUNCE 5

/* Audio config */
#define AUDIO_PIN          B1
#define AUDIO_PWM_DRIVER   PWMD3
#define AUDIO_PWM_CHANNEL  4
#define AUDIO_PWM_PAL_MODE 2
#define AUDIO_STATE_TIMER  GPTD4

#define STARTUP_SONG SONG(STARTUP_SOUND)

#define ENCODERS_PAD_A { C13 }
#define ENCODERS_PAD_B { C14 }

#define BOOTMAGIC_LITE_ROW 0
#define BOOTMAGIC_LITE_COLUMN 0