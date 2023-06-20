#ifndef __BLOK_SQUARE_H
#define __BLOK_SQUARE_H

typedef struct square__
{
    int x;
    int y;
    int width;
    int height;
} square;

square square_new(int x, int y, int width, int height);

void square_position_set(const square *sq, int x, int y);

void square_size_set(const square *sq, int width, int height);

void square_free(const square *sq);

#endif