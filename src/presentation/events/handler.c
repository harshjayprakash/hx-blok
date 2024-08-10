/**
 * @file handler.c
 * @date 2024-08-10
 * @brief 
 */

#include "handler.h"
#include "../window.h"
#include "../objects/block.h"

void NeonHandleWindowPaintEvent(HDC displayContext)
{
    RECT windowArea = NeonGetWindowArea();

    HDC bufferedContext = CreateCompatibleDC(displayContext);
    HBITMAP bitmapMemory = CreateCompatibleBitmap(displayContext, windowArea.right, windowArea.bottom);

    (void) SelectObject(bufferedContext, bitmapMemory);

    NeonRenderBlock(bufferedContext);

    (void) BitBlt(displayContext, 0, 0, windowArea.right, windowArea.bottom, bufferedContext, 0, 0, SRCCOPY);

    (void) DeleteObject(bitmapMemory);
    (void) DeleteDC(bufferedContext);
}