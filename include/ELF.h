/* COPYRIGHT (C) HARRY CLARK 2024 */

/* SEGA DREAMCAST ROM DISK TOOLKIT */

/* THIS FILE IS A CONJUNCTION METHOD BETWEEN THE FILE SYSTEM */
/* TO BE ABLE TO CREATE BOOTABLE AND EXECUTABLE MEDIA THAT THE DREAMCAST */
/* CAN READ AND WRITE FROM */

#ifndef ELF_FS
#define ELF_FS

/* NESTED INCLUDES */

#include "common.h"
#include "FILE_SYS.h"
#include "FILE_SYS_ROM.h"
#include "util.h"

#if defined(USE_ELF_FS)
#define USE_ELF_FS
#else
#define USE_ELF_FS

#include <malloc.h>
#include <stdlib.h>

/* THE ASSEMBLY REVOLVING AROUND THE DREAMCAST OFTEN USES */
/* VARIOUS KEYWORDS, MEANS OF DECLARATIONS AND PRAGMAS THAT ARE */
/* FROM DIFFERENT ARCHITECTURES */

/* SUCH IS THE CASE WHEREBY M68K ASM SOMETIMES USES IA32 KEYWORDS */
/* FOR DIFFERENT ADDRESSING MODES */

#if defined(USE_ASM_PRAGMAS)
#define USE_ASM_PRAGMAS
#else
#define USE_ASM_PRAGMAS

#define     ARCH_386        3
#define     ARCH_ARM        40
#define     ARCH_SH4        42   

#define     ARCH_WRITE      0x1
#define     ARCH_ALLOC      0x2
#define     ARCH_EXEC       0x4

#define     ELF_HEADER_MAX  0x7f

typedef struct ELF_HEADER
{
    U8* IDENTIFIER[16];
    U16* TYPE;
    U16* ARCH;
    U32 PHOFF;
    U32 SHOFF;
    U32 FLAGS;
    U32 SIZE;

    union ENTRY
    {
        U32* BASE;
        U16* PHENT_SIZE;
        U16* PHNUM;
        U16* SHENT_SIZE;
        U16* SHNUM;

    } ENTRY;

} ELF_HEADER;

typedef struct ELF_PROGRAM
{
    U32* TYPE;
    U32* OFFSET;
    U32* VIRTUAL_ADDR;
    U32* PHYSICAL_ADDR;
    U16 FILE_SIZE;
    U16 MEM_SIZE;
    U32 FLAGS;
    U32 ALIGN;

} ELF_PROGRAM;

S32 ELF_FILE_LOAD(const char* FUNCTION, size_t* OUTPUT);
void ELF_HEADER_OFFSET(void);

#endif
#endif

#endif

