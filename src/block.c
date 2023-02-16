#include "block.h"

void Block_Init(Block* self, int x, int y, int width, int height, COLORREF colour)
{
    if (self == NULL) { return; }
    self->x = x;
    self->y = y;
    self->width = width;
    self->height = height;
    self->colour = colour;
    self->nMovfX = width;
    self->nMovfY = height;
    self->limitX = width * 10;
    self->limitY = height * 10;
}

void Block_Del(Block* self)
{
    
}

void Block_SetColour(Block* self, COLORREF colour)
{
    if (self == NULL) { return; }
    self->colour = colour;
}

void Block_SetMoveRate(Block* self, int rateX, int rateY)
{
    if (self == NULL) { return; }
    self->nMovfX = rateX;
    self->nMovfY = rateY;
}

void Block_SetPosition(Block* self, int x, int y)
{
    if (self == NULL) { return; }
    self->x = x;
    self->y = y;
}

void Block_SetSize(Block* self, int width, int height)
{
    if (self == NULL) { return; }
    self->width = width;
    self->height = height;
}

void Block_SetLimits(Block* self, int x, int y)
{
    if (self == NULL) { return; }
    self->limitX = x;
    self->limitY = y;
}

RECT Block_ConvertToRect(Block* self)
{
    if (self == NULL) 
    { 
        RECT rectInvalid = {0L, 0L, 0L, 0L};
        return rectInvalid;
    }
    RECT rectBlock = {self->x, self->y, self->x + self->width, self->y + self->height};
    return rectBlock;
}

void Block_MoveUp(Block* self)
{
    if (self == NULL) { return; }
    if (self->y != 0)
        self->y -= self->nMovfY;
}

void Block_MoveDown(Block* self)
{
    if (self == NULL) { return; }
    if (self->y < self->limitY - self->height)
        self->y += self->nMovfY;
}

void Block_MoveLeft(Block* self)
{
    if (self == NULL) { return; }
    if (self->x != 0)
        self->x -= self->nMovfX;
}

void Block_MoveRight(Block* self)
{
    if (self == NULL) { return; }
    if (self->x < self->limitX - self->width)
        self->x += self->nMovfX;
}
