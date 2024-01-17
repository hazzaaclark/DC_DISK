/* COPYRIGHT (C) HARRY CLARK 2024 */

/* SEGA DREAMCAST ROM DISK TOOLKIT */

/* THIS FILE PERTAINS TOWARDS THE MAIN FUNCTIONALITY OF THE PROGRAM */

/* SYSTEM INCLUDES */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/* I'M TESTING TO DETERMINE IF MODULARISATION WOULD BENEFIT ME IN TERMS OF */
/* REDUCING THE COMPLEXITIY OF THE MAIN FUNCTION */

/* RATHER KEEP THE MAIN FUNCTION CLUTTER FREE */

FILE* OPEN_FILE(const char* FILE_PATH, const char* FILE_MODE, const char* STDERR)
{
    /* ASSUMING THERE IS NO FILE BEING PASSED THROUGH */
    /* CHECKS THE MODE OF THE FILE BEING PASSED THROUGH AS INPUT OR OUTPUT */

    if(FILE_PATH == NULL) return FILE_MODE[0] == 'r' ? stdin : stdout;

    FILE* ROM_FILE = fopen(FILE_PATH, FILE_MODE);

    if(ROM_FILE == NULL)
    {
        fprintf(stderr, "Womp womp no file to create\n", STDERR);
    }

    return ROM_FILE;
}


int main(int argc, char* argv[])
{
    char* OUTPUT_FILE_PATH;
    bool PRINT_USAGE;

    if(argc < 2 || PRINT_USAGE)
    {
        fputs
        (
            "-----------------------------------------\n"
            "   DREAMCAST ROMDISK TOOL - Harry Clark  \n"
            "                                         \n"
            "   Options:                              \n"
            "       -o [path] - Output File.          \n"
            "       -m [path] - Make File.            \n"
            "       -c [path] - Checksum Test         \n"
            "       -i [path] - Input File            \n"
            "-----------------------------------------\n"
        ,stdout);
    }

    else 
    {
        if(OUTPUT_FILE_PATH == NULL)
        {
            fprintf(stderr, "Output File Path must be specified with '-o'.\n");
        }

        else 
        {
            
        }
    }
}
