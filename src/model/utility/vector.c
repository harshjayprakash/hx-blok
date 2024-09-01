/**
 * \file vector.c
 * \date 13-08-2024
 * \brief Implementation of vector related functions.
 *
 * This file contains the vector function operations as defined in the header file.
 */

#include "vector.h"
#include "position.h"
#include <memory.h>

NeonVector NeonCreateVector(size_t size)
{
    NeonLog(NeonInformation, NeonCreateResult(NeonNone, L"Initialising Vector."));

    NeonVector vector = (NeonVector){NULL, size, 0, (-1)};

    vector.array = calloc(vector.max, sizeof(NeonNode));

    if (!vector.array)
    {
        NeonLog(NeonError,
                NeonCreateResult(NeonNullPtr, L"Vector Initialisation Failed"));
    }

    return vector;
}

size_t NeonGenerateNewVectorSize(size_t size)
{
    return size + (size * 2);
}

NeonResult NeonReSizeVector(NeonVector *vector, size_t newSize)
{
    NeonLog(NeonInformation,
            NeonCreateResult(NeonNone, L"Attempting to Re-sizing Vector."));

    if (!vector)
    {
        return NeonLogAndReturn(
            NeonError,
            NeonCreateResult(NeonNullPtr, L"Vector Re-size Failed: Null Pointer Error."));
    }

    if (!vector->array)
    {
        return NeonLogAndReturn(
            NeonError, NeonCreateResult(NeonNullPtr,
                                        L"Vector Re-size Failed: Vector Array is Null."));
    }

    if (newSize + 1 < vector->max)
    {
        return NeonLogAndReturn(
            NeonError,
            NeonCreateResult(NeonOutOfRange, L"Vector Re-size Failed: Invalid Size."));
    }

    NeonNode *newMemory = realloc(vector->array, newSize * sizeof(NeonNode));

    if (!newMemory)
    {
        return NeonLogAndReturn(
            NeonError,
            NeonCreateResult(NeonOutOfRange,
                             L"Vector Re-size Failed: Memory Allocation Error."));
    }

    vector->array = newMemory;
    vector->max = newSize;

    return NeonLogAndReturn(NeonInformation,
                            NeonCreateResult(NeonNone, L"Re-sized Vector."));
}

int NeonIsVectorFull(const NeonVector *vector)
{
    if (!vector)
    {
        NeonLog(NeonError,
                NeonCreateResult(NeonNullPtr,
                                 L"Vector Full Check Failed: Null Pointer Error."));
        return -1;
    }

    if (vector->head == vector->max - 1)
    {
        return 1;
    }

    return 0;
}

int NeonIsVectorEmpty(const NeonVector *vector)
{
    if (!vector)
    {
        NeonLog(NeonError,
                NeonCreateResult(NeonNullPtr,
                                 L"Vector Empty Check Failed: Null Pointer Error."));
        return -1;
    }

    if (vector->head == -1)
    {
        return 1;
    }

    return 0;
}

NeonResult NeonPushNode(NeonVector *vector, const NeonNode node)
{
    if (!vector)
    {
        return NeonLogAndReturn(
            NeonError,
            NeonCreateResult(NeonNullPtr, L"Node Push Failed: Null Pointer Error."));
    }

    if (!vector->array)
    {
        return NeonLogAndReturn(
            NeonError,
            NeonCreateResult(NeonNullPtr, L"Node Push Failed: Vectory Array is Null."));
    }

    if (NeonIsVectorFull(vector) == 1)
    {
        NeonReSizeVector(vector, NeonGenerateNewVectorSize(vector->max));
    }

    vector->head++;
    vector->size++;
    (vector->array + vector->head)->indexed = 1;
    NeonCopyPosition(&((vector->array + vector->head)->position), node.position);

    return NeonLogAndReturn(NeonInformation, NeonCreateResult(NeonNone, L"Node Pushed."));
}

NeonNode *NeonGetNodeAsPointer(const NeonVector *vector, const int index)
{
    if (!vector)
    {
        NeonLog(
            NeonError,
            NeonCreateResult(NeonNullPtr, L"Node via Index Failed: Null Pointer Error."));
        return NULL;
    }

    if (!vector->array)
    {
        NeonLog(NeonError,
                NeonCreateResult(NeonNullPtr,
                                 L"Node via Index Failed: Vectory Array is Null."));
        return NULL;
    }

    if (index > vector->max - 1 || index < 0)
    {
        NeonLog(NeonError, NeonCreateResult(NeonOutOfRange,
                                            L"Node via Index Failed: Out of Range."));
        return NULL;
    }

    return (vector->array + index);
}

NeonResult NeonClearVector(NeonVector *vector)
{
    if (!vector)
    {
        return NeonLogAndReturn(
            NeonError, NeonCreateResult(NeonNullPtr,
                                        L"Clearing Vector Failed: Null Pointer Error."));
    }

    if (!vector->array)
    {
        return NeonLogAndReturn(
            NeonError,
            NeonCreateResult(NeonNullPtr,
                             L"Clearing Vector Failed: Vector Array is Null."));
    }

    for (int index = 0; index < vector->max; index++)
    {
        NeonNode *nodePtr = NeonGetNodeAsPointer(vector, index);

        if (!nodePtr)
        {
            continue;
        }

        nodePtr->indexed = 0;
        NeonSetPosition(&(nodePtr->position), -1, -1);
    }

    vector->size = 0;
    vector->head = -1;

    return NeonLogAndReturn(NeonInformation,
                            NeonCreateResult(NeonNone, L"Vector Cleared."));
}

int NeonNodeExists(const NeonVector *vector, const NeonNode node)
{
    if (!vector)
    {
        NeonLog(NeonError,
                NeonCreateResult(NeonNullPtr,
                                 L"Node Exists Check Failed: Null Pointer Error."));
        return 0;
    }

    if (!vector->array)
    {
        NeonLog(NeonError,
                NeonCreateResult(NeonNullPtr,
                                 L"Node Exists Check Failed: Vector Array is Null."));
        return 0;
    }

    for (int index = 0; index < vector->size; index++)
    {
        NeonNode *nodePtr = NeonGetNodeAsPointer(vector, index);

        if (node.position.x == nodePtr->position.x &&
            node.position.y == nodePtr->position.y)
        {
            return 1;
        }
    }

    return 0;
}

void NeonPrintVector(const NeonVector *vector)
{
    if (!vector)
    {
        NeonLog(NeonError, NeonCreateResult(NeonNullPtr,
                                            L"Vector Print Failed: Null Pointer Error."));
        return;
    }

    if (!vector->array)
    {
        NeonLog(
            NeonError,
            NeonCreateResult(NeonNullPtr, L"Vector Print Failed: Vector Array is Null."));
        return;
    }

    (void)wprintf(L"Vector: { Max: %llu, Size: %llu, Head: %d\n", vector->max,
                  vector->size, vector->head);

    for (int index = 0; index < vector->max; index++)
    {
        NeonNode *nodePtr = NeonGetNodeAsPointer(vector, index);

        if (!nodePtr)
        {
            continue;
        }

        (void)wprintf(L"{ { X: %d, Y: %d }, Indexed: %d }\n", nodePtr->position.x,
                      nodePtr->position.y, nodePtr->indexed);
    }
}

void NeonDestroyVector(NeonVector *vector)
{
    if (!vector)
    {
        NeonLog(NeonError, NeonCreateResult(NeonNullPtr, L"Vector Destruction Failure."));
        return;
    }

    free(vector->array);
    NeonLog(NeonInformation, NeonCreateResult(NeonNone, L"Cleaned Up Vector Resources."));
}