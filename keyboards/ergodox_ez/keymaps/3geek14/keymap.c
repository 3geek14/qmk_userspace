/* Copyright 2023 Pi Fisher
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

#include QMK_KEYBOARD_H
#include "version.h"

#define SCREEN_LEFT LCTL(LGUI(KC_LEFT))
#define SCREEN_RIGHT LCTL(LGUI(KC_RIGHT))
#define SCREENSHOT LGUI(LSFT(KC_S))

enum layers {
    BASE,	// default layer
    GAME,	// gaming
    UTIL,	// symbols
};

enum custom_keycodes {
  VRSN = SAFE_RANGE,
  RGB_SLD,
  SHRUG,
  SIGNATURE,
  THUMB_U,
};

enum unicode_names {
    INTERRO,
    IRONY,
    SNEK
};

const uint32_t PROGMEM unicode_map[] = {
    [INTERRO]  = 0x203D,	// ‽
    [IRONY] = 0x2E2E,	// ⸮
    [SNEK]  = 0x1F40D,	// 🐍
};

enum tap_dance_declarations {
  TD_DOT_DOTS,
  TD_LSOP,
  TD_RSCP,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Base layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  |   6  |           |   5  |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Del    |   Q  |   W  |   E  |   R  |   T  |  L1  |           |  L1  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LAlt   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |' / Cmd |
 * |--------+------+------+------+------+------|  L2  |           |  L2  |------+------+------+------+------+--------|
 * |(/LShift|Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  | ./…  |//Ctrl|)/RShift|
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | `/L2 |  '"  |AltShf| Left | Right|                                       |  Up  | Down |   [  |   ]  | ~L2  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                       ,---------------.       ,---------------.
 *                                       |Ctrl/App| LGui |       | Alt  |Ctrl/Esc|
 *                                ,------|--------|------|       |------+--------+------.
 *                                |      |        | Home |       | PgUp |        |      |
 *                                | Space| Backsp |------|       |------|  Tab   |Enter |
 *                                |      | ace    | End  |       | PgDn |        |      |
 *                                `----------------------'       `----------------------'
 */
[BASE] = LAYOUT_ergodox_pretty(
  KC_EQUAL,	KC_1,	KC_2,	KC_3,	KC_4,	KC_5,	KC_6,                     	KC_5,	KC_6,	KC_7,	KC_8,	KC_9,	KC_0,	KC_MINUS,
  KC_DELETE,	KC_Q,	KC_W,	KC_E,	KC_R,	KC_T,	TG(UTIL),	TG(UTIL),	KC_Y,	KC_U,	KC_I,	KC_O,	KC_P,	KC_BACKSLASH,
  KC_LALT,	KC_A,	KC_S,	KC_D,	KC_F,	KC_G,			KC_H,	KC_J,	KC_K,	KC_L,	KC_SEMICOLON,	LGUI_T(KC_QUOTE),
  LSFT_T(KC_LEFT_PAREN),	LCTL_T(KC_Z),	KC_X,	KC_C,	KC_V,	KC_B,	TG(GAME),	TG(GAME),	KC_N,	KC_M,	KC_COMMA,	TD(TD_DOT_DOTS),	RCTL_T(KC_SLASH),	RSFT_T(KC_RIGHT_PAREN),
  LT(UTIL,KC_GRAVE),	KC_QUOTE,	LALT(KC_LSFT),	KC_LEFT,	KC_RIGHT,					KC_UP,	KC_DOWN,	KC_LBRC,	KC_RBRC,	MO(UTIL),
  
                                                  		LCTL_T(KC_APPLICATION),	KC_LGUI,     	KC_LALT,	LCTL_T(KC_ESCAPE),
			KC_HOME,	KC_PGUP,		
	KC_SPACE,	KC_BACKSPACE,	KC_END,	KC_PGDN,	KC_TAB,	KC_ENTER
  ),
/* Keymap 1: Games
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |   1  |   2  |   3  |   4  |   5  |      |           | RGui |   6  |   7  |   8  |   9  |   0  |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   Q  |   W  |   E  |   R  |   T  |      |           |      |      |LClick| MsUp |RClick|      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  LAlt  |   A  |   S  |   D  |   F  |   G  |------|           |------|      |MsLeft|MsDown|MsRght|      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LCtrl| XXXX | XXXX | Left | Right|                                       |  Up  | Down | XXXX | XXXX |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      | Esc  |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 | Space|   X  |------|       |------| Tab  |Enter |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[GAME] = LAYOUT_ergodox_pretty(
  KC_TRNS,	KC_1,	KC_2,	KC_3,	KC_4,	KC_5,	KC_TRNS,               	KC_RGUI,	KC_6,	KC_7,	KC_8,	KC_9,	KC_0,	KC_TRNS,
  KC_TRNS,	KC_Q,	KC_W,	KC_E,	KC_R,	KC_T,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_BTN1,	KC_MS_U,	KC_BTN2,	KC_TRNS,	KC_TRNS,
  KC_LALT,	KC_A,	KC_S,	KC_D,	KC_F,	KC_G,			KC_TRNS,	KC_MS_L,	KC_MS_D,	KC_MS_R,	KC_TRNS,	KC_TRNS,
  KC_LSFT,	KC_Z,	KC_X,	KC_C,	KC_V,	KC_B,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
  KC_LCTL,	KC_NO,	KC_NO,	KC_LEFT,	KC_RIGHT,					KC_UP,	KC_DOWN,	KC_NO,	KC_NO,	KC_TRNS,

                                             		KC_TRNS,	KC_TRNS,     	KC_TRNS,	KC_ESCAPE,
			KC_TRNS,	KC_TRNS,
	KC_SPC,	KC_X,	KC_TRNS,	KC_TRNS,	KC_TAB,	KC_ENTER
  ),
/* Keymap 2: Utility
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |           |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      | :+1: |   7  |   8  |   9  |      |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |ScrSht|      |      |      |------|           |------|      |   4  |   5  |   6  |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |Ctrl+Z|      |      |      |      |      |           |      |   0  |   1  |   2  |   3  |   ‽  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      | ScrL | ScrR |                                       |VolUp |VolDn | Mute |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------| Sig  |Shrug |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[UTIL] = LAYOUT_ergodox_pretty(
  KC_TRNS,	KC_F1,	KC_F2,	KC_F3,	KC_F4,	KC_F5,	KC_F6,                 	KC_F5,	KC_F6,	KC_F7,	KC_F8,	KC_F9,	KC_F10,	KC_F11,
  KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	THUMB_U,	KC_7,	KC_8,	KC_9,	KC_TRNS,	KC_F12,
  KC_TRNS,	KC_TRNS,	SCREENSHOT,	KC_TRNS,	KC_TRNS,	KC_TRNS,			KC_TRNS,	KC_4,	KC_5,	KC_6,	KC_TRNS,	KC_TRNS,
  KC_TRNS,	LCTL(KC_Z),	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_0,	KC_1,	KC_2,	KC_3,	X(INTERRO),	KC_TRNS,
  KC_TRNS,	KC_TRNS,	KC_TRNS,	SCREEN_LEFT,	SCREEN_RIGHT,					KC_VOLU,	KC_VOLD,	KC_MUTE,	KC_TRNS,	KC_TRNS,
  
                                                      		KC_TRNS,	KC_TRNS,     	KC_TRNS,	KC_TRNS,
			KC_TRNS,	KC_TRNS,
	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	SIGNATURE,	SHRUG
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        return false;
      }
    #ifdef RGBLIGHT_ENABLE
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
        return false;
      }
    #endif
    case SHRUG:
      if (record->event.pressed) {
        send_unicode_string("¯\\_(ツ)_/¯"); // ¯\_(ツ)_/¯
        return true;
      }
    case SIGNATURE:
      if (record->event.pressed) {
        send_unicode_string("4∑(-1)^n÷(2n+1) 🚣🎣"); // 4∑(-1)^n÷(2n+1) 🚣🎣
        return true;
      }
    case THUMB_U:
      if (record->event.pressed) {
        register_unicode(0x1F44D); // 👍
        return true;
      }
    case LSFT_T(KC_LEFT_PAREN):
      if (record->tap.count && record->event.pressed) {
        tap_code16(KC_LEFT_PAREN);	// Send KC_LEFT_PAREN on tap
        return false;	// Return false to ignore further pressing of key
      }
      break;
    case RSFT_T(KC_RIGHT_PAREN):
      if (record->tap.count && record->event.pressed) {
        tap_code16(KC_RIGHT_PAREN);	// Send KC_RIGHT_PAREN on tap
        return false;	// Return false to ignore further pressing of key
      }
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = get_highest_layer(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
        #endif
        break;
      default:
        break;
    }

  return state;
};

static bool dot_held;

void dot_dots_each(tap_dance_state_t *state, void *user_data) {
  if (state->count > 1) {
    unregister_code(KC_DOT);
  }
  register_code(KC_DOT);
}

void dot_dots_finished(tap_dance_state_t *state, void *user_data) {
  if (state->count == 3) {
    unregister_code(KC_DOT);
    tap_code(KC_BACKSPACE);
    tap_code(KC_BACKSPACE);
    tap_code(KC_BACKSPACE);
    register_unicode(0x2026); // …
  } else {
    if (state->pressed) {
      dot_held = true;
    } else {
      unregister_code(KC_DOT);
      dot_held = false;
    }
  }
};

void dot_dots_reset(tap_dance_state_t *state, void *user_data) {
  if(dot_held) {
    unregister_code(KC_DOT);
    dot_held = false;
  }
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Period, thrice for ellipsis
    [TD_DOT_DOTS] = ACTION_TAP_DANCE_FN_ADVANCED(dot_dots_each, dot_dots_finished, dot_dots_reset),
    // Tap once for open paren, hold for left shift
    [TD_LSOP] = ACTION_TAP_DANCE_FN_ADVANCED(dot_dots_each, dot_dots_finished, dot_dots_reset),
    // Tap once for close paren, hold for right shift
    [TD_RSCP] = ACTION_TAP_DANCE_FN_ADVANCED(dot_dots_each, dot_dots_finished, dot_dots_reset),
};
