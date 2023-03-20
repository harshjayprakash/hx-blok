#ifndef WINDOW_H
#define WINDOW_H

#include <windows.h>
#include <tchar.h>
#include <wingdi.h>

#include "app.h"
#include "window_events.h"

/**
 * A structure that contains the Window information.
*/
typedef struct Window
{
    Application* xApp;
    HWND hWnd;
    TCHAR clsName[260];
    WNDCLASSEX wcex;
    int isRegistered;
    int isCreated;
    int isVisible;
} Window;

/**
 * Constructor for the Window structure.
 * @param app: A reference to the Application structure.
 * @returns 0 for 'success', 1 for 'self does not contain an instance of the
 *      window structure', 2 for 'app does not contain an instance of the
 *      application structure', 3 for 'failed to register window', 4 for 'failed
 *      to create window'.
*/
int Window_Init(Window* self, Application* app);

/**
 * Destructor for the Window structure. Frees up any memory allocated within
 * the Window structure.
 * @returns 0 for 'success', 1 for 'self does not contain an instance of the
 *      window structure.
*/
int Window_Del(Window* self);

/**
 * Initialises and registers the extended version of the window class.
 * @returns Result of the RegisterClassEx Macro method. OR -1 for 'window class
 *      has already been registered'.
*/
int Window_Register(Window* self);

/**
 * Creates the window assigning it the HWND, the handle to the window.
 * @returns 0 for 'success', 1 for 'failed to create window', -1 for 'the window
 *      has already been registered', -2 for 'the window class has not been
 *      registered'.
*/
int Window_Create(Window* self);

/**
 * Shows the window created.
 * @returns 0 for 'success', -1 for 'the window has not been created', -2 for 
 *      'the window class has not been registered', -3 for 'the window is
 *      already visible'.
*/
int Window_Show(Window* self);

/**
 * Updates the window.
 * @returns 0 for 'success', -1 for 'the window has not been created', -2 for 
 *      'the window class has not been registered'.
*/
int Window_Update(Window* self);

/**
 * Runs the message loop, a while loop that translates and dispatches window
 * messages including creating any controls.
 * @returns 0 for 'success', -1 for 'the window has not been created', -2 for 
 *      'the window class has not been registered'.
*/
int Window_MessageLoop(Window* self);

/**
 * The window callback procedure that handles all window messages (actions).
 * This is not called directly; it is linked to the window class.
 * @param hWnd: Handle to the window.
 * @param uMsg: The message identifier.
 * @param wParam: Message parameter 1 - type unsigned int pointer.
 * @param lParam: Message parameter 2 - type long pointer.
*/
LONG_PTR __stdcall Window_Callback(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

#endif // WINDOW_H