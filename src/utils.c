#include "utils.h"

const COLOR BLACK   = {   0,   0,   0 };
const COLOR WHITE   = { 255, 255, 255 };
const COLOR RED     = { 255,   0,   0 };
const COLOR GREEN   = {   0, 255,   0 };
const COLOR BLUE    = {   0,   0, 255 };


const u8 DEFAULT_WINDOW_W = (u8) 1024;
const u8 DEFAULT_WINDOW_H =  (u8) 768;
const u8 DEFAULT_WINDOW_OPACITY = (u8) 255;

const f4 TARGET_FPS = (f4) 60.0f;
const f4 TARGET_RENDERTIME_MS = (f4) 1.0f / TARGET_FPS;

