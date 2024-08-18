/**
 * \file canvas.h
 * \date 18-08-2024
 * \brief Function definitions for the canvas component.
 *
 * This file contains the function definitions for the canvas component's initialisation,
 * rendering and releasing resources.
 */

#ifndef NEON_CANVAS_H
#define NEON_CANVAS_H

#define STRICT 1
#include <Windows.h>

/**
 * \brief Initialises the canvas component.
 */
void NeonInitCanvasComponent(void);

/**
 * \brief Renders the canvas components.
 *
 * \param displayContext The display context handle.
 */
void NeonRenderCanvasComponent(HDC displayContext);

/**
 * \brief Returns if the canvas has been locked.
 * 
 * \return If the canvas has been locked.
 */
int NeonIsCanvasLocked(void);

/**
 * \brief Toggles the lock for the canvas component.
 */
void NeonToggleCanvasLock(void);

/**
 * \brief Frees the canvas component.
 */
void NeonFreeCanvasComponent(void);

#endif