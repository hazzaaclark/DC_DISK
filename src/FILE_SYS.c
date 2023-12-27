/* COPYRIGHT (C) HARRY CLARK 2023 */

/* SEGA DREAMCAST ROM DISK TOOLKIT */

/* THIS FILE PERTAINS TOWARDS THE FUNCTIONALITY BY WHICH */
/* THE SEGA DREAMCAST'S FILE SYSTEM WORKS IN ACCORDANCE WITH */
/* THE HARDWARE TO CREATE EFI FILE SYSTEMS */

/* NESTED INCLUDES */

#include "FILE_SYS.h"

#ifdef USE_FILE_SYS

/* ASSUMING THE CURRENT DIRECTORY HAS BEEN INITIALISED */
/* WE BEGIN TO ESTABLISH THE NODE BASED SYSTEM BY WHICH */
/* FILES ARE TRANSFERRED TO AND FROM ACROSS ALL AREAS OF */
/* THE STACK */

/* WE USE THREADDING REFERNCING TO BE ABLE TO READ */
/* AND WRITE CORRESPONDING CONTENTS TO FILES */

STATIC
FS_DIRECTORY* ROOT_DIRECTORY(UNK* HANDLE)
{
    #undef USE_THREADDING

    struct MMU_HANDLER* MMU;
    struct MMU_NODE* MMU_NODES;

    CONTENT* CONTENT = (int*)malloc(HANDLE);
    
}

#endif
