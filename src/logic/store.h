#ifndef BLOK_LOGIC_STORE_H
#define BLOK_LOGIC_STORE_H

#include "../core/result.h"
#include "../model/square.h"
#include "../model/vector.h"

struct TStore
{
    struct TSquare movableSquare;
    struct TSquare projectedSquare;
    struct TVector markedRegions;
};

enum TResult blokStoreInit(void);

struct TStore *blokStoreGet(void);

enum TResult blokStoreFree(void);

#endif