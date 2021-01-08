// !!! DO NOT ADD #pragma once !!! //
RGB_MATRIX_EFFECT(layer4)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static void layer4_init(effect_params_t* params) {
  makeBasicColors(7);
  LAYER = 4;
  initGlitter(0);
}

static bool layer4_run(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);
  unsetEntireBoard(0);
  doRainbow(LAYER);
  for(int i=led_min; i<=led_max; i++) {
    if (byRow(i, 1)) {
      doGlitter(i, fadeColor(0, 4, red, green));
    }
    if (byRow(i, 2)) {
      doGlitter(i, fadeColor(0, 4, green, red));
    }
    if (byRow(i, 3)) {
      doGlitter(i, fadeColor(0, 4, red, green));
    }
    if (byRow(i, 4)) {
      doGlitter(i, fadeColor(0, 4, green, red));
    }
    if (byRow(i, 5)) {
      doGlitter(i, fadeColor(0, 4, red, green));
    }
    if (isGlow(i)) {
      doMarquee(i, LAST_KEY+1, led_max, green, red);
    }
  }
  return led_max < DRIVER_LED_TOTAL;
}

// e.g: A simple effect, self-contained within a single method
static bool layer4(effect_params_t* params) {
  if (params->init) layer4_init(params);
  return layer4_run(params);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS