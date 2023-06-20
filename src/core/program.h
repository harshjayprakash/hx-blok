#ifndef __BLOK_PROGRAM_H
#define __BLOK_PROGRAM_H

#include <windows.h>

typedef struct program__
{
    HINSTANCE instance_handle;

    HINSTANCE previous_instance_handle;
    LPSTR command_line_arguments;
    int show_flag;
} program;

#endif