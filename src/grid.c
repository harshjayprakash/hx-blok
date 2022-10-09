#include "incl/grid.h"
#include "incl/global.h"

int Grid_Init(Grid* self, int _width, int _height)
{
    self->height = _height;
    self->width = _width;
    self->map = (GridPoint*) malloc((_width * _height) * sizeof(GridPoint));

    if (self->map == NULL)
    {
        fprintf(stderr, "Failed to allocate memory [map: GridPoint*]\n");
        fflush(stderr);
        return 1;
    }

    return 0;
}

int Grid_Del(Grid* self)
{
    if (self->map != NULL)
        free(self->map);
    if (self->prevMap != NULL)
        free(self->prevMap);
    return 0;
}

int Grid_Realloc(Grid* self)
{
    fprintf(stderr, "Not implementated\n");
    fflush(stderr);

    return 1;
}

int Grid_AddBlock(Grid* self, int _x, int _y)
{
    if (self->map == NULL)
    {
        fprintf(stderr, "Required variable [map: GridPoint*] has not been allocated any memory\n");
        fflush(stderr);

        return 1;
    }

    GridPoint gp = { _x, _y, 1 };
    self->map[self->idxr++] = gp;

    return 0;
}

int Grid_RemoveBlock(Grid* self, int _x, int _y)
{
    if (self->map == NULL)
    {
        fprintf(stderr, "Required variable [map: GridPoint*] has not been allocated any memory\n");
        fflush(stderr);

        return 1;
    }

    for (int i = 0; i < self->idxr + 1; i++)
    {
        if (self->map[i].posX == _x
            && self->map[i].posY == _y)
        {
            self->map[i].posX = self->map[self->idxr].posX;
            self->map[i].posY = self->map[self->idxr].posY;
            self->map[i].illumated = self->map[self->idxr].illumated;
            self->map[self->idxr].posX = 0;
            self->map[self->idxr].posY = 0;
            self->map[self->idxr].illumated = 0;
            self->idxr--;
        }
    }
    
    return 0;
}