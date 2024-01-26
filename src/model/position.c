#include "position.h"

struct TPosition blokPositionNew(int x, int y)
{
    return (struct TPosition) { 
        x, y
    };
}

enum TResult blokPositionSet(struct TPosition *pos, int x, int y)
{
    if (!pos)
    {
        return BLOK_NULLPTR_ERROR;
    }

    pos->x = x;
    pos->y = y;

    return BLOK_SUCCESS;
}

enum TResult blokPositionCopy(struct TPosition *src, struct TPosition *dest)
{
    if (!src || !dest)
    {
        return BLOK_NULLPTR_ERROR;
    }

    dest->x = src->x;
    dest->y = src->y;

    return BLOK_SUCCESS;
}