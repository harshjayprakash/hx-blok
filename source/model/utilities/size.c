#include "size.h"

NeonSize NeonNewSize(const int width, const int height)
{
    return (NeonSize) { width, height };
}

NeonSize NeonNewSizeFromSelf(const NeonSize size)
{
    return NeonNewSize(size.width, size.height);
}

void NeonSetWidth(NeonSize *size, const int width)
{
    if (!size) { return; }

    size->width = width;
}

void NeonSetHeight(NeonSize *size, const int height)
{
    if (!size) { return; }

    size->height = height;
}

void NeonSetSize(NeonSize *size, const int width, const int height)
{
    NeonSetWidth(size, width);
    NeonSetHeight(size, height);
}

void NeonCopySize(NeonSize *dest, const NeonSize src)
{
    NeonSetSize(dest, src.width, src.height);
}