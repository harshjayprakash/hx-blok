/**
 * \file handler.c
 * \date 07-09-2024
 * \brief Implementation of the window handle events.
 *
 * This file contains the implementation of handling window events.
 */

#define STRICT 1
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

    NeonSize sqSize = NeonGetBlockSize();

    RECT updateRegion = NeonGetBlockAsRect();
    updateRegion.top -= sqSize.height;
    updateRegion.left -= sqSize.width;
    updateRegion.right += sqSize.height;
    updateRegion.bottom += sqSize.width;

    (void)InvalidateRect(NeonGetWindowHandle(), &updateRegion, FALSE);
    NeonInvalidateCoordinateTextArea();
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
            NeonUpdateVectorMemoryBar();
            (void)InvalidateRect(NeonGetWindowHandle(), NULL, FALSE);
            return;
        }

        if (NeonIsInLockToggleArea(positionX, positionY))
        {
            NeonLog(NeonInformation, NeonCreateResult(NeonNone, L"Toggling Lock Mode."));
            NeonHandleLockToggleButtonClick();
            NeonInvalidateLockedToggleArea();
            return;
        }

        if (NeonIsInGenerateButtonArea(positionX, positionY))
        {
            NeonLog(NeonInformation,
                    NeonCreateResult(NeonNone, L"Generating Random Obstructables."));
            RECT windowArea = NeonGetWindowArea();

            NeonSize squareSize = NeonGetBlockSize();

            int generateCount = (windowArea.bottom * windowArea.right) / 2000;

            for (int index = 0; index < generateCount; index++)
            {
                int newX = ((rand() % windowArea.right) / squareSize.width) *
                           squareSize.width;
                int newY = ((rand() % windowArea.bottom) / squareSize.height) *
                           squareSize.height;

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

    NeonSize squareSize = NeonGetBlockSize();

    int MultiX = (positionX / squareSize.width) * squareSize.width;
    int MultiY = (positionY / squareSize.height) * squareSize.height;

    wchar_t logMessage[60];

    (void)swprintf(logMessage, 60, L"Click At (%d, %d)", MultiX, MultiY);
    NeonLog(NeonInformation, NeonCreateResult(NeonNone, logMessage));

    if (NeonObstrutableExistsAtPosition(MultiX, MultiY))
    {
        NeonLog(NeonInformation,
                NeonCreateResult(NeonNone,
                                 L"Existing Obstructable At Given Position: Skipping."));
        return;
    }

    NeonAddObstrutable(NeonCreatePosition(MultiX, MultiY));
    NeonUpdateVectorMemoryBar();
}