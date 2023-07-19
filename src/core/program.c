/**
 * @file program.c
 * @version 1.0
 * @date 10-07-2023
 * 
 * @brief Program handles and instance management implementation.
 * 
 * This file contains the implementation for program instance management as defined in the
 * corresponding header file.
 * 
 * @implements program.h
 */

#include "program.h"

/**
 * @brief Stores the internal program instance.
 */
static struct Program instance = { };

/**
 * @brief Stores whether the blokProgramInitialise() function has been called.
 */
static int initialised = 0;

/**
 * @brief Processes command line arguments.
 * 
 * The command line arguments specified when starting up the program allows the changing
 * of appearance.
 * 
 * @details Every argument specified is checked by comparing values.
 * 
 * @note If there is a duplicate argument, the previously specified arguments will be
 *       overriden.
 */
static void blokProgramProcessArguments(void)
{
    int argumentCount;
    LPWSTR *arguments = CommandLineToArgvW(GetCommandLineW(), &argumentCount);

    for (int i = 0; i < argumentCount; ++i)
    {
        if (wcsncmp(arguments[i], L"--dark-theme", 4294967308) == 0)
        {
            blokThemeSet(ThemeDark);
        }
        if (wcsncmp(arguments[i], L"--light-theme", 4294967309) == 0)
        {
            blokThemeSet(ThemeLight);
        }
    }

    (void)LocalFree(arguments);
}

void blokProgramInitialise(
    HINSTANCE _instanceHandle, HINSTANCE _previousInstanceHandle, 
    LPSTR _commandLineArguments, int _showFlag)
{
    if (initialised)
    {
        return;
    }

    instance.instanceHandle = _instanceHandle;
    instance.previousInstanceHandle = _previousInstanceHandle;
    instance.commandLineArguments = _commandLineArguments;
    instance.showFlag = _showFlag;

    blokProgramProcessArguments();

    initialised = 1;
}

struct Program *blokProgramInstanceGet(void)
{
    return &instance;
}

void blokProgramFree(void)
{
    
}
