#ifndef BLOK_VECTOR_H
#define BLOK_VECTOR_H

#include <stdlib.h>
#include <memory.h>

#include "mark.h"
#include "../core/macros.h"

struct Vector
{
    struct Mark *arr;
    int max;
    int head;
};

#endif
