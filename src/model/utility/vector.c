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