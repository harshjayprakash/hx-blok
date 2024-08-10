/**
 * @file handler.c
 * @date 2024-08-10
 * @brief 
 */

#include "handler.h"
#include "../objects/block.h"

void NeonHandleWindowPaintEvent(HDC displayContext)
{
    NeonRenderBlock(displayContext);
}