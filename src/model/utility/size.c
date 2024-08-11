/**
 * @file size.c
 * @date 2024-08-10
 * @brief
 */

#include "size.h"
#include "../../core/log.h"

NeonSize NeonCreateSize(const int width, const int height)
{
    return (NeonSize) { width, height };
}

NeonSize NeonCreateSizeFromSelf(const NeonSize size)
{
    return NeonCreateSize(size.width, size.height);
}

void NeonSetSize(NeonSize *size, const int width, const int height)
{
    if (!size)
    {
        NeonLog(NeonWarning, NeonCreateResult(NeonNullPtr, L"Cannot update size: is null"));
        return;
    }

    NeonSetWidth(size, width);
    NeonSetHeight(size, height);
}

void NeonSetWidth(NeonSize *size, const int width)
{
    if (!size)
    {
        NeonLog(NeonWarning, NeonCreateResult(NeonNullPtr, L"Cannot update width: size is null"));
        return;
    } 

    size->width = width;
}

void NeonSetHeight(NeonSize *size, const int height)
{
    if (!size)
    {
        NeonLog(NeonWarning, NeonCreateResult(NeonNullPtr, L"Cannot update height: size is null"));
        return;
    } 

    size->height = height;
}

void NeonCopySize(NeonSize *dest, const NeonSize src)
{
    if (!dest)
    {
        NeonLog(NeonWarning, NeonCreateResult(NeonNullPtr, L"Cannot copy size: destination is null"));
        return;
    } 

    NeonSetSize(dest, src.width, src.height);
}