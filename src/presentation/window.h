/**
 * \file window.h
 * \date 13-08-2024
 * \brief Function definitions for window.
 * 
 * This file contains the function definitions for window creation, destruction and 
 * management.
 */

#ifndef NEON_WINDOW_H
#define NEON_WINDOW_H

#define STRICT 1
#include <Windows.h>

#include "../core/result.h"

/**
 * \brief Initialises the window.
 * 
 * \return A result denoting if the operation was successful. 
 */
NeonResult NeonInitWindow(void);

/**
 * \brief Gets the window area.
 * 
 * \return The window area in form RECT.
 */
RECT NeonGetWindowArea(void);

/**
 * \brief Gets the window handle.
 * 
 * \return The window handle.
 */
HWND NeonGetWindowHandle(void);

/**
 * \brief Frees any resources used by the window.
 * 
 * \return A resut denoting if the operation was successful.
 *
 * \warning This function must be called to clean up window, after closing.
 */
NeonResult NeonFreeWindow(void);

#endif