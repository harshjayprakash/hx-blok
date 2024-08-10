/**
 * @file handler.c
 * @date 2024-08-10
 * @brief 
 */

#include "handler.h"
#include "../window.h"
#include "../objects/block.h"
#include "../../core/log.h"

void NeonHandleWindowPaintEvent(HDC displayContext)
{
    NeonRenderBlock(displayContext);
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
    InvalidateRect(NeonGetWindowHandle(), NULL, TRUE);
}