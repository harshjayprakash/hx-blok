#ifndef BLOK_VECTOR_H
#define BLOK_VECTOR_H

#include <stdlib.h>
#include <memory.h>

#include "mark.h"
#include "../core/macros.h"

struct Vector
{
    struct Mark *arr;
    int max;
    int head;
};

struct Vector blokVectorNew(int _size);

int blokVectorGenerateNewSize(int _size);

int blokVectorResize(struct Vector *vector, int _newSize);

int blokVectorFull(struct Vector *vector);

int blokVectorEmpty(struct Vector *vector);

int blokVectorPush(struct Vector *vector, struct Mark _node);

struct Mark *blokVectorPointerGet(struct Vector *vector, int _index);

struct Mark blokVectorGet(struct Vector *vector, int _index);

struct Mark blokVectorPop(struct Vector *vector);

struct Mark blokVectorPeak(struct Vector *vector);

int blokVectorRemoveIndex(struct Vector *vector, int _index);

int blokVectorRemoveObject(struct Vector *vector, struct Mark _node);

int blokVectorFind(struct Vector *vector, struct Mark _node);

int blokVectorNextAvailableIndex(struct Vector *vector);

void blokVectorFree(struct Vector *vector);

#endif
