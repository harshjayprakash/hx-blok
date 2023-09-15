/**
 * @file mark.h
 * @version 0.7.1
 * @date 14-09-2023
 * 
 * @brief Provides the representation of a mark.
 * 
 * This header file contains the functions a model for a mark to be displayed within the
 * window.
 */

#ifndef BLOK_MARK_H
#define BLOK_MARK_H

#include <stdio.h>

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

/**
 * @brief Compares the marks passed as arguments.
 * 
 * @details This function individually compares all the values within the mark structure
 *          with both arguments.
 * 
 * @param firstMark The first mark to be compared.
 * @param secondMark The second mark to be compared.
 * @return An integer indicating whether the objects values match or not.
 * 
 * @retval BLOK_OBJECT_EQUALS: The objects provided match.
 * @retval BLOK_OBJECT_NOT_EQUALS: The objects provided do not match.
 * 
 * @see macro.h
 */
int blokMarkEquals(struct Mark firstMark, struct Mark secondMark);

/**
 * @brief Prints the mark's information to the console.
 * 
 * @details This function combines the given mark's information into a single string
 *          printing it to the debug console.
 * 
 * @param mark the instance of the mark.
 */
void blokMarkPrint(struct Mark *mark);

#endif