/**
 * @file window.h
 * @date 2024-08-10
 * @brief
 */

#ifndef NEON_WINDOW_H
#define NEON_WINDOW_H

#define STRICT 1
#include <Windows.h>

#include "../core/result.h"

/**
 * @brief Initialises the window.
 * 
 * @return NeonResult If the window initialisation was successful.
 */
NeonResult NeonInitWindow(void);

/**
 * @brief Get window's area.
 * 
 * @return RECT Window area in RECT format.
 */
RECT NeonGetWindowArea(void);

/**
 * @brief Get window handle.
 * 
 * @return HWND Window handle.
 */
HWND NeonGetWindowHandle(void);

/**
 * @brief Frees any resources of the window.
 * 
 * @return NeonResult If the window destruction was successful.
 */
NeonResult NeonFreeWindow(void);

#endif