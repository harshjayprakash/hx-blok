#include "vector.h"
#include <memory.h>

NeonVector NeonCreateVector(size_t size)
{
    NeonLog(NeonInformation, NeonCreateResult(NeonNone, L"Initialising vector."));  

    NeonVector vector = (NeonVector) {
        NULL, size, 0, (-1)
    };

    vector.array = calloc(vector.max, sizeof(NeonNode));

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

    if (!vector->array)
    {
        return NeonLogAndReturn(NeonError, NeonCreateResult(NeonNullPtr, L"Failed to push node: vector array is null"));    
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

NeonNode *NeonGetNodeAsPointer(const NeonVector *vector, const int index)
{
    if (!vector)
    {
        NeonLog(NeonError, NeonCreateResult(NeonNullPtr, L"Failed to get node via index: vector is null"));   
        return NULL; 
    }

    if (!vector->array)
    {
        NeonLog(NeonError, NeonCreateResult(NeonNullPtr, L"Failed to get node via index: vector array is null"));   
        return NULL; 
    }

    if (index > vector->max - 1 || index < 0)
    {
        NeonLog(NeonError, NeonCreateResult(NeonOutOfRange, L"Failed to get node via index: index out of range"));
        return NULL;
    }

    return (vector->array + index);
}

void NeonPrintVector(const NeonVector *vector)
{
    if (!vector)
    {
        NeonLog(NeonError, NeonCreateResult(NeonNullPtr, L"Failed to print vector: is null"));
        return;
    }

    if (!vector->array)
    {
        NeonLog(NeonError, NeonCreateResult(NeonNullPtr, L"Failed to print vector: vector array is null"));   
        return; 
    }

    (void) wprintf(
        L"Vector: { Max: %llu, Size: %llu, Head: %d\n",
        vector->max, vector->size, vector->head
    );

    for (int index = 0; index < vector->max; index++)
    {
        NeonNode *nodePtr = NeonGetNodeAsPointer(vector, index);

        if (!nodePtr) { continue; }

        wprintf(
            L"{ { X: %d, Y: %d }, Indexed: %d }",
            nodePtr->position.x, nodePtr->position.y, nodePtr->indexed
        );
    }
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