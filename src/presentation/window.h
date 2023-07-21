/**
 * @file window.h
 * @version 0.6.1
 * @date 20-07-2023
 * 
 * @brief Graphical window instance management.
 * 
 * This header file contains the window creation and destruction methods, providing an
 * abstraction to the Windows API.
 */

#ifndef BLOK_WINDOW_H
#define BLOK_WINDOW_H

#include <Windows.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <wchar.h>

#include "../core/macros.h"
#include "../core/program.h"
#include "../core/debug.h"
#include "../logic/theme.h"
#include "../logic/store.h"
#include "../logic/casts.h"

/**
 * @brief Stores the window's handles and components.
 */
struct Window
{
    /**
     * @brief Stores the window handle.
     * 
     * This is used to refer to the window in events.
     */
    HWND windowHandle;

    /**
     * @brief Stores the window event messages.
     * 
     * This is used by the callback loop to process the messages.
     */
    MSG windowMessage;

    /**
     * @brief Stores the native window class information.
     * 
     * This is a local window class to allow styling and binding of the callback loop.
     */
    WNDCLASSEXW nativeWindowClass;

    /**
     * @brief Stores the window class name.
     * 
     * This is used to refer to the native window class.
     */
    wchar_t windowClassName[BLOK_MAX_CHAR_LENGTH];
};

/**
 * @brief Wraps the window structure, providing a method of checks to ensure the instance
 *        is available and successfully created.
 */
struct WindowWrapper
{
    /**
     * @brief Stores whether the windows class has been registered.
     */
    int registered;

    /**
     * @brief Stores whether the window has been created successfully.
     */
    int created;

    /**
     * @brief Stores whether the window instance is available.
     */
    int present;

    /**
     * @brief Stores the potential window structure instance.
     */
    struct Window instance;
};

/**
 * @brief Creates a new window
 * 
 * @details This function registers a window class, creates the window assigning it to the
 *          window handle. If these steps fail the returned wrapper does not contain an
 *          instance of the window, cleaning up the resources. If these succeeded, the
 *          window is shown and the message loop is started, then assigning the instance
 *          into the structure, before returning the wrapper.
 * 
 * @return A wrapper of the window structure, containing a potential window instance.
 * 
 * @note This function can only be called once due to the fact that it registers the 
 *       window class, which should not have duplicates.
 */
struct WindowWrapper blokWindowNew(void);

/**
 * @brief Frees the memory allocated by the window, cleaning up the resources used.
 * 
 * @details This function checks all window instance, unregistering the window class and 
 *          freeing all the resource, each being checked beforehand.
 * 
 * @param window the instance of the window.
 */
void blokWindowFree(struct Window *window);
  
#endif
