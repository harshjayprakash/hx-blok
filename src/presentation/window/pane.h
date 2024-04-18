#ifndef BLOQ_PANE_H
#define BLOQ_PANE_H

#include <Windows.h>
#include "../../core/common/globals.h"

typedef struct bloqPane
{
    HWND handle;
    MSG message;
    WNDCLASSEXW klass;
    wchar_t *name;
    int initError;
} TPane;

TPane bloqInitPane(void);

void bloqFreePane(TPane *pane);

#endif