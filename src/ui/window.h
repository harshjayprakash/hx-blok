#ifndef BLOK_UI_WINDOW_H
#define BLOK_UI_WINDOW_H

#include <Windows.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <wchar.h>

#include "../core/result.h"
#include "../core/program.h"
#include "../logic/theme.h"
#include "../logic/store.h"
#include "../logic/casts.h"
#include "../model/vector.h"


struct TNativeWindow
{
    HWND handle;
    MSG message;
    WNDCLASSEXW clazz;
    wchar_t name[260];
};

struct TWindow
{
    int registered;
    int created;
    int present;
    struct TNativeWindow inst;
};

struct TWindow blokWindowNew(void);

void blokWindowFree(struct TWindow* wnd);

#endif