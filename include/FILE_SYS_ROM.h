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

typedef ATTRIBUTE_32 struct ROM_DISK
{
    char* VOLUME_BASE[8];
    char* VOLUME_NAME[16];
    char* FILENAME[FILE_SYS_MAX];

    U32* CHECKSUM;
    U32* FS_STACK_SIZE;
    U32* HEADER_OFFSET;
    U32* DATA_SIZE;

    struct ROMDISK_DIR;

} ROM_DISK;

typedef struct ROM_FILE_HANDLER
{
    U32* ROM_INDEX;
    unsigned ROM_DIR;
    U32* INDEX_POINTER;
    U32* ROM_SIZE;
    ROM_DISK* MOUNT;

} ROM_FILE_HANDLER;

#endif

#if defined(ROMDISK_PARAMS)
#define ROMDISK_PARAMS
#else
#define ROMDISK_PARAMS

#define     ROMDISK_ENTRY_COND       0
#define     ROMDISK_EXIT_COND        1

void ROMDISK_INIT(void);
void ROMDISK_EXIT(void);

unsigned ROMDISK_MOUNT(char* MOUNT, void* BUFFER);
unsigned ROMDISK_UNMOUNT(char* MOUNT); 
U32 ROMDISK_READ(void);
U32 ROMDISK_SEEK(void);

U32 ROMDISK_FIND(struct ROM_DISK* ROM, char* FUNCTION, char*);
U32 ROMDISK_OPEN(const FS_HANDLER* FS_HANDLE, const char* FUNCTION, U32 MODE);
U32 ROMDISK_CLOSE(void*);

STATIC void ROMDISK_LIST(int*);

STATIC ROM_DISK* RD_DIR_HANDLER;
STATIC FS_HANDLER* FSH_MOUNT;

#endif
#endif
#endif
