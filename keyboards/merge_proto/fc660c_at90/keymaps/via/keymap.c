/*
Copyright 2017 Balz Guenat

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include QMK_KEYBOARD_H

enum layer_names {
    _BASE,
    _ONE,
    _TWO,
    _THREE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
            KC_ESC, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL, KC_BSPC,     KC_INS,
            KC_TAB, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,KC_RBRC,KC_BSLS,     KC_DEL,
    KC_F3,  KC_CAPS,KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,     KC_ENT,
    KC_F4,  KC_LSFT,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_RSFT,     KC_UP,
    KC_F5,  KC_LCTL,KC_LGUI,KC_LALT,     KC_F1,     KC_SPC,     KC_F2,       KC_RALT,KC_RGUI,KC_RCTL,      KC_LEFT,KC_DOWN,KC_RGHT
    ),
  [_ONE] = LAYOUT(
                    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,     _______,
                    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,     _______,
    _______,        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,     _______,
    _______,        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,    _______,      _______,
    _______,        _______,_______,_______,    _______,     _______,      _______,      _______,_______,_______,      _______,_______,_______
    ),
  [_TWO] = LAYOUT(
                    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,     _______,
                    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,     _______,
    _______,        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,     _______,
    _______,        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,    _______,      _______,
    _______,        _______,_______,_______,    _______,     _______,      _______,      _______,_______,_______,      _______,_______,_______
    ),
  [_THREE] = LAYOUT(
                    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,     _______,
                    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,     _______,
    _______,        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,     _______,
    _______,        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,    _______,      _______,
    _______,        _______,_______,_______,    _______,     _______,      _______,      _______,_______,_______,      _______,_______,_______
    )
};


#ifdef OLED_ENABLE
void suspend_power_down_user(void) {
    oled_off();
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_90;
    }

    return rotation;
}

// 32 * 18 Merge logos
static const char PROGMEM merge_logo[] = {
    0xf8, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x0e,
    0x06, 0x04, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfc, 0xf8, 0xf0, 0xc0,
    0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xc0,
    0x80, 0x80, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x3f, 0x0f,
    0x00, 0x01, 0x01, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x01,
    0x01, 0x00, 0x01, 0x01, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00
};

uint8_t current_wpm = 0;

static void print_status_narrow(void) {
    oled_set_cursor(0,1);
    oled_write_raw_P(merge_logo, sizeof(merge_logo));
    oled_set_cursor(0,5);
    oled_write_P(PSTR("-----"), false);
    oled_set_cursor(0,6);
    oled_write_P(PSTR("LYR "), false);
    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_P(PSTR("0"), false);
            break;
        case _ONE:
            oled_write_P(PSTR("1"), false);
            break;
        case _TWO:
            oled_write_P(PSTR("2"), false);
            break;
        case _THREE:
            oled_write_P(PSTR("3"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR(" "), false);
    oled_write_P(PSTR("CAP "), false);
    oled_write_P(PSTR("."), led_usb_state.caps_lock);
    oled_write_P(PSTR("NUM "), false);
    oled_write_P(PSTR("."), led_usb_state.num_lock);
    oled_write_P(PSTR("SCR "), false);
    oled_write_P(PSTR("."), led_usb_state.scroll_lock);
    //oled_write_ln_P(PSTR(" "), false);
    oled_write_P(PSTR("-----"), false);

    // WPM counter Start
    char wpm_str[5];
    oled_set_cursor(0,13);
    wpm_str[4] = '\0';
    uint8_t n = current_wpm;
    wpm_str[3] = '0' + n % 10;
    wpm_str[2] = '0' + (n /= 10) % 10;
    wpm_str[1] = '0' + n / 10;
    wpm_str[0] = ' ';
    oled_write(wpm_str, false);
    oled_set_cursor(0,14);
    oled_write(" WPM ", false);
    // WPM counter End
}

bool oled_task_user(void) {
    current_wpm = get_current_wpm();
    print_status_narrow();
    return false;
}

#endif