#ifndef BLOK_WINDOW_H
#define BLOK_WINDOW_H

#include <Windows.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <wchar.h>

#include "../core/macros.h"
#include "../core/program.h"
#include "../core/debug.h"
#include "../logic/theme.h"
#include "../logic/store.h"
#include "../logic/casts.h"

struct Window
{
    HWND windowHandle;
    MSG windowMessage;
    WNDCLASSEXW nativeWindowClass;
    wchar_t windowClassName[BLOK_MAX_CHAR_LENGTH];
};

struct WindowWrapper
{
    int registered;
    int created;
    int present;
    struct Window instance;
};

struct WindowWrapper blokWindowNew(void);

void blokWindowFree(struct Window *window);

#endif
