/**
 * @file canvas.c
 * @date 2024-08-10
 * @brief
 */

#include "canvas.h"
#include "../objects/block.h"
#include "../objects/obstructables.h"

void NeonInitCanvasComponent(void)
{
    NeonInitBlockObject();
    NeonInitObstructables();
}

void NeonRenderCanvasComponent(HDC displayContext)
{
    NeonRenderBlock(displayContext);
    NeonRenderObstructables(displayContext);
}

void NeonFreeCanvasComponent(void)
{
    NeonFreeBlockObject();
    NeonFreeObstructables();
}