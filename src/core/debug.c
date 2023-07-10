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
 * @brief Input stream for the console.
 */
static FILE *consoleIn;

/**
 * @brief Output stream for the console.
 */
static FILE *consoleOut;

/**
 * @brief Error stream for the console.
 */
static FILE *consoleErr;

void blokDebugConsoleOpen()
{
    consoleIn = stdin;
    consoleOut = stdout;
    consoleErr = stderr;
    AllocConsole();
    AttachConsole(GetCurrentProcessId());
    freopen_s(&consoleIn, "CONIN$", "r", stdin);
    freopen_s(&consoleOut, "CONOUT$", "w", stdout);
    freopen_s(&consoleErr, "CONOUT$", "w", stderr);
    SetConsoleTitleW(L"The Blok Experiment Console");
    printf("======= THE BLOCK EXPERIMENT DEBUGGING MECHANISM =======\n");
}

void blokDebugConsoleClose()
{
    fclose(consoleIn);
    fclose(consoleOut);
    fclose(consoleErr);
    FreeConsole();
}

void blokDebugConsoleLog(const char *message)
{
    printf("%s\n", message);
}
