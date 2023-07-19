/**
 * @file compass.h
 * @version 0.6.1
 * @date 18-07-2023
 * 
 * @brief Directional representation.
 * 
 * This header file contains an enumeration for representing a direction via the compass
 * rose.
 */

#ifndef BLOK_COMPASS_H
#define BLOK_COMPASS_H

/**
 * @brief Describes the direction with compass terms.
 */
enum CompassRose
{
    /**
     * @brief Represents the up movement (north).
     */
    DirectionNorth,

    /**
     * @brief Represents the right movement (east).
     */
    DirectionEast,

    /**
     * @brief Represents the down movement (south).
     */
    DirectionSouth,

    /**
     * @brief Represents the left movement (wes).
     */
    DirectionWest
};

#endif