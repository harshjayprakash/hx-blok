/**
 * \file canvas.c
 * \date 13-08-2024
 * \brief Implementation for the canvas component.
 * 
 * This contains the implementation of the canvas component (initialisation, rendering and 
 * releasing resources).
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
    NeonRenderObstructables(displayContext);
    NeonRenderBlock(displayContext);
}

void NeonFreeCanvasComponent(void)
{
    NeonFreeBlockObject();
    NeonFreeObstructables();
}