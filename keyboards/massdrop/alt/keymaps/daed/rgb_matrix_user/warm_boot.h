// !!! DO NOT ADD #pragma once !!! //
RGB_MATRIX_EFFECT(warmboot)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

Color RED;
Color WHITE;

int armed = 0;
int brightMod = 0;
uint32_t delay = 0;
int timer = 0;

static void warmboot_init(effect_params_t* params) {
    makeBasicColors(7);
    initGlitter(0);
    LAYER = 1;
}

static Color setBrightness(Color col) {
    int scale = 0;
    scale = brightMod;
    if (scale > col.r) {
        scale = col.r;
    }
    col.r = col.r - (col.r - scale);
    
    scale = brightMod;
    if (scale > col.g) {
        scale = col.g;
    }
    col.g = col.g - (col.g - scale);
    
    scale = brightMod;
    if (scale > col.b) {
        scale = col.b;
    }
    col.b = col.b - (col.b - scale);
    return col;
}

static bool warmboot_run(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    unsetEntireBoard(0);


    // every X ticks after armed, we reset the timer
    // when we do, increment the brightness.  This
    // increases brightness at a linear rate, but it
    // will be used proportionally for any given color.
    // since it's per color channel, this should also
    // work well with the glitter effect. 
    if (timer == 60) {
        timer = 0;
        if (brightMod < 20) {
            brightMod += 1;
        }
        else if (brightMod < 250) {
            brightMod += 5;    
        } 
    }
    // 255 is the cap on brightMod.  Reset it to 0 to have the effect recurring.
    // We will disable this when we're not troubleshooting.
    if (brightMod == 250) {
        doRainbow(LAYER);
    }
    // if armed, we count ticks
    if (armed) {
        timer++;
    }
    // wait 200 ticks before arming effects
    delay++;
    if (delay == 1000) {
        armed = 1;
    }

    for(int i=led_min; i<=led_max; i++) {
        if (isModifier(i, TAB)) {
            // light grey-ish purple
            setRGB(i, setBrightness(magenta));
        }
        else if (isModifier(i, CTRL)) {
            // blue
            setRGB(i, setBrightness(blue));
        }
        else if (isModifier(i, SHIFT)) {
            // orange
            setRGB(i, setBrightness(orange));
        }
        else if (isModifier(i, FN)) {
            // blue (as ctrl)
            setRGB(i, setBrightness(blue));
        }
        else if (isModifier(i, META)) {
            // red
            setRGB(i, setBrightness(red));
        }
        else if (isModifier(i, ALT)) {
            // blue (as ctrl)
            setRGB(i, setBrightness(blue));
        }
        else if (isModifier(i, SPACE)) {
            doGlitter(i, setBrightness(grey));
        }
        else if (isModifier(i, ENTER)) {
            // green
            setRGB(i, setBrightness(green));
        }
        else if (isModifier(i, BACKSPACE)) {
            // light grey-ish purple (as tab)
            setRGB(i, setBrightness(magenta));
        }
        else if (isKey(i) && !isHomeKeys(i) && isPrintable(i)) {
            //setRGB(i, alphaNum);
            doGlitter(i, setBrightness(grey));
        }
        else if (isHomeKeys(i)) {
            //doGlitter(i, white);
            setRGB(i, setBrightness(white));
        }
        else if (isArrow(i)) {
            setRGB(i, setBrightness(white));
        }
        else if (isMedia(i)) {
            setRGB(i, setBrightness(pink));
        }
        else if (isGlow(i)) {
            doMarquee(i, LAST_KEY+1, led_max, setBrightness(blue), setBrightness(gold));
        }   
    }
    return led_max < DRIVER_LED_TOTAL;
}


static bool warmboot(effect_params_t* params) {
  if (params->init) warmboot_init(params);
  return warmboot_run(params);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS