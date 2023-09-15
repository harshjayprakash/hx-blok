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

struct Square blokSquareNew(
    int _positionX, int _positionY, 
    int _width, int _height, 
    int _boundaryX, int _boundaryY)
{
    return (struct Square) { 
        _positionX, _positionY, 
        _width, _height, 
        _boundaryX, _boundaryY };
}

void blokSquarePositionSet(struct Square *square, int _positionX, int _positionY)
{
    if (!square)
    {
        return;
    }

    if (_positionX > square->boundaryX 
            || _positionY > square->boundaryY || _positionX < 0 || _positionY < 0)
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

void blokSquareBoundarySet(struct Square *square, int _boundaryX, int _boundaryY)
{
    if (!square)
    {
        return;
    }

    if (_boundaryX < 0 || _boundaryY < 0)
    {
        return;
    }

    square->boundaryX = _boundaryX;
    square->boundaryY = _boundaryY;
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
    destination->boundaryX = (*from).boundaryX;
    destination->boundaryY = (*from).boundaryY;
}
