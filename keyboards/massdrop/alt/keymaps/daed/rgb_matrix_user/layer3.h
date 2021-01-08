// !!! DO NOT ADD #pragma once !!! //
RGB_MATRIX_EFFECT(layer3)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static void layer3_init(effect_params_t* params) {
  makeBasicColors(7);
  LAYER = 3;
  initGlitter(0);
}

static bool layer3_run(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);
  unsetEntireBoard(0);
  doRainbow(LAYER);
  for(int i=led_min; i<=led_max; i++) {
    if (isVimKeys(i)) {
      doGlitter(i, vapor1);
    }
    else if (isKey(i) && isPrintable(i)) {
      setRGB(i, vapor1);
    }
    else if (isKey(i) && !isPrintable(i)) {
      setRGB(i, vapor3);
    }
    else if (isGlow(i))
    {
      doMarquee(i, LAST_KEY+1, led_max, vapor3, vapor4);
    }   
  }
  return led_max < DRIVER_LED_TOTAL;
}

// e.g: A simple effect, self-contained within a single method
static bool layer3(effect_params_t* params) {
  if (params->init) layer3_init(params);
  return layer3_run(params);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS