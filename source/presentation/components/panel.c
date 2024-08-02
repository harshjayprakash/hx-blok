#include "panel.h"
#include "canvas.h"
#include "../window/window.h"
#include "../graphics/renderer.h"
#include "../colour/theme.h"
#include <wingdi.h>
#include <stdio.h>

static wchar_t mCoordinateText[260];

void NeonRenderPanel(HDC displayContext)
{
    RECT windowArea = NeonGetWindowArea();
    NeonUpdateCoordinateText();

    (void) SelectObject(displayContext, NeonGetBackgroundBrush());
    (void) SelectObject(displayContext, NeonGetOutlinePen());
    (void) Rectangle(displayContext, windowArea.left + 1, windowArea.bottom - 40, windowArea.right - 1, windowArea.bottom - 1);
    (void) SetBkColor(displayContext, NeonGetBackgroundColour());
    (void) SetTextColor(displayContext, NeonGetForegroundColour());
    (void) TextOutW(displayContext, 15, (windowArea.bottom - windowArea.top) - 30, mCoordinateText, (int) wcslen(mCoordinateText));
}

void NeonUpdateCoordinateText(void)
{
    NeonSquare *sq = NeonGetBlockReference();
    
    if (!sq) { return; }
    
    (void) _snwprintf_s(mCoordinateText, 260, 260, L"( X: %d, Y: %d )", sq->position.x, sq->position.y);
}