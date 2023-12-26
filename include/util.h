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

#endif

#endif