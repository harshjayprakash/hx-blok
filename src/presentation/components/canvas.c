/**
 * @file canvas.c
 * @date 2024-08-10
 * @brief
 */

#include "canvas.h"
#include "../objects/block.h"

void NeonInitCanvasComponent(void)
{
    NeonInitBlockObject();
}

void NeonRenderCanvasComponent(HDC displayContext)
{
    NeonRenderBlock(displayContext);
}

void NeonFreeCanvasComponent(void)
{
    NeonFreeBlockObject();
}