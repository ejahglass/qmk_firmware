RGB_MATRIX_EFFECT(common)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#include <math.h>

#define LAST_KEY 66
#define MAX_TICKS 150
// needs to be an even number for now
#define GLITTER_RANGE 100
#define GLITTER_STEP 20
#define LED_COUNT 106

static bool set[LED_COUNT];
static uint8_t offset[LED_COUNT];
static uint8_t marqueeActive = 0;
static uint16_t marqueeTicks = 0;
static uint8_t LAYER;

struct color {
  uint8_t r;
  uint8_t g; 
  uint8_t b;
};
typedef struct color Color;

enum mods {
    ESC,
    TAB,
    CTRL,
    SHIFT,
    FN,
    META,
    ALT,
    SPACE,
    ENTER,
    BACKSPACE    
};

Color red;
Color blue;
Color pink;
Color yellow;
Color gold;
Color green;
Color white;
Color lightblue;
Color magenta;
Color orange;
Color grey;
Color coldwhite;
Color off;

// some vaporwave colors
Color vapor1;
Color vapor2;
Color vapor3;
Color vapor4;

// this requires an int passed even though it doesn't do anything.
static void makeBasicColors(int x) {
    red.r    = 255;
    red.g    =   0;
    red.b    =   0;
    lightblue.r =  40;
    lightblue.g =  40;
    lightblue.b = 255;
    blue.r   =   0;
    blue.g   =   0;
    blue.b   = 255;
    magenta.r= 200;
    magenta.g=  75;
    magenta.b= 200;
    pink.r   = 254;
    pink.g   =   1;
    pink.b   = 154;
    yellow.r = 255;
    yellow.g = 255;
    yellow.b =   0;
    gold.r   = 200;
    gold.g   = 200;
    gold.b   =   0;
    green.r  =   0;
    green.g  = 225;
    green.b  =   0;
    white.r  = 255;
    white.g  = 255;
    white.b  = 255;
    orange.r = 255;
    orange.g = 140;
    orange.b =   0;
    grey.r   = 129;
    grey.g   = 140;
    grey.b   = 190;
    coldwhite.r = 200;
    coldwhite.g = 225;
    coldwhite.b = 255;
    off.r    = 0;
    off.g    = 0;
    off.b    = 0;
    vapor1.r = 255;
    vapor1.g = 113;
    vapor1.b = 206;
    vapor2.r =   1;
    vapor2.g = 205;
    vapor2.b = 254;
    vapor3.r =   5;
    vapor3.g = 255;
    vapor3.b = 161;
    vapor4.r = 185;
    vapor4.g = 103;
    vapor4.b = 255;
}

static void setRGB(int x, Color rgb) {
    int flag = rgb_matrix_get_flags();
    bool on = false;
    // LED_FLAG_ALL
    if (flag == 255) {
        on = true;
    }
    // LED_FLAG_UNDERGLOW
    else if (flag == 2 && x > LAST_KEY) {
        on = true;
    }
    // LED_FLAG_KEYLIGHT
    else if (flag == 4 && x <= LAST_KEY) {
        on = true;
    }
    if (!set[x] && on) {
        rgb_matrix_set_color(x, rgb.r, rgb.g, rgb.b);
        set[x] = true;
    }
}

static void unset(int x) {
    set[x] = false;
}

static void unsetEntireBoard(int x) {
    for(int i=0; i<LED_COUNT; i++) {
        unset(i);
    }
}
    
bool isKey(int x) {
    if (x <= LAST_KEY) 
        return true;
    return false;
}
bool isGlow(int x) {
    if (x > LAST_KEY) 
        return true;
    return false;
}
bool isHomeKeys(int x) {
    // asdfjkl;
    if (x >= 31 && x <= 34) 
        return true;
    if (x >= 37 && x <= 40) 
        return true;
    return false;
}
bool isVimKeys(int x) {
    // hjkl
    if (x >= 36 && x <= 39)
        return true;
    return false;
}
bool isPrintable(int x) {
    if (x >= 1 && x <= 12)
        return true;
    if (x >= 16 && x <= 28)
        return true;
    if (x >= 31 && x <= 41)
        return true;
    if (x >= 45 && x <= 54)
        return true;
    return false;
}

bool isWASD(int x) {
    if (x == 17 || (x >= 31 && x <=33))
        return true;
    return false;
}

bool isGamerKey(int x) {
    if (x >= 1 && x <= 5)
        return true;
    if (x >= 16 && x <= 20)
        return true;
    if (x >= 31 && x <= 35)
        return true;
    if (x >= 45 && x <= 48)
        return true;
    return false;
}

bool isArrow(int x) {
    if (x >= 64 && x <= 66)
        return true;
    if (x == 56)
        return true;
    return false;
}

bool isModifier(int x, int modifier) {
    switch (modifier) {
        case ESC:
            if (x == 0) return true;
            else return false;
        case TAB:
            if (x == 15) return true;
            else return false;
        case CTRL:
            if (x == 30 || x == 63) return true;
            else return false;
        case SHIFT:
            if (x == 44 || x == 55) return true;
            else return false;        
        case FN:
            if (x == 58) return true;
            else return false;               
        case META:
            if (x == 59) return true;
            else return false;  
        case SPACE:
            if (x == 61) return true;
            else return false;  
        case ALT:
            if (x == 60 || x == 62) return true;
            else return false; 
        case ENTER:
            if (x == 42) return true;
            else return false;  
        case BACKSPACE:
            if (x == 13) return true;
            else return false;  
        default:
            return false;
    }
}

bool isShiftNumbers(int x) {
    if (x >= 1 && x <= 12)
        return true;
    return false;
}

bool isShiftPrintScreen(int x) {
    if (x >= 25 && x <= 27)
        return true;
    return false;
}

bool isShiftLayers(int x) {
    if (x >= 51 && x <= 54)
        return true;
    return false;
}

bool isMedia(int x) {
    if (x == 14 || x ==29 || x==43 || x==57)
        return true;
    return false;
}

static void initGlitter(int x) {
    for(int i=0; i<=105; i++) {
        offset[i] = 12 * rand();
    }
}

bool byRow(int x, int row) {
    switch (row) {
        case 1:
            if (x >=  0 && x <= 14) 
                return true;
            break;
        case 2:
            if (x >= 15 && x <= 29)
                return true;
            break;
        case 3:
            if (x >= 30 && x <= 43)
                return true;
            break;
        case 4:
            if (x >= 44 && x <= 57)
                return true;
            break;
        case 5:
            if (x >= 58 && x <= 66)
                return true;
            break;
        default:
            return false;
    }
    return false;
}

static Color fadeColor(int curStep, int steps, Color color1, Color color2) {
    Color faded;
    int fade_r = (color1.r - color2.r) / steps;
    int fade_g = (color1.g - color2.g) / steps;
    int fade_b = (color1.b - color2.b) / steps;
    faded.r = fade_r*(curStep) + color2.r;
    faded.g = fade_g*(curStep) + color2.g;
    faded.b = fade_b*(curStep) + color2.b;
    return faded;
}

/*
 *  
 *  Animations start here
 * 
 */
static void doGlitter(int i, Color base) {
    uint16_t time = scale16by8(g_rgb_counters.tick, rgb_matrix_config.speed / 4);
    if (rand() * 50 == 1) {
        if (rand() * 2 == 1) {
            offset[i] += 2;
        }
        else {
            offset[i] -= 2;
        }
    }
    float val = (((float)sin8(time + offset[i]) / 256)/2.1) + .05;
    Color glit;
    glit.r = base.r * val;
    glit.g = base.g * val;
    glit.b = base.b * val;
    setRGB(i, glit);
    //rgb_matrix_set_color(i, newR, newG, newB);
}

static void doRainbow(int i) {
    HSV hsv = { 0, 200, 200 };
    uint8_t time = scale16by8(g_rgb_counters.tick, rgb_matrix_config.speed / 4);
    hsv.h = abs8(g_led_config.point[i].y - 32) + (g_led_config.point[i].x - time) + 50;

    RGB rgb = hsv_to_rgb(hsv);
    Color layer;
    layer.r = rgb.r;
    layer.g = rgb.g;
    layer.b = rgb.b;
    setRGB(i, layer);
}

static void doRainbow2(int i) {
    if (rand() * 50 == 1) {
        if (rand() * 2 == 1) {
            offset[i]++;
        }
        else {
            offset[i]--;
        }
    }
    HSV hsv = { 0, 160, 200 };
    hsv.h = scale16by8(g_rgb_counters.tick + offset[i], rgb_matrix_config.speed / 4) + (offset[i]*2);
    RGB rgb = hsv_to_rgb(hsv);
    Color layer;
    layer.r = rgb.r;
    layer.g = rgb.g;
    layer.b = rgb.b;
    setRGB(i, layer);
}

const uint8_t FADEOUT_SPEED = 120; // personal preference
/*
static bool doReactGradient(effect_params_t* params) {
  const uint16_t max_tick = 65535 / FADEOUT_SPEED;

  // calculate target color
  const HSV hsv = {
    rgb_matrix_config.hue + 80,
    rgb_matrix_config.sat,
    rgb_matrix_config.val
  };
  const RGB highlight = hsv_to_rgb(hsv);

  // Relies on hue being 8-bit and wrapping
  for (uint8_t i = led_min; i < led_max; i++) {
    // get gradient color
    const rgb_led led = g_rgb_leds[i];
    uint8_t hue = rgb_matrix_config.hue;
    if (led.matrix_co.raw != 0xFF) {
      // Keys
      hue += 10 * led.matrix_co.row;
    } else {
      // Underglow (same color as last row of keys)
      hue += 10 * (MATRIX_ROWS - 1);
    }

    HSV hsv = { hue, 0xFF, rgb_matrix_config.val };
    RGB rgb = hsv_to_rgb(hsv);

    // checks if key has been hit
    uint16_t tick = 0xffff;
    for(uint8_t j = g_last_hit_tracker.count; j > 0; j--) {
      if (g_last_hit_tracker.index[j - 1] == i) {
        tick = g_last_hit_tracker.tick[j - 1];
        break;
      }
    }
    // scale the tick down based on fadeout preferences
    tick = scale16by8(tick, FADEOUT_SPEED);
    // Linear interpolate through RGB space
    if (tick < max_tick) {
      float pct = tick / (float)max_tick;
      rgb.r = highlight.r - pct * (highlight.r - rgb.r);
      rgb.g = highlight.g - pct * (highlight.g - rgb.g);
      rgb.b = highlight.b - pct * (highlight.b - rgb.b);
    }

    rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
  }

  return led_max < DRIVER_LED_TOTAL;
}
*/
static void doMarquee(int x, int startLed, int stopLed, Color accent, Color background) {
    int ledCount = 38;

    if (scale16by8(g_rgb_counters.tick, qadd8(rgb_matrix_config.speed, 16)) % 3 == 0) 
        marqueeTicks++;
    if (marqueeTicks == 75)
    {
        marqueeActive += 1;
        marqueeTicks=0;
    }
    uint8_t steps = 12;
    Color faded;
    
    int fade_r = (accent.r - background.r) / steps;
    int fade_g = (accent.g - background.g) / steps;
    int fade_b = (accent.b - background.b) / steps;

    for (int i = 0; i <= steps; i++) {
        if (x == mod8(marqueeActive+i,ledCount)+startLed) {
            faded.r = fade_r*(i+1) + background.r;
            faded.g = fade_g*(i+1) + background.g;
            faded.b = fade_b*(i+1) + background.b;
            unset(x);
            doGlitter(x, faded);
            //setRGB(x, faded);
        }
    }
    if ( x == mod8(marqueeActive+steps,ledCount)+startLed) {
        unset(x);
        doGlitter(x, accent);
        //setRGB(x, accent);
    }
    if ( x == mod8(marqueeActive+steps+1,ledCount)+startLed) {
        unset(x);
        doGlitter(x, accent);
        //setRGB(x, accent);
    }

    marqueeActive = marqueeActive % ledCount;
    //setRGB(x, background);
    doGlitter(x, background);
}

// test pattern
static bool common(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    Color testPattern;
    for(int i=led_min; i<=led_max; i++) {
        testPattern.r = 255*(i/led_max);
        testPattern.g = 100;
        testPattern.b = 255*(i/led_max);
        setRGB(i, testPattern);
    }
    return led_max < DRIVER_LED_TOTAL;
}

#endif