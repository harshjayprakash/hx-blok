#ifndef __BLOK_SQUARE_H
#define __BLOK_SQUARE_H

typedef struct square__
{
    int x;
    int y;
    int width;
    int height;
} square;

square square_new(int _x, int _y, int _width, int _height);

void square_position_set(square *sq, int _x, int _y);

void square_size_set(square *sq, int _width, int _height);

void square_free(square *sq);

#endif