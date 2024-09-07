/**
 * \file square.h
 * \date 13-08-2024
 * \brief Function definitions and structure for the square object.
 *
 * This file contains the structure to represent the square object and the function
 * required to create and copy the square object.
 */

#ifndef NEON_SQUARE_H
#define NEON_SQUARE_H

#include "../utility/position.h"
#include "../utility/size.h"

/**
 * \brief Structure that represents a square.
 */
typedef struct __NeonSquare
{
    NeonPosition position;
    NeonSize size;
} NeonSquare;

/**
 * \brief Creates a new square.
 *
 * \param position The position of the square.
 * \param size The size of the square.
 * \return The new stack allocated square object.
 */
NeonSquare NeonCreateSquare(const NeonPosition position, const NeonSize size);

/**
 * \brief Copies the square object.
 *
 * \param dest The instance to be copied to.
 * \param src The instance to be copied from.
 */
void NeonCopySquare(NeonSquare *dest, const NeonSquare src);

#endif