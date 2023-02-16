#include "grid.h"

void Coord_Set(Coord* self, int x, int y)
{
    if (self == NULL) { return; }
    self->x = x;
    self->y = y;
}

int Grid_Init(Grid* self, int width, int height)
{
    if (self == NULL) { return 2; }
    self->height = height;
    self->width = width;
    self->indexer = 0;
    self->allocated = width * height;
    self->map = (Coord*) calloc(self->allocated, sizeof(Coord));
    self->prevMap = (Coord*) calloc(self->allocated, sizeof(Coord));
    if (self->map == NULL) { return 1; }
    if (self->prevMap == NULL) { return 1; }
    for (int i = 0; i < self->allocated; i++)
    {
        self->map[i].x = -1;
        self->map[i].y = -1;
    }
    return 0;
}

int Grid_Del(Grid* self)
{
    if (self->map != NULL) { free(self->map); }
    if (self->prevMap != NULL) { free(self->prevMap); }
    return 0;
}

int Grid_Realloc(Grid* self)
{
    return -1;
}

int Grid_AddMark(Grid* self, int x, int y)
{
    if (self == NULL) { return 2; }
    if (self->map == NULL) { return 1; }
    if (self->indexer >= self->allocated) { return 3; }
    // int newIndex =  Grid_GetNextEmptyIndex(self);
    // if (newIndex < 0) { return 4; }
    Coord_Set(&(self->map[self->indexer]), x, y);
    self->indexer++;
    return 0;
}

int Grid_RemoveMark(Grid* self, int x, int y)
{
    if (self == NULL) { return 2; }
    if (self->map == NULL) { return 1; }
    if (self->prevMap == NULL) { return 5; }
    if (self->indexer <= 0) { return 3; }
    int foundIndex = Grid_FindMark(self, x, y);
    if (foundIndex < 0) { return 4; }
    Coord_Set(&(self->map[foundIndex]), -1, -1);
    for (int i = 0; i < self->allocated; i++) { self->prevMap[i] = self->map[i]; }
    int newIndex = 0;
    for (int i = 0; i < self->indexer; i++) {
        if (self->prevMap[i].x == -1 || self->prevMap[i].y == -1) continue;
        self->map[newIndex++] = self->prevMap[i];
    }
    self->indexer = newIndex;
    return 0;
}

int Grid_FindMark(Grid* self, int x, int y)
{
    if (self == NULL) { return -2; }
    if (self->map == NULL) { return -1; }
    for (int i = 0; i < self->allocated; i++)
    {
        if (self->map[i].x == x && self->map[i].y == y) { return i; }
    }
    return -3;
}

int Grid_GetNextEmptyIndex(Grid* self)
{
    if (self == NULL) { return -2; }
    if (self->map == NULL) { return -1; }
    for (int i = 0; i < self->allocated; i++)
    {
        if (self->map[i].x == -1 && self->map[i].y == -1) { return i; }
    }
    return -3;
}