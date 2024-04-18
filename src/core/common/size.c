#include "size.h"

TSize bloqNewSize(int width, int height)
{
    return (TSize) { width, height };
}

void bloqSetSizeWidth(TSize *self, int width)
{
    if (!self) { return; }

    self->width = width;
}

void bloqSetSizeHeight(TSize *self, int height)
{
    if (!self) { return; }

    self->height = height;
}

void bloqSetSize(TSize *self, int width, int height)
{
    bloqSetSizeWidth(self, width);
    bloqSetSizeHeight(self, height);
}

void bloqCopySize(TSize *src, TSize *dest)
{
    if (!src || !dest) { return; }

    bloqSetSize(dest, src->width, src->height);
}