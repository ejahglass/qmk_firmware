// !!! DO NOT ADD #pragma once !!! //
RGB_MATRIX_EFFECT(layer5)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static void layer5_init(effect_params_t* params) {
  makeBasicColors(7);
  initGlitter(0);
  LAYER = 5;
}

static bool layer5_run(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    unsetEntireBoard(0);
    doRainbow(LAYER);
    for(int i=led_min; i<=led_max; i++) {
        if (isShiftNumbers(i)) {
            setRGB(i, blue);
        }
        else if (isShiftPrintScreen(i)) {
            setRGB(i, lightblue);
        }
        else if (isShiftLayers(i)) {
            doRainbow2(i);
        }
        else if (isMedia(i)) {
            setRGB(i, gold);
        }
        else if (isVimKeys(i)) {
            setRGB(i, coldwhite);
        }
        else if (isArrow(i)) {
            setRGB(i, vapor2);
        }
        // Fn+B for ~1 second is keyboard bootloader 
        else if (i == 49) {
            doGlitter(i, orange);
        }
        else if (isKey(i)) {
            setRGB(i, off);
        }
        else if (isGlow(i)) {
            doGlitter(i, green);
        }

    }
    return led_max < DRIVER_LED_TOTAL;
}

static bool layer5(effect_params_t* params) {
  if (params->init) layer5_init(params);
  return layer5_run(params);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS