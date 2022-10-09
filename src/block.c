#include "incl/block.h"
#include "incl/global.h"

void Block_Init(Block* self, int _x, int _y, int _width, int _height, COLORREF _colour)
{
    self->x = _x;
    self->y = _y;
    self->width = _width;
    self->height = _height;
    self->colour = _colour;
    self->nMovfX = _width;
    self->nMovfY = _height;
    self->limitX = _width * 10;
    self->limitY = _height * 10;
    self->fcollusions = 0;
}

void Block_Del(Block* self)
{
    
}

void Block_SetColour(Block* self, COLORREF _colour)
{
    self->colour = _colour;
}

void Block_SetMoveRate(Block* self, int _rateX, int _rateY)
{
    self->nMovfX = _rateX;
    self->nMovfY = _rateY;
}

void Block_SetPosition(Block* self, int _x, int _y)
{
    self->x = _x;
    self->y = _y;
}

void Block_SetSize(Block* self, int _width, int _height)
{
    self->width = _width;
    self->height = _height;
}

void Block_SetLimits(Block* self, int _x, int _y)
{
    self->limitX = _x;
    self->limitY = _y;
}

RECT Block_ConvertToRect(Block* self)
{
    RECT rectBlock = {self->x, self->y, self->x + self->width, self->y + self->height};
    return rectBlock;
}

void Block_MoveUp(Block* self)
{
    if (self->y != 0)
        self->y -= self->nMovfY;
}

void Block_MoveDown(Block* self)
{
    if (self->y < self->limitY - self->height)
        self->y += self->nMovfY;
}

void Block_MoveLeft(Block* self)
{
    if (self->x != 0)
        self->x -= self->nMovfX;
}

void Block_MoveRight(Block* self)
{
    if (self->x < self->limitX - self->width)
        self->x += self->nMovfX;
}

