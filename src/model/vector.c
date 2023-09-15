/**
 * @file vector.c
 * @version 0.7.1
 * @date 14-09-2023
 * 
 * @brief Implements the vector.
 * 
 * This file implements the operations of the vector as defined in the corresponding
 * header file.
 * 
 * @implements vector.h
 */

#include "vector.h"

struct Vector blokVectorNew(int _size)
{
    struct Vector vector = { NULL, _size, -1 };
    vector.arr = calloc(_size, sizeof(struct Mark));
    return vector;
}

int blokVectorGenerateNewSize(int _size)
{
    return _size * (_size / 2);
}

int blokVectorResize(struct Vector *vector, int _newSize)
{
    if (!vector)
    {
        return BLOK_ERROR_NULL_POINTER;
    }

    if (!vector->arr)
    {
        return BLOK_ERROR_VECTOR_ARRAY_NULL;
    }

    if (_newSize + 1 < vector->max)
    {
        return BLOK_ERROR_VECTOR_INVALID_SIZE;
    }

    struct Mark *newMemory = realloc(vector->arr, _newSize * sizeof(struct Mark));

    if (!newMemory)
    {
        return BLOK_ERROR_MEMORY_REALLOCATION;
    }

    vector->arr = newMemory;

    for (int i = vector->max; i < _newSize; i++)
    {
        blokMarkPositionSet(vector->arr + i, -1, -1);
    }

    vector->max = _newSize;
    
    return BLOK_SUCCESSFUL_OPERATION;
}

int blokVectorFull(struct Vector *vector)
{
    if (!vector)
    {
        return BLOK_ERROR_NULL_POINTER;
    }

    if (!vector->arr)
    {
        return BLOK_ERROR_VECTOR_ARRAY_NULL;
    }

    if (vector->head == vector->max - 1)
    {
        return BLOK_VECTOR_FULL;
    }

    return BLOK_VECTOR_NOT_FULL;
}

int blokVectorEmpty(struct Vector *vector)
{
    if (!vector)
    {
        return BLOK_ERROR_NULL_POINTER;
    }

    if (!vector->arr)
    {
        return BLOK_ERROR_VECTOR_ARRAY_NULL;
    }

    if (vector->head == -1)
    {
        return BLOK_VECTOR_EMPTY;
    }

    return BLOK_VECTOR_NOT_EMPTY;
}

int blokVectorPush(struct Vector *vector, struct Mark _node)
{
    if (!vector)
    {
        return BLOK_ERROR_NULL_POINTER;
    }

    if (!vector->arr)
    {
        return BLOK_ERROR_VECTOR_ARRAY_NULL;
    }
    
    if (blokVectorFull(vector) == BLOK_VECTOR_FULL)
    {
        blokVectorResize(vector, blokVectorGenerateNewSize(vector->max));
    }

    vector->head++;
    blokMarkPositionSet((vector->arr + vector->head), _node.positionX, _node.positionY);

    return BLOK_SUCCESSFUL_OPERATION;
}

struct Mark *blokVectorPointerGet(struct Vector *vector, int _index)
{
    if (!vector)
    {
        return NULL;
    }

    if (!vector->arr)
    {
        return NULL;
    }

    if (_index > vector->head || _index < 0)
    {
        return NULL;
    }

    return (vector->arr + _index);
}

struct Mark blokVectorGet(struct Vector *vector, int _index)
{
    struct Mark *mark = blokVectorPointerGet(vector, _index);
    
    if (!mark)
    {
        return (struct Mark){ -1, -1 };
    }

    return *mark;
}

struct Mark blokVectorPop(struct Vector *vector)
{
    return (struct Mark){ -1, -1 };
}

struct Mark blokVectorPeak(struct Vector *vector)
{
    if (!vector)
    {
        return (struct Mark){ -1, -1 };
    }

    if (!vector->arr)
    {
        return (struct Mark){ -1, -1 };
    }
    
    return blokVectorGet(vector, vector->head);
}

int blokVectorRemoveIndex(struct Vector *vector, int _index)
{
    if (!vector)
    {
        return BLOK_ERROR_NULL_POINTER;
    }

    if (!vector->arr)
    {
        return BLOK_ERROR_VECTOR_ARRAY_NULL;
    }

    if (_index > vector->head || _index < 0)
    {
        return BLOK_ERROR_VECTOR_OUT_OF_RANGE;
    }

    struct Mark *node = blokVectorPointerGet(vector, _index);
    blokMarkPositionSet(node, -1, -1);

    return BLOK_SUCCESSFUL_OPERATION;
}

int blokVectorRemoveObject(struct Vector *vector, struct Mark _node)
{
    if (!vector)
    {
        return BLOK_ERROR_NULL_POINTER;
    }

    if (!vector->arr)
    {
        return BLOK_ERROR_VECTOR_ARRAY_NULL;
    }

    return blokVectorRemoveIndex(vector, blokVectorFind(vector, _node));
}

int blokVectorFind(struct Vector *vector, struct Mark _node)
{
    if (!vector)
    {
        return BLOK_ERROR_NULL_POINTER;
    }

    if (!vector->arr)
    {
        return BLOK_ERROR_VECTOR_ARRAY_NULL;
    }

    for (int i = 0; i < vector->head + 1; i++)
    {
        if (blokMarkEquals(vector->arr[i], _node))
        {
            return i;
        }
    }

    return BLOK_ERROR_VECTOR_INDEX_NOT_FOUND;
}

int blokVectorNextAvailableIndex(struct Vector *vector)
{
    if (!vector)
    {
        return BLOK_ERROR_NULL_POINTER;
    }

    if (!vector->arr)
    {
        return BLOK_ERROR_VECTOR_ARRAY_NULL;
    }

    for (int i = 0; i < vector->max; i++)
    {
        if (blokMarkEquals(vector->arr[i], (struct Mark){ -1, -1 }))
        {
            return i;
        }
    }

    return BLOK_ERROR_VECTOR_NO_INDEX_AVAILABLE;
}

int blokVectorExists(struct Vector *vector, struct Mark _node)
{
    if (blokVectorFind(vector, _node) > -1)
    {
        return BLOK_VECTOR_OBJECT_EXISTS;
    }

    return BLOK_VECTOR_OBJECT_NON_EXISTANT;
}

void blokVectorFree(struct Vector *vector)
{
    if (!vector)
    {
        return;
    }

    BLOK_FREE_IF_NOT_NULL(vector->arr, free);
}
