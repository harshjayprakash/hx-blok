/**
 * @file square.c
 * @date 2024-08-10
 * @brief
 */

#include "square.h"

NeonSquare NeonCreateSquare(const NeonPosition position, const NeonSize size)
{
    return (NeonSquare) { NeonCreatePositionFromSelf(position), NeonCreateSizeFromSelf(size)  };
}