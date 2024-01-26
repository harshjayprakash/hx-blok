#include "dimension.h"

struct TDimension blokDimensionNew(int width, int height)
{
    return (struct TDimension) { 
        width, height
    };
}

enum TResult blokDimensionSet(struct TDimension *pos, int width, int height)
{
    if (!pos)
    {
        return BLOK_NULLPTR_ERROR;
    }

    pos->width = width;
    pos->height = height;

    return BLOK_SUCCESS;
}

enum TResult blokDimensionCopy(struct TDimension *src, struct TDimension *dest)
{
    if (!src || !dest)
    {
        return BLOK_NULLPTR_ERROR;
    }

    dest->width = src->width;
    dest->height = src->height;

    return BLOK_SUCCESS;
}