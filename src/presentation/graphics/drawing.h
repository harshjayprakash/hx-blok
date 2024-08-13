/**
 * \file drawing.h
 * \date 13-08-2024
 * \brief Function definitions for the drawing module.
 * 
 * This file contains the function definitions for getting the tools for painting to the
 * display.
 */

#ifndef NEON_DRAWING_H
#define NEON_DRAWING_H

#define STRICT 1
#include <Windows.h>

/**
 * \brief Initialises the drawing tools.
 * 
 * \warning The tools must be freed using the `NeonFreeDrawingTools` function.
 */
void NeonInitDrawingTools(void);

/**
 * \brief Gets the background coloured solid brush.
 * 
 * \return The background coloured solid brush handle.
 */
HBRUSH NeonGetBackgroundBrush(void);

/**
 * \brief Gets the foreground coloured solid brush.
 * 
 * \return The foreground coloured solid brush handle.
 */
HBRUSH NeonGetForegroundBrush(void);

/**
 * \brief Gets the foreground coloured solid brush.
 * 
 * \return The foreground coloured solid brush handle.
 */
HBRUSH NeonGetAccentBrush(void);

/**
 * \brief Gets the foreground coloured pen.
 * 
 * \return The foreground coloured pen handle.
 */
HPEN NeonGetForegroundPen(void);

/**
 * \brief Cleans up resources used by the drawing tools.
 * 
 * \warning The tools must be freed using this function.
 */
void NeonFreeDrawingTools(void);

#endif