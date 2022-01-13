/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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

enum layers {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _MOUSE,
};


// Aliases for readability
#define QWERTY   DF(_QWERTY)

#define LOWER    MO(_LOWER)
#define RAISE    MO(_RAISE)
#define MOUSE    MO(_MOUSE)

// #define CTL_ESC  MT(MOD_LCTL, KC_ESC)
// #define CTL_QUOT MT(MOD_RCTL, KC_QUOTE)
// #define CTL_MINS MT(MOD_RCTL, KC_MINUS)
// #define ALT_ENT  MT(MOD_LALT, KC_ENT)
#define CTRL_C      LCTL_T(KC_C)
#define C_BSLS      LCTL_T(KC_BSLS)
#define C_QUOT      RCTL_T(KC_QUOT)
#define GUI_V       LGUI_T(KC_V)
#define CTRL_COMM   RCTL_T(KC_COMM)
#define GUI_M       RGUI_T(KC_M)
#define A_LBRC      LALT_T(KC_LBRC)
#define A_RBRC      RALT_T(KC_RBRC)
#define S_ESC       LSFT_T(KC_ESC)
#define S_EQL       RSFT_T(KC_EQL)
#define MOUS_HOME   LT(MOUSE, KC_HOME)
#define MOUS_END    LT(MOUSE, KC_END)

#define LSC_GRV     MT(MOD_LSFT | MOD_LCTL, KC_GRV)
#define RSC_DEL     MT(MOD_RSFT | MOD_RCTL, KC_DEL)
#define LAC_Q       LCA_T(KC_Q)
#define RAC_P       MT(MOD_RGUI | MOD_RALT, KC_P)
#define LGC_W       MT(MOD_LGUI | MOD_LCTL, KC_W)
#define RGC_O       MT(MOD_RGUI | MOD_RCTL, KC_O)
#define LGA_E       LAG_T(KC_E)
#define RGA_I       RAG_T(KC_I)
#define LGS_R       LSG_T(KC_R)
#define RGS_U       RSG_T(KC_U)
#define LAS_T       LSA_T(KC_T)
#define RAS_Y       RSA_T(KC_Y)


#define SPECIAL LCAG(KC_SPC) // Hold Left Control, Alt and GUI and press Space

// Note: LAlt/Enter (ALT_ENT) is not the same thing as the keyboard shortcut Alt+Enter.
// The notation `mod/tap` denotes a key that activates the modifier `mod` when held down, and
// produces the key `tap` when tapped (i.e. pressed and released).

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: QWERTY
 *
 * ,--------------------------------------------.                                ,-----------------------------------------------.
 * | sc_~ ` | ac_Q  | gc_W | ga_E | gs_R | sa_T |                                | sa_Y | gs_U |  ga_I   | gc_O  | ac_P  |sc_Del |
 * |--------+-------+------+------+------+------|                                |------+------+---------+-------+-------+-------|
 * | c_\ |  |   A   |   S  |   D  |   F  |  G   |                                |   H  |  J   |    K    |   L   |  ; :  | c_' " |
 * |--------+-------+------+------+------+------+--------------.    ,------------+------+------+---------+-------+-------+-------|
 * |Mse/Med |   Z   |   X  |  c_C |  g_V |  B   |  Tab  |M/Home|    |M/End |Enter|   N  | g_M  |  c_, <  |  . >  |  / ?  |  - _  |
 * `--------+-------+------+------+------+------+-------+------|    |------+-----+------+------+---------+-------+-------+-------'
 *                         | Mute | a_[{ |Space |s_Esc | Raise |    |Lower |s_+ =|Bkspc | a_]} | Special |
 *                         `-----------------------------------'    `------------------------------------'
 */
    [_QWERTY] = LAYOUT(
     LSC_GRV , LAC_Q ,  LGC_W  , LGA_E ,  LGS_R ,  LAS_T ,                                           RAS_Y , RGS_U ,    RGA_I ,  RGC_O , RAC_P   , RSC_DEL,
     C_BSLS  , KC_A  ,  KC_S   , KC_D  ,   KC_F ,   KC_G ,                                           KC_H  , KC_J  ,    KC_K  ,   KC_L , KC_SCLN , C_QUOT ,
     MOUSE   , KC_Z  ,  KC_X   ,CTRL_C ,  GUI_V ,   KC_B , KC_TAB ,MOUS_HOME,     MOUS_END ,KC_ENT , KC_N  , GUI_M , CTRL_COMM, KC_DOT , KC_SLSH , KC_MINS,
                             KC_KB_MUTE, A_LBRC , KC_SPC , S_ESC  ,  RAISE  ,     LOWER  ,  S_EQL  ,KC_BSPC, A_RBRC, SPECIAL
    ),

