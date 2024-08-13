/**
 * \file log.h
 * \date 13-08-2024
 * \brief Function definitions and types for logging.
 *
 * This file contains the functions and types for logging functionality.
 */

#ifndef NEON_LOG_H
#define NEON_LOG_H

#include "result.h"

/**
 * \brief Enumeration to indicate a log level.
 */
typedef enum __NeonLogLevel
{
    NeonInformation = 0x0000001, ///< Informative Log Level
    NeonWarning = 0x0000002,     ///< Warning Log Level
    NeonError = 0x0000003,       ///< Error Log Level
    NeonUnknown = 0x0000000,     ///< Unknown Log Level
} NeonLogLevel;

/**
 * \brief Enumeration of the method of logging.
 */
typedef enum __NeonLogTechnique
{
    NeonFile = 0x0000001,    ///< Logging to a file
    NeonConsole = 0x0000010, ///< Logging to the console
} NeonLogTechnique;

/**
 * \brief Initialises the logger.
 *
 * \param technique The method of logging.
 */
void NeonInitLogger(const NeonLogTechnique technique);

/**
 * \brief Log a message.
 *
 * \param level The log level.
 * \param information The result containing the message.
 */
void NeonLog(const NeonLogLevel level, const NeonResult information);

/**
 * \brief Log a message then return the result.
 *
 * \param level The log level.
 * \param information The result containing the message.
 * \return The result containing the message.
 */
NeonResult NeonLogAndReturn(const NeonLogLevel level, const NeonResult information);

/**
 * \brief Cleans up resources used by the logger.
 */
void NeonFreeLogger(void);

#endif