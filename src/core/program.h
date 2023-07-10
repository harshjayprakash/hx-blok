/**
 * @file program.h
 * @version 1.0
 * @date 10-07-2023
 * 
 * @brief Program handles and instance management.
 * 
 * This header file is for storing the arguments passed through WinMain, allowing global
 * access throughout the program.
 */

#ifndef BLOK_PROGRAM_H
#define BLOK_PROGRAM_H

#include <Windows.h>

#include "macros.h"
#include "../logic/theme.h"

/**
 * @struct Program
 * @brief Stores the program entrypoint arguments.
 * 
 * These the same arguments specified by WinMain, allowing access to other parts of the
 * program.
 */
struct Program
{
    /**
     * @brief Stores the handle to the current instance of the program.
     * 
     * This is required throughout the program as the graphical user interface is tied
     * to this instance and used to find the executable in memory.
     */
    HINSTANCE instanceHandle;

    /**
     * @brief Store the previous version of the instance handle.
     * 
     * This is not used within the program, therefore it will always be null as this
     * program is not 16-bit.
     */
    HINSTANCE previousInstanceHandle;

    /**
     * @brief Stores the command line for the program.
     * 
     * This is not currently used in the program.
     */
    LPSTR commandLineArguments;

    /**
     * @brief Stores how the window is to be shown.
     * 
     * This is required when showing a window after creation, as this could specify the
     * program to start minimised or maximumised.
     */
    int showFlag;
};

/**
 * @brief Internally stores the arguments provided.
 * 
 * This to ensure that the values are available throughout the rest of the program, out
 * of scope from WinMain.
 * 
 * @param _instanceHandle The handle to the current instance of the program.
 * @param _previousInstanceHandle Always NULL in the program.
 * @param _commandLineArguments A pointer to a null terminated string that specifies the 
 *                              command line for the program.
 * @param _showFlag Controls how the window is to be shown.
 * 
 * @details Before initialisation, check is made to prevent this function from being
 *          called more than once. Then the values are copied to the module's local
 *          storage, if this is the first call.
 * 
 * @note This function must called within WinMain to retrieve these values to allow global 
 *       access. It can only be called once.
 */
void blokProgramInitialise(
    HINSTANCE _instanceHandle, HINSTANCE _previousInstanceHandle,
    LPSTR _commandLineArguments, int _showFlag);

/**
 * @brief Retrieves the program instance.
 * 
 * The program instance is a static struct, initialised by the blokProgramInitialise()
 * function.
 * 
 * @return A pointer to the program instance.
 * 
 * @note The ownership of the memory is not transferred to the caller. The returned 
 *       pointer provides access to the program instance, but the caller should not 
 *       deallocate or modify the memory directly.
 * 
 * @see struct Program
 */
struct Program *blokProgramInstanceGet(void);

/**
 * @brief Deallocates the program instance.
 *  
 * Responsible for freeing memory allocated by the static struct initialised.
 */
void blokProgramFree(void);

#endif