/*
 * Lower Layer: Numbers and Arrow/Scroll Navigation
 *
 * ,-------------------------------------------.                                ,--------------------------------------------.
 * |    0   |  1   |  2   |  3   |  4   |  5   |                                |   6  |  7   |  8   |  9   |   0   |   1    |
 * |--------+------+------+------+------+------|                                |------+------+------+------+-------+--------|
 * |ScrlLt  |ScrlRt|PgDn  |ScrlDn|ScrlUp| PgUp |                                | Left | Down |  Up  |Right | Home  |  End   |
 * |--------+------+------+------+------+------+-------------.    ,-------------+------+------+------+------+-------+--------|
 * |        |      |      |      |      |      |      | PgDn |    | PgUp |      |      |        |        |      |       |    |
 * `----------------------+------+------+------+------+------|    |------+------+------+------+------+-----------------------'
 *                        |      |      |      |      |      |    |      |      |      |      |      |
 *                        `----------------------------------'    `----------------------------------'
 */
    [_LOWER] = LAYOUT(
         KC_0,   KC_1 ,   KC_2 ,   KC_3 ,   KC_4 ,   KC_5 ,                                             KC_6 ,   KC_7 ,   KC_8 ,   KC_9 ,   KC_0 ,   KC_1 ,
      KC_WH_L, KC_WH_R, KC_PGDN, KC_WH_D, KC_WH_U, KC_PGUP,                                           KC_LEFT, KC_DOWN,  KC_UP , KC_RGHT, KC_HOME,  KC_END,
      _______, _______, _______, _______, _______, _______, _______, KC_PGDN,       KC_PGUP, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
    ),

/*
 * Raise Layer: Symbols and Function keys
 *
 * ,-----------------------------------------.                                ,------------------------------------------.
 * |      |  !   |  @   |  #   |  $   |  %   |                                |   ^  |   &   |  *   |  (  |  )   |       |
 * |------+------+------+------+------+------|                                |------+------+------+------+------+-------|
 * |  F1  |  F2  | F3   | F4   | F5   |  F6  |                                |  F7  |  F8  |  F9  |  F10 |  F11 |  F12  |
 * |------+------+------+------+------+------+-------------.    ,-------------+------+------+------+------+------+-------|
 * |      |      |      |      |      |      |      |CapsLk|    |PrtScn|      |      |      |      |      |      |       |
 * `--------------------+------+------+------+------+------|    |------+------+------+------+------+---------------------'
 *                      |      |      |      |      |      |    |      |      |      |      |      |
 *                      `----------------------------------'    `----------------------------------'
 */
    [_RAISE] = LAYOUT(
      _______,  KC_EXLM,  KC_AT  , KC_HASH, KC_DLR , KC_PERC,                                         KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
      KC_F1  ,  KC_F2  ,  KC_F3  , KC_F4  , KC_F5  , KC_F6  ,                                         KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,
      _______,  _______,  _______, _______, _______, _______, _______, KC_CAPS,     KC_PSCR, _______, _______, _______, _______, _______, _______, _______,
                                   _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
    ),

/*
 * Mouse Layer: Mouse Nav and Media
 *
 * ,------------------------------------------.                                           ,---------------------------------------------.
 * |      |        |MouseUp |        | RtClck |       |                                   |      |       |       |       |      |       |
 * |------+--------+--------+--------+--------+-------|                                   |------+-------+-------+-------+------+-------|
 * |      |MouseLt |MouseDn |MouseRt | LtClck |       |                                   |      | Play  | Prev  | Next  |      |       |
 * |------+--------+--------+--------+--------+-------+-------------.       ,-------------+------+-------+-------+-------+------+-------|
 * |      |        |        |        | MidClck| Accl0 |Accl1 |Accl2 |       |      |      |      | VolDn | VolUp |VolMute|      |       |
 * `------------------------+--------+--------+-------+------+------|       |------+------+------+-------+-------+----------------------'
 *                          |        |        |       |      |      |       |      |      |      |       |       |
 *                          `---------------------------------------'       `------------------------------------'
 */
    [_MOUSE] = LAYOUT(
      _______, _______, KC_MS_U, _______, KC_BTN2, _______,                                         _______, _______, _______, _______, _______, _______,
      _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN1, _______,                                         _______, KC_MPLY, KC_MRWD, KC_MFFD, _______, _______,
      _______, _______, _______, _______, KC_BTN3, KC_ACL0, KC_ACL1, KC_ACL2,     _______, _______, _______, KC_VOLD, KC_VOLU, KC_MUTE, _______, _______,
                                 _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
    ),

// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

/* The default OLED and rotary encoder code can be found at the bottom of qmk_firmware/keyboards/splitkb/kyria/rev1/rev1.c
 * These default settings can be overriden by your own settings in your keymap.c
 * For your convenience, here's a copy of those settings so that you can uncomment them if you wish to apply your own modifications.
 * DO NOT edit the rev1.c file; instead override the weakly defined default functions by your own.
 */


#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {

    if (index == 0) {
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        // Page up/Page down
        if (clockwise) {
            tap_code(KC_PGUP);
        } else {
            tap_code(KC_PGDN);
        }
    }
    return false;
}
#endif
