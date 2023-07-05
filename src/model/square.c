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

void square_move(struct square *sq, enum direction _direction)
{
    if (!sq)
    {
        return;
    }
    switch (_direction)
    {
    case north:
        square_position_set(sq, sq->x, (sq->y - sq->height));
        return;
    case east:
        square_position_set(sq, (sq->x + sq->width), sq->y);
        return;
    case south:
        square_position_set(sq, sq->x, (sq->y + sq->height));
        return;
    case west:
        square_position_set(sq, (sq->x - sq->width), sq->y);
        return;
    }
}

RECT square_winapi_rect_cast(const struct square *sq)
{
    if (!sq)
    {
        return (RECT){0, 0, 15, 15};
    }
    RECT rect = {sq->x, sq->y, sq->x + sq->width, sq->y + sq->height};
    return rect;
}

void square_free(struct square *sq)
{
}
