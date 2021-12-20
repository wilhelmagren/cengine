#ifndef UTILS_H
#define UTILS_H
#include <stdint.h>


// datatypes
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;

typedef int8_t s8;
typedef int16_t s16;
typedef int32_t s32;

typedef float f4;
typedef double f8;
typedef long double f10;


// colors
typedef struct {
    u8 r, g, b;
}  COLOR;

#endif
