#ifndef BLOK_WINDOW_H
#define BLOK_WINDOW_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <windows.h>
#include <wingdi.h>

#include "../core/program.h"
#include "../service/store.h"
#include "../core/error.h"

#define CHAR_LENGTH_COUNT 260

/**
 * @brief Contains all the components for the creation of a window.
 */
struct window {
    /**
     * @brief Stores the handle to the window.
     */
    HWND window_handle;

    /**
     * @brief Stores the message or events that occur when the window is
     * running.
     */
    MSG window_message;

    /**
     * @brief Stores the native window class information.
     */
    WNDCLASSEXW window_class;

    /**
     * @brief Stores the name of the native window class.
     */
    wchar_t window_class_name[CHAR_LENGTH_COUNT];
};

/**
 * @brief Stores the potential instance of the window or null.
 */
union window_instance_handler {
    /**
     * @brief Stores the instance of the window.
     */
    struct window instance;
    /**
     * @brief Stores NULL.
     */
    void *potential_instance;
};

/**
 * @brief Provides a wrapper around the window structure with varies checks to
 * ensure that window creation was successful.
 */
struct window_wrapper {
    /**
     * @brief Stores whether window registration was successful.
     */
    bool registered;

    /**
     * @brief Stores whether the window has been created.
     */
    bool created;

    /**
     * @brief Stores whether the instance of the window is stored in this
     * wrapper.
     */
    bool present;

    /**
     * @brief Stores the potential instance of the window or null.
     */
    union window_instance_handler handle;
};

/**
 * @brief Creates a window.
 * @return A window wrapper to provide additional checks if creation was successful.
 */
struct window_wrapper window_new(void);

/**
 * @brief Frees any memory allocated to the window object.
 * @param wnd THe instance of the window.
 */
void window_free(struct window *wnd);

#endif
