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

#define LCA_GRV     LCA_T(KC_GRV)
#define LCG_Q       MT(MOD_LCTL | MOD_LGUI, KC_Q)
#define LSG_E       LSG_T(KC_E)
#define LAG_W       LAG_T(KC_W)
#define LSA_R       LSA_T(KC_R)
#define LSC_T       MT(MOD_LSFT | MOD_LCTL, KC_T)
#define LCA_DEL     LCA_T(KC_DEL)
#define RCG_P       MT(MOD_RCTL | MOD_RGUI, KC_P)
#define RSG_I       RSG_T(KC_I)
#define RAG_O       RAG_T(KC_O)
#define RSA_U       RSA_T(KC_U)
#define RSC_Y       MT(MOD_RSFT | MOD_RCTL, KC_Y)


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
 * | ca_~ ` | cg_Q  | ag_W | sg_E | sa_R | sc_T |                                | sc_Y | sa_U |  sg_I   | ag_O  | cg_P  |ca_Del |
 * |--------+-------+------+------+------+------|                                |------+------+---------+-------+-------+-------|
 * | c_\ |  |   A   |   S  |   D  |   F  |  G   |                                |   H  |  J   |    K    |   L   |  ; :  | c_' " |
 * |--------+-------+------+------+------+------+--------------.    ,------------+------+------+---------+-------+-------+-------|
 * |Mse/Med |   Z   |   X  |  c_C |  g_V |  B   |  Tab  |M/Home|    |M/End |Enter|   N  | g_M  |  c_, <  |  . >  |  / ?  |  - _  |
 * `--------+-------+------+------+------+------+-------+------|    |------+-----+------+------+---------+-------+-------+-------'
 *                         | Mute | a_[{ |s_Esc |Space | Raise |    |Lower |Bkspc|s_+ = | a_]} | Special |
 *                         `-----------------------------------'    `------------------------------------'
 */
    [_QWERTY] = LAYOUT(
     LCA_GRV , LCG_Q ,  LAG_W  , LSG_E ,  LSA_R ,  LSC_T ,                                           RSC_Y , RSA_U ,    RSG_I ,  RAG_O , RCG_P   , LCA_DEL,
     C_BSLS  , KC_A  ,  KC_S   , KC_D  ,   KC_F ,   KC_G ,                                           KC_H  , KC_J  ,    KC_K  ,   KC_L , KC_SCLN , C_QUOT ,
     MOUSE   , KC_Z  ,  KC_X   ,CTRL_C ,  GUI_V ,   KC_B , KC_TAB ,MOUS_HOME,     MOUS_END ,KC_ENT , KC_N  , GUI_M , CTRL_COMM, KC_DOT , KC_SLSH , KC_MINS,
                             KC_KB_MUTE, A_LBRC ,  S_ESC , KC_SPC ,  RAISE  ,     LOWER  ,  KC_BSPC, S_EQL , A_RBRC, SPECIAL
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
