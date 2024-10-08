/**
 * \file args.h
 * \date 18-08-2024
 * \brief Function prototypes for processing arguments.
 *
 * This file contains function prototypes for argument processing and retrieving stored 
 * arguments.
 */

#ifndef NEON_ARGS_H
#define NEON_ARGS_H

#include "result.h"

/**
 * \brief Processes the arguments provided on execution.
 *
 * \return Result containing if the operation was successful.
 */
NeonResult NeonProcessArguments(void);

/**
 * \brief Gets the block scaling.
 *
 * \return The block size scale.
 */
int NeonGetBlockScale(void);

#endif