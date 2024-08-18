/**
 * @file button.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-08-18
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef NEON_BUTTON_H
#define NEON_BUTTON_H

#define STRICT 1
#include <Windows.h>
#include <stdlib.h>

typedef struct __NeonButtonControl
{
    wchar_t text[60];
    size_t max;
    COORD alignment;
    RECT area;
} NeonButtonControl;

#endif