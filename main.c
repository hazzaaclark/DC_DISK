/* COPYRIGHT (C) HARRY CLARK 2024 */

/* SEGA DREAMCAST ROM DISK TOOLKIT */

/* THIS FILE PERTAINS TOWARDS THE MAIN FUNCTIONALITY OF THE PROGRAM */

/* SYSTEM INCLUDES */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

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
    }
}