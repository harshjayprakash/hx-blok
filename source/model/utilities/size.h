#ifndef NEON_SIZE_H
#define NEON_SIZE_H

typedef struct _NeonSize
{
    int width;
    int height;
} NeonSize;

NeonSize NeonNewSize(const int width, const int height);

NeonSize NeonNewSizeFromSelf(const NeonSize size);

void NeonSetSize(NeonSize *size, const int width, const int height);

void NeonSetWidth(NeonSize *size, const int width);

void NeonSetHeight(NeonSize *size, const int height);

void NeonCopySize(NeonSize *dest, const NeonSize src);

#endif