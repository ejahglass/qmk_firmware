#include QMK_KEYBOARD_H
#include "process_unicode.h"

enum alt_keycodes {
    U_T_AUTO = SAFE_RANGE, //USB Extra Port Toggle Auto Detect / Always Active
    U_T_AGCR,              //USB Toggle Automatic GCR control
    DBG_TOG,               //DEBUG Toggle On / Off
    DBG_MTRX,              //DEBUG Toggle Matrix Prints
    DBG_KBD,               //DEBUG Toggle Keyboard Prints
    DBG_MOU,               //DEBUG Toggle Mouse Prints
    MD_BOOT,               //Restart into bootloader after hold timeout
	
	WIDETXT, // w i d e t e x t   f o r   a   w i d e   b o y
    TAUNTXT, // FoR ThE UlTiMaTe sHiTpOsTiNg eXpErIeNcE
	CHRS,    // cheers
	OMEGALUL, // OMEGALUL
	LULW,     // LULW

    UC_HELP,   // URL for QMK unicode help
    UC_SHRG,   // shrug       - ¯\_(ツ)_/¯
    UC_FLIP,   // table flip  - (ノಠ痊ಠ)ノ彡┻━┻
    UC_FU,     // fuck you    - ╭∩╮(･◡･)╭∩╮
	UC_MIGHTY, // mighty donger - ᕙ༼ຈل͜ຈ༽ᕗ
	UC_JAM,    // jammin        - ♫ ┌༼ຈل͜ຈ༽┘ ♪

#define UC_100  X(E_100)  // hundo       - 💯
#define UC_BBB  X(E_BBB)  // dat B       - 🅱️
#define UC_CLAP X(E_CLAP) // clap        - 👏
#define UC_EYES X(E_EYES) // shifty eyes - 👀
#define UC_GRIM X(E_GRIM) // grimmace    - 😬
#define UC_THNK X(E_THNK) // thinking    - 🤔
#define UC_UGHH X(E_UGHH) // UGHHHHH     - 😩
#define UC_THMB X(E_THMB) // thumbs up   - 👍
};

enum unicode_names {
    E_100,
    E_BBB,
    E_CLAP,
    E_EYES,
    E_GRIM,
    E_THNK,
    E_UGHH,
	E_THMB,
};

const uint32_t PROGMEM unicode_map[] = {
    [E_BBB]  = 0x1F171, // dat B       - 🅱️
    [E_100]  = 0x1F4AF, // hundo       - 💯
    [E_EYES] = 0x1F440, // shifty eyes - 👀
    [E_CLAP] = 0x1F44F, // clap        - 👏
    [E_GRIM] = 0x1f62c, // grimmace    - 😬
    [E_THNK] = 0x1f914, // thinking    - 🤔
    [E_UGHH] = 0x1f629, // UGHHHHH     - 😩
	[E_THMB] = 0x1F44D, // thumbs up   - 👍
};

enum alt_layers {
    _QWERTY,
    _ACTIONS,
    _MEMES,
    _ADJUST,
	_TWITCH,
};

