#ifndef NEON_DIRECTION_H
#define NEON_DIRECTION_H

/**
 * @brief Represents the compass rose.
 */
typedef enum __NeonDirection
{
    /**
     * @brief Denotes the north direction.
     */
    NeonNorth = 12,
    /**
     * @brief Denotes the east direction.
     */
    NeonEast = 3,
    /**
     * @brief Denotes the south direction.
     */
    NeonSouth = 6,
    /**
     * @brief Denotes the west direction.
     */
    NeonWest = 9,
} NeonDirection;

#endif