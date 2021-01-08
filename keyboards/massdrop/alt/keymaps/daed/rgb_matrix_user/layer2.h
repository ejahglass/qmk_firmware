// !!! DO NOT ADD #pragma once !!! //
RGB_MATRIX_EFFECT(layer2)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static void layer2_init(effect_params_t* params) {
  makeBasicColors(7);
  initGlitter(0);
  LAYER = 2;

}

static bool layer2_run(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);
  unsetEntireBoard(0);
  doRainbow(LAYER);
  for(int i=led_min; i<=led_max; i++) {
    if (isWASD(i)) {
      doGlitter(i, blue);
    }
    else if (isGamerKey(i)) {
      doGlitter(i, gold);
    }
    else if (isMedia(i)) {
      doGlitter(i, red);
    }
    else if (isKey(i) && !isPrintable(i)) {
      setRGB(i, blue);
    }
    else if (isGlow(i)) {
      doMarquee(i, LAST_KEY+1, led_max, blue, red);
    }  
    else {
      doGlitter(i, pink);
    }
  }
  return led_max < DRIVER_LED_TOTAL;
}

// e.g: A simple effect, self-contained within a single method
static bool layer2(effect_params_t* params) {
  if (params->init) layer2_init(params);
  return layer2_run(params);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS