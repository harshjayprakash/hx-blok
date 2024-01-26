#include "square.h"
#include <stdio.h>

struct TSquare blokSquareNew(
    struct TPosition pos, struct TDimension size, struct TDimension boundary)
{
    return (struct TSquare) {
        pos, size, boundary
    };
}

enum TResult blokSquarePositionSet(struct TSquare *sq, struct TPosition pos)
{
    if (!sq)
    {
        return BLOK_NULLPTR_ERROR;
    }

    if (pos.x > sq->boundary.width || pos.y > sq->boundary.height 
        || pos.x < 0 || pos.y < 0)
    {
        return BLOK_OUTSIDE_BOUNDARY;
    }

    return blokPositionCopy(&pos, &sq->pos);
}

enum TResult blokSquareSizeSet(struct TSquare *sq, struct TDimension size)
{
    if (!sq)
    {
        return BLOK_NULLPTR_ERROR;
    }

    return blokDimensionCopy(&size, &sq->size);
}

enum TResult blokSquareBoundarySet(struct TSquare *sq, struct TDimension boundary)
{
    if (!sq)
    {
        return BLOK_NULLPTR_ERROR;
    }

    if (boundary.width < sq->size.width || boundary.height < sq->size.height)
    {
        return BLOK_INVALID_BOUNDARY;
    }

    return blokDimensionCopy(&boundary, &sq->boundary);
}

enum TResult blokSquareMove(struct TSquare *sq, enum TCompass direction)
{
    if (!sq)
    {
        return BLOK_NULLPTR_ERROR;
    }

    switch (direction)
    {
    case BLOK_DIRECTION_NORTH:
        return blokSquarePositionSet(
            sq, blokPositionNew(sq->pos.x, (sq->pos.y - sq->size.height)));
    case BLOK_DIRECTION_EAST:
        return blokSquarePositionSet(
            sq, blokPositionNew((sq->pos.x + sq->size.width), sq->pos.y));
    case BLOK_DIRECTION_SOUTH:
        return blokSquarePositionSet(
            sq, blokPositionNew(sq->pos.x, (sq->pos.y + sq->size.height)));
    case BLOK_DIRECTION_WEST:
        return blokSquarePositionSet(
            sq, blokPositionNew((sq->pos.x - sq->size.width), sq->pos.y));
    default:
        break;
    }
}

enum TResult blokSquareCopy(struct TSquare *src, struct TSquare *dest)
{
    if (!src || !dest)
    {
        return BLOK_NULLPTR_ERROR;
    }

    enum TResult result;

    result = blokPositionCopy(&src->pos, &dest->pos);
    if (result != BLOK_SUCCESS)
    {
        return result;
    }

    result = blokDimensionCopy(&src->size, &dest->size);
    if (result != BLOK_SUCCESS)
    {
        return result;
    }

    result = blokDimensionCopy(&src->boundary, &dest->boundary);
    if (result != BLOK_SUCCESS)
    {
        return result;
    }

    return BLOK_SUCCESS;
}