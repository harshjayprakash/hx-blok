/**
 * @file result.h
 * @date 2024-08-09
 * @brief
 */

#ifndef NEON_RESULT_H
#define NEON_RESULT_H

#include <wchar.h>

/**
 * @brief A type to provide context on messages from an integer.
 */
typedef enum __NeonResultCode 
{
    /**
     * @brief Operation was successful.
     */
    NeonSuccess         = 0x000000,
    /**
     * @brief Operation failed.
     */
    NeonFail            = 0x000001,
    /**
     * @brief Cannot re-initalise.
     */
    NeonCannotReInit    = 0x000010,
    /**
     * @brief Not initialised
     */
    NeonNotInit         = 0x000011,
    /**
     * @brief Not Implementated
     */
    NeonNotImpl         = 0x000100,
    /**
     * @brief No error to report.
     */
    NeonNone            = 0x000200
} NeonResultCode;

/**
 * @brief A type to provide information about failures.
 */
typedef struct __NeonResult 
{
    /**
     * @brief A reference to the code error.
     */
    NeonResultCode        code;
    /**
     * @brief A specific message given by the program.
     */
    wchar_t               message[260];
} NeonResult;

/**
 * @brief Creates a new result object.
 * 
 * @param code The reference code.
 * @param pMessage The message.
 * @return NeonResult The result object.
 */
NeonResult NeonCreateResult(NeonResultCode code, wchar_t *pMessage);

#endif