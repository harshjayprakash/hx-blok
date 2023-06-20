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

void program_init(
    HINSTANCE _instance_handle, 
    HINSTANCE _previous_instance_handle, 
    LPSTR _command_line_arguments, 
    int _show_flag);

program *program_instance_get(void);

void program_free(void);

#endif