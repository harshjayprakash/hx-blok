/**
 * @file position.c
 * @date 2024-08-10
 * @brief
 */

#include "position.h"

NeonPosition NeonCreatePosition(const int x, const int y)
{
    return (NeonPosition) { x, y };
}

NeonPosition NeonCreatePositionFromSelf(const NeonPosition position)
{
    return NeonCreatePosition(position.x, position.y);
}