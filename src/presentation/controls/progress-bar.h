/**
 * @file progress-bar.h
 * @author your name (you@domain.com)
 * @brief 
 * 
 */

#ifndef NEON_PROGRESS_BAR_H
#define NEON_PROGRESS_BAR_H

#define STRICT 1
#include <Windows.h>
#include <stdlib.h>

typedef struct __NeonProgressBarControl
{
    wchar_t text[60];
    size_t maxTextSize;
    COORD textPosition;
    RECT barOutline;
    RECT bar;
    RECT area;
    int barMin;
    int barMax;
    int barSpan;
} NeonProgressBarControl;

#endif