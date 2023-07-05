#include "square.h"

struct square square_new(int _x, int _y, int _width, int _height)
{
    struct square sq = {_x, _y, _width, _height};
    return sq;
}

void square_position_set(struct square *sq, int _x, int _y)
{
    if (!sq)
    {
        return;
    }
    sq->x = _x;
    sq->y = _y;
}

void square_size_set(struct square *sq, int _width, int _height)
{
    if (!sq)
    {
        return;
    }
    sq->width = _width;
    sq->height = _height;
}

void square_free(struct square *sq)
{
}
