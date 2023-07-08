#ifndef BLOK_STORE_H
#define BLOK_STORE_H

#include "../model/square.h"
#include "../model/vector.h"

struct Store
{
    struct Square movableSquare;
    struct Vector markedRegions;
};

void blokStoreInitialise(void);

struct Store *blokStoreInstanceGet(void);

void blokStoreFree(void);

#endif
