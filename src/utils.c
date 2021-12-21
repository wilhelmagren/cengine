#include "utils.h"

const COLOR BLACK   = {   0,   0,   0 };
const COLOR GRAY    = {  40,  40,  40 };
const COLOR WHITE   = { 255, 255, 255 };
const COLOR RED     = { 255,   0,   0 };
const COLOR GREEN   = {   0, 255,   0 };
const COLOR BLUE    = {   0,   0, 255 };


const int DEFAULT_WINDOW_W = 1024;
const int DEFAULT_WINDOW_H =  768;
const int DEFAULT_WINDOW_OPACITY = 255;

const f4 TARGET_FPS = (f4) 60.0f;
const f4 TARGET_RENDERTIME_MS = (f4) 1.0f / TARGET_FPS;

bool _f4Equality(f4 a, f4 b) {
    f4 precision = 0.000001;
    return fabs(a-b) < precision;
}

