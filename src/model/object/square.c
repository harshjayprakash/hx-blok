/**
 * \file square.c
 * \date 13-08-2024
 * \brief Implementation of square functions.
 *
 * This file contans the implementation of the functions of the square module to create a
 * new square and copy squares.
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