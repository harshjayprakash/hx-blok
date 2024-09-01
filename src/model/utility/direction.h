/**
 * \file direction.h
 * \date 01-09-2024
 * \brief Enumeration for denoting direction.
 * 
 * This file contains an enumeration that represents direction via the compass rose.
 */

#ifndef NEON_DIRECTION_H
#define NEON_DIRECTION_H

/**
 * \brief Models a compass rose.
 */
typedef enum __NeonDirection
{
    NeonNorth = 12, ///< The North Direction (Up)
    NeonEast = 3,   ///< The East Direction (Right)
    NeonSouth = 6,  ///< The South Direction (Down)
    NeonWest = 9,   ///< The West Direction (Left)
} NeonDirection;

#endif