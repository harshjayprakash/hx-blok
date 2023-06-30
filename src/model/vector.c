#include "vector.h"

struct vector vector_new(int _size) {
    struct vector vec;
    vec.head = -1;
    vec.max = _size;
    vec.dyn_array = malloc(_size * sizeof(struct mark));
    return vec;
}

int vector_resize(struct vector *vec, int _new_size) {
    if (!vec)
        return BLOK_VECTOR_NULL;

    if (!vec->dyn_array)
        return BLOK_VECTOR_ARRAY_NULL;

    struct mark *new_mem =
        realloc(vec->dyn_array, _new_size * sizeof(struct mark));

    if (!new_mem)
        return BLOK_VECTOR_REALLOC_FAILED;

    vec->dyn_array = new_mem;
    vec->max = _new_size;

    return BLOK_OPERATION_SUCCESS;
}

int vector_push(struct vector *vec, struct mark _node) {
    if (vec->head == vec->max)
        return BLOK_VECTOR_CAPACITY_FULL;

    vec->dyn_array[vec->head++] = _node;
    return BLOK_OPERATION_SUCCESS;
}

struct mark *vector_get_ptr(const struct vector *vec, int _index) {
    if (_index - 1 > vec->head) {
        return NULL;
    }

    return (vec->dyn_array + (_index - 1));
}

struct mark vector_get(const struct vector *vec, int _index) {
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
        return BLOK_NULL_POINTER_ERROR;

    for (int i = 0; i < vec->head + 1; i++) {
        if (vec->dyn_array[i].illumated == mark_invisible) {
            return i;
        }
    }

    if (vec->head + 1 > vec->max)
        return BLOK_VECTOR_CAPACITY_FULL;

    return vec->head + 1;
}

void vector_free(struct vector *vec) {
    if (!vec)
        return;

    if (vec->dyn_array)
        free(vec->dyn_array);
}
