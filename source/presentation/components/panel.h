#ifndef NEON_PANEL_H
#define NEON_PANEL_H

#include <windows.h>

void NeonRenderPanel(HDC displayContextHandle, RECT windowSize, HBRUSH backgroundBrushHandle, HBRUSH foregroundBrushHandle);

void NeonUpdateCoordinateText(void);

#endif