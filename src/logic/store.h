/**
 * @file store.h
 * @version 0.7.1
 * @date 14-09-2023
 * 
 * @brief A global store instance management.
 * 
 * The file contains the functions to retrieve the global store instance, to allow global
 * access to value throughout the program.
 */

#ifndef BLOK_STORE_H
#define BLOK_STORE_H

#include "../model/square.h"
#include "../model/vector.h"

/**
 * @brief Models what data to be stored in the global store.
 */
struct Store
{
    /**
     * @brief Stores the user movable square rendered within the window.
     * 
     * @see struct Square.
     */
    struct Square movableSquare;

    /**
     * @brief Stores a projected version of the square that determines if a collusion 
     *        occurs with a marked area.
     * 
     * @see struct Square.
     */
    struct Square projectedSquare;

    /**
     * @brief Stores vector (dynamic list) of the marked regions.
     * 
     * @see struct Vector.
     */
    struct Vector markedRegions;
};

/**
 * @brief Initialises the store.
 * 
 * This is to ensure that any memory allocation required has taken place.
 * 
 * @details The Square and the Vector is initialised, whith the vector's default mark
 *          default mark values of coordinate (-1, -1).
 */
void blokStoreInitialise(void);

/**
 * @brief Retrieves the store instance.
 * 
 * The store instance is a static struct, initialised by the blokStoreInitialise() 
 * function.
 * 
 * @return A pointer to the store instance.
 * 
 * @note The ownership of the memory is not transferred to the caller. The returned
 *       pointer provides access to the store instance. This memory should not be
 *       deallocated.
 * 
 * @see struct Store.
 */
struct Store *blokStoreInstanceGet(void);

/**
 * @brief Deallocates the store instance.
 * 
 * Responsible for freeing memory allocated by the static struct initialised.
 */
void blokStoreFree(void);

#endif
