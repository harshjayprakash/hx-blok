/**
 * @file square.h
 * @date 2024-08-10
 * @brief
 */

#ifndef NEON_SQUARE_H
#define NEON_SQUARE_H

#include "../utility/position.h"
#include "../utility/size.h"

/**
 * @brief A object to represent the movable block.
 */
typedef struct __NeonSquare
{
    NeonPosition position;
    NeonSize size;
} NeonSquare;

/**
 * @brief Creates a new square object.
 * 
 * @param position The position of the square.
 * @param size The position of the size.
 * @return NeonSquare A stack allocated square object.
 */
NeonSquare NeonCreateSquare(const NeonPosition position, const NeonSize size);

#endif