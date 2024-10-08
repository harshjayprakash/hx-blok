/**
 * \file block.h
 * \date 07-09-2024
 * \brief Function definitions for the block object.
 *
 * This file contains the definitions for the block object including: initialising,
 * rendering, releasing resources, getting the block, moving the block or setting
 * boundaries.
 */

#ifndef NEON_BLOCK_H
#define NEON_BLOCK_H

#define STRICT 1
#include <Windows.h>

#include "../../model/object/square.h"
#include "../../model/utility/direction.h"

/**
 * \brief Initialises the block object.
 */
void NeonInitBlockObject(void);

/**
 * \brief Renders the block object.
 *
 * \param displayContext The display context handle.
 */
void NeonRenderBlock(HDC displayContext);

/**
 * \brief Moves the block in the specified direction.
 *
 * \param direction The direction to be moved.
 */
void NeonMoveBlock(NeonDirection direction);

/**
 * \brief Sets the boundary the block must stay in.
 *
 * \param size The size of the boundary.
 */
void NeonSetBlockBoundary(const NeonSize size);

/**
 * \brief Gets the position of the block.
 * 
 * \return Stack allocated position of the block.
 */
NeonPosition NeonGetBlockPosition(void);

/**
 * \brief Gets the size of the block.
 * 
 * \return Stack allocated size of the block.
 */
NeonSize NeonGetBlockSize(void);

/**
 * \brief Gets the block as a winapi rectangle.
 *
 * \return The block as the rect type.
 */
RECT NeonGetBlockAsRect(void);

/**
 * \brief Cleans up the resources used by the block object.
 */
void NeonFreeBlockObject(void);

#endif