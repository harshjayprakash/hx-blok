#ifndef BLOQ_SIZE_H
#define BLOQ_SIZE_H

typedef struct bloqSize
{
    int width;
    int height;
} TSize;

TSize bloqNewSize(int width, int height);

void bloqSetSizeWidth(TSize *self, int width);

void bloqSetSizeHeight(TSize *self, int height);

void bloqSetSize(TSize *self, int width, int height);

void bloqCopySize(TSize *src, TSize *dest);

#endif