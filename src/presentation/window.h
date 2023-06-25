#ifndef BLOK_WINDOW_H
#define BLOK_WINDOW_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <windows.h>

#include "../core/program.h"

#define CHAR_LENGTH_COUNT 260

typedef struct window__
{
    HWND window_handle;
    MSG window_message;
    WNDCLASSEXW window_class;
    wchar_t window_class_name[CHAR_LENGTH_COUNT];
} window;

union window_instance_handler {
    struct window instance;
    void *potential_instance;
};

struct window_wrapper {
    bool registered;

    bool created;

    bool present;

    union window_instance_handler handle;
struct window_wrapper window_new(void);
#endif