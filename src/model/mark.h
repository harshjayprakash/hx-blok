/**
 * @file mark.h
 * @version 0.6.1
 * @date 13-07-2023
 * 
 * @brief Provides the representation of a mark.
 * 
 * This header file contains the functions a model for a mark to be displayed within the
 * window.
 */

#ifndef BLOK_MARK_H
#define BLOK_MARK_H

#include "../core/macros.h"

/**
 * @brief Models a positional mark.
 */
struct Mark
{
    /**
     * @brief The x position of the mark.
     */
    int positionX;

    /**
     * @brief The y position of the mark.
     */
    int positionY;
};

/**
 * @brief Creates a new mark object.
 * 
 * @param _positionX The x position of the mark.
 * @param _positionY The y position of the mark.
 * 
 * @return The newly initialised mark.
 */
struct Mark blokMarkNew(int _positionX, int _positionY);

/**
 * @brief Sets the position of a mark.
 * 
 * @param mark The instance of the mark.
 * @param _positionX The new x position.
 * @param _positionY The new y position.
 */
void blokMarkPositionSet(struct Mark *mark, int _positionX, int _positionY);

#endif