// !!! DO NOT ADD #pragma once !!! //
RGB_MATRIX_EFFECT(warm_boot)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

Color RED;
Color WHITE;

static void layer1_init(effect_params_t* params) {
    makeBasicColors(7);
    initGlitter(0);
    LAYER = 1;
}

static bool layer1_run(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    unsetEntireBoard(0);
    doRainbow(LAYER);
    for(int i=led_min; i<=led_max; i++) {
        if (isModifier(i, TAB)) {
            // light grey-ish purple
            setRGB(i, magenta);
        }
        else if (isModifier(i, CTRL)) {
            // blue
            setRGB(i, blue);
        }
        else if (isModifier(i, SHIFT)) {
            // orange
            setRGB(i, orange);
        }
        else if (isModifier(i, FN)) {
            // blue (as ctrl)
            setRGB(i, blue);
        }
        else if (isModifier(i, META)) {
            // red
            setRGB(i, red);
        }
        else if (isModifier(i, ALT)) {
            // blue (as ctrl)
            setRGB(i, blue);
        }
        else if (isModifier(i, SPACE)) {
            doGlitter(i, grey);
        }
        else if (isModifier(i, ENTER)) {
            // green
            setRGB(i, green);
        }
        else if (isModifier(i, BACKSPACE)) {
            // light grey-ish purple (as tab)
            setRGB(i, magenta);
        }
        else if (isKey(i) && !isHomeKeys(i) && isPrintable(i)) {
            //setRGB(i, alphaNum);
            doGlitter(i, grey);
        }
        else if (isHomeKeys(i)) {
            //doGlitter(i, white);
            setRGB(i, white);
        }
        else if (isArrow(i)) {
            setRGB(i, white);
        }
        else if (isMedia(i)) {
            setRGB(i, pink);
        }
        else if (isGlow(i)) {
            doMarquee(i, LAST_KEY+1, led_max, blue, gold);
        }   
    }
    return led_max < DRIVER_LED_TOTAL;
}


static bool layer1(effect_params_t* params) {
  if (params->init) layer1_init(params);
  return layer1_run(params);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS