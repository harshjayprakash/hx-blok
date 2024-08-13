/**
 * \file position.h
 * \date 13-08-2024
 * \brief Function definitions and structure for the position.
 *
 * This file contains the structure to model position and function definitions to create
 * and set positions.
 */

#ifndef NEON_POSITION_H
#define NEON_POSITION_H

/**
 * \brief Models the position of an object.
 */
typedef struct __NeonPosition
{
    int x;   ///< The X Position
    int y;   ///< The Y Position
} NeonPosition;

/**
 * \brief Creates a new position object.
 * 
 * \param x The x position
 * \param y The y position
 * \return A new stack allocated position object.
 */
NeonPosition NeonCreatePosition(const int x, const int y);

/**
 * \brief Creates a new position object from an existing position object.
 * 
 * \param position The existing position object.
 * \return A new stack allocated position object.
 */
NeonPosition NeonCreatePositionFromSelf(const NeonPosition position);

/**
 * \brief Sets the position.
 * 
 * \param position The position instance to be updated.
 * \param x The new x position.
 * \param y The new y position.
 */
void NeonSetPosition(NeonPosition *position, const int x, const int y);

/**
 * \brief Sets the x position.
 * 
 * \param position The position instance to be updated.
 * \param x The new x position.
 */
void NeonSetXPosition(NeonPosition *position, const int x);

/**
 * \brief Sets the y position.
 * 
 * \param position The position instance to be updated.
 * \param y The new y position.
 */
void NeonSetYPosition(NeonPosition *position, const int y);

/**
 * @brief Copies the positon object.
 * 
 * @param dest The instance to be copied to.
 * @param src The instance to be copied from.
 */
void NeonCopyPosition(NeonPosition *dest, const NeonPosition src);

#endif