#ifndef BLOK_MARK_H
#define BLOK_MARK_H

#include "../core/macros.h"

struct Mark
{
    int positionX;
    int positionY;
};

struct Mark blokMarkNew(int _positionX, int _positionY);

void blokMarkPositionSet(struct Mark *mark, int _positionX, int _positionY);

#endif