#define TG_NKRO MAGIC_TOGGLE_NKRO //Toggle 6KRO / NKRO mode
#define ___X___ XXXXXXX // KC_NO
#define TAPPING_TOGGLE 2
keymap_config_t keymap_config;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_65_ansi_blocker(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,  \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_HOME, \
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGUP, \
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   KC_PGDN, \
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(1),   KC_LEFT, KC_DOWN, KC_RGHT  \
    ),
    [_ACTIONS] = LAYOUT_65_ansi_blocker(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_MUTE, \
        _______, _______, _______, _______, _______, _______, _______, U_T_AUTO,U_T_AGCR,_______, KC_PSCR, KC_SLCK, KC_PAUS, _______, KC_MEDIA_PLAY_PAUSE, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, KC_VOLU, \
        _______, _______, _______, _______, _______, MD_BOOT, NK_TOGG, DBG_TOG, _______, _______, _______, _______,          KC_PGUP, KC_VOLD, \
        MO(3), _______, TAUNTXT,                            WIDETXT,                            MO(2), _______, KC_MPRV, KC_PGDN, KC_MNXT  \
    ),

    [_MEMES] = LAYOUT(
        TG(_TWITCH), UC_100,  ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, UC_THMB, ___X___, ___X___, \
        ___X___, ___X___, ___X___, UC_EYES, UC_FU, UC_THNK, ___X___, UC_UGHH, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, \
        ___X___, ___X___, UC_SHRG, ___X___, UC_FLIP, UC_GRIM, ___X___, UC_JAM, ___X___, ___X___, ___X___, ___X___,          ___X___, ___X___, \
        ___X___, ___X___, ___X___, UC_CLAP, ___X___, UC_BBB,  ___X___, UC_MIGHTY, ___X___, ___X___, UC_HELP, ___X___,          ___X___, ___X___, \
        UC_M_OS, UC_M_WC, UC_M_WI,                            CHRS,                            ___X___, ___X___, ___X___, ___X___, ___X___  \
    ),	

    [_ADJUST] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, RGB_SPD, RGB_VAI, RGB_SPI, RGB_HUI, RGB_SAI, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, RGB_RMOD, RGB_VAD, RGB_MOD, RGB_HUD, RGB_SAD, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, RGB_TOG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______  \
    ),
    
	    [_TWITCH] = LAYOUT(
        TG(_TWITCH), ___X___,  ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, \
        ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, \
        ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___,          ___X___, ___X___, \
        ___X___, ___X___, ___X___, ___X___, ___X___, ___X___,  ___X___, ___X___, ___X___, ___X___, ___X___, ___X___,          ___X___, ___X___, \
        ___X___, ___X___, ___X___,                           KC_SPC,                            LULW, OMEGALUL, ___X___, ___X___, ___X___  \
    ),	
    
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
};

