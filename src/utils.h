#ifndef UTILS_H
#define UTILS_H
#include <stdint.h>


typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;

typedef int8_t s8;
typedef int16_t s16;
typedef int32_t s32;

typedef float f4;
typedef double f8;
typedef long double f10;


typedef u8 COLOR[3];

const COLOR BLACK   = {   0,   0,   0 };
const COLOR WHITE   = { 255, 255, 255 };
const COLOR RED     = { 255,   0,   0 };
const COLOR GREEN   = {   0, 255,   0 };
const COLOR BLUE    = {   0,   0, 255 };


const u8 DEFAULT_WINDOW_W = (u8)1024;
const u8 DEFAULT_WINDOW_H =  (u8)768;
const u8 DEFAULT_WINDOW_OPACITY = (u8)255;

const f4 TARGET_FPS = 60.0f;
const f4 TARGET_RENDERTIME_MS = 1.0f / TARGET_FPS;


#endif
