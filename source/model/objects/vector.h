#ifndef NEON_VECTOR_H
#define NEON_VECTOR_H

#include "../utilities/position.h"
#include <stddef.h>

typedef struct _NeonVectorItem
{
    int indexed;
    NeonPosition coordinates;
} NeonVectorItem;

typedef struct _NeonVector
{
    NeonVectorItem *array;
    int head;
    size_t max;
    size_t size;
} NeonVector;

NeonVector NeonNewVector(size_t size);

size_t NeonGenerateNewSize(size_t size);

int NeonReSizeVector(NeonVector *vector, size_t newSize);

int NeonIsEmpty(const NeonVector *vector);

int NeonIsFull(const NeonVector *vector);

int NeonPush(NeonVector *vector, const NeonVectorItem node);

NeonVectorItem *NeonGetNode(const NeonVector *vector, int index);

int NeonFindNode(const NeonVector *vector, const NeonVectorItem node);

int NeonNodeExists(const NeonVector *vector, const NeonVectorItem node);

void NeonFreeVector(NeonVector *vector);

void NeonPrintVector(const NeonVector vector);

#endif