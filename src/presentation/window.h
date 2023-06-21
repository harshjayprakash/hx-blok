#ifndef __BLOK_WINDOW_H
#define __BLOK_WINDOW_H

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

union inst_ {
    window instance;
    void *unsafe_instance;
};

typedef struct optional_window__
{
    int registered;
    int created;
    int is_present;
    union inst_ get;
} optional_window;

optional_window window_new(void);

void window_free(window *wnd);

#endif