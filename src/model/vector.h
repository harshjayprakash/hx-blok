/**
 * @file vector.h
 * @version 0.6.1
 * @date 19-07-2023
 * 
 * @brief A vector.
 * 
 * This header file contains a vector (dynamic list), used to store all the maks made by
 * the user in the window.
 */

#ifndef BLOK_VECTOR_H
#define BLOK_VECTOR_H

#include <stdlib.h>
#include <memory.h>

#include "mark.h"
#include "../core/macros.h"

/**
 * @brief Represents a vector. A wrapper for a dyanmically allocated list.
 */
struct Vector
{
    /**
     * @brief The internal dynamically allocated list that stored the marks.
     * 
     * @see struct Mark
     */
    struct Mark *arr;

    /**
     * @brief Stores the maxmium size that has been allocated to the dynamic list.
     */
    int max;

    /**
     * @brief The current largest index that has been occupied.
     */
    int head;
};

/**
 * @brief Constructs a new vector.
 * 
 * The newly constructed returned vector is stack allocated, but containing dynamic 
 * memory.
 * 
 * @details The size is stored as the maximum with the head initialised as -1. Then the
 *          internal array is allocated, based on the size provided.
 * 
 * @param _size the size of the vector.
 * @return A vector.
 * 
 * @note The blokVectorFree function must be used to free the memeory allocated.
 */
struct Vector blokVectorNew(int _size);

/**
 * @brief Generates a new size based on input.
 * 
 * @details The new size is always 1.5 larger than the input provided.
 * 
 * @param _size the current size.
 * @return The new recommended allocation size.
 */
int blokVectorGenerateNewSize(int _size);

/**
 * @brief Resizes the vector to the given size.
 * 
 * This allows more nodes to be stored within the vector.
 * 
 * @details This function performs checks, involving the instance of the internal dyanmic
 *          array and if the new size is larger than the current before proceeding to 
 *          reallocation, in which the new memory allocated is checked before assigning it
 *          to the vector as well as the size.
 * 
 * @param vector the instance of the vector.
 * @param _newSize the new size.
 * @return An integer dictating status, a macro.
 * 
 * @retval BLOK_ERROR_NULL_POINTER
 * @retval BLOK_ERROR_VECTOR_ARRAY_NULL
 * @retval BLOK_ERROR_MEMORY_REALLOCATION
 * @retval BLOK_SUCCESSFUL_OPERATION
 * 
 * @see macro.h
 */
int blokVectorResize(struct Vector *vector, int _newSize);

/**
 * @brief Checks if the vector is full.
 * 
 * @details This function checks the head index pointer against the maximum size of the
 *          internal array to determine whether the vector is full.
 * 
 * @param vector the instance of the vector.
 * @return An integer macro.
 * 
 * @retval BLOK_ERROR_NULL_POINTER
 * @retval BLOK_ERROR_VECTOR_ARRAY_NULL
 * @retval BLOK_VECTOR_FULL
 * @retval BLOK_VECTOR_NOT_FULL
 * 
 * @see macro.h
 */
int blokVectorFull(struct Vector *vector);

/**
 * @brief Checks if the vector is empty.
 * 
 * @details This function checks if the head index pointer is equal to -1, signifying that
 *          the internal array is empty.
 * 
 * @param vector the instance of the vector.
 * @return An integer macro.
 * 
 * @retval BLOK_ERROR_NULL_POINTER
 * @retval BLOK_ERROR_VECTOR_ARRAY_NULL
 * @retval BLOK_VECTOR_EMPTY
 * @retval BLOK_VECTOR_NOT_EMPTY
 * 
 * @see macro.h
 */
int blokVectorEmpty(struct Vector *vector);

/**
 * @brief Adds a node to the vector.
 * 
 * @details This function checks if there is space available for node before adding to the
 *          vector. If this is not the case, the vector is resized before performing the
 *          operation.
 * 
 * @param vector the instance of the vector.
 * @param _node the node to be added.
 * @return An integer macro.
 * 
 * @retval BLOK_ERROR_NULL_POINTER
 * @retval BLOK_ERROR_VECTOR_ARRAY_NULL
 * @retval BLOK_SUCCESSFUL
 * 
 * @see macro.h
 */
int blokVectorPush(struct Vector *vector, struct Mark _node);

/**
 * @brief Gets a reference to a node at an index.
 * 
 * @param vector the instance of the vector.
 * @param _index the index of the node to be retrieved.
 * @return a reference to the node or null if the operation fails.
 * 
 * @note The caller should not deallocate this memory directly as it provides access to
 *       the object at the index given.
 */
