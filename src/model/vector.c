#include "vector.h"
#include <stdio.h>

struct TVector blokVectorNew(int size)
{
    struct TVector vec = {
        .arr = NULL,
        .max = size,
        .head = -1
    };

    vec.arr = calloc(size, sizeof(struct TPosition));

    if (vec.arr)
    {
        for (int i = 0; i < size; i++)
        {
            blokPositionSet(vec.arr + i, -1, -1);
        }
    }
    
    return vec;
}

int blokVectorGenerateNewSize(int size)
{
    return size * (size / 2);
}

enum TResult blokVectorResize(struct TVector *vec, int newSize)
{
    if (!vec)
    {
        return BLOK_NULLPTR_ERROR;
    }

    if (!vec->arr)
    {
        return BLOK_VEC_ARR_NULL;
    }

    if (newSize + 1  < vec->max) 
    {
        return BLOK_VEC_INVALID_SIZE;
    }

    struct TPosition *newMem = realloc(vec->arr, newSize * sizeof(struct TPosition));

    if (!newMem)
    {
        return BLOK_REALLOC_ERROR;
    }

    vec->arr = newMem;

    for (int i = vec->max; i < newSize; i++)
    {
        blokPositionSet(vec->arr + i, -1, -1);
    }

    vec->max = newSize;

    return BLOK_SUCCESS;
}

enum TResult blokVectorFull(struct TVector *vec)
{
    if (!vec)
    {
        return BLOK_NULLPTR_ERROR;
    }

    if (!vec->arr)
    {
        return BLOK_VEC_ARR_NULL;
    }

    if (vec->head == vec->max - 1)
    {
        return BLOK_VEC_ARR_FULL;
    }

    return BLOK_VEC_ARR_NOT_FULL;
}

enum TResult blokVectorEmpty(struct TVector *vec)
{
    if (!vec)
    {
        return BLOK_NULLPTR_ERROR;
    }

    if (!vec->arr)
    {
        return BLOK_VEC_ARR_NULL;
    }

    if (vec->head == -1)
    {
        return BLOK_VEC_ARR_EMPTY;
    }

    return BLOK_VEC_ARR_NOT_EMPTY;
}

enum TResult blokVectorPush(struct TVector *vec, struct TPosition node)
{
    if (!vec)
    {
        return BLOK_NULLPTR_ERROR;
    }

    if (!vec->arr)
    {
        return BLOK_VEC_ARR_NULL;
    }

    if (blokVectorFull(vec) == BLOK_VEC_ARR_FULL)
    {
        blokVectorResize(vec, blokVectorGenerateNewSize(vec->max));
    }

    vec->head++;
    blokPositionSet((vec->arr + vec->head), node.x, node.y);

    return BLOK_SUCCESS;
}

struct TPosition *blokVectorPointerGet(struct TVector *vec, int index)
{
    if (!vec)
    {
        return NULL;
    }

    if (!vec->arr)
    {
        return NULL;
    }

    if (index > vec->head || index < 0)
    {
        return NULL;
    }

    return (vec->arr + index);
}

struct TPosition blokVectorGet(struct TVector *vec, int index)
{
    struct TPosition *pos = blokVectorPointerGet(vec, index);

    if (!pos)
    {
        return (struct TPosition) {
            .x = -1,
            .y = -1
        };
    }

    return *pos;
}

struct TPosition blokVectorPop(struct TVector *vec)
{
    /* Not Implementated */
    return (struct TPosition) {
        .x = -1,
        .y = -1
    };
}

struct TPosition blokVectorPeak(struct TVector *vec)
{
    if (!vec)
    {
        return (struct TPosition) {
            .x = -1,
            .y = -1
        };
    }

    if (!vec->arr)
    {
        return (struct TPosition) {
            .x = -1,
            .y = -1
        };
    }

    return blokVectorGet(vec, vec->head);
}

enum TResult blokVectorRemoveIndex(struct TVector *vec, int index)
{
    if (!vec)
    {
        return BLOK_NULLPTR_ERROR;
    }

    if (!vec->arr)
    {
        return BLOK_VEC_ARR_NULL;
    }

    if (index > vec->head || index < 0)
    {
        return BLOK_OUT_OF_RANGE;
    }

    struct TPosition *node = blokVectorPointerGet(vec, index);
    blokPositionSet(node, -1, -1);

    return BLOK_SUCCESS;
}

enum TResult blokVectorRemoveObject(struct TVector *vec, struct TPosition node)
{
    if (!vec)
    {
        return BLOK_NULLPTR_ERROR;
    }

    if (!vec->arr)
    {
        return BLOK_VEC_ARR_NULL;
    }

    return blokVectorRemoveIndex(vec, blokVectorFind(vec, node));
}

int blokVectorFind(struct TVector *vec, struct TPosition node)
{
    if (!vec)
    {
        return (int)BLOK_NULLPTR_ERROR;
    }

    if (!vec->arr)
    {
        return (int)BLOK_VEC_ARR_NULL;
    }

    for (int i = 0; i < vec->head + 1; i++)
    {
        if (vec->arr[i].x == node.x && vec->arr[i].y == node.y)
        {
            return i;
        }
    }

    return (int)BLOK_INDEX_NOT_FOUND;
}

int blokVectorNewAvailableIndex(struct TVector *vec)
{
    if (!vec)
    {
        return (int)BLOK_NULLPTR_ERROR;
    }

    if (!vec->arr)
    {
        return (int)BLOK_VEC_ARR_NULL;
    }

    for (int i = 0; i < vec->head + 1; i++)
    {
        if (vec->arr[i].x == -1 && vec->arr[i].y == -1)
        {
            return i;
        }
    }

    return (int)BLOK_INDEX_NOT_FOUND;
}

enum TResult blokVectorExists(struct TVector *vec, struct TPosition node)
{
    if (blokVectorFind(vec, node) > -1)
    {
        return BLOK_OBJ_EXISTS;
    }

    return BLOK_OBJ_NON_EXISTANT;
}

enum TResult blokVectorClear(struct TVector *vec)
{
    if (!vec)
    {
        return BLOK_NULLPTR_ERROR;
    }

    if (!vec->arr)
    {
        return BLOK_VEC_ARR_NULL;
    }

    for (int i = 0; i < vec->max; i++)
    {
        blokPositionSet(vec->arr + i, -1, -1);
    }

    return BLOK_SUCCESS;
}

enum TResult blokVectorFree(struct TVector *vec)
{
    if (!vec)
    {
        return BLOK_NULLPTR_ERROR;
    }

    if (!vec->arr) 
    {
        free(vec->arr);
    }

    return BLOK_SUCCESS;
}