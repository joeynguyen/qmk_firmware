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
    _DESKS,
};


// Aliases for readability
#define QWERTY   DF(_QWERTY)

#define LOWER    MO(_LOWER)
#define RAISE    MO(_RAISE)
#define MOUSE    MO(_MOUSE)
#define DESKS    MO(_DESKS)
#define RAI_ESC  LT(RAISE, KC_ESC)
#define LOW_ENT  LT(LOWER, KC_ENT)

// #define CTL_ESC  MT(MOD_LCTL, KC_ESC)
// #define CTL_QUOT MT(MOD_RCTL, KC_QUOTE)
// #define CTL_MINS MT(MOD_RCTL, KC_MINUS)
// #define ALT_ENT  MT(MOD_LALT, KC_ENT)
// #define CTRL_C      LCTL_T(KC_C)
// #define CTRL_COMM   RCTL_T(KC_COMM)
#define C_DEL          LCTL_T(KC_DEL)
#define C_QUOT         LCTL_T(KC_QUOT)
#define GUI_V          LGUI_T(KC_V)
#define GUI_M          LGUI_T(KC_M)
#define C_B            LCTL_T(KC_B)
#define C_N            LCTL_T(KC_N)
// #define GUI_B          LGUI_T(KC_B)
// #define GUI_N          RGUI_T(KC_N)
#define S_TAB          LSFT_T(KC_TAB)
#define A_SPC          LALT_T(KC_SPC)
#define A_BSPC         LALT_T(KC_BSPC)
#define S_EQL          LSFT_T(KC_EQL)
#define A_ENT          LALT_T(KC_ENT)

// #define TAB_LT         RCS(KC_TAB)  // tab left
// #define TAB_RT         LCTL(KC_TAB) // tab right
#define GUI_TAB        LGUI(KC_TAB) // MacOS Command-Tab (switch to previous app)
#define DESK_LT        C(KC_LEFT)   // MacOS - move Space left
#define DESK_RT        C(KC_RGHT)   // MacOS - move Space right

#define LSC_GRV     MT(MOD_LSFT | MOD_LCTL, KC_GRV)
#define LSC_BSLS    MT(MOD_LSFT | MOD_LCTL, KC_BSLS)
// #define SC_GRV      C_S_T(KC_GRV)
// #define SC_BSLS     C_S_T(KC_BSLS)
#define LAC_Q       LCA_T(KC_Q)
#define LAC_P       MT(MOD_LALT | MOD_LCTL, KC_P)
#define LGC_E       MT(MOD_LGUI | MOD_LCTL, KC_E)
#define LGC_I       MT(MOD_LGUI | MOD_LCTL, KC_I)
#define LGCS_MINS   MT(MOD_LGUI | MOD_LCTL | MOD_LSFT, KC_MINS)
#define LGA_W       LAG_T(KC_W)
#define LGA_O       LAG_T(KC_O)
#define LGS_R       LSG_T(KC_R)
#define LGS_U       LSG_T(KC_U)
#define LAS_T       LSA_T(KC_T)
#define LAS_Y       LSA_T(KC_Y)

#define SPECIAL LCAG(KC_SPC) // Hold Left Control, Alt and GUI and press Space
#define MOUS_HOME      LT(MOUSE, KC_HOME)
#define MOUS_END       LT(MOUSE, KC_END)
#define MOUS_SPECIAL   LT(MOUSE, SPECIAL)

// Note: LAlt/Enter (A_ENT) is not the same thing as the keyboard shortcut Alt+Enter.
// The notation `mod/tap` denotes a key that activates the modifier `mod` when held down, and
// produces the key `tap` when tapped (i.e. pressed and released).

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: QWERTY
 *
 * ,----------------------------------------------.                                             .------------------------------------------------,
 * |   sc_~ ` | ac_Q | ga_W | gc_E | gs_R | sa_T  |                                             | sa_Y | gs_U |  gc_I   |  ga_O | ac_P | sc_\ |  |
 * |----------+------+------+------+------+-------|                                             |------+------+---------+-------+------+---------|
 * |   c_Del  |  A   |  S   |   D  |  F   |  G    |                                             |  H   |  J   |   K     |   L   |  ; : | c_' "   |
 * |----------+------+------+------+------+-------+-------------------.     .-------------------+------+------+---------+-------+------+---------|
 * | Mse/Spec |  Z   |  X   |   C  |  g_V |  c_B  |  GuiTab | M/Home  |     |  M/End  | GuiTab  | c_N  | g_M  |   , <   |  . >  |  / ? | gcs_- _ |
 * `----------+------+------+------+------+-------+---------+---------|     |---------+---------+------+------+---------+-------+------+---------'
 *                          | Mute | [ {  | s_Tab | a_Space | RAI_Esc |     | LOW_Ent |  Bkspc  | a_=+ |  ] } | Special |
 *                          `-----------------------------------------'     `-------------------------------------------'
 */
    [_QWERTY] = LAYOUT(
     LSC_GRV     , LAC_Q, LGA_W, LGC_E,   LGS_R, LAS_T,                                              LAS_Y,   LGS_U,   LGC_I,  LGA_O,   LAC_P,  LSC_BSLS,
     C_DEL       ,  KC_A,  KC_S,  KC_D,    KC_F,  KC_G,                                               KC_H,    KC_J,    KC_K,   KC_L, KC_SCLN,    C_QUOT,
     MOUS_SPECIAL,  KC_Z,  KC_X,  KC_C,   GUI_V,   C_B, GUI_TAB, MOUS_HOME,       MOUS_END, GUI_TAB,   C_N,   GUI_M, KC_COMM, KC_DOT, KC_SLSH, LGCS_MINS,
                            KC_KB_MUTE, KC_LBRC, S_TAB,   A_SPC,   RAI_ESC,       LOW_ENT ,  A_BSPC, S_EQL, KC_RBRC, SPECIAL
    ),

/*
 * Lower Layer: Numbers and Arrow/Scroll Navigation
 *
 * ,-----------------------------------------.                                       ,------------------------------------------.
 * |   0   |  1   |  2  |  3   |  4   |  5   |                                       |   6   |   7  |  8  |   9   |  0  |  \ |  |
 * |-------+------+-----+------+------+------|                                       |-------+------+-----+-------+-----+-------|
 * | LCtrl |      |     | PgUp | PgDn |      |                                       |  Left | Down | Up  | Right |     | RCtrl |
 * |-------+------+-----+------+------+------+--------------.          ,-------------+-------+------+-----+-------+-----+-------|
 * |       |      |     |      | LGui |LCtrl |      |       |          |      |      | RCtrl | RGui |     |       |     |       |
 * `--------------------+------+------+------+------+-------|          |------+------+-------+------+-----+---------------------'
 *                      |      |      |LShft | LAlt | DESKS |          |Lower | RAlt | RShft |      |     |
 *                      `-----------------------------------'          `----------------------------------'
 */
    [_LOWER] = LAYOUT(
         KC_0,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                              KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSLS,
      KC_LCTL, XXXXXXX, XXXXXXX, KC_PGUP, KC_PGDN, XXXXXXX,                                           KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX, KC_RCTL,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LGUI, KC_LCTL, XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX, KC_RCTL, KC_RGUI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                 XXXXXXX, XXXXXXX, KC_LSFT, KC_LALT,   DESKS,       XXXXXXX, KC_RALT, KC_RSFT, XXXXXXX, XXXXXXX
    ),

/*
 * Raise Layer: Symbols and Function keys
 *
 * ,------------------------------------------.                                       ,------------------------------------------.
 * |       |  !   |  @   |  #   |   $  |   %  |                                       |   ^   |   &   |  *   |  (  |  )  |       |
 * |-------+------+------+------+------+------|                                       |-------+-------+------+-----+-----+-------|
 * | LCtrl |  F1  |  F2  |  F3  |  F4  |  F5  |                                       |  F6   |  F7   |  F8  | F9  | F10 | RCtrl |
 * |-------+------+------+------+------+------+--------------.         ,--------------+-------+-------+------+-----+-----+-------|
 * |       |      |      |      | LGui |LCtrl |      |CapsLk |         |PrtScn |      |       | RGui  |      | F11 | F12 |       |
 * `---------------------+------+------+------+------+-------|         |-------+------+-------+-------+------+-------------------'
 *                       |      |      |LShft | LAlt | Raise |         | DESKS | RAlt | RShft |      |      |
 *                       `-----------------------------------'         `------------------------------------'
 */
    [_RAISE] = LAYOUT(
      XXXXXXX,  KC_EXLM,  KC_AT  , KC_HASH, KC_DLR , KC_PERC,                                         KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, XXXXXXX,
      KC_LCTL,  KC_F1  ,  KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                                         KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_RCTL,
      XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, KC_LGUI, KC_LCTL, XXXXXXX, KC_CAPS,     KC_PSCR, XXXXXXX, KC_RCTL, KC_RGUI, XXXXXXX, KC_F11 , KC_F12 , XXXXXXX,
                                   XXXXXXX, XXXXXXX, KC_LSFT, KC_LALT, XXXXXXX,       DESKS, KC_RALT, KC_RSFT, XXXXXXX, XXXXXXX
    ),

