#ifndef BLOK_STORE_H
#define BLOK_STORE_H

#include <windows.h>

#include "../model/square.h"

struct store
{
    struct square movable_square;
};

struct store *store_instance_get(void);

#endif
