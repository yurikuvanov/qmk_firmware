/* Copyright 2015-2017 Jack Humbert
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

#include "planck.h"
/* #include QMK_KEYBOARD_H */
#include "keymap_jp.h"  // qmk_firmware/quantum/keymap_extras/keymap_jp.h

extern keymap_config_t keymap_config;

enum planck_layers {
  _US,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum planck_keycodes {
  US = SAFE_RANGE,
  PLOVER,
  BACKLIT,
  WN_SCLN,
  WN_MINS,
  EXT_PLV
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*US
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  | ; :  | -  _ |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  | , <  | . >  | / ?  |SHIFT |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  | Ctrl | Alt  | GUI  |Lower | Space|Enter |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_US] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_MINS,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT ,
    KC_ESC,  KC_LCTL, KC_LALT, KC_LGUI, LT(LOWER,KC_LANG2),KC_SPC,KC_ENT,LT(RAISE,KC_LANG1),KC_LEFT, KC_DOWN, KC_UP,KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |半/全 |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | DEL  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      | Vol- | Vol+ | Mute |   ~  |   \  |   [  |   ]  |   {  |   }  |   "  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |CpsLck|      | Prev | Next | Play |   ^  |   |  |   _  |   +  |   <  |   >  |   `  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    KC_GRV,  KC_EXLM, JP_AT,   KC_HASH, KC_DLR,  KC_PERC, JP_CIRC, JP_AMPR, JP_ASTR, JP_LPRN, JP_RPRN, KC_DEL,
    _______, XXXXXXX, KC_VOLD, KC_VOLU, KC_MUTE, JP_TILD,  JP_YEN, JP_LBRC, JP_RBRC, JP_LCBR, JP_RCBR, JP_DQT,
    _______, XXXXXXX, KC_MRWD, KC_MFFD, KC_MPLY, JP_CIRC, JP_PIPE, JP_UNDS, JP_PLUS, JP_LT,    JP_GT, JP_QUOT,
    _______, _______, _______, _______, _______, _______, _______, _______,    KC_MNXT,    KC_VOLD, KC_VOLU, KC_MPLY
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  DEL |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      | Vol- | Vol+ | Mute |   .  | Left | Down |  Up  |Right |   *  |   =  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      | Prev | Next | Play |   ,  |   +  |   1  |   2  |   3  |   /  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |   0  |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
    _______, XXXXXXX, KC_VOLD, KC_VOLU, KC_MUTE, KC_DOT,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_PAST, JP_EQL,
    _______, XXXXXXX, KC_MRWD, KC_MFFD, KC_MPLY, KC_COMM, KC_PPLS, KC_1,    KC_2,    KC_3,    KC_PSLS, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),


/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|  US  |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL ,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, US,     _______,  _______, _______,  _______,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
)

};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case US:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_US);
      }
      return false;
      break;
  }
  return true;
}
