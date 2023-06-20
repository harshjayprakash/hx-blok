#ifndef __BLOK_SQUARE_H
#define __BLOK_SQUARE_H

/**
 * @brief Models a square object.
 */
typedef struct square__
{
    int x;
    int y;
    int width;
    int height;
} square;


/**
 * @brief Responsible for creating a new square instance.
 * @param _x the x coordinate of the square.
 * @param _y the y coordinate of the square.
 * @param _width the width of the square.
 * @param _height the height of the square.
 * @return a new stack allocated instance of a square.
 */
square square_new(int _x, int _y, int _width, int _height);


/**
 * @brief Sets the position of the given square
 * @param sq the instance of the square.
 * @param _x the new x coordinate.
 * @param _y the new y coordinate.
 */
void square_position_set(square *sq, int _x, int _y);

/**
 * @brief Sets the size of the given square.
 * @param sq the instance of the square.
 * @param _width the new width of the square.
 * @param _height the new height of the square.
 */
void square_size_set(square *sq, int _width, int _height);

/**
 * @brief Frees any memory allocated of the given square.
 * @param sq the instance of the square.
 */
void square_free(square *sq);

#endif