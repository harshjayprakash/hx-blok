#include "square.h"

square square_new(int _x, int _y, int _width, int _height)
{
    square sq = { _x, _y, _width, _height };
    return sq;
}

void square_position_set(square *sq, int _x, int _y)
{
    sq->x = _x;
    sq->y = _y;
}

void square_size_set(square *sq, int _width, int _height)
{
    sq->width = _width;
    sq->height = _height;
}

void square_free(square *sq)
{

}