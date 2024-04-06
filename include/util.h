/* COPYRIGHT (C) HARRY CLARK 2023 */

/* SEGA DREAMCAST ROM DISK TOOLKIT */

/* THIS FILE PERTAINS TOWARDS THE GENERAL PURPOSE UTILITY */
/* USED THROUGHOUT THE PROGRAM */

/* PROVIDING FURTHER FUNCTIONALITY TOWARDS HOW TO GO ABOUT */
/* CREATING ROM IMAGES */

#ifndef UTILITY
#define UTILITY

/* NESTED INCLUDES */

#include "common.h"

/* SYSTEM INCLUDES */

#ifdef __GNUC__
#include <sys/types.h>
#include <sys/stat.h>
#endif

#include <assert.h>
#include <malloc.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/* THREADDING IS THE PARADIGM BY WHICH WE ARE ABLE TO */
/* DETERMINE EXECUTION PATHS ALONG THE PROGRAM COUNTER */

/* IN THIS CONTEXT, WE ASSUME THE EXECUTION PATH IS BEING HANDLED */
/* BY THE SH4'S PC, THAT OF WHICH WILL HANDLE THE READING AND WRITING */
/* AND SUBSEQUENT EXECUTION OF THIS ARBITARY ROM FILE */

/* MEMORY WILL BE TRANSFERRED TO AND FROM THE STACK TO AID IN THESE OPERATIONS */
/* AND IN DOING SO, PROVIDE MEMORY ALLOCATIONS TO SUIT THE NEEDS OF THE OPERATION */

#if defined(USE_THREADDING)
#define USE_THREADDING  
#else
#define USE_THREADDING

#define         THREAD_MAX_LENGTH           128
#define         THREAD_MAX_ROM_SIZE         2048

#define         THREAD_ITERATE_POS          2
#define         THREAD_ITERATE_OFF          3

#define         THREAD_PRIO_MAX             4096
#define         THREAD_PRIO_DEFAULT           10
#define         THREAD_LABEL_SIZE            256
#define         THREAD_RUNNING              0x0001
#define         THREAD_READY                0x0002
#define         THREAD_WAIT                 0x0003
#define         THREAD_FINISHED             0x0004

typedef struct HEADER
{
    void* SH4_TLS;
    U64* POINTER;

} HEADER;

/* ATTRIBUTE IS THE CONSTANT DIRECTIVE WHEREBY WE DEFINE */
/* A CONSTANT BYTEWISE SIZE THROUGHOUT ALL TYPES IN STRUCT */

/* THIS STRUCTURE PERTAINS TOWARDS THE FUNCTIONALITY OF THE MAIN THREADS */

/* SOURCE: https://gcc.gnu.org/onlinedocs/gcc/Attribute-Syntax.html */

typedef ATTRIBUTE_32 struct THREAD
{
    struct CPU_IRQ* IRQ_CONTEXT;
    unsigned LIST:32;
    unsigned QUEUE:32;

    UNK* THREAD_ID;
    UNK* PRIORITY;

    U32* FLAGS;
    unsigned int STATE;
    void(*HOOK_CALLBACK)(void* OBJECT, char* MESSAGE);

} THREAD;

/* AN ARBITARY 32 BIT STRUCTURE TO DECLARE TO DECLARE THE TYPES */
/* SEEN ON THE HITACHI SUPERH4 CPU */

/* SOURCE: https://www.st.com/resource/en/user_manual/cd00147165-sh-4-32-bit-cpu-core-architecture-stmicroelectronics.pdf */

typedef ATTRIBUTE_32 struct CPU_IRQ
{
    U32* PC;
    U32* PR;
    U32* GBR;
    U32* VBR;
    U32* MAC_HI;
    U32* MAC_LO;
    U32* SR;
    U32* FPCR;
    U32* PFPR[16];
    U32* SFPF[16];
    U32* GPR[16];
    U32* FPSCR;

} CPU_IRQ;

typedef struct ROM
{
    char RELEASE_BUFFER[17];
    char* ROM_KEY[THREAD_MAX_LENGTH];
    char* ROM_VALUE[THREAD_MAX_LENGTH];
    char ROM_FILE_HEADER[THREAD_MAX_LENGTH]; 
    const char* RELEASE_DATE;
    size_t ROM_START;
    size_t ROM_END;
    size_t ROM_READ_BUFFER;
    size_t ROM_BYTES;

} ROM;

typedef U32(*IRQ_TYPE)(void);
typedef int IRQ_HANLDER(void);
typedef int CONTENT;

void IRQ_RETURN(void);
void IRQ_CREATE_CONTEXT(CPU_IRQ* IRQ_CONTEXT, U32* STACK, U32* ARGS, unsigned MODE);
void IRQ_ENABLE(void);
void IRQ_RESTORE(int VALUE);
int IRQ_INIT(void);
void IRQ_SHUTDOWN(void);
IRQ_HANLDER* GET_HANDLER(U32* SOURCE);

static char* ROM_BUFFER(const char* RELEASE, char* BUFFER);
static void ROM_PROC_OPTION(const char* RELEASE);
static bool IS_VALID_DATE(const char* VALUE);
int ROM_HEADER_OFFSET();



#endif

#endif
