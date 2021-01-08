#pragma once

#include "quantum.h"
#include "config_led.h"
#include "matrix.h"

#include "i2c_master.h"
#include "md_rgb_matrix.h" //For led keycodes
#include "usb/udi_cdc.h"
#include "usb/usb2422.h"

#define LAYOUT_65_ansi_blocker( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K10, K11, K12, K13, K14, K15, \
    K16, K17, K18, K19, K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K30, \
    K31, K32, K33, K34, K35, K36, K37, K38, K39, K40, K41, K42, K43, K44, K45, \
    K46, K47, K48, K49, K50, K51, K52, K53, K54, K55, K56, K57, K58, K59, K60, \
    K61, K62, K63, K64, K65, K66, K67 \
) { \
    {   K01,   K02,   K03,   K04,   K05,   K06,   K07,   K08,   K09,   K10,   K11,   K12,   K13,   K14,   K15, }, \
    {   K16,   K17,   K18,   K19,   K20,   K21,   K22,   K23,   K24,   K25,   K26,   K27,   K28,   K29,   K30, }, \
    {   K31,   K32,   K33,   K34,   K35,   K36,   K37,   K38,   K39,   K40,   K41,   K42, KC_NO,   K43,   K44, }, \
    {   K45, KC_NO,   K46,   K47,   K48,   K49,   K50,   K51,   K52,   K53,   K54,   K55,   K56,   K57,   K58, }, \
    {   K59,   K60,   K61, KC_NO, KC_NO, KC_NO,   K62, KC_NO, KC_NO, KC_NO,   K63,   K64,   K65,   K66,   K67, }, \
}

#define TOGGLE_FLAG_AND_PRINT(var, name) { \
        if (var) { \
            dprintf(name " disabled\r\n"); \
            var = !var; \
        } else { \
            var = !var; \
            dprintf(name " enabled\r\n"); \
        } \
    }

#define LAYOUT LAYOUT_65_ansi_blocker // Ensure that user made existing keymaps do not break. 

extern rgb_config_t rgb_matrix_alt_config;