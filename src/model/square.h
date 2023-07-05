#ifndef BLOK_SQUARE_H
#define BLOK_SQUARE_H

#include "direction.h"

/**
 * @brief Models a square object.
 */
struct square
{
    int x;
    int y;
    int width;
    int height;
};

/**
 * @brief Responsible for creating a new square instance.
 * @param _x the x coordinate of the square.
 * @param _y the y coordinate of the square.
 * @param _width the width of the square.
 * @param _height the height of the square.
 * @return a new stack allocated instance of a square.
 */
struct square square_new(int _x, int _y, int _width, int _height);

/**
 * @brief Sets the position of the given square
 * @param sq the instance of the square.
 * @param _x the new x coordinate.
 * @param _y the new y coordinate.
 */
void square_position_set(struct square *sq, int _x, int _y);

/**
 * @brief Sets the size of the given square.
 * @param sq the instance of the square.
 * @param _width the new width of the square.
 * @param _height the new height of the square.
 */
void square_size_set(struct square *sq, int _width, int _height);

/**
 * @brief Moves the square in the direction specified.
 * @param sq the instance of the square.
 * @param _direction the direction to move.
 */
void square_move(struct square *sq, enum direction _direction);

/**
 * @brief Frees any memory allocated of the given square.
 * @param sq the instance of the square.
 */
void square_free(struct square *sq);

#endif