#define MODS_SHIFT  (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT))
#define MODS_CTRL  (get_mods() & MOD_BIT(KC_LCTL) || get_mods() & MOD_BIT(KC_RCTRL))
#define MODS_ALT  (get_mods() & MOD_BIT(KC_LALT) || get_mods() & MOD_BIT(KC_RALT))


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint32_t key_timer;
	
	static struct {
        bool on;
        bool first;
    } w_i_d_e_t_e_x_t = {false, false};

    if (w_i_d_e_t_e_x_t.on) {
        if (record->event.pressed) {
            switch (keycode) {
                case KC_A...KC_0:
                case KC_SPC:
                    if (w_i_d_e_t_e_x_t.first) {
                        w_i_d_e_t_e_x_t.first = false;
                    } else {
                        send_char(' ');
                    }
                    break;
                case KC_ENT:
                    w_i_d_e_t_e_x_t.first = true;
                    break;
                case KC_BSPC:
                    send_char('\b'); // backspace
                    break;
            }
        }
    }

    static bool tAuNtTeXt = false;

    if (tAuNtTeXt) {
        if (record->event.pressed) {
            if (keycode != KC_SPC)
                tap_code(KC_CAPS);
        }
    }

    switch (keycode) {
        /* z e s t y   m e m e s */
        case WIDETXT:
            if (record->event.pressed) {
                w_i_d_e_t_e_x_t.on = !w_i_d_e_t_e_x_t.on;
                w_i_d_e_t_e_x_t.first = true;
            }
            return false;
        case TAUNTXT:
            if (record->event.pressed) {
                tAuNtTeXt = !tAuNtTeXt;
            }
            return false;
	
	    /* Unicode */
        case UC_HELP:
            if (record->event.pressed) {
                SEND_STRING("https://beta.docs.qmk.fm/features/feature_unicode#input-modes"SS_TAP(X_ENTER));
            }
            return false;
        case UC_SHRG: // ¯\_(ツ)_/¯
            if (record->event.pressed) {
                send_unicode_hex_string("00AF 005C 005F 0028 30C4 0029 005F 002F 00AF");
            }
            return false;
        case UC_FLIP: // (ノಠ痊ಠ)ノ彡┻━┻
            if (record->event.pressed) {
                send_unicode_string("(ノಠ痊ಠ)ノ彡┻━┻");
            }
            return false;
        case UC_FU: // ╭∩╮(･◡･)╭∩╮
            if (record->event.pressed) {
                send_unicode_string("╭∩╮(･◡･)╭∩╮");
            }
            return false;
			
		case UC_MIGHTY: // ᕙ༼ຈل͜ຈ༽ᕗ
            if (record->event.pressed) {
                send_unicode_string("ᕙ༼ຈل͜ຈ༽ᕗ");
            }
            return false;	
			
		case UC_JAM: // ♫ ┌༼ຈل͜ຈ༽┘ ♪
		    if (record->event.pressed) {
				send_unicode_string("♫ ┌༼ຈل͜ຈ༽┘ ♪");
			}
			return false;
    
        /* Text String Macros */
        case CHRS:
            if (record->event.pressed) {
            // when keycode CHRS is pressed
                send_unicode_string("cheers! ( ຈ∀ຈ)y─┛");
            } else {
            // when keycode CHRS is released
            }
            return true;
			
		case OMEGALUL:
            if (record->event.pressed) {
            // when keycode OMEGALUL is pressed
                send_string("OMEGALUL");
            } else {
            // when keycode OMEGALUL is released
            }
            return true;
			
		case LULW:
            if (record->event.pressed) {
            // when keycode LULW is pressed
                send_string("LULW");
            } else {
            // when keycode LULW is released
            }
            return true;


  /* Massdrop debug */
		
        case U_T_AUTO:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_extra_manual, "USB extra port manual mode");
            }
            return false;
        case U_T_AGCR:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_gcr_auto, "USB GCR auto mode");
            }
            return false;
        case DBG_TOG:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_enable, "Debug mode");
            }
            return false;
        case DBG_MTRX:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_matrix, "Debug matrix");
            }
            return false;	
        case DBG_KBD:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_keyboard, "Debug keyboard");
            }
            return false;
        case DBG_MOU:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_mouse, "Debug mouse");
            }
            return false;				
        case MD_BOOT:
            if (record->event.pressed) {
                key_timer = timer_read32();
            } else {
                if (timer_elapsed32(key_timer) >= 500) {
                    reset_keyboard();
                }
            }
            return false;

        case RGB_TOG:
            if (record->event.pressed) {
              switch (rgb_matrix_get_flags()) {
                case LED_FLAG_ALL: {
                    rgb_matrix_set_flags(LED_FLAG_KEYLIGHT);
                    rgb_matrix_set_color_all(0, 0, 0);
                  }
                  break;
                case LED_FLAG_KEYLIGHT: {
                    rgb_matrix_set_flags(LED_FLAG_UNDERGLOW);
                    rgb_matrix_set_color_all(0, 0, 0);
                  }
                  break;
                case LED_FLAG_UNDERGLOW: {
                    rgb_matrix_set_flags(LED_FLAG_NONE);
                    rgb_matrix_disable_noeeprom();                  }
                  break;
                default: {
                    rgb_matrix_set_flags(LED_FLAG_ALL);
                    rgb_matrix_enable_noeeprom();
                  }
                  break;
              }
            }
            return false;
        default:
            return true; //Process all other keycodes normally
    }
}

uint8_t prev = _QWERTY;
uint32_t desired = 1;
uint16_t hue = 120;
uint16_t sat = 255;
uint16_t val = 255;

void get_hsv(void) {
    hue = rgblight_get_hue();
    sat = rgblight_get_sat();
    val = rgblight_get_val();
}

void reset_hsv(void) {
    rgblight_sethsv(hue, sat, val);
}

void matrix_init_user() {
    rgblight_mode(desired);
    rgblight_enable();
    reset_hsv();
}

uint32_t layer_state_set_user(uint32_t state) {
  uint8_t layer = biton32(state);
  if (prev!=_ADJUST) {
      switch (layer) {
        case _QWERTY:
          rgblight_mode(desired);
          if(desired < 6 || (desired > 14 && desired < 25)) { // Skip in rainbow modes.
            reset_hsv();
          }
          break;
        
        case _ACTIONS:
          rgblight_mode(14);
          break;
        
        case _MEMES:
          rgblight_mode(5);
          break;

        case _ADJUST:
          rgblight_mode(desired);
          break;
      }
  } else {
      desired = rgblight_get_mode();
      get_hsv();
  }
  prev = layer;
  return state;
}