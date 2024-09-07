/**
 * \file result.h
 * \date 13-08-2024
 * \brief Function definitions, enumerations and structures for the result module.
 *
 * This file contains an enumeration of the result codes, a result structure that can be
 * used as return value and logging. This also include the function definition of creating
 * a result.
 */

#ifndef NEON_RESULT_H
#define NEON_RESULT_H

#include <wchar.h>

/**
 * \brief Result codes to dictate specific successes and failures.
 */
typedef enum __NeonResultCode
{
    NeonSuccess = 0x000000,      ///< Operation was successful
    NeonNone = 0x000001,         ///< Operation does not require a result
    NeonFail = 0x000001,         ///< Operation failed
    NeonCannotReInit = 0x000010, ///< Cannot Re-Initialise Error
    NeonNotInit = 0x000011,      ///< Not Initialised Error
    NeonNullPtr = 0x000012,      ///< Null Pointer Error
    NeonNotImpl = 0x000100,      ///< Not Implementated Error
    NeonOutOfRange = 0x000400,   ///< Out of Range Error
} NeonResultCode;

/**
 * \brief Represents a result or exception with a message.
 */
typedef struct __NeonResult
{
    NeonResultCode code;  ///< Result Code
    wchar_t message[260]; ///< Additional Result Message
} NeonResult;

/**
 * \brief Creates a result
 *
 * \param code The result code.
 * \param pMessage The additional message.
 * \return A new stack allocated result.
 */
NeonResult NeonCreateResult(NeonResultCode code, wchar_t *pMessage);

#endif