#ifndef NEON_VECTOR_H
#define NEON_VECTOR_H

#include <stdlib.h>
#include "position.h"
#include "../../core/log.h"
#include "../../core/result.h"

typedef struct __NeonNode {
    NeonPosition position;
    int indexed;
} NeonNode;

typedef struct __NeonVector {
    NeonNode *array;
    size_t max;
    size_t size;
    long long head;
} NeonVector;

NeonVector NeonCreateVector(size_t size);

int NeonIsVectorFull(const NeonVector *vector);

int NeonIsVectorEmpty(const NeonVector *vector);

void NeonDestroyVector(NeonVector *vector);

#endif