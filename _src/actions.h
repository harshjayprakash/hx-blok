#ifndef ACTIONS_H
#define ACTIONS_H

#include <windows.h>
#include <tchar.h>

#include "globals.h"
#include "grid.h"

/**
 * Paints the marked blocks.
 * @param hDeviceContext: Handle to the device context for the client area 
 *      of the window.
*/
void Action_PaintMarkedBlocks(HDC hDeviceContext);

/**
 * Paints the main user movable block
 * @param hDeviceContext: Handle to the device context for the client area 
 *      of the window.
*/
void Action_PaintUserMovableBlock(HDC hDeviceContext);

/**
 * Paints the coordinates of the block, shown in the bottom left of the window.
 * @param hDeviceContext: Handle to the device context for the client area 
 *      of the window.
*/
void Action_PaintCoordinatesText(HDC hDeviceContext);

/**
 * Paints 'ON MARKED LOCATION' when the user movable block is over a marked
 * block on the grid.
 * @param hDeviceContext: Handle to the device context for the client area 
 *      of the window.
*/
void Action_PaintOnMarkedLocationText(HDC hDeviceContext);

/**
 * Sets the the maximum coordinates that the block can be moved to based on the
 * window size.
 * @param hWnd: Handle to the window.
*/
void Action_ResetBlockMovableLimits(HWND hWnd);

/**
 * Responds to the user's clicks, removing or adding a marked block.
 * @param hWnd: Handle to the window.
 * @param lParam: Message parameter (type long pointer), used to get mouse
 *      coordinates.
*/
void Action_AddRemoveMarkedBlocks(HWND hWnd, LPARAM lParam);

#endif // ACTIONS_H