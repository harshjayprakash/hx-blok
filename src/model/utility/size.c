/**
 * @file size.c
 * @date 2024-08-10
 * @brief
 */

#include "size.h"

NeonSize NeonCreateSize(const int width, const int height)
{
    return (NeonSize) { width, height };
}

NeonSize NeonCreateSizeFromSelf(const NeonSize size)
{
    return NeonCreateSize(size.width, size.height);
}