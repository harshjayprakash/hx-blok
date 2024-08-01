#include "square.h"

NeonSquare NeonNewSquare(const int x, const int y, const int width, const int height)
{
    return (NeonSquare) { { x, y }, { width, height } };
}

NeonSquare NeonNewSquareFromStruct(const NeonPosition pos, const NeonSize size)
{
    return (NeonSquare) { pos, size };
}

void NeonMoveSquare(NeonSquare *sq, const NeonCompass direction)
{
    if (!sq) { return; }

    switch (direction)
    {
    case NeonNorth:
        NeonSetPositionY(&sq->position, (sq->position.y - sq->size.height));
        return;
    case NeonEast:
        NeonSetPositionX(&sq->position, (sq->position.x + sq->size.width));
        return;
    case NeonSouth:
        NeonSetPositionY(&sq->position, (sq->position.y + sq->size.height));
        return;
    case NeonWest:
        NeonSetPositionX(&sq->position, (sq->position.x - sq->size.width));
        return;
    }
}