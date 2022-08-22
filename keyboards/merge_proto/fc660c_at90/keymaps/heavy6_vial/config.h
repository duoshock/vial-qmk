/* Copyright 2017 Balz Guenat
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

#pragma once

// place overrides here

#define VIAL_KEYBOARD_UID {0xFA, 0x28, 0xDE, 0xC0, 0x94, 0xBE, 0x42, 0xA5}

#define VIAL_UNLOCK_COMBO_ROWS { 1, 4 }
#define VIAL_UNLOCK_COMBO_COLS { 3, 14 }

#ifdef PRODUCT
#undef PRODUCT
#define PRODUCT         Heavy-6 AT90USB1286 Vial
#endif

#ifdef AUDIO_ENABLE
#define AUDIO_PIN C4
#    define STARTUP_SONG SONG(STARTUP_SOUND)
#endif

#define DYNAMIC_KEYMAP_LAYER_COUNT 5