/*
 * Mouse Layer: Mouse Nav and Media
 *
 * ,------------------------------------------------------.                                     ,---------------------------------------------.
 * |      |         | MouseUp |         | RtClck  |       |                                     |      |       |       |       |      |       |
 * |------+---------+---------+---------+---------+-------|                                     |------+-------+-------+-------+------+-------|
 * |      | MouseLt | MouseDn | MouseRt | LtClck  |       |                                     |      | Play  | Prev  | Next  |      |       |
 * |------+---------+---------+---------+---------+-------+---------------.       ,-------------+------+-------+-------+-------+------+-------|
 * |      |         |         |         | MidClck | Accl0 | Accl1 | Accl2 |       |      |      |      | VolDn | VolUp |VolMute|      |       |
 * `--------------------------+---------+---------+-------+-------+-------|       |------+------+------+-------+-------+----------------------'
 *                            |         |         |       |       |       |       |      |      |      |       |       |
 *                            `-------------------------------------------'       `------------------------------------'
 */
    [_MOUSE] = LAYOUT(
      XXXXXXX, XXXXXXX, KC_MS_U, XXXXXXX, KC_BTN2, XXXXXXX,                                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN1, XXXXXXX,                                         XXXXXXX, KC_MPLY, KC_MRWD, KC_MFFD, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN3, KC_ACL0, KC_ACL1, KC_ACL2,     XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLD, KC_VOLU, KC_MUTE, XXXXXXX, XXXXXXX,
                                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),

/*
 * Desktops Layer
 *
 * ,--------------------------------------------.                                                                              ,----------------------------------------------.
 * |      |  D1  |  D2  |  D3  |    D4   |  D5  |                                                                              |  D6  |    D7   |  D8  |  D9  |  D10  |  D11  |
 * |------+------+------+------+---------+------|                                                                              |------+---------+------+------+-------+-------|
 * |      |      |      |      | DESK_LT |      |                                                                              |      | DESK_RT |      |      |       |       |
 * |------+------+------+------+---------+------+-------------.                                                  ,-------------+------+---------+------+------+-------+-------|
 * |      |      |      |      |         |      |      |      |                                                  |      |      |      |         |      |      |       |       |
 * `--------------------+------+---------+------+------+------|                                                  |------+------+------+---------+------+----------------------'
 *                      |      |         |      |      |      |                                                  |      |      |      |         |      |
 *                      `-------------------------------------'                                                  `-------------------------------------'
 */
    [_DESKS] = LAYOUT(
      XXXXXXX,    A(KC_1),       A(KC_2),       A(KC_3),       A(KC_4),       A(KC_5),                                              A(KC_6),       A(KC_7),    A(KC_8),    A(KC_9),    A(KC_0),     A(KC_MINS),
      XXXXXXX,    XXXXXXX,       XXXXXXX,       XXXXXXX,       DESK_LT,       XXXXXXX,                                              XXXXXXX,       DESK_RT,    XXXXXXX,    XXXXXXX,    XXXXXXX,        XXXXXXX,
      XXXXXXX,    XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,  XXXXXXX,  XXXXXXX,       XXXXXXX,  XXXXXXX, XXXXXXX,       XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,        XXXXXXX,
                                                XXXXXXX,       XXXXXXX,       XXXXXXX,  XXXXXXX,  XXXXXXX,       XXXXXXX,  XXXXXXX, XXXXXXX,       XXXXXXX,    XXXXXXX
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
// https://docs.splitkb.com/hc/en-us/articles/360010513760-How-can-I-use-a-rotary-encoder-
// Alt/Cmd-Tab application switching
bool is_alt_cmd_tab_active = false;
uint16_t alt_cmd_tab_timer = 0;

bool encoder_update_user(uint8_t index, bool clockwise) {
    switch (get_highest_layer(layer_state)) {
        case _RAISE:
            if (index == 0) { /* First encoder */
                // Volume control
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
            } else if (index == 1) { /* Second encoder */
                // Ctrl + Left/Right Arrows
                if (clockwise) {
                    tap_code16(C(KC_LEFT));
                } else {
                    tap_code16(C(KC_RGHT));
                }
            }
            break;
        default:
            if (index == 0) { /* First encoder */
                // Volume control
                if (clockwise) {
                    tap_code(KC_VOLD);
                } else {
                    tap_code(KC_VOLU);
                }
            } else if (index == 1) { /* Second encoder */
                // Command-Tab / Command-Shift-Tab
                if (clockwise) {
                    if (!is_alt_cmd_tab_active) {
                        is_alt_cmd_tab_active = true;
                        register_code(KC_LGUI);
                    }
                    alt_cmd_tab_timer = timer_read();
                    tap_code16(KC_TAB);
                } else {
                    if (!is_alt_cmd_tab_active) {
                        is_alt_cmd_tab_active = true;
                        register_code(KC_LGUI);
                    }
                    alt_cmd_tab_timer = timer_read();
                    tap_code16(S(KC_TAB));
                }
            }
    }
    return false;
}
void matrix_scan_user(void) {
    if (is_alt_cmd_tab_active) {
        if (timer_elapsed(alt_cmd_tab_timer) > 1000) { // 1 second
            unregister_code(KC_LGUI);
            is_alt_cmd_tab_active = false;
        }
    }
}

#endif
