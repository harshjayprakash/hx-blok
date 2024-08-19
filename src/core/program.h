/**
 * \file program.h
 * \date 13-08-2024
 * \brief Function definitions of the program singleton module.
 *
 * This file contains function definitions for the program module for global use.
 */

#ifndef NEON_PROGRAM_H
#define NEON_PROGRAM_H

#define STRICT 1
#include "result.h"
#include <Windows.h>

/**
 * \brief Initialises the program.
 *
 * \param instanceHandle The program's instance handle.
 * \param showFlags How the program will be displayed.
 * \return Result containing if the operation was successful.
 */
NeonResult NeonInit(HINSTANCE instanceHandle, int showFlags);

/**
 * \brief Checks if the program has been initialised.
 *
 * @return If the program has been initialised.
 */
int NeonIsInit(void);

/**
 * \brief Start method for the program.
 *
 * \return Result containing if the operation was successful.
 */
NeonResult NeonStart(void);

/**
 * \brief Retrieves the program's instance handle.
 *
 * \return HINSTANCE The instance handle.
 */
HINSTANCE NeonGetHandle(void);

/**
 * \brief Retrieves the show flag.
 *
 * \return The show flag.
 */
int NeonGetShowFlag(void);

/**
 * \brief Cleans up resources used by the program module.
 *
 * \return Result containing if the operation was successful.
 */
NeonResult NeonFree(void);

#endif