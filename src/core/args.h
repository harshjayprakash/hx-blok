/**
 * \file args.h
 * \date 18-08-2024
 * \brief 
 * 
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


int NeonGetBlockScale(void);

#endif