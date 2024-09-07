/**
 * \file position.c
 * \date 13-08-2024
 * \brief Implementation of position function definitions.
 *
 * This file contains the implementation of the function definitions provided in the
 * position header file.
 */

#include "position.h"
#include "../../core/log.h"
#include "../../core/result.h"

NeonPosition NeonCreatePosition(const int x, const int y)
{
    return (NeonPosition){x, y};
}

NeonPosition NeonCreatePositionFromSelf(const NeonPosition position)
{
    return NeonCreatePosition(position.x, position.y);
}

void NeonSetPosition(NeonPosition *position, const int x, const int y)
{
    if (!position)
    {
        NeonLog(NeonWarning,
                NeonCreateResult(NeonNullPtr,
                                 L"Update Position Failed: Null Pointer Error."));
        return;
    }

    NeonSetXPosition(position, x);
    NeonSetYPosition(position, y);
}

void NeonSetXPosition(NeonPosition *position, const int x)
{
    if (!position)
    {
        NeonLog(NeonWarning,
                NeonCreateResult(NeonNullPtr,
                                 L"X Position Update Failed: Null Pointer Error."));
        return;
    }

    position->x = x;
}

void NeonSetYPosition(NeonPosition *position, const int y)
{
    if (!position)
    {
        NeonLog(NeonWarning,
                NeonCreateResult(NeonNullPtr,
                                 L"Y Position Update Failed: Null Pointer Error."));
        return;
    }

    position->y = y;
}

void NeonCopyPosition(NeonPosition *dest, const NeonPosition src)
{
    if (!dest)
    {
        NeonLog(
            NeonWarning,
            NeonCreateResult(NeonNullPtr, L"Position Copy Failed: Null Pointer Error."));
        return;
    }

    NeonSetPosition(dest, src.x, src.y);
}