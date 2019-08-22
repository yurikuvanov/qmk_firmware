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
#include "muse.h"
#include "action_layer.h"
#include "keymap_jp.h"  // qmk_firmware/quantum/keymap_extras/keymap_jp.h

extern keymap_config_t keymap_config;

enum planck_layers {
  _JIS,
  _US,
  _LOWER,
  _RAISE,
  _LOWERUS,
  _RAISEUS,
  _PLOVER,
  _ADJUST
};

enum planck_keycodes {
  JIS = SAFE_RANGE,
  US,
  BACKLIT,
  WN_SCLN,
  WN_MINS,
  EXT_PLV
};

#define LOWER LT(_LOWER, JP_MHEN)
#define RAISE LT(_RAISE, JP_HENK)
#define LOWERUS LT(_LOWERUS, KC_LANG2)
#define RAISEUS LT(_RAISEUS, KC_LANG1)
#define ADJUST MO(_ADJUST)           // ホールドでAdjustレイヤーをon


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* JIS
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  | ; :  | -  _ |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  | , <  | . >  | / ?  |SHIFT |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |  GUI | Alt  | Ctrl |Lower | Space|Enter |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_JIS] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    WN_SCLN, WN_MINS,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT ,
    KC_ESC,  KC_LGUI, KC_LALT, KC_LCTL, LOWER,   KC_SPC,  KC_ENT,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   ADJUST
),
 /*  US
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  | ; :  | -  _ |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  | , <  | . >  | / ?  |SHIFT |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |Adjust| Alt  |  GUI |Lower | Space|Enter |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */

 [_US] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_MINS,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT ,
    KC_ESC,  ADJUST, KC_LALT, KC_LGUI, LOWERUS, KC_SPC,  KC_ENT,  RAISEUS, KC_LEFT, KC_DOWN, KC_UP,    ADJUST
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
    _______, XXXXXXX, KC_MRWD, KC_MFFD, KC_MPLY, JP_CIRC, JP_PIPE, JP_UNDS, JP_PLUS, JP_LT,   JP_GT,   JP_QUOT,
    _______, _______, _______, _______, KC_TRNS, _______, _______, KC_TRNS, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
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
    _______, XXXXXXX, KC_VOLD, KC_VOLU, KC_MUTE, KC_DOT,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_PAST, KC_EQL,
    _______, XXXXXXX, KC_MRWD, KC_MFFD, KC_MPLY, KC_COMM, KC_PPLS, KC_1,    KC_2,    KC_3,    KC_PSLS, _______,
    _______, _______, _______, _______, KC_TRNS, _______, _______, KC_TRNS, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),
/* Lowerus
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
[_LOWERUS] = LAYOUT_planck_grid(
    KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
    _______, XXXXXXX, KC_VOLD, KC_VOLU, KC_MUTE, KC_TILD,  KC_BSLS, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, KC_DQT,
    _______, XXXXXXX, KC_MRWD, KC_MFFD, KC_MPLY, KC_CIRC, KC_PIPE, KC_UNDS, KC_PPLS, KC_LT,    KC_GT, KC_QUOT,
    _______, _______, _______, _______, KC_TRNS, _______, _______, KC_TRNS,    KC_MNXT,    KC_VOLD, KC_VOLU, KC_MPLY
),
/* RaiseUS
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
[_RAISEUS] = LAYOUT_planck_grid(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
    _______, XXXXXXX, KC_VOLD, KC_VOLU, KC_MUTE, KC_DOT,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_PAST, KC_EQL,
    _______, XXXXXXX, KC_MRWD, KC_MFFD, KC_MPLY, KC_COMM, KC_PPLS, KC_1,    KC_2,    KC_3,    KC_PSLS, _______,
    _______, _______, _______, _______, KC_TRNS, _______, _______, KC_TRNS, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap| JIS  |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, US, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL ,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, JIS,     _______,  _______, _______,  _______,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, KC_TRNS
)

};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

uint32_t layer_state_set_user(uint32_t state) {
  state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
  state = update_tri_layer_state(state, _LOWERUS, _RAISEUS, _ADJUST);
  return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static bool lshift = false;
    static bool rshift = false;
  switch (keycode) {
    case JIS:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_JIS);
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(plover_song);
        #endif
      }
      return false;
      break;
    case US:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_US);
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(plover_song);
        #endif
      }
      return false;
      break;
    case WN_SCLN:                          // JISの「;」と「:」
      if (record->event.pressed) {
        lshift = keyboard_report->mods & MOD_BIT(KC_LSFT);
        rshift = keyboard_report->mods & MOD_BIT(KC_RSFT);
        if (lshift || rshift) {
          if (lshift) unregister_code(KC_LSFT);
          if (rshift) unregister_code(KC_RSFT);
          register_code(JP_COLN);
          unregister_code(JP_COLN);
          if (lshift) register_code(KC_LSFT);
          if (rshift) register_code(KC_RSFT);
        } else {
          register_code(JP_SCLN);
          unregister_code(JP_SCLN);
        }
      }
      return false;
      break;
    case WN_MINS:                          // JISの「-」と「_」
      if (record->event.pressed) {
        lshift = keyboard_report->mods & MOD_BIT(KC_LSFT);
        rshift = keyboard_report->mods & MOD_BIT(KC_RSFT);
        if (lshift || rshift) {
          register_code(JP_BSLS);
          unregister_code(JP_BSLS);
        } else {
          register_code(JP_MINS);
          unregister_code(JP_MINS);
        }
      }
      return false;
      break;
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        register_code(KC_MS_WH_DOWN);
        unregister_code(KC_MS_WH_DOWN);
      #else
        register_code(KC_PGDN);
        unregister_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        register_code(KC_MS_WH_UP);
        unregister_code(KC_MS_WH_UP);
      #else
        register_code(KC_PGUP);
        unregister_code(KC_PGUP);
      #endif
    }
  }
}

void dip_update(uint8_t index, bool active) {
  switch (index) {
    case 0:
      if (active) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_song);
        #endif
        layer_on(_ADJUST);
      } else {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_ADJUST);
      }
      break;
    case 1:
      if (active) {
        muse_mode = true;
      } else {
        muse_mode = false;
        #ifdef AUDIO_ENABLE
          stop_all_notes();
        #endif
      }
   }
}

void matrix_scan_user(void) {
  #ifdef AUDIO_ENABLE
    if (muse_mode) {
      if (muse_counter == 0) {
        uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
        if (muse_note != last_muse_note) {
          stop_note(compute_freq_for_midi_note(last_muse_note));
          play_note(compute_freq_for_midi_note(muse_note), 0xF);
          last_muse_note = muse_note;
        }
      }
      muse_counter = (muse_counter + 1) % muse_tempo;
    }
  #endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}

