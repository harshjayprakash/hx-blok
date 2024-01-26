#ifndef BLOK_MODEL_DIMENSION_H
#define BLOK_MODEL_DIMENSION_H

#include "../core/result.h"

struct TDimension 
{
    int width;
    int height;
};

struct TDimension blokDimensionNew(int width, int height);

enum TResult blokDimensionSet(struct TDimension *pos, int width, int height);

enum TResult blokDimensionCopy(struct TDimension *src, struct TDimension *dest);

#endif