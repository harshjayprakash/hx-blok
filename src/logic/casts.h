/**
 * @file casts.h
 * @version 0.6.1
 * @date 18-07-2023
 * 
 * @brief Provides casts to different types.
 * 
 * This file contains functions to convert between data types, without the loss of the
 * information.
 */

#ifndef BLOK_CASTS_H
#define BLOK_CASTS_H

#include <Windows.h>

#include "../core/macros.h"
#include "../model/square.h"

/**
 * @brief Casts a square to a winapi rectangle.
 * 
 * This is worked out mathematically as it is not a direct comparison to the RECT type.
 * 
 * @details This process is worked out by the following equations
 *          left = x position
 *          top = y position
 *          right = x position + width
 *          bottom = y position + height
 * 
 * @param square The square to be converted.
 * 
 * @return WinApi RECT.
 * 
 * @see struct Square, (WINAPI) typedef struct tagRECT RECT.
 */
RECT blokCastSquareToWinApiRect(struct Square *square);

#endif