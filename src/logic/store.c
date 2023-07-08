#include "store.h"

static struct Store singletonInstance;

void blokStoreInitialise(void)
{
    singletonInstance.movableSquare = blokSquareNew(0, 0, 15, 15);
    singletonInstance.markedRegions = blokVectorNew(10);
    
    for (int i = 0; i < singletonInstance.markedRegions.max; i++)
    {
        blokMarkPositionSet(&(singletonInstance.markedRegions.arr[i]), -1, -1);
    }
}

struct Store *blokStoreInstanceGet(void)
{
    return &singletonInstance;
}

void blokStoreFree(void)
{
    blokVectorFree(&(singletonInstance.markedRegions));
}
