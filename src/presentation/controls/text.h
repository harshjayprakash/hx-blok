/**
 * \file text.h
 * \date 18-08-2024
 * \brief
 * 
 */

#ifndef NEON_TEXT_H
#define NEON_TEXT_H

#define STRICT 1
#include <Windows.h>
#include <stdlib.h>

typedef struct __NeonTextControl
{
    wchar_t text[60];
    size_t max;
    COORD position;
    RECT area;
} NeonTextControl;

#endif