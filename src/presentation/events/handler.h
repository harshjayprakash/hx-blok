/**
 * @file handler.h
 * @date 2024-08-10
 * @brief
 */

#ifndef NEON_HANDLER_H
#define NEON_HANDLER_H

#define STRICT 1
#include <Windows.h>

/**
 * @brief Handles the paint window event.
 * 
 * @param displayContext The display context to paint to.
 */
void NeonHandleWindowPaintEvent(HDC displayContext);

#endif