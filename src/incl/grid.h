#ifndef GRID_H
#define GRID_H

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct GridPoint
{
    int posX;
    int posY;
    int illumated;
} GridPoint;

typedef struct Grid
{
    GridPoint *map;
    GridPoint *prevMap;
    int width;
    int height;
    int idxr;
} Grid;

int Grid_Init(Grid* self, int _width, int _height);
int Grid_Del(Grid* self);
int Grid_Realloc(Grid* self);

int Grid_AddBlock(Grid* self, int _x, int _y);
int Grid_RemoveBlock(Grid* self, int _x, int _y);

#endif