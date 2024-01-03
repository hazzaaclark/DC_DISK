/* COPYRIGHT (C) HARRY CLARK 2024 */

/* SEGA DREAMCAST ROM DISK TOOLKIT */

/* THIS FILE PERTAINS TOWARDS THE FUNCTIONALITY BY WHICH */
/* THE SEGA DREAMCAST'S FILE SYSTEM WORKS IN ACCORDANCE WITH */
/* THE HARDWARE TO CREATE EFI FILE SYSTEMS */

/* MOREOVER, THIS FILE IMPLEMENTS THE LINUX ROMFS FILE SYSTEM */
/* FOR PARSING CONTENTS WITHIN A PRE-DEFINED BOOT ENVIRONMENT */

#ifndef FILE_SYS_ROM
#define FILE_SYS_ROM

/* NESTED INCLUDES */

#include "util.h"
#include "FILE_SYS.h"

/* SYSTEM INCLUDES */

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#if defined(__GNUC__)
#include <sys/file.h>
#include <sys/types.h>

#if defined(USE_ROM_BOOT)
#define USE_ROM_BOOT
#else
#define USE_ROM_BOOT

typedef ATTRIBUTE_32 struct FILE_SYS_ROM
{
    char* VOLUME_BASE[8];
    char* VOLUME_NAME[16];
    char* FILENAME[FILE_SYS_MAX];

    U32* CHECKSUM;
    U32* FS_STACK_SIZE;
    U32* HEADER_OFFSET;
    U32* DATA_SIZE;

} ROM_DISK;

#endif
#endif
#endif