/**
 * @file macros.h
 * @version 1.0
 * @date 10-07-2023
 * 
 * @brief Global non-debugging macros.
 * 
 * This file contains macros used throughout the program that are not used for debugging.
 * These can include simplifying operations, represent values or error codes.
 */

#ifndef BLOK_MACROS_H
#define BLOK_MACROS_H

/**
 * @brief Specifies the maximum character length.
 */
#define BLOK_MAX_CHAR_LENGTH 260

/**
 * @brief Exits a void function based on the given condition.
 * 
 * @param CONDITION the condition for exit.
 */
#define BLOK_EXIT_IF(CONDITION) \
    if (CONDITION) return

/**
 * @brief Exits a non-void function based on the given condition, returns the value
 *        specified.
 * 
 * @param CONDITION the condition for exit.
 * @param RETURN_VALUE the value to be returned.
 * 
 * @note As this a macro returning the value, the return type is not checked.
 */
#define BLOK_NON_VOID_EXIT_IF(CONDITION, RETURN_VALUE) \
    if (CONDITION) return (RETURN_VALUE)

/**
 * @brief Frees the given object's memory using the function specified.
 * 
 * The object checked ensuring that it is not null before proceeding to use the function 
 * for deallocatioon.
 * 
 * @param OBJECT the object to be deallocated.
 * @param FUNC the function used for deallocation.
 */
#define BLOK_FREE_IF_NOT_NULL(OBJECT, FUNC) \
    if ((OBJECT) != NULL) FUNC(OBJECT)

/**
 * @brief Specifies a successful operation value.
 */
#define BLOK_SUCCESSFUL_OPERATION 0

/**
 * @brief Specifies the error that the object was null.
 */
#define BLOK_ERROR_NULL_POINTER (-1)

/**
 * @brief Specifies that an error occured during window creation.
 * 
 */
#define BLOK_ERROR_WINDOW_CREATION (-28)

/**
 * @brief Specifies that an error occured during window class registration.
 */
#define BLOK_ERROR_WINDOW_REGISTRATION 0

/**
 * @brief Specifies that the internel vector array was null.
 */
#define BLOK_ERROR_VECTOR_ARRAY_NULL (-210)

/**
 * @brief Specifies that the there is no index available in the vector.
 * 
 */
#define BLOK_ERROR_VECTOR_NO_INDEX_AVAILABLE (-324)

/**
 * @brief Specifies that the specified index was not found in the vector.
 * 
 */
#define BLOK_ERROR_VECTOR_INDEX_NOT_FOUND (-342)

/**
 * @brief Specifies that the specified index was out of bounds.
 */
#define BLOK_ERROR_VECTOR_OUT_OF_RANGE (-232)

/**
 * @brief Specifies that the vector is full.
 */
#define BLOK_VECTOR_FULL (-3204)

/**
 * @brief Specifies that the vector is not full.
 */
#define BLOK_VECTOR_NOT_FULL (-32432)

/**
 * @brief Specifies that the vector is empty.
 */
#define BLOK_VECTOR_EMPTY (-3242)

/**
 * @brief Specifies that the vector is not empty.
 */
#define BLOK_VECTOR_NOT_EMPTY (-324230)

#endif