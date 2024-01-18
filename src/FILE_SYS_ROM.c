/* COPYRIGHT (C) HARRY CLARK 2024 */

/* SEGA DREAMCAST ROM DISK TOOLKIT */

/* THIS FILE PERTAINS TOWARDS THE FUNCTIONALITY BY WHICH */
/* THE SEGA DREAMCAST'S FILE SYSTEM WORKS IN ACCORDANCE WITH */
/* THE HARDWARE TO CREATE EFI FILE SYSTEMS */

/* MOREOVER, THIS FILE IMPLEMENTS THE LINUX ROMFS FILE SYSTEM */
/* FOR PARSING CONTENTS WITHIN A PRE-DEFINED BOOT ENVIRONMENT */

/* NESTED INCLUDES */

#include "FILE_SYS.h"
#include "FILE_SYS_ROM.h"

/* SYSTEM INCLUDES */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/* CREATE AN ARRAY STRUCTURE SUCH THAT THE PROGRAM IS ABLE TO */
/* DYNAMICALLY SORT AND RESPOND TO EACH OF THE CORRESPONDENCE OF */
/* THE ROM MOUNTING PROCESS */

/* TAKING INTO ACCOUNT THE LOGISTICS BEHIND OPENING AND CLOSING, */
/* PARSING CONTENTS, DIRECTORIES, AND DYNAMICALLY MAPPING DATA */

#undef USE_ROM_BOOT

STATIC
FS_HANDLER* FSH_MOUNT[] = 
{
    {"NAME"},                   // ROMDISK NAME
    {"KERNEL_LVL"},             // KERNEL LEVEL/MODE
    {"KERNEL_VERSION"},         // KERNEL VERSION
    {"POSIX_MALLOC"},           // MALLOC FOR POSIX DEVICES
    {"POSIX_FLAGS"},            // FLAGS FOR SAID DEVICES

    0, NULL,                    // ASSUMES THERE IS NO CACHE

    {'ROM_DISK_OPEN'},
    {'ROM_DISK_CLOSE'},
    {'ROM_DISK_SEEK'},
    {'ROM_DISK_READ'},
    {'ROM_DISK_WRITE'},
    {'ROM_DISK_MAP'},
    {'ROM_DISK_IOCTL', NULL},
    NULL,                       // LINK
    NULL,                       // SYMLINK
    NULL,                       // SEEK MODE
    NULL,                       // READ MODE
    NULL                        // DIRECTORY
};

/* INITIALISE THE FILE SYSTEM BASED ON THE LISTING PERTAINING */
/* TOWARDS WHETHER THERE IS A ROM DISK BEING INDEXXED */

STATIC
void ROMDISK_INIT(void)
{
    #undef ROMDISK_PARAMS

    if(ROMDISK_ENTRY_COND) return;
}

/* FIND THE CORRESPONDING FILE CONTENTS THROUGH THE MEANS */
/* OF EITHER A SINGULAR FILE OR A PATH */

/* THIS WILL ASSUME THAT THERE IS AN ABSOLUTE PATH CONTAINING A FILE */
/* IF NOT, IT WILL LOOK FOR A DIRECTORY */

/* THE RETURN TYPE WILL BE THE OFFSET USED TO PARSE THE LOCATION */
/* OF THE ARBITARY FILE */

STATIC
U32 ROMDISK_FIND(struct ROM_DISK* ROM, char* FUNCTION, char* DIRECTORY)
{
    S32 INDEX;
    char* CURRENT_OFFSET;
    struct ROM_FILE_HANDLER* FILE_HANDLER;  
    struct GDI* GDI_MOUNT;

    /* SEARCHES FOR THE FIRST OCCURANCE OF THE ROOT */

    while(CURRENT_OFFSET = strchr(FUNCTION, '/'))
    {
        /* IF NOT CURRENT OFFSET EXISTS IN THE NODE */
        /* EVALUATE THE LIST BASED OF THE LIST DIRECTORY */

        /* FROM THERE, ALLOCATE SIZE FOR THE MOUNTED DISK IMAGE */
        /* IN RELATION TO THE INDEX POINTER */

        if(CURRENT_OFFSET != FUNCTION)
        {
            INDEX += sizeof(ROMDISK_LIST_DIR());
            
            FILE_HANDLER = (UNK*)malloc(sizeof((GDI_MOUNT->IMAGE + INDEX)));
        }
    }
}

/* FIND AND LIST THE CURRENT DIRECTORY OR ABSOLUTE FILE PATH */
/* IN RELATION TO THE OFFSET POINTER */

/* SEE THE FUNCTION ABOVE FOR FURTHER CLARITY */

STATIC
void ROMDISK_LIST_DIR(void)
{
    struct FS_DESCRIPTOR* FILE_DESC;
    struct ROM_DISK* ROM; 
    S32 INDEX;
    U32 DIRECTORY; 
    U32 FILE_TYPE;
    UNK FILE_LENGTH;

    #ifdef USE_GDI
    
    struct GDI* GDI_MNT;

    /* ASSUME THAT THE SIZE OF THE INDEX POINTER */
    /* IS WITHIN A SPECIFIC 16 BIT OFFSET */

    /* WE ALLOCATE MEMORY FOR THE HEADER OFFSET */
    /* THAT WILL BE ACCESSED BY THE FIND DIRECTORY */

    while(GDI_MNT->IMAGE != INDEX & 0x0F)
    {
        INDEX = (U32*)malloc(sizeof(ROM->HEADER_OFFSET));

        /* WHEN THERE IS A DIRECTORY, CHECK THE TYPE OF THE FILE */
        /* THIS CAN BE ANY OF THE THREE OPTIONS: */
        /*=======================================================*/
        /* GDI */
        /* CDI */
        /* CUE */

        if(!DIRECTORY)
        {
            if(FILE_TYPE % 3)
            {
                assert(INDEX + FILE_TYPE);

                /* IF THERE IS NO CONCURRENT INDEX BEING PARSED */
                /* CONTINUE TO KEEP EVALUATING UNTIL THE DESIGNATED */
                /* TYPES HAVE BEEN FOUND */

                if(!INDEX)
                    break;
                else    
                    continue;
            }

            /* AFTER THIS PREPRIATORY CHECK, DETERMINE THE FILENAME */
            /* AND ENSURE THAT IT MATCHES THE TYPES */

            if((strlen(ROM->FILENAME) == FILE_LENGTH) && strncmp(ROM->FILENAME, FILE_LENGTH, 0)) 
                return INDEX;
        }

        return INDEX;
    }

    #endif
}
