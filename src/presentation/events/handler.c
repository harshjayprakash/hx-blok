/**
 * \file handler.c
 * \date 13-08-2024
 * \brief Implementation of the window handle events.
 *
 * This file contains the implementation of handling window events.
 */

#include "handler.h"
#include "../../core/log.h"
#include "../components/canvas.h"
#include "../components/panel.h"
#include "../objects/block.h"
#include "../objects/obstructables.h"
#include "../window.h"
#include <Windows.h>
#include <time.h>

void NeonHandleWindowPaintEvent(HDC displayContext)
{
    NeonRenderCanvasComponent(displayContext);
    NeonRenderPanelComponent(displayContext);
}

void NeonHandleWindowKeyDownEvent(WPARAM wordParam)
{
    NeonDirection direction;

    switch ((int)wordParam)
    {
    case VK_UP:
        NeonLog(NeonInformation,
                NeonCreateResult(NeonNone, L"Key Event Detected: Up Arrow"));
        direction = NeonNorth;
        break;
    case VK_RIGHT:
        NeonLog(NeonInformation,
                NeonCreateResult(NeonNone, L"Key Event Detected: Right Arrow"));
        direction = NeonEast;
        break;
    case VK_DOWN:
        NeonLog(NeonInformation,
                NeonCreateResult(NeonNone, L"Key Event Detected: Down Arrow"));
        direction = NeonSouth;
        break;
    case VK_LEFT:
        NeonLog(NeonInformation,
                NeonCreateResult(NeonNone, L"Key Event Detected: Left Arrow"));
        direction = NeonWest;
        break;
    default:
        return;
    }

    NeonMoveBlock(direction);
    NeonUpdateCoordinatesText();
    InvalidateRect(NeonGetWindowHandle(), NULL, TRUE);
}

void NeonHandleWindowLeftMouseDown(LPARAM longParam)
{
    int positionX = (LOWORD(longParam));
    int positionY = (HIWORD(longParam));

    if (NeonIsInClearButtonArea(positionX, positionY))
    {
        NeonLog(NeonInformation,
                NeonCreateResult(NeonNone, L"Clearing all obstructables."));
        NeonClearObstrutables();
        InvalidateRect(NeonGetWindowHandle(), NULL, TRUE);
        return;
    }

    if (NeonIsInLockToggleArea(positionX, positionY))
    {
        NeonLog(NeonInformation, NeonCreateResult(NeonNone, L"Toggled locked module."));
        NeonLockToggleButton();
        InvalidateRect(NeonGetWindowHandle(), NULL, TRUE);
        return;
    }

    if (NeonIsLocked())
    {
        return;
    }

    NeonSquare *square = NeonGetBlockAsPointer();

    if (!square)
    {
        NeonLog(NeonError, NeonCreateResult(NeonNullPtr, L"Failed to retrieve square."));
        return;
    }

    int MultiX = (positionX / square->size.width) * square->size.width;
    int MultiY = (positionY / square->size.height) * square->size.height;

    wchar_t logMessage[60];

    (void)swprintf(logMessage, 60, L"Click detected at (%d, %d)", MultiX, MultiY);
    NeonLog(NeonInformation, NeonCreateResult(NeonNone, logMessage));

    if (NeonObstrutableExistsAtPosition(MultiX, MultiY))
    {
        NeonLog(
            NeonInformation,
            NeonCreateResult(NeonNone, L"Obstructable exists at position. Skipping."));
        return;
    }

    NeonAddObstrutable(NeonCreatePosition(MultiX, MultiY));
    NeonUpdateVectorMemoryBar();
}