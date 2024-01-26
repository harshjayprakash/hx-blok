#ifndef BLOK_MODEL_POSITION_H
#define BLOK_MODEL_POSITION_H

#include "../core/result.h"

struct TPosition 
{
    int x;
    int y;
};

struct TPosition blokPositionNew(int x, int y);

enum TResult blokPositionSet(struct TPosition *pos, int x, int y);

enum TResult blokPositionCopy(struct TPosition *src, struct TPosition *dest);

#endif