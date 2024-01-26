#ifndef BLOK_MODEL_VECTOR_H
#define BLOK_MODEL_VECTOR_H

#include <stdlib.h>
#include <memory.h>
#include "position.h"
#include "../core/result.h"

struct TVector {
    struct TPosition *arr;
    int max;
    int head;
};

union TOptionalIndex {
    int index;
    enum TResult result;
};

struct TVector blokVectorNew(int size);

int blokVectorGenerateNewSize(int size);

enum TResult blokVectorResize(struct TVector *vec, int newSize);

enum TResult blokVectorFull(struct TVector *vec);

enum TResult blokVectorEmpty(struct TVector *vec);

enum TResult blokVectorPush(struct TVector *vec, struct TPosition node);

struct TPosition *blokVectorPointerGet(struct TVector *vec, int index);

struct TPosition blokVectorGet(struct TVector *vec, int index);

struct TPosition blokVectorPop(struct TVector *vec);

struct TPosition blokVectorPeak(struct TVector *vec);

enum TResult blokVectorRemoveIndex(struct TVector *vec, int index);

enum TResult blokVectorRemoveObject(struct TVector *vec, struct TPosition node);

int blokVectorFind(struct TVector *vec, struct TPosition node);

int blokVectorNewAvailableIndex(struct TVector *vec);

enum TResult blokVectorExists(struct TVector *vec, struct TPosition node);

enum TResult blokVectorFree(struct TVector *vec);

#endif