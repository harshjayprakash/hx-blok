/**
 * @file square.c
 * @date 2024-08-10
 * @brief
 */

#include "square.h"
#include "../../core/log.h"

NeonSquare NeonCreateSquare(const NeonPosition position, const NeonSize size)
{
    return (NeonSquare) { NeonCreatePositionFromSelf(position), NeonCreateSizeFromSelf(size)  };
}

void NeonCopySquare(NeonSquare *dest, const NeonSquare src)
{
    if (!dest)
    {
        NeonLog(NeonWarning, NeonCreateResult(NeonNullPtr, L"Cannot copy square: destination is null"));
        return;
    } 

    NeonCopySize(&(dest->size), src.size);
    NeonCopyPosition(&(dest->position), src.position);
}