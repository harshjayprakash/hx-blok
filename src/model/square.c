#include "square.h"

struct Square blokSquareNew(int _positionX, int _positionY, int _width, int _height)
{
    return (struct Square){ _positionX, _positionY, _width, _height };
}

void blokSquarePositionSet(struct Square *square, int _positionX, int _positionY)
{
    if (!square)
    {
        return;
    }

    square->positionX = _positionX;
    square->positionY = _positionY;
}

void blokSquareSizeSet(struct Square *square, int _width, int _height)
{
    if (!square)
    {
        return;
    }

    square->width = _width;
    square->height = _height;
}

void blokSquareMove(struct Square *square, enum CompassRose _direction)
{
    if (!square)
    {
        return;
    }

    switch (_direction)
    {
    case DirectionNorth:
        blokSquarePositionSet(
            square, square->positionX, (square->positionY - square->height));
        break;
    case DirectionEast:
        blokSquarePositionSet(
            square, (square->positionX + square->width), square->positionY);
        break;
    case DirectionSouth:
        blokSquarePositionSet(
            square, square->positionX, (square->positionY + square->height));
        break;
    case DirectionWest:
        blokSquarePositionSet(
            square, (square->positionX - square->width), square->positionY);
        break;
    default:
        break; 
    }
}
