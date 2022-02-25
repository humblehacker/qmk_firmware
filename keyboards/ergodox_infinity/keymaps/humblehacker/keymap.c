#include QMK_KEYBOARD_H
#include "version.h"

enum custom_layers {
    DV_CASG,   // default layer
    SYMB,   // symbols
    MDIA,   // media keys
    _ALT,
    _FUN,
};


enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  VRSN,
  RGB_SLD,
  _CMNT,
  _BLKCMNT,
  _ARROW,
  _DBLARRW,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | `      |   1  |   2  |   3  |   4  |   5  | Esc  |           | Caps |   6  |   7  |   8  |   9  |   0  |   \    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   '  |   ,  |   .  |   p  |   y  |Leader|           |Leader|   f  |   g  |   c  |   r  |   l  |   /    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LCtrl  |   a  |   o  |   e  |   u  |   i  |------|           |------|   d  |   h  |   t  |   n  |   s  |   -    |
 * |--------+------+------+------+------+------| Tab  |           | Enter|------+------+------+------+------+--------|
 * | LShift |   ;  |   q  |   j  |   k  |   x  |      |           |      |   b  |   m  |   w  |   v  |   z  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | _FUN |   =  |   §  |  ←   |  →   |                                       |   ↑  |   ↓  |   [  |   ]  | _FUN |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | LAlt | Home |       | PgUp |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | End  |       | PgDn |      |      |
 *                                 | Bksp | LGUI |------|       |------| Enter|  Spc |
 *                                 |      |      |(_FUN)|       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[DV_CASG] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_GRAVE,  KC_1,       KC_2,       KC_3,     KC_4,     KC_5,   KC_ESC,
        KC_TAB,    KC_QUOT,    KC_COMMA,   KC_DOT,   KC_P,     KC_Y,   KC_LEAD,
        KC_LCTL,   KC_A,       KC_O,       KC_E,     KC_U,     KC_I,
        KC_LSFT,   KC_SCOLON,  KC_Q,       KC_J,     KC_K,     KC_X,   KC_TAB,
        MO(_FUN),  KC_EQUAL,   KC_NUBS,    KC_LEFT,  KC_RGHT,

                                                        KC_LOPT, KC_HOME,
                                                                 KC_END,
                                               KC_BSPC, KC_LGUI, OSL(_FUN),
        // right hand
             KC_CAPS,  KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_BSLS,
             KC_LEAD,  KC_F,     KC_G,     KC_C,     KC_R,     KC_L,     KC_SLSH,
                       KC_D,     KC_H,     KC_T,     KC_N,     KC_S,     KC_MINS,
             KC_ENTER, KC_B,     KC_M,     KC_W,     KC_V,     KC_Z,     KC_RSFT,
                                 KC_UP,    KC_DOWN,  KC_LBRC,  KC_RBRC,  MO(_FUN),

             KC_PGUP,           _______,
             KC_PGDN,
             OSL(_FUN), KC_ENT, KC_SPC
    ),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * | Version |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   !  |   @  |   #  |   $  |   %  |------|           |------|   ^  |   &  |   *  |   (  |   )  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   :  |   ~  |   |  |  ->  |  =>  |      |           |      | bcom |   -  |   2  |   {  |   }  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |   +  |      |      |      |                                       |   _  |  //  |   [  |   ]  |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[_ALT] = LAYOUT_ergodox(
       // left hand
       VRSN,    KC_F1,   KC_F2,   KC_F3 ,  KC_F4,   KC_F5,    _______,
       _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,     _______,
       _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,
       _______, KC_COLN, KC_TILD, KC_PIPE, _ARROW,  _DBLARRW, _______,
       _______, KC_PLUS, _______, _______, _______,
                                        _______, _______,
                                                 _______,
                               _______, _______, _______,
       // right hand
       _______, KC_F6,   KC_F7,    KC_F8,   KC_F9,   KC_F10,  _______,
       _______, KC_6,    KC_7,     KC_8,    KC_9,    KC_0,    _______,
                KC_CIRC, KC_AMPR,  KC_ASTR, KC_LPRN, KC_RPRN, _______,
       _______, KC_AMPR, KC_MINUS, KC_QUES, KC_LCBR, KC_RCBR, _______,
                         KC_UNDS,  _CMNT,   KC_LBRC, KC_RBRC, _______,
       _______, _______,
       _______,
       _______, _______, _______
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |  F11 |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |  F12 |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[_FUN] = LAYOUT_ergodox(
       _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,
       _______, _______, _______, _______, _______, _______, _______, 
       _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______,
                                            _______, _______,
                                                     _______,
                                   _______, _______, _______,
    // right hand
       _______,  KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,  _______,
       _______,  _______,  _______,  _______,  _______,  KC_F11,  _______,
                 _______,  _______,  _______,  _______,  KC_F12,  _______,
       _______,  _______,  _______,  _______,  _______,  _______, _______,
                           _______,  _______,  _______,  _______, _______,
       _______, _______,
       _______,
       _______, _______, _______
),
};

#define SSLEFT() SS_TAP(X_LEFT)

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case _CMNT:
            if (record->event.pressed) return true;
            SEND_STRING("//");
            break;

        case _BLKCMNT:
            if (record->event.pressed) return true;
            SEND_STRING("/*  */" SSLEFT() SSLEFT() SSLEFT());
            break;

        case _ARROW:
            if (record->event.pressed) return true;
            SEND_STRING("->");
            break;

        case _DBLARRW:
            if (record->event.pressed) return true;
            SEND_STRING("=>");
            break;

        case VRSN:
            if (record->event.pressed) {
                SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            }
            return false;
            break;
        case RGB_SLD:
            if (record->event.pressed) {
                #ifdef RGBLIGHT_ENABLE
                rgblight_mode(1);
                #endif
            }
            return false;
            break;
    }
    return true;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

LEADER_EXTERNS();

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_Q) {
      // Anything you can do in a macro.
      SEND_STRING("QMK is awesome.");
    }
    SEQ_ONE_KEY(KC_GRAVE) {
      SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
    }
    SEQ_ONE_KEY(KC_CAPS) {
      reset_keyboard();
    }
    SEQ_ONE_KEY(KC_ESC) {
      reset_keyboard();
    }
  }

  uint8_t layer = biton32(layer_state);

  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer) {
    // TODO: Make this relevant to the ErgoDox EZ.
    case 1:
      ergodox_right_led_1_on();
      break;
    case 2:
      ergodox_right_led_2_on();
      break;
    default:
      // none
      break;
  }
}
