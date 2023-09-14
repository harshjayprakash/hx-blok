/**
 * @file store.c
 * @version 0.6.1
 * @date 18-07-2023
 * 
 * @brief Global store management.
 * 
 * This file contains the functions for the global store instance management as defined
 * in corresponding to the header file.
 * 
 * @implements store.h
 */

#include "store.h"

/**
 * @brief Stores the internal instance of the store, acessable externally through the
 *        blokStoreInstanceGet() function.
 */
static struct Store instance;

/**
 * @brief Stores whether the instance of the store has been initialised to prevent
 *        memory allocation.
 */
static int initialised = 0;

void blokStoreInitialise(void)
{
    if (initialised)
    {
        return;
    }

    instance.movableSquare = blokSquareNew(0, 0, 15, 15);
    instance.projectedSquare = blokSquareNew(0, 0, 15, 15);
    instance.markedRegions = blokVectorNew(10);
    
    for (int i = 0; i < instance.markedRegions.max; i++)
    {
        blokMarkPositionSet(instance.markedRegions.arr + i, -1, -1);
    }

    initialised = 1;
}

struct Store *blokStoreInstanceGet(void)
{
    return &instance;
}

void blokStoreFree(void)
{
    blokVectorFree(&(instance.markedRegions));
}
