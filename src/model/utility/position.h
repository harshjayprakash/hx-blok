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

/**
 * @brief Set position.
 * 
 * @param position The position instance to be updated.
 * @param x The new x position.
 * @param y The new y position.
 */
void NeonSetPosition(NeonPosition *position, const int x, const int y);

/**
 * @brief Set the x position.
 * 
 * @param position The position instance to be updated.
 * @param x The new x position.
 */
void NeonSetXPosition(NeonPosition *position, const int x);

/**
 * @brief Set the y position
 * 
 * @param position The position instance to be updated.
 * @param y The new y position.
 */
void NeonSetYPosition(NeonPosition *position, const int y);


/**
 * @brief Copies position object attributes to the destination instance.
 * 
 * @param dest The instance to copy to.
 * @param src The instance to copy from.
 */
void NeonCopyPosition(NeonPosition *dest, const NeonPosition src);

#endif