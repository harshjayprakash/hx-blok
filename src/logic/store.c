#include "store.h"

static struct Store instance;

void blokStoreInitialise(void)
{
    instance.movableSquare = blokSquareNew(0, 0, 15, 15);
    instance.markedRegions = blokVectorNew(10);
    
    for (int i = 0; i < instance.markedRegions.max; i++)
    {
        blokMarkPositionSet(&(instance.markedRegions.arr[i]), -1, -1);
    }
}

struct Store *blokStoreInstanceGet(void)
{
    return &instance;
}

void blokStoreFree(void)
{
    blokVectorFree(&(instance.markedRegions));
}
