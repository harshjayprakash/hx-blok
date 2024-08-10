/**
 * @file program.h
 * @date 2024-08-09
 * @brief
 */

#ifndef NEON_PROGRAM_H
#define NEON_PROGRAM_H

#define STRICT 1
#include <Windows.h>
#include "result.h"

/**
 * @brief Initialise program.
 * 
 * @param instanceHandle Handle to the instance of the program.
 * @param showFlags How the program will be displayed.
 * @return NeonResult - If operation succeeded.
 */
NeonResult NeonInit(HINSTANCE instanceHandle, int showFlags);

/**
 * @brief Processes arguments given to the program via cli.
 * 
 * @return NeonResult - If operation was successful.
 */
NeonResult NeonProcessArguments(void);

/**
 * @brief An entrypoint for starting the program operations.
 */
NeonResult NeonStart(void);

/**
 * @brief Gets the program's instance handle.
 * 
 * @return HINSTANCE The program's instance handle.
 */
HINSTANCE NeonGetHandle(void);

/**
 * @brief Gets the program show flag.
 * 
 * @return int The program show flag.
 */
int NeonGetShowFlag(void);

/**
 * @brief Frees any resources used by the program module.
 * 
 * @return NeonResult - If operation succeeded.
 */
NeonResult NeonFree(void);


#endif