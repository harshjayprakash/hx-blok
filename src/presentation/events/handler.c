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
                NeonCreateResult(NeonNone, L"Up Arrow Key Event Detected."));
        direction = NeonNorth;
        break;
    case VK_RIGHT:
        NeonLog(NeonInformation,
                NeonCreateResult(NeonNone, L"Right Arrow Key Event Detected."));
        direction = NeonEast;
        break;
    case VK_DOWN:
        NeonLog(NeonInformation,
                NeonCreateResult(NeonNone, L"Down Arrow Key Event Detected."));
        direction = NeonSouth;
        break;
    case VK_LEFT:
        NeonLog(NeonInformation,
                NeonCreateResult(NeonNone, L"Left Arrow Key Event Detected"));
        direction = NeonWest;
        break;
    default:
        return;
    }

    NeonMoveBlock(direction);
    NeonUpdateCoordinatesText();

    NeonSquare *sq = NeonGetBlockAsPointer();

    if (!sq) 
    {
        InvalidateRect(NeonGetWindowHandle(), NULL, TRUE);
        return;
    }

    RECT updateRegion = NeonGetBlockAsRect();
    updateRegion.top -= sq->size.height;
    updateRegion.left -= sq->size.width;
    updateRegion.right += sq->size.height;
    updateRegion.bottom += sq->size.width;

    RECT coordinateRegion = NeonGetCoordinateArea();

    InvalidateRect(NeonGetWindowHandle(), &updateRegion, TRUE);
    InvalidateRect(NeonGetWindowHandle(), &coordinateRegion, TRUE);
}

void NeonHandleWindowLeftMouseDown(LPARAM longParam)
{
    int positionX = (LOWORD(longParam));
    int positionY = (HIWORD(longParam));

    if (NeonIsInPanelArea(positionX, positionY))
    {
        if (NeonIsInClearButtonArea(positionX, positionY))
        {
            NeonLog(NeonInformation,
                    NeonCreateResult(NeonNone, L"Clearing All Obstructables."));
            NeonClearObstrutables();
            InvalidateRect(NeonGetWindowHandle(), NULL, TRUE);
            NeonUpdateVectorMemoryBar();
            return;
        }

        if (NeonIsInLockToggleArea(positionX, positionY))
        {
            NeonLog(NeonInformation, NeonCreateResult(NeonNone, L"Toggling Lock Mode."));
            NeonHandleLockToggleButtonClick();
            InvalidateRect(NeonGetWindowHandle(), NULL, TRUE);
            return;
        }

        if (NeonIsInGenerateButtonArea(positionX, positionY))
        {
            NeonLog(NeonInformation, NeonCreateResult(NeonNone, L"Generating Random Obstructables."));
            RECT windowArea = NeonGetWindowArea();

            NeonSquare *square = NeonGetBlockAsPointer();

            if (!square)
            {
                NeonLog(NeonError, NeonCreateResult(NeonNullPtr, L"Square Retrieval Failed: Null Pointer Error."));
                return;
            }

            int generateCount = (windowArea.bottom * windowArea.right) / 2000;

            for (int index = 0; index < generateCount; index++)
            {
                int newX = ((rand()%windowArea.right) / square->size.width) * square->size.width;
                int newY = ((rand()%windowArea.bottom) / square->size.height) * square->size.height;

                if (NeonObstrutableExistsAtPosition(newX, newY))
                {
                    continue;
                }

                NeonAddObstrutable(NeonCreatePosition(newX, newY));
                NeonUpdateVectorMemoryBar();
            }
        }

        return;
    }

    if (NeonIsCanvasLocked())
    {
        return;
    }

    NeonSquare *square = NeonGetBlockAsPointer();

    if (!square)
    {
        NeonLog(NeonError, NeonCreateResult(NeonNullPtr, L"Square Retrieval Error: Null Pointer Error."));
        return;
    }

    int MultiX = (positionX / square->size.width) * square->size.width;
    int MultiY = (positionY / square->size.height) * square->size.height;

    wchar_t logMessage[60];

    (void)swprintf(logMessage, 60, L"Click At (%d, %d)", MultiX, MultiY);
    NeonLog(NeonInformation, NeonCreateResult(NeonNone, logMessage));

    if (NeonObstrutableExistsAtPosition(MultiX, MultiY))
    {
        NeonLog(
            NeonInformation,
            NeonCreateResult(NeonNone, L"Existing Obstructable At Given Position: Skipping."));
        return;
    }

    NeonAddObstrutable(NeonCreatePosition(MultiX, MultiY));
    NeonUpdateVectorMemoryBar();
}