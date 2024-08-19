/**
 * \file size.c
 * \date 13-08-2024
 * \brief Implementation of functions for size object.
 *
 * This file contains the implementation of functions required for the size object. This
 * includes creating a new instance and setting sizes.
 */

#include "size.h"
#include "../../core/log.h"

NeonSize NeonCreateSize(const int width, const int height)
{
    return (NeonSize){width, height};
}

NeonSize NeonCreateSizeFromSelf(const NeonSize size)
{
    return NeonCreateSize(size.width, size.height);
}

void NeonSetSize(NeonSize *size, const int width, const int height)
{
    if (!size)
    {
        NeonLog(NeonWarning,
                NeonCreateResult(NeonNullPtr, L"Size Update Failed: Null Pointer Error."));
        return;
    }

    NeonSetWidth(size, width);
    NeonSetHeight(size, height);
}

void NeonSetWidth(NeonSize *size, const int width)
{
    if (!size)
    {
        NeonLog(NeonWarning,
                NeonCreateResult(NeonNullPtr, L"Width Updated Failed: Null Pointer Error."));
        return;
    }

    size->width = width;
}

void NeonSetHeight(NeonSize *size, const int height)
{
    if (!size)
    {
        NeonLog(NeonWarning,
                NeonCreateResult(NeonNullPtr, L"Height Updated Failed: Null Pointer Error."));
        return;
    }

    size->height = height;
}

void NeonCopySize(NeonSize *dest, const NeonSize src)
{
    if (!dest)
    {
        NeonLog(NeonWarning,
                NeonCreateResult(NeonNullPtr, L"Size Copy Failed: Null Pointer Error."));
        return;
    }

    NeonSetSize(dest, src.width, src.height);
}