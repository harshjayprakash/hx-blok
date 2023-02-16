#ifndef GRID_H
#define GRID_H

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

/**
 * A structure for a coordinate that can be used to identify a point on the
 * grid.
*/
typedef struct Coord
{
    int x;
    int y;
} Coord;

/**
 * Sets the Coordinates of the Coord structure that is passed by reference.
 * @param x: The x coordinate.
 * @param y: The y coordinate.
*/
void Coord_Set(Coord* self, int x, int y);

/**
 * A structure that stores information about the grid that is used in the
 * window.
*/
typedef struct Grid
{
    Coord* map;
    Coord* prevMap;
    int allocated;
    int width;
    int height;
    int indexer;
} Grid;

/**
 * Constructor for the Grid structure. This method allocates memory allocates
 * memory to the map variable.
 * @param width: The number of points in the grid in the x axis.
 * @param height: The number of points in the grid in the y axis.
 * @return 0 for 'success', 1 for 'failure to allocate memory', 2 for 'self does 
 *      not contain an instance of grid'
*/
int Grid_Init(Grid* self, int width, int height);

/**
 * Destructor for the Grid structure. This method frees up the memory allocated 
 * to the map variable.
*/
int Grid_Del(Grid* self);

/**
 * Allows reallocation of the map variable.
 * @return 0 for 'success', 1 for 'failure to allocate memory', 2 for 'self does 
 *      not contain an instance of grid', -1 for 'not implementated'.
 * @todo NOT Implementated.
*/
int Grid_Realloc(Grid* self);

/**
 * Adds a mark to the grid that will be displayed in the window.
 * @param x: The x coordinate to be marked.
 * @param y: The y coordinate to be marked.
 * @return 0 for 'success', 1 for 'map variable not allocated', 2 for 'self does 
 *      not contain an instance of grid', 3 for 'grid reached array limit', 4
 *      for 'could not find available index'.
*/
int Grid_AddMark(Grid* self, int x, int y);

/**
 * Removes the mark specified.
 * @param x: The x coordinate of the mark to be removed.
 * @param y: The y coordinate of the mark to be removed.
 * @return 0 for 'success', 1 for 'map variable not allocated', 2 for 'self does 
 *      not contain an instance of grid', 3 for 'grid reached array limit', 3
 *      for 'grid is empty', 4 for 'could not find index'.
 * @bug Extra blocks may expectedly be rendered.
*/
int Grid_RemoveMark(Grid* self, int x, int y);

/**
 * Finds the index of the point based on the coordinates specified.
 * @param x: The x coordinate of the mark.
 * @param y: The y coordinate of the mark.
 * @return The index of the point specified. OR '-1' for
 *      map variable not allocated, -2 for 'self does not contain an instance
 *      of grid', -3 for 'index not found'.
*/
int Grid_FindMark(Grid* self, int x, int y);

/**
 * Finds the next empty index available in the map array.
 * @return The index of a point that the has not got a coordinates. OR '-1' for
 *      map variable not allocated, -2 for 'self does not contain an instance
 *      of grid', -3 for 'no available index found'.
*/
int Grid_GetNextEmptyIndex(Grid* self);

#endif // GRID_H