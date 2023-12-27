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

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

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

typedef U32(*IRQ_TYPE)(void);
typedef int IRQ_HANLDER(void);

void IRQ_RETURN(void);
void IRQ_CREATE_CONTEXT(CPU_IRQ* IRQ_CONTEXT, U32* STACK, U32* ARGS, unsigned MODE);
void IRQ_ENABLE(void);
void IRQ_RESTORE(int VALUE);
int IRQ_INIT(void);
void IRQ_SHUTDOWN(void);
IRQ_HANLDER* GET_HANDLER(U32* SOURCE);


#endif

#endif
