#include "handler.h"
#include "../colour/theme.h"
#include "../../model/objects/square.h"
#include "../components/canvas.h"
#include "../components/panel.h"
#include "../../model/utilities/direction.h"
#include "../window/window.h"
#include "../graphics/renderer.h"
#include <stdio.h>

static HDC bufferedContext;
static HBITMAP bitmapMemory;

void NeonHandlePaintEvent(HWND window, HDC displayContext)
{
    RECT windowArea = NeonGetWindowArea();
    NeonInitRenderTools();

    bufferedContext = CreateCompatibleDC(displayContext);
    bitmapMemory = CreateCompatibleBitmap(displayContext, windowArea.right, windowArea.bottom);

    (void) SelectObject(bufferedContext, bitmapMemory);

    NeonRenderCanvas(bufferedContext);
    NeonRenderPanel(bufferedContext);

    (void) BitBlt(displayContext, 0, 0, windowArea.right, windowArea.bottom, bufferedContext, 0, 0, SRCCOPY);

    (void) DeleteObject(bitmapMemory);
    (void) DeleteDC(bufferedContext);
    NeonFreeRenderTools();
}

void NeonHandleKeyDownEvent(WPARAM wordParam)
{
    NeonCompass directionToMove;

    switch ((int)wordParam)
    {
    case VK_UP:
        directionToMove = NeonNorth;
        break;
    case VK_RIGHT:
        directionToMove = NeonEast;
        break;
    case VK_DOWN:
        directionToMove = NeonSouth;
        break;
    case VK_LEFT:
        directionToMove = NeonWest;
        break;
    default:
        return;
    }

    NeonMoveSquare(NeonGetBlockReference(), directionToMove);
}

void NeonHandleLeftMouseButton(LPARAM longParam)
{
    NeonSquare *square = NeonGetBlockReference();
    NeonVector *markedRegions = NeonGetVectorReference();

    if (!square || !markedRegions) { return; }

    int posX = (LOWORD(longParam) / square->size.width) * square->size.width;
    int posY = (HIWORD(longParam) / square->size.height) * square->size.height;

    NeonVectorItem newNode = { 1, { posX, posY } };

    if (NeonNodeExists(markedRegions, newNode) == 0)
    {
        NeonPush(markedRegions, newNode);
    }

    NeonPrintVector(*markedRegions);
    
}