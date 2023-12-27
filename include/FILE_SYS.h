/* COPYRIGHT (C) HARRY CLARK 2023 */

/* SEGA DREAMCAST ROM DISK TOOLKIT */

/* THIS FILE PERTAINS TOWARDS THE FUNCTIONALITY BY WHICH */
/* THE SEGA DREAMCAST'S FILE SYSTEM WORKS IN ACCORDANCE WITH */
/* THE HARDWARE TO CREATE EFI FILE SYSTEMS */

#ifndef FILE_SYS
#define FILE_SYS

/* NESTED INCLUDES */

#include "util.h"

/* SYSTEM INCLUDES */

#include <assert.h>
#include <errno.h>
#include <limits.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

#if defined(USE_FILE_SYS)
#define USE_FILE_SYS
#else
#define USE_FILE_SYS

#define     SEEK_MODE_SET           0
#define     SEEK_MODE_CLEAR         1
#define     SEEK_MODE_CURRENT       2 

typedef struct FS_HANDLER
{
    int CACHE;
    void* DATA;
    void(*OPEN_FILE)(const struct FS_HANDLER* FS, const char* IDENTIFER);
    int(*CLOSE_FILE)(void* HANDLER);

    UNK(*READ)(void* HANDLER, void* BUFFER, UNK* COUNT);
    UNK(*READ)(void* HANDLER, const void* BUFFER, UNK* COUNT);

} FS_HANDLER;

#endif

#endif
