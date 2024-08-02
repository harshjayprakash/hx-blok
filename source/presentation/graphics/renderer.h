#ifndef NEON_RENDERER_H
#define NEON_RENDERER_H

#include <windows.h>

void NeonInitRenderTools(void);

HBRUSH NeonGetBackgroundBrush(void);

HBRUSH NeonGetForegroundBrush(void);

HBRUSH NeonGetAccentBrush(void);

HPEN NeonGetOutlinePen(void);

void NeonFreeRenderTools(void);

#endif