struct Mark *blokVectorPointerGet(struct Vector *vector, int _index);

/**
 * @brief Gets the node at an index.
 * 
 * @details This function calls the blokVectorPointerGet function to perform the checks
 *          and then this function checks if the returned value is null, signifying a
 *          failure, in which
 *          (struct Mark){ -1, -1 }
 *          is returned.
 * 
 *          Or returned node will be dereferenced providing a stack allocated copy of the
 *          the node.
 * 
 * @param vector the instance of the vector.
 * @param _index the index of the node to be retrieved.
 * @return the node or if the operation fails a mark with coordinates of -1.
 */
struct Mark blokVectorGet(struct Vector *vector, int _index);

/**
 * @brief Removes the last pushed item from the vector.
 * 
 * @param vector the instance of the vector.
 * @return the node that has been removed.
 * 
 * @todo This function has not been implementated and will return
 *       (struct Mark){ -1, -1 }
 */
struct Mark blokVectorPop(struct Vector *vector);

/**
 * @brief Gets the last pushed item from the vector.
 * 
 * @details This function calls the blokVectorGet function retrieving the index of the 
 *          head.
 * 
 * @param vector the instance of the vector.
 * @return A node or if the operation fails a mark with coordinates of -1.
 */
struct Mark blokVectorPeak(struct Vector *vector);

/**
 * @brief Removes the node based on index.
 * 
 * @details This function sets the index node to the coordinate of (-1, -1) as this is not 
 *          rendered in the window.
 * 
 * @param vector the instance of the vector.
 * @param _index the index to be removed.
 * @return A integer macro denoting whether the operation was sucessful.
 * 
 * @retval BLOK_ERROR_NULL_POINTER
 * @retval BLOK_ERROR_VECTOR_ARRAY_NULL
 * @retval BLOK_ERROR_VECTOR_OUT_OF_RANGE
 * @retval BLOK_SUCCESSFUL_OPERATION
 * 
 * @see macro.h
 */
int blokVectorRemoveIndex(struct Vector *vector, int _index);

/**
 * @brief Removes the node given.
 * 
 * @details This function finds the index of the given node, and calls the 
 *          blokVectorRemoveIndex to remove the node.
 * 
 * @param vector the instance of the vector.
 * @param _node the node to be removed.
 * @return A integer macro denoting whether the operation was successeful.
 * 
 * @retval BLOK_ERROR_NULL_POINTER
 * @retval BLOK_ERROR_VECTOR_ARRAY_NULL
 * @retval BLOK_ERROR_VECTOR_OUT_OF_RANGE
 * @retval BLOK_SUCCESSFUL_OPERATION
 * 
 * @see macro.h
 */
int blokVectorRemoveObject(struct Vector *vector, struct Mark _node);

/**
 * @brief Finds the given node in the vector.
 * 
 * @details This function loops through all nodes up to the head index returning the index
 *          of the node. If this fails the integer will be negative.
 * 
 * @param vector the instance of the vector.
 * @param _node the node to be found.
 * @return A integer index of the node or a macro denoting whether the operation failed.
 * 
 * @retval Index of the node.
 * @retval BLOK_ERROR_NULL_POINTER
 * @retval BLOK_ERROR_VECTOR_ARRAY_NULL
 * @retval BLOK_ERROR_VECTOR_INDEX_NOT_FOUND
 * 
 * @see macro.h
 */
int blokVectorFind(struct Vector *vector, struct Mark _node);

/**
 * @brief Finds the next available index in the vector.
 * 
 * @details This function loops through the whole vector array to see if there is an empty
 *          position denoted by the mark position (-1, -1).
 * 
 * @param vector the instance of the vector.
 * @return A integer of the empty index or a negative integer macro for an error.
 * 
 * @retval Available index
 * @retval BLOK_ERROR_NULL_POINTER
 * @retval BLOK_ERROR_VECTOR_ARRAY_NULL
 * @retval BLOK_ERROR_VECTOR_NO_INDEX_AVAILABLE
 * 
 * @see macro.h
 */
int blokVectorNextAvailableIndex(struct Vector *vector);

/**
 * @brief Frees the memory allocated to the vector.
 * 
 * @details This function checks for an instance before freeing the memory allocated.
 * 
 * @param vector the instance of the vector.
 */
void blokVectorFree(struct Vector *vector);

#endif
