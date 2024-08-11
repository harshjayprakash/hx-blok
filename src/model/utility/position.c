/**
 * @file position.c
 * @date 2024-08-10
 * @brief
 */

#include "position.h"
#include "../../core/log.h"
#include "../../core/result.h"

NeonPosition NeonCreatePosition(const int x, const int y)
{
    return (NeonPosition) { x, y };
}

NeonPosition NeonCreatePositionFromSelf(const NeonPosition position)
{
    return NeonCreatePosition(position.x, position.y);
}

void NeonSetPosition(NeonPosition *position, const int x, const int y)
{
    if (!position)
    {
        NeonLog(NeonWarning, NeonCreateResult(NeonNullPtr, L"Cannot update position: is null"));
        return;
    }

    NeonSetXPosition(position, x);
    NeonSetYPosition(position, y);
}

void NeonSetXPosition(NeonPosition *position, const int x)
{
    if (!position)
    {
        NeonLog(NeonWarning, NeonCreateResult(NeonNullPtr, L"Cannot update x position: is null"));
        return;
    }

    position->x = x;
}

void NeonSetYPosition(NeonPosition *position, const int y)
{
    if (!position)
    {
        NeonLog(NeonWarning, NeonCreateResult(NeonNullPtr, L"Cannot update y position: is null"));
        return;
    }

    position->y = y;
}

void NeonCopyPosition(NeonPosition *dest, const NeonPosition src)
{
    if (!dest)
    {
        NeonLog(NeonWarning, NeonCreateResult(NeonNullPtr, L"Cannot copy position: destination is null"));
        return;
    }

    NeonSetPosition(dest, src.x, src.y);
}