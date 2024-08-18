/**
 * @file toggle-button.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-08-18
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef NEON_TOGGLE_BUTTON_H
#define NEON_TOGGLE_BUTTON_H

#include <Windows.h>
#include <stdlib.h>

typedef struct __NeonToggleButtonControl
{
    wchar_t text[60];
    size_t max;
    COORD textPosition;
    RECT wholeArea;
    RECT buttonArea;
    RECT selectedArea;
    int selected;
} NeonToggleButtonControl;

#endif