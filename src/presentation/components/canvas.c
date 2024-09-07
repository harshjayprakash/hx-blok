/**
 * \file canvas.c
 * \date 18-08-2024
 * \brief Implementation for the canvas component.
 *
 * This contains the implementation of the canvas component (initialisation, rendering and
 * releasing resources).
 */

#include "canvas.h"
#include "../objects/block.h"
#include "../objects/obstructables.h"

static int mLocked = 0;

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

int NeonIsCanvasLocked(void)
{
    return mLocked;
}

void NeonToggleCanvasLock(void)
{
    mLocked = (mLocked == 0) ? 1 : 0;
}

void NeonFreeCanvasComponent(void)
{
    NeonFreeBlockObject();
    NeonFreeObstructables();
}