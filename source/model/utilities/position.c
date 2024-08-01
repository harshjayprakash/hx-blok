#include "position.h"

NeonPosition NeonNewPosition(const int x, const int y)
{
    return (NeonPosition) { x, y };
}

NeonPosition NeonNewPositionFromSelf(const NeonPosition pos)
{
    return NeonNewPosition(pos.x, pos.y);
}

void NeonSetPositionX(NeonPosition *pos, const int x)
{
    if (!pos) { return; }
    
    pos->x = x;
}

void NeonSetPositionY(NeonPosition *pos, const int y)
{
    if (!pos) { return; }
    
    pos->y = y;
}

void NeonSetPosition(NeonPosition *pos, const int x, const int y)
{
    NeonSetPositionX(pos, x);
    NeonSetPositionY(pos, y);
}

void NeonCopyPosition(NeonPosition *dest, const NeonPosition src)
{
    NeonSetPosition(dest, src.x, src.y);
}