#ifndef NEON_SQUARE_H
#define NEON_SQUARE_H

#include "../utilities/position.h"
#include "../utilities/size.h"
#include "../utilities/direction.h"

typedef struct _NeonSquare
{
    NeonPosition position;
    NeonSize size;
} NeonSquare;

NeonSquare NeonNewSquare(const int x, const int y, const int width, const int height);

NeonSquare NeonNewSquareFromStruct(const NeonPosition pos, const NeonSize size);

void NeonMoveSquare(NeonSquare *sq, const NeonCompass direction);

#endif