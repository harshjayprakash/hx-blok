#include "position.h"

TPosition bloqNewPosition(const int x, const int y)
{
    return (TPosition) { x, y };
}

void bloqSetPositionX(TPosition *pos, const int x)
{
    if (!pos) { return; }

    pos->x = x;
}

void bloqSetPositionY(TPosition *pos, const int y)
{
    if (!pos) { return; }

    pos->y = y;
}

void bloqSetPosition(TPosition *pos, const int x, const int y)
{
    bloqSetPositionX(pos, x);
    bloqSetPositionY(pos, y);
}

void bloqCopyPosition(TPosition *src, TPosition *dest)
{
    if (!src || !dest) { return; }

    bloqSetPosition(dest, src->x, src->y);
}

