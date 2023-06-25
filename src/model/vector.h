#ifndef BLOK_VECTOR_H
#define BLOK_VECTOR_H


#include "mark.h"

struct vector {
    struct mark *dyn_array;
    int max;
    int head;
};

#endif