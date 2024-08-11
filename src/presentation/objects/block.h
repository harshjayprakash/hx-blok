/**
 * @file block.h
 * @date 2024-08-10
 * @brief
 */

#ifndef NEON_BLOCK_H
#define NEON_BLOCK_H

#define STRICT 1
#include <Windows.h>

#include "../../model/object/square.h"
#include "../../model/utility/direction.h"

/**
 * @brief Initialises the block object.
 */
void NeonInitBlockObject(void);

/**
 * @brief Renders the block to the window.
 * 
 * @param displayContext The display to render to.
 */
void NeonRenderBlock(HDC displayContext);

/**
 * @brief Moves the block based on the input direction.
 * 
 * @param direction The direction the block should move.
 */
void NeonMoveBlock(NeonDirection direction);

/**
 * @brief Sets the boundary the block must stay between.
 * 
 * @param size The size object to denote the area to stay within.
 */
void NeonSetBlockBoundary(const NeonSize size);

/**
 * @brief Cleans up the resources used by the block object.
 */
void NeonFreeBlockObject(void);

#endif