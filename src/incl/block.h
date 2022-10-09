#ifndef BLOCK_H
#define BLOCK_H

#include <windows.h>

typedef struct Block
{
    int x;
    int y;
    int width;
    int height;
    int nMovfX;
    int nMovfY;
    int limitX;
    int limitY;
    short fcollusions;
    COLORREF colour;
} Block;

void Block_Init(Block* self, int _x, int _y, int _width, int _height, COLORREF _colour);
void Block_Del(Block* self);

void Block_SetColour(Block* self, COLORREF _colour);
void Block_SetMoveRate(Block* self, int _rateX, int _rateY);
void Block_SetPosition(Block* self, int _x, int _y);
void Block_SetSize(Block* self, int _width, int _height);
void Block_SetLimits(Block* self, int _x, int _y);

RECT Block_ConvertToRect(Block* self);
void Block_MoveUp(Block* self);
void Block_MoveDown(Block* self);
void Block_MoveLeft(Block* self);
void Block_MoveRight(Block* self);

#endif