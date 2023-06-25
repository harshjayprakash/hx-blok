#include "vector.h"

struct vector vector_new(const int _size) {
    struct vector vec;
    vec.head = -1;
    vec.max = _size;
    vec.dyn_array = malloc(_size * sizeof(struct mark));
    return vec;
}

int vector_resize(struct vector *vec, int _new_size) {
    if (!vec)
        return 1;

    if (!vec->dyn_array)
        return 2;

    struct mark *new_mem =
        realloc(vec->dyn_array, _new_size * sizeof(struct mark));

    if (!new_mem)
        return 3;

    vec->dyn_array = new_mem;
    vec->max = _new_size;

    return 0;
}

int vector_push(struct vector *vec, struct mark _node) {
    if (vec->head == vec->max)
        return 1;

    vec->dyn_array[vec->head++] = _node;
    return 0;
}

struct mark *vector_get_ptr(const struct vector *vec, int _index) {
    if (_index - 1 > vec->head) {
        return NULL;
    }

    return (vec->dyn_array + (_index - 1));
}

const struct mark vector_get(const struct vector *vec, int _index) {
    struct mark value = {0, 0, mark_invisible};
    if (!vec)
        return value;

    struct mark *result = vector_get_ptr(vec, _index);
    if (!result)
        return value;

    return *result;
}

int vector_next_available_index(const struct vector *vec) {
    if (!vec)
        return -1;

    for (int i = 0; i < vec->head + 1; i++) {
        if (vec->dyn_array[i].illumated == mark_invisible) {
            return i;
        }
    }

    if (vec->head + 1 > vec->max)
        return -2;

    return vec->head + 1;
}

void vector_free(struct vector *vec) {
    if (!vec)
        return;

    if (vec->dyn_array)
        free(vec->dyn_array);
}