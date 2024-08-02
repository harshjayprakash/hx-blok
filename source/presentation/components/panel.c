#include "panel.h"
#include <wingdi.h>

static wchar_t mCoordinateText[] = L"( X: 0, Y: 0 )";

void NeonRenderPanel(HDC displayContextHandle, RECT windowSize, HBRUSH backgroundBrushHandle, HBRUSH foregroundBrushHandle)
{
    Rectangle(
        displayContextHandle, 
        windowSize.left + 1, 
        windowSize.bottom - 40, 
        windowSize.right - 1,
        windowSize.bottom - 1);
    
    TextOutW(displayContextHandle, 15, (windowSize.bottom - windowSize.top) - 30,
    mCoordinateText, (int) wcslen(mCoordinateText));
}

void NeonUpdateCoordinateText(void)
{
    
    
}