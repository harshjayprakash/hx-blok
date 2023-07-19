/**
 * @file square.h
 * @version 0.6.1
 * @date 18-07-2023
 * 
 * @brief Representation of a square.
 * 
 * This file contains the representation of a square that will be used to denote the user,
 * which is movable.
 */

#ifndef BLOK_SQUARE_H
#define BLOK_SQUARE_H

#include "../core/macros.h"
#include "compass.h"

/**
 * @brief Representation of a square.
 */
struct Square
{
    /**
     * @brief Stores the x position of the square.
     */
    int positionX;

    /**
     * @brief Stores the y position of the square.
     */
    int positionY;

    /**
     * @brief Stores the width of the square.
     */
    int width;

    /**
     * @brief Stores the height of the square.
     */
    int height;
};

/**
 * @brief Constructs a new square.
 * 
 * This newly constructed object is returned as a stack allocated instance.
 * 
 * @param _positionX the x position of the square.
 * @param _positionY the y position of the square.
 * @param _width the width of the square.
 * @param _height the height of the square.
 * @return A Square.
 */
struct Square blokSquareNew(int _positionX, int _positionY, int _width, int _height);

/**
 * @brief Sets the position of the square.
 * 
 * @details This function re-assigns the positional coordinates of the provided square..
 * 
 * @param square the instance of the square.
 * @param _positionX the new x position of the square.
 * @param _positionY the new y position of the square.
 */
void blokSquarePositionSet(struct Square *square, int _positionX, int _positionY);

/**
 * @brief Sets the size of the square.
 * 
 * @details This function re-assigns the dimensions of the provided square.
 * 
 * @param square the instance of the square.
 * @param _width the new width of the square.
 * @param _height the new height of the square.
 */
void blokSquareSizeSet(struct Square *square, int _width, int _height);

/**
 * @brief Moves the position of the square.
 * 
 * @details This function works out the new set of coordinates based on the initialised 
 *          dimensions of the square and the given direction.
 *          Up:      position y - height
 *          Right:   position x + width
 *          Down:    position y + height
 *          Left:    position x - width
 * 
 *          The new coordinates are set using the blokSquarePositionSet function.
 * 
 * @param square the instance of the square.
 * @param _direction the direction the square should move.
 */
void blokSquareMove(struct Square *square, enum CompassRose _direction);

#endif
