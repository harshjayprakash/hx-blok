#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

NeonVector NeonNewVector(size_t size)
{
    NeonVector vector = { 0 };
    vector.size = 0;
    vector.max = size;
    vector.head = (-1);

    vector.array = calloc(size, sizeof(NeonVectorItem));

    if (vector.array)
    {
        for (int index = 0; index < vector.max; index++)
        {
            (vector.array + index)->indexed = 0;
            NeonSetPosition(&(vector.array + index)->coordinates, -1, -1);
        }
    }

    return vector;
}

size_t NeonGenerateNewSize(size_t size)
{
    return size * (size / 2);
}

int NeonReSizeVector(NeonVector *vector, size_t newSize)
{
    if (!vector) { return -1; }

    if (!vector->array) { return -1; }

    if (newSize + 1 < vector->max) { return -1; }

    NeonVectorItem *newMemory = realloc(vector->array, newSize * sizeof(NeonVectorItem));

    if (!newMemory) { return -1; }

    vector->array = newMemory;

    for (int index = vector->max; index < newSize; index++)
    {
        ((vector->array + index))->indexed = 0;
        NeonSetPosition(&((vector->array + index))->coordinates, -1, -1);
    }

    vector->max = newSize;

    return 0;
}

int NeonIsEmpty(const NeonVector *vector)
{
    if (!vector) { return -1; }

    if (!vector->array) { return -1; }

    if (vector->head == -1) { return 1; }

    return 0;
}

int NeonIsFull(const NeonVector *vector)
{
    if (!vector) { return -1; }

    if (!vector->array) { return -1; }

    if (vector->head == vector->max - 1) { return 1; }

    return 0;
}

int NeonPush(NeonVector *vector, const NeonVectorItem node)
{
    if (!vector) { return -1; }

    if (!vector->array) { return -1; }

    if (NeonIsFull(vector) == 1)
    {
        NeonReSizeVector(vector, NeonGenerateNewSize(vector->max));
    }

    vector->head++;
    NeonSetPosition(&(vector->array + vector->head)->coordinates, node.coordinates.x, node.coordinates.y);
    (vector->array + vector->head)->indexed = 1;

    return 0;
}

NeonVectorItem *NeonGetNode(const NeonVector *vector, int index)
{
    if (!vector) { return 0; }

    if (!vector->array) { return 0; }

    if (index > vector->head || index < 0) { return 0; }

    return (vector->array + index);
}

int NeonFindNode(const NeonVector *vector, const NeonVectorItem node)
{
    if (!vector) { return -1; }

    if (!vector->array) { return -1; }

    for (int index = 0; index < vector->head + 1; index++)
    {
        if ((vector->array)->coordinates.x == node.coordinates.x || (vector->array)->coordinates.y == node.coordinates.y)
        {
            return index;
        }
    }

    return -1;
}

int NeonNodeExists(const NeonVector *vector, const NeonVectorItem node)
{
    if (NeonFindNode(vector, node) > -1)
    {
        return 1;
    }

    return 0;
}

void NeonFreeVector(NeonVector *vector)
{
    if (!vector) { return; }

    free(vector);
}

void NeonPrintVector(const NeonVector vector)
{
    if (!vector.array) { return; }

    printf(
        "Vector ~ Head: %d, Max: %zu, CurrentSize: %zu\n", 
        vector.head, vector.max, vector.size
    );

    for (int index = 0; index < vector.max; index++)
    {
        printf(
            "Vector Item ~ Coordinates: (%d, %d), Indexed: %d\n",
            (vector.array + index)->coordinates.x,
            (vector.array + index)->coordinates.y,
            (vector.array + index)->indexed
        );
    }
}