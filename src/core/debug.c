/**
 * @file debug.c
 * @version 1.0
 * @date 10-07-2023
 * 
 * @brief Debugging console implementation
 * 
 * This file implements the functionality for managing the debugging the console as
 * defined in the corresponding header file.
 * 
 * @implements debug.h
 */

#include "debug.h"

/**
 * @brief Output stream for the console.
 */
static FILE *consoleOut;

void blokDebugConsoleOpen()
{
    consoleOut = stdout;
    (void)AllocConsole();
    (void)AttachConsole(GetCurrentProcessId());
    (void)freopen_s(&consoleOut, "CONOUT$", "w", stdout);
    (void)SetConsoleTitleW(L"The Blok Experiment Console");
    (void)printf("======= THE BLOCK EXPERIMENT DEBUGGING MECHANISM =======\n");
}

void blokDebugConsoleClose()
{
    (void)fclose(consoleOut);
    (void)FreeConsole();
}

void blokDebugConsoleLog(const char *message)
{
    printf("%s\n", message);
}
