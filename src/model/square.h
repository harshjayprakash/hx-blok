#ifndef BLOK_SQUARE_H
#define BLOK_SQUARE_H

#include "../core/macros.h"
#include "compass.h"

struct Square
{
    int positionX;
    int positionY;
    int width;
    int height;
};

struct Square blokSquareNew(int _positionX, int _positionY, int _width, int _height);

void blokSquarePositionSet(struct Square *square, int _positionX, int _positionY);

void blokSquareSizeSet(struct Square *square, int _width, int _height);

void blokSquareMove(struct Square *square, enum CompassRose _direction);

#endif
