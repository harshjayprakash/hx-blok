/**
 * @file drawing.h
 * @date 2024-08-10
 * @brief
 */

#ifndef NEON_DRAWING_H
#define NEON_DRAWING_H

#define STRICT 1
#include <Windows.h>

/**
 * @brief Initialises the drawing tools.
 */
void NeonInitDrawingTools(void);

/**
 * @brief Returns the background solid brush.
 * 
 * @return HBRUSH A background coloured solid brush.
 */
HBRUSH NeonGetBackgroundBrush(void);

/**
 * @brief Returns the foreground solid brush.
 * 
 * @return HBRUSH A foreground coloured solid brush.
 */
HBRUSH NeonGetForegroundBrush(void);

/**
 * @brief Returns the accent solid brush.
 * 
 * @return HBRUSH A accent coloured solid brush.
 */
HBRUSH NeonGetAccentBrush(void);

/**
 * @brief Returns the foreground pen.
 * 
 * @return HPEN A foreground coloured pen.
 */
HPEN NeonGetForegroundPen(void);

/**
 * @brief Cleans up drawing tool resources.
 */
void NeonFreeDrawingTools(void);

#endif