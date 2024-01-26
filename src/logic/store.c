#include "store.h"

static struct TStore storeInst;

static int initialised = 0;

enum TResult blokStoreInit(void)
{
    if (initialised)
    {
        return BLOK_UNNESSECARY_INIT;
    }

    storeInst.movableSquare = blokSquareNew(
        blokPositionNew(0, 0), 
        blokDimensionNew(15, 15), 
        blokDimensionNew(260, 260));
    storeInst.projectedSquare = blokSquareNew(
        blokPositionNew(0, 0), 
        blokDimensionNew(15, 15), 
        blokDimensionNew(260, 260));
    storeInst.markedRegions = blokVectorNew(10);

    initialised = 1;

    return BLOK_SUCCESS;
}

struct TStore *blokStoreGet(void)
{
    return &storeInst;
}

enum TResult blokStoreFree(void)
{
    return blokVectorFree(&storeInst.markedRegions);
}