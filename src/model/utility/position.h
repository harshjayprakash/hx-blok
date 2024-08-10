/**
 * @file position.h
 * @date 2024-08-10
 * @brief
 */

#ifndef NEON_POSITION_H
#define NEON_POSITION_H

/**
 * @brief A object to represent position.
 */
typedef struct __NeonPosition
{
    /**
     * @brief X position.
     */
    int x;
    /**
     * @brief Y position.
     */
    int y;
} NeonPosition;

/**
 * @brief Creates a new position object.
 * 
 * @param x The x position.
 * @param y The y position.
 * @return NeonPosition A stack allocated position object.
 */
NeonPosition NeonCreatePosition(const int x, const int y);

/**
 * @brief Creates a new position object from another instance.
 * 
 * @param position The position to copy.
 * @return NeonPosition A new stack allocated instance of position.
 */
NeonPosition NeonCreatePositionFromSelf(const NeonPosition position);

#endif