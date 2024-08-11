/**
 * @file handler.c
 * @date 2024-08-10
 * @brief 
 */

#include "handler.h"
#include "../window.h"
#include "../objects/block.h"
#include "../../core/log.h"
#include "../components/panel.h"
#include "../components/canvas.h"
#include "../objects/obstructables.h"


void NeonHandleWindowPaintEvent(HDC displayContext)
{
    NeonRenderCanvasComponent(displayContext);
    NeonRenderPanelComponent(displayContext);
}

void NeonHandleWindowKeyDownEvent(WPARAM wordParam)
{
    NeonDirection direction;

    switch ((int) wordParam)
    {
    case VK_UP:
        NeonLog(NeonInformation, NeonCreateResult(NeonNone, L"Key Event Detected: Up Arrow"));
        direction = NeonNorth;
        break;
    case VK_RIGHT:
        NeonLog(NeonInformation, NeonCreateResult(NeonNone, L"Key Event Detected: Right Arrow"));
        direction = NeonEast;
        break;
    case VK_DOWN:
        NeonLog(NeonInformation, NeonCreateResult(NeonNone, L"Key Event Detected: Down Arrow"));
        direction = NeonSouth;
        break;
    case VK_LEFT:
        NeonLog(NeonInformation, NeonCreateResult(NeonNone, L"Key Event Detected: Left Arrow"));
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
    NeonSquare *square = NeonGetBlockAsPointer();

    if (!square)
    {
        NeonLog(NeonError, NeonCreateResult(NeonNullPtr, L"Failed to retrieve square."));
        return;
    }

    int positionX = (LOWORD(longParam) / square->size.width) * square->size.width;
    int positionY = (HIWORD(longParam) / square->size.height) * square->size.height;

    wchar_t logMessage[60];

    (void) swprintf(logMessage, 60, L"Click detected at (%d, %d)", positionX, positionY);
    NeonLog(NeonInformation, NeonCreateResult(NeonNone, logMessage));

    NeonAddObstrutable(NeonCreatePosition(positionX, positionY));
    NeonUpdateVectorMemoryBar();
}