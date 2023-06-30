#ifndef BLOK_VECTOR_H
#define BLOK_VECTOR_H

#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

#include "mark.h"

struct vector {
    struct mark *dyn_array;
    int max;
    int head;
};

struct vector vector_new(int _size);

int vector_resize(struct vector *vec, int _new_size);

int vector_push(struct vector *vec, struct mark _node);

struct mark vector_get(const struct vector *vec, int _index);

struct mark *vector_get_ptr(const struct vector *vec, int _index);

int vector_next_available_index(const struct vector *vec);

void vector_free(struct vector *vec);

#endif
