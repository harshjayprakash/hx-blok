/**
 * @file debug.c
 * @version 0.7.1
 * @date 14-09-2023
 * 
 * @brief Debugging console implementation
 * 
 * This file implements the functionality for managing the debugging console as defined in 
 * the corresponding header file.
 * 
 * @implements debug.h
 */

#include "debug.h"

/**
 * @brief Output stream for the console.
 * 
 * This allows the output to be redirected to the console allocated.
 */
static FILE *consoleOut;

void blokDebugConsoleOpen()
{
    consoleOut = stdout;
    (void)AllocConsole();
    (void)AttachConsole(GetCurrentProcessId());
    (void)freopen_s(&consoleOut, "CONOUT$", "w", stdout);
    (void)SetConsoleTitleW(L"The Experimental Block Console");
    (void)printf("======= THE BLOCK EXPERIMENT DEBUGGING MECHANISM =======\n");
}

void blokDebugConsoleClose()
{
    (void)fclose(consoleOut);
    (void)FreeConsole();
}

void blokDebugConsoleLog(const char *message)
{
    (void)printf("%s\n", message);
}
