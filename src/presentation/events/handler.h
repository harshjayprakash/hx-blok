/**
 * \file handler.h
 * \date 13-08-2024
 * \brief Function definition for handling window events.
 *
 * This file contains the function definitions for handling the paint, key down and left
 * mouse down window events.
 */

#ifndef NEON_HANDLER_H
#define NEON_HANDLER_H

#define STRICT 1
#include <Windows.h>

/**
 * \brief Handles the window paint event.
 *
 * \param displayContext The display context handle.
 */
void NeonHandleWindowPaintEvent(HDC displayContext);

/**
 * \brief Handles the key down window event.
 *
 * \param wordParam The key pressed.
 */
void NeonHandleWindowKeyDownEvent(WPARAM wordParam);

/**
 * \brief Handles the mouse down window event.
 *
 * \param longParam The coordinates of where the mouse was clicked.
 */
void NeonHandleWindowLeftMouseDown(LPARAM longParam);

#endif