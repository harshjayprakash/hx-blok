#ifndef WINDOW_EVENTS_H
#define WINDOW_EVENTS_H

#include <windows.h>
#include <tchar.h>

#include "globals.h"
#include "block.h"
#include "grid.h"
#include "actions.h"

/**
 * Runs after translating a message in the message loop.
 * @param hWnd: Handle to the window.
 * @param uMsg: The message identifier.
*/
int WindowEvent_OnRun(HWND hWnd, MSG uMsg);

/**
 * Window event to send the quit application message to message queue.
 * @param hWnd: Handle to the window.
 * @param wParam: Message parameter 1 - type unsigned int pointer.
 * @param lParam: Message parameter 2 - type long pointer.
*/
int WindowEvent_OnDestroy(HWND hWnd, WPARAM wParam, LPARAM lParam);

/**
 * Window event handler for pressing a key on the keyboard. The arrow keys have
 * been implementated to move the block.
 * @param hWnd: Handle to the window.
 * @param wParam: Message parameter 1 - type unsigned int pointer.
 * @param lParam: Message parameter 2 - type long pointer.
*/
int WindowEvent_OnKeyDown(HWND hWnd, WPARAM wParam, LPARAM lParam);

/**
 * Overriding window event handler for resizing the window to change the block
 * limits to prevent it from going out of view.
 * @param hWnd: Handle to the window.
 * @param wParam: Message parameter 1 - type unsigned int pointer.
 * @param lParam: Message parameter 2 - type long pointer.
*/
int WindowEvent_OnSize(HWND hWnd, WPARAM wParam, LPARAM lParam);

/**
 * 
*/
int WindowEvent_OnLeftMouseUp(HWND hWnd, WPARAM wParam, LPARAM lParam);



#endif // WINDOW_EVENTS_H