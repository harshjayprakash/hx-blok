#ifndef BLOK_MODEL_SQUARE_H
#define BLOK_MODEL_SQUARE_H

#include "../core/result.h"
#include "position.h"
#include "dimension.h"
#include "compass.h"

struct TSquare {
    struct TPosition pos;
    struct TDimension size;
    struct TDimension boundary;
};

struct TSquare blokSquareNew(
    struct TPosition pos, struct TDimension size, struct TDimension boundary);

enum TResult blokSquarePositionSet(struct TSquare *sq, struct TPosition pos);

enum TResult blokSquareSizeSet(struct TSquare *sq, struct TDimension size);

enum TResult blokSquareBoundarySet(struct TSquare *sq, struct TDimension boundary);

enum TResult blokSquareMove(struct TSquare *sq, enum TCompass direction);

enum TResult blokSquareCopy(struct TSquare *src, struct TSquare *dest);

#endif