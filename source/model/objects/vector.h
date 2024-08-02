#ifndef NEON_VECTOR_H
#define NEON_VECTOR_H

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

int NeonIsEmpty(const NeonVector *vec);

int NeonIsFull(const NeonVector *vec);

int NeonFreeVector(NeonVector *vec);

#endif