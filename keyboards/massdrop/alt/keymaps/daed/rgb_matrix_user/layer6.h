// !!! DO NOT ADD #pragma once !!! //
RGB_MATRIX_EFFECT(layer6)
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

// This layer should be visibly identical to layer 5 except for the layer number
static void layer6_init(effect_params_t* params) {
    layer5_init(params);
    LAYER = 6;
}

static bool layer6_run(effect_params_t* params) {
    return layer5_run(params);
}

static bool layer6(effect_params_t* params) {
    if (params->init) layer6_init(params);
    return layer6_run(params);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS