/**
 * @file log.h
 * @date 2024-08-09
 * @brief
 */

#ifndef NEON_LOG_H
#define NEON_LOG_H

#include "result.h"

/**
 * @brief A type to describe the crticality of log event.
 */
typedef enum __NeonLogLevel
{
    /**
     * @brief Information log level.
     */
    NeonInformation = 0x0000001,
    /**
     * @brief Warning log level.
     */
    NeonWarning     = 0x0000002,
    /**
     * @brief Error log level.
     */
    NeonError       = 0x0000003,
    /**
     * @brief Unkown log level.
     */
    NeonUnknown     = 0x0000000,
} NeonLogLevel;

/**
 * @brief A type to describe how logging will take place.
 */
typedef enum __NeonLogTechnique
{
    /**
     * @brief Logs to a file.
     */
    NeonFile        = 0x0000001,
    /**
     * @brief Logs to the console.
     */
    NeonConsole     = 0x0000010,
} NeonLogTechnique;

/**
 * @brief Initialises the logger module.
 * 
 * @param technique How log messages will be shown.
 */
void NeonInitLogger(const NeonLogTechnique technique);

/**
 * @brief Outputs a log event to the initialised method.
 * 
 * @param level The log level.
 * @param information The message to be logged.
 */
void NeonLog(const NeonLogLevel level, const NeonResult information);

/**
 * @brief Outputs a log event to the initialised method and returns the result.
 * 
 * @param level The log level.
 * @param information The message to be logged.
 * @return NeonResult Returns the logged message.
 */
NeonResult NeonLogAndReturn(const NeonLogLevel level, const NeonResult information);

/**
 * @brief Cleans up any resources used by the logger module.
 */
void NeonFreeLogger(void);

#endif