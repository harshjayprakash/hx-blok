/**
 * @file debug.h
 * @version 1.0
 * @date 10-07-2023
 * 
 * @brief Debugging console.
 * 
 * This file contains the functions and macros for managing the debugging.
 */

#ifndef BLOK_DEBUG_H
#define BLOK_DEBUG_H

#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>

/**
 * @brief Specifies if debugging mechanisms are enabled.
 * 
 * If this value is zero, debugging will be disabled globally.
 */
#define BLOK_DEBUG_MECHANISMS_ENABLED 1

/**
 * @brief Opens the debugging console.
 *
 * This function opens the debugging console, allowing the application to output debug 
 * messages and interact with the debugger.
 * 
 * @details The standard streams are redirected to the new console that has been allocated
 *          and attached to the current process id. In addition, the console's title has
 *          been set.
 *
 * @note This function should be called before using any other debug console functions.
 */
void blokDebugConsoleOpen();

/**
 * @brief Closes the debugging console.
 *
 * This function closes the debugging console and restores the standard input, output,
 * and error streams.
 * 
 * @details The standard streams are closed and the allocated console is freed.
 *
 * @note This function should be called when debugging is no longer required or at the
 *       end of the application.
 */
void blokDebugConsoleClose();


/**
 * @brief Logs a message to the debugging console.
 *
 * This function prints the specified message to the debugging console.
 *
 * @param message The message to be logged.
 *
 * @details The message passed to the printf function.
 * 
 * @note The message will be printed followed by a newline character.
 */
void blokDebugConsoleLog(const char *message);

#if BLOK_DEBUG_MECHANISMS_ENABLED

/**
 * @brief [Enabled] Opens the debugging console.
 * 
 * This macro opens the debugging console, allowing the program to output debug messages.
 * 
 * @see blokDebugConsoleOpen()
 */
#define BLOK_DEBUG_CONSOLE_OPEN() blokDebugConsoleOpen()

/**
 * @brief [Enabled] Closes the debugging console.
 * 
 * This macro closes the debugging console, which was previously opened by the 
 * BLOK_DEBUG_CONSOLE_OPEN macro.
 * 
 * @see blokDebugConsoleClose()
 */
#define BLOK_DEBUG_CONSOLE_CLOSE() blokDebugConsoleClose()

/**
 * @brief [Enabled] Logs a message to the debugging console.
 * 
 * This macro logs the specified message to the debugging console.
 * 
 * @param MESSAGE The message to be logged.
 * @see blokDebugConsoleLog()
 */
#define BLOK_LOG(MESSAGE) blokDebugConsoleLog(MESSAGE)

#else

/**
 * @brief [Disabled] Empty macro for opening the debugging console.
 * 
 * Since debugging mechanisms are disabled, this macro does nothing.
 */
#define BLOK_DEBUG_CONSOLE_OPEN() 

/**
 * @brief [Disabled] Empty macro for closing the debugging console.
 * 
 * Since debugging mechanisms are disabled, this macro does nothing.
 */
#define BLOK_DEBUG_CONSOLE_CLOSE() 

/**
 * @brief [Disabled] Empty macro for logging messages.
 * 
 * Since debugging mechanisms are disabled, this macro does nothing.
 */
#define BLOK_LOG(MESSAGE)

#endif

#endif