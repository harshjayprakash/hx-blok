/**
 * @file square.c
 * @version 0.6.1
 * @date 18-07-2023
 * 
 * @brief Implementation of the square.
 * 
 * This file contains the implementations in correspondance to the header file.
 * 
 * @implements square.h
 */

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

void blokSquareCopy(struct Square *from, struct Square *destination)
{
    if (!from || !destination)
    {
        return;
    }

    destination->height = (*from).height;
    destination->width = (*from).width;
    destination->positionX = (*from).positionX;
    destination->positionY = (*from).positionY;
}
