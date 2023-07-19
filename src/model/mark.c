/**
 * @file mark.c
 * @version 0.6.1
 * @date 18-07-2023
 * 
 * @brief Implementation of the mark.
 * 
 * This file contains the implementation of the mark as defined in the corresponding 
 * header file.
 * 
 * @implements mark.h
 */

#include "mark.h"

struct Mark blokMarkNew(int _positionX, int _positionY)
{
    return (struct Mark){ _positionX, _positionY };
}

void blokMarkPositionSet(struct Mark *mark, int _positionX, int _positionY)
{
    if (!mark)
    {
        return;
    }

    mark->positionX = _positionX;
    mark->positionY = _positionY;
}