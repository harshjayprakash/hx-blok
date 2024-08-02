#ifndef NEON_VECTOR_H
#define NEON_VECTOR_H

#include "../utilities/position.h"

typedef struct _NeonVectorItem
{
    NeonPosition pos;
} NeonVectorItem;

typedef struct _NeonVector
{
    NeonVectorItem *array;
    int max;
    int head;
} NeonVector;

NeonVector NeonNewVector(const int size);

int NeonGenerateNewSize(const int currentSize);

void NeonReSizeVector(const NeonVector *vec);

int NeonIsEmpty(const NeonVector *vec);

int NeonIsFull(const NeonVector *vec);

void NeonFreeVector(NeonVector *vec);

#endif