#include "vector.h"
#include <memory.h>

NeonVector NeonCreateVector(size_t size)
{
    NeonVector vector = (NeonVector) {
        NULL, size, 0, (-1)
    };

    vector.array = calloc(vector.size, sizeof(NeonNode));

    if (!vector.array)
    {
        NeonLog(NeonError, NeonCreateResult(NeonNullPtr, L"Failed initialise vector."));
    }

    return vector;
}

int NeonIsVectorFull(const NeonVector *vector)
{
    if (!vector)
    {
        NeonLog(NeonError, NeonCreateResult(NeonNullPtr, L"Failed to get vector status: is null"));
        return -1;
    }

    if (vector->head == vector->max && vector->size == vector->max)
    {
        return 1;
    }
    
    return 0;
}

int NeonIsVectorEmpty(const NeonVector *vector)
{
    if (!vector)
    {
        NeonLog(NeonError, NeonCreateResult(NeonNullPtr, L"Failed to get vector status: is null"));
        return -1;
    }

    if (vector->size == 0 && vector->head == -1)
    {
        return 1;
    }

    return 0;
}

NeonResult NeonPushNode(NeonVector *vector, const NeonNode node)
{
    if (!vector)
    {
        return NeonLogAndReturn(NeonError, NeonCreateResult(NeonNullPtr, L"Failed to push node: vector is null"));
    }

    if (NeonIsVectorFull(vector))
    {
        return NeonLogAndReturn(NeonError, NeonCreateResult(NeonNullPtr, L"Failed to push node: vector is full"));
    }

    vector->head++;
    vector->size++;
    (vector->array + vector->head)->indexed = 1;
    NeonCopyPosition(&((vector->array + vector->head)->position), node.position);

    return NeonLogAndReturn(NeonInformation, NeonCreateResult(NeonNone, L"Vector: node pushed."));
}

void NeonDestroyVector(NeonVector *vector)
{
    if (!vector)
    {
        NeonLog(NeonError, NeonCreateResult(NeonNullPtr, L"Failed to free vector: is null"));
        return;
    }

    free(vector->array);
    NeonLog(NeonInformation, NeonCreateResult(NeonNone, L"Cleaned up resources used by vector."));
}