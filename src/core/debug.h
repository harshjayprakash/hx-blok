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
 * This allows to any terminal output while the program is running.
 * 
 * @details Opening the debugging console consists of:
 *          1. Assigning the files to the main streams (stdin, stdout, stderr).
 *          2. Allocating a console.
 *          3. Attaching the console to the current procees id occupied by the program.
 *          4. Opening the file streams.
 *          
 *          In addition to this, the console's title is set, as well as printing a title
 *          in the console.
 * 
 * @note This function should not be called directly. Please use the macro versions only.
 */
void blokDebugConsoleOpen();

/**
 * @brief Closes the debugging console.
 * 
 * This cleans up allocated console memory.
 * 
 * @details Closing the debugging console consists of:
 *          1. Closing all the file streams, opened.
 *          2. Freeing the console.
 * 
 *          This function assumes that the console has been opened before calling the
 *          corresponding close function.
 * 
 * @note This function should not be called directly. Please use the macro versions only.
 */
void blokDebugConsoleClose();

/**
 * @brief Outputs to the debugging console.
 * 
 * Prints the given message to the standard output.
 * 
 * @details Prints the message with the addition of a newline character using 
 *          prinf(const char* const, ...).
 * 
 * @param message The message to be printed.
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