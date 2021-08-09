#include QMK_KEYBOARD_H

enum layer_names {
    _DV_CASG,
    _DV_SCAG,
    _DV,
    _ALT,
    _FUN,
};

enum custom_keycodes {
    _CMNT = SAFE_RANGE,
    _BLKCMNT,
    _ARROW,
    _DBLARRW,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /*
   *  '   ,   .   P   Y        ||      F    G    C    R    L
   *  A   O   E   U   I        ||      D    H    T    N    S
   *  ;   Q   J   K   X   tab  || ent  B    M    W    V    Z
   *  =   `   \  FUN bksp ALT  || ent spc  FUN   /   CAP   -
   */
  [_DV] = LAYOUT( /* Dvorak */
    KC_QUOTE,  KC_COMMA, KC_DOT,    KC_P,     KC_Y,                      KC_F,    KC_G,     KC_C,     KC_R,    KC_L,
    KC_A,      KC_O,     KC_E,      KC_U,     KC_I,                      KC_D,    KC_H,     KC_T,     KC_N,    KC_S,
    KC_SCOLON, KC_Q,     KC_J,      KC_K,     KC_X,    KC_TAB, KC_ENTER, KC_B,    KC_M,     KC_W,     KC_V,    KC_Z,
    KC_EQUAL,  KC_GRAVE, KC_BSLASH, MO(_FUN), KC_BSPC, KC_ESC, KC_ENTER, KC_SPC,  MO(_FUN), KC_SLASH, KC_CAPS, KC_MINUS ),

  [_DV_SCAG] = LAYOUT( /* Dvorak - Shift Control Alt Command */
    KC_QUOTE,     KC_COMMA,     KC_DOT,       KC_P,         KC_Y,                                        KC_F,   KC_G,         KC_C,         KC_R,         KC_L,
    LSFT_T(KC_A), LCTL_T(KC_O), LALT_T(KC_E), LGUI_T(KC_U), KC_I,                                        KC_D,   RGUI_T(KC_H), RALT_T(KC_T), RCTL_T(KC_N), RSFT_T(KC_S),
    KC_SCOLON,    KC_Q,         KC_J,         KC_K,         KC_X,    KC_TAB,          KC_ENTER,          KC_B,   KC_M,         KC_W,         KC_V,         KC_Z,
    KC_EQUAL,     KC_GRAVE,     KC_BSLASH,    MO(_FUN),     KC_BSPC, LT(_ALT,KC_ESC), LT(_ALT,KC_ENTER), KC_SPC, MO(_FUN),     KC_SLASH,     KC_CAPS,      KC_MINUS ),

  [_DV_CASG] = LAYOUT( /* Dvorak - Control Alt Shift Command */
    KC_QUOTE,     KC_COMMA,     KC_DOT,       KC_P,         KC_Y,                                        KC_F,   KC_G,         KC_C,         KC_R,         KC_L,
    LCTL_T(KC_A), LALT_T(KC_O), LSFT_T(KC_E), LGUI_T(KC_U), KC_I,                                        KC_D,   RGUI_T(KC_H), RSFT_T(KC_T), RALT_T(KC_N), RCTL_T(KC_S),
    KC_SCOLON,    KC_Q,         KC_J,         KC_K,         KC_X,    KC_TAB,          KC_ENTER,          KC_B,   KC_M,         KC_W,         KC_V,         KC_Z,
    KC_EQUAL,     KC_GRAVE,     KC_BSLASH,    MO(_FUN),     KC_BSPC, LT(_ALT,KC_ESC), LT(_ALT,KC_ENTER), KC_SPC, MO(_FUN),     KC_SLASH,     KC_CAPS,      KC_MINUS ),


  /*
   *  1    2    3    4    5    ||    6    7    8    9    0
   *  !    @    #    $    %    ||    ^    &    *    (    )
   *  :    ~    |    ->   =>   ||   bcom  -    ?    {    }
   *  +                                   _   //    [    ]
   */
  [_ALT] = LAYOUT( 
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
    KC_COLN, KC_TILD, KC_PIPE, _ARROW,  _DBLARRW, _______, _______, _BLKCMNT,KC_MINUS,KC_QUES, KC_LCBR, KC_RCBR,
    KC_PLUS, _______, _______, _______, _______,  _______, _______, _______, KC_UNDS, _CMNT,   KC_LBRC, KC_RBRC ),
    

  /*
   * F1  F2  F3  F4  F5      ||       F6   F7    F8    F9   F10
   *                         ||      bksp   ←    ↑     →    F11
   *                    home || pgup             ↓          F12
   *                    end  || pgdn 
   */
  [_FUN] = LAYOUT(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
    _______, _______, _______, _______, _______,                   KC_BSPC, KC_LEFT, KC_UP,   KC_RGHT, KC_F11,
    _______, _______, _______, _______, _______, KC_HOME, KC_PGUP, _______, _______, KC_DOWN, _______, KC_F12,
    _______, _______, _______, _______, _______, KC_END,  KC_PGDN, _______, _______, _______, _______, _______),

};


uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // case SFT_T(KC_SPC):
        //     return TAPPING_TERM + 1250;
        // case LT(1, KC_GRV):
        //     return 130;
        default:
            return TAPPING_TERM;
    }
}

#define SSLEFT() SS_TAP(X_LEFT)

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) return true;

    switch (keycode) {
    case _CMNT:
        SEND_STRING("//");
        break;

    case _BLKCMNT:
        SEND_STRING("/*  */" SSLEFT() SSLEFT() SSLEFT());
        break;

    case _ARROW:
        SEND_STRING("->");
        break;

    case _DBLARRW:
        SEND_STRING("=>");
        break;

    }
    return true;
};

