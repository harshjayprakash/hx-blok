/**
 * @file canvas.h
 * @date 2024-08-10
 * @brief
 */

#ifndef NEON_CANVAS_H
#define NEON_CANVAS_H

#define STRICT 1
#include <Windows.h>

void NeonInitCanvasComponent(void);

void NeonRenderCanvasComponent(HDC displayContext);

void NeonFreeCanvasComponent(void);

#endif 