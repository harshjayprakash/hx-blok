#ifndef BLOK_VECTOR_H
#define BLOK_VECTOR_H

#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

#include "../core/error.h"
#include "mark.h"

/**
 * @brief Represents a dynamically allocated and resizable linked list.
 */
struct vector
{
    /**
     * @brief Stores the memory address of the start of the array.
     */
    struct mark *dyn_array;

    /**
     * @brief Stores the maximum size of the array.
     */
    int max;

    /**
     * @brief Stores the current size of the of the array or last known item's
     * index.
     */
    int head;
};

/**
 * @brief Creates an new vector.
 * @param _size The size of the vector.
 * @return A stack allocated instance of the vector.
 */
struct vector vector_new(int _size);

/**
 * @brief Resizes the vector to the given size.
 * @param vec The instance of the vector.
 * @param _new_size The new size of the vector.
 * @return 0 for success, anything else for an error. Refer to 'error.h'.
 */
int vector_resize(struct vector *vec, int _new_size);

/**
 * @brief Addes a node to the vector.
 * @param vec The instance of the vector.
 * @param _node The node to be inserted.
 * @return 0 for success, anything else for an error. Refer to 'error.h'.
 */
int vector_push(struct vector *vec, struct mark _node);

/**
 * @brief Gets the node (mark) at the given index.
 * @param vec The instance of the vector.
 * @param _index The index of the node to be retrieved.
 * @return A copy of the node at the index given.
 */
struct mark vector_get(const struct vector *vec, int _index);

/**
 * @brief Gets the pointer tp node (mark) at the index given.
 * @param vec The instance of the vector.
 * @param _index The index of the node to be retrieved.
 * @return A pointer to the node at the index given.
 */
struct mark *vector_get_ptr(const struct vector *vec, int _index);

/**
 * @brief Gets the next available index.
 * @param vec The instance of the vector.
 * @return The integer index or a negative number for an error. Refer to
 * 'error.h'.
 */
int vector_next_available_index(const struct vector *vec);

/**
 * @brief Removes the last element.
 * @param vec The instance of the vector.
 * @return A stack allocated of the node at the last index that has been removed.
 */
struct mark vector_pop(struct vector *vec);

/**
 * @brief Gets the last element.
 * @param vec The instance of the vector.
 * @return A stack allocated of the node at the last index. 
 */
struct mark vector_peak(const struct vector *vec);

/**
 * @brief Frees any memory allocated to the vector object.
 * @param vec The instance of the vector.
 */
void vector_free(struct vector *vec);

#endif
