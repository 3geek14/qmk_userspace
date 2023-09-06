/* Copyright 2020 ZSA Technology Labs, Inc <@zsa>
 * Copyright 2020 Jack Humbert <jack.humb@gmail.com>
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
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
    QWER,	// default layer
    COLE, // colemak-dh
    GAME,	// gaming
    UTIL,	// symbols
};

enum custom_keycodes {
  VRSN = SAFE_RANGE,
  RGB_SLD,
  SHRUG,
  SIGNATURE,
  EMAIL,
  THUMB_U,
  WAVE,
  EYES,
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

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[QWER] = LAYOUT_moonlander(
		KC_EQL,	KC_1,	KC_2,	KC_3,	KC_4,	KC_5,	KC_6,	/**/	KC_5,	KC_6,	KC_7,	KC_8,	KC_9,	KC_0,	KC_MINS,
		KC_DEL,	KC_Q,	KC_W,	KC_E,	KC_R,	KC_T,	KC_Y,	/**/	KC_T,	KC_Y,	KC_U,	KC_I,	KC_O,	KC_P,	KC_BSLS,
		LALT_T(CW_TOGG),	KC_A,	KC_S,	KC_D,	KC_F,	KC_G,	KC_H,	/**/	KC_G,	KC_H,	KC_J,	KC_K,	KC_L,	KC_SCLN,	LGUI_T(KC_QUOT),
		KC_LSFT,	LCTL_T(KC_Z),	KC_X,	KC_C,	KC_V,	KC_B,		/**/		KC_N,	KC_M,	KC_COMM,	TD(TD_DOT_DOTS),	RCTL_T(KC_SLSH),	KC_RSFT,
    									/**/							
		LT(UTIL,KC_GRV),	KC_PGUP,	KC_PGDN,	KC_LEFT,	KC_RGHT,		KC_HOME,	/**/	RCTL_T(KC_ESC),		KC_UP,	KC_DOWN,	KC_LBRC,	KC_RBRC,	MO(UTIL),
						KC_SPC,	KC_BSPC,	KC_END,	/**/	LALT_T(KC_APPLICATION),	KC_TAB,	KC_ENT
	),
	[COLE] = LAYOUT_moonlander(
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	/**/	_______,	_______,	_______,	_______,	_______,	_______,	_______,
		_______,	KC_Q,	KC_W,	KC_F,	KC_P,	KC_B,	_______,	/**/	_______,	KC_J,	KC_L,	KC_U,	KC_Y,	KC_SCLN,	_______,
		_______,	KC_A,	KC_R,	KC_S,	KC_T,	KC_G,	_______,	/**/	_______,	KC_M,	KC_N,	KC_E,	KC_I,	KC_O,	_______,
		_______,	LCTL_T(KC_Z),	KC_X,	KC_C,	KC_D,	KC_V,		/**/		KC_K,	KC_H,	KC_COMM,	TD(TD_DOT_DOTS),	RCTL_T(KC_SLSH),	_______,
    									/**/							
		_______,	_______,	_______,	_______,	_______,		_______,	/**/	_______,		_______,	_______,	_______,	_______,	_______,
						_______,	_______,	_______,	/**/	_______,	_______,	_______
	),
	[GAME] = LAYOUT_moonlander(
		_______,	KC_1,	KC_2,	KC_3,	KC_4,	KC_5,	_______,	/**/	KC_RGUI,	KC_6,	KC_7,	KC_8,	KC_9,	KC_0,	_______,
		_______,	KC_Q,	KC_W,	KC_E,	KC_R,	KC_T,	_______,	/**/	_______,	_______,	KC_BTN1,	KC_MS_U,	KC_BTN2,	_______,	_______,
		KC_LALT,	KC_A,	KC_S,	KC_D,	KC_F,	KC_G,	_______,	/**/	_______,	_______,	KC_MS_L,	KC_MS_D,	KC_MS_R,	_______,	_______,
		KC_LSFT,	KC_Z,	KC_X,	KC_C,	KC_V,	KC_B,		/**/		_______,	_______,	_______,	_______,	_______,	_______,
    									/**/							
		KC_LCTL,	KC_NO,	KC_NO,	KC_LEFT,	KC_RGHT,		_______,	/**/	KC_ESC,		KC_UP,	KC_DOWN,	KC_NO,	KC_NO,	_______,
						KC_SPC,	KC_BSPC,	_______,	/**/	_______,	KC_TAB,	KC_ENT
	),
	[UTIL] = LAYOUT_moonlander(
		_______,	KC_F1,	KC_F2,	KC_F3,	KC_F4,	KC_F5,	KC_F6,	/**/	KC_F5,	KC_F6,	KC_F7,	KC_F8,	KC_F9,	KC_F10,	KC_F11,
		_______,	_______,	_______,	EYES,	_______,	_______,	TG(COLE),	/**/	_______,	THUMB_U,	KC_7,	KC_8,	KC_9,	_______,	KC_F12,
		_______,	_______,	SCREENSHOT,	_______,	_______,	_______,	TG(GAME),	/**/	_______,	WAVE,	KC_4,	KC_5,	KC_6,	_______,	_______,
		_______,	LCTL(KC_Z),	_______,	_______,	_______,	_______,		/**/		KC_0,	KC_1,	KC_2,	KC_3,	X(INTERRO),	_______,
    									/**/							
		_______,	LCTL(KC_PGUP),	LCTL(KC_PGDN),	SCREEN_LEFT,	SCREEN_RIGHT,		_______,	/**/	_______,		KC_VOLU,	KC_VOLD,	KC_MUTE,	_______,	_______,
						_______,	_______,	_______,	/**/	EMAIL,	SIGNATURE,	SHRUG
	),
      /*
	[LAYER] = LAYOUT_moonlander(
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	**	_______,	_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	**	_______,	_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	**	_______,	_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,		**		_______,	_______,	_______,	_______,	_______,	_______,
    									**							
		_______,	_______,	_______,	_______,	_______,		_______,	**	_______,		_______,	_______,	_______,	_______,	_______,
						_______,	_______,	_______,	**	_______,	_______,	_______
	),
      */
};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
#if VIA_ENABLE
    case USER00:
      if (record->event.pressed) {
        SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
    case USER01:
      if (record->event.pressed) {
        keyboard_config.led_level ^= 1;
        eeconfig_update_kb(keyboard_config.raw);
        if (keyboard_config.led_level) {
          layer_state_set_kb(layer_state);
        } else {
          ML_LED_1(false);
          ML_LED_2(false);
          ML_LED_3(false);
          ML_LED_4(false);
          ML_LED_5(false);
          ML_LED_6(false);
        }
      }
      break;
#endif
    case SHRUG:
      if (record->event.pressed) {
        send_unicode_string("¯\\_(ツ)_/¯"); // Shruggie
        return true;
      }
    case SIGNATURE:
      if (record->event.pressed) {
        send_unicode_string(SIGNATURE_STRING);
        return true;
      }
    case EMAIL:
      if (record->event.pressed) {
        send_unicode_string(EMAIL_STRING);
        return true;
      }
    case THUMB_U:
      if (record->event.pressed) {
        send_unicode_string("👍🏻"); // Thumbs Up: Light Skin Tone
        return true;
      }
    case WAVE:
      if (record->event.pressed) {
        send_unicode_string("👋🏻"); // Waving Hand: Light Skin Tone
        return true;
      }
    case EYES:
      if (record->event.pressed) {
        send_unicode_string("👀"); // Eyes
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
