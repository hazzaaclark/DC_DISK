/* COPYRIGHT (C) HARRY CLARK 2023 */

/* SEGA DREAMCAST ROM DISK TOOLKIT */

/* THIS FILE IS ABOUT COMMON DATA TYPES USED THROUGHOUT THE PROJECT */
/* CREATING TYPE DEFINED METHODS TO INSTANTIATE RAW POINTERS FOR MY */
/* METHODS, FUNCTIONS, ETC */

#ifndef COMMON
#define COMMON

#include <stdint.h>
#include <stdio.h>

#ifndef UNSIGNED_TYPES
#define UNSIGNED_TYPES

typedef uint8_t U8;
typedef uint16_t U16;
typedef uint32_t U32;
typedef uint64_t U64;
typedef size_t UNK;

typedef unsigned int UINT;
typedef unsigned long ULONG;
typedef unsigned short USHORT;

#endif 

#ifndef SIGNED_TYPES
#define SIGNED_TYPES

typedef int8_t S8;
typedef int16_t S16;
typedef int32_t S32;
typedef int64_t S64;

#endif

#ifndef FLOATING_POINT
#define FLOATING_POINT

typedef float F32;
typedef double F64;
typedef volatile float VF32;
typedef volatile double VF64;

#endif

#define     STATIC          static
#define     INLINE          inline

#define ATTRIBUTE_32 __attribute__((aligned(32)))

#if defined(__GNUC__)
#define __GNUC__
#endif


#endif
