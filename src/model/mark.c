/**
 * @file mark.c
 * @version 0.7.1
 * @date 14-09-2023
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

int blokMarkEquals(struct Mark firstMark, struct Mark secondMark)
{
    if (firstMark.positionX == secondMark.positionX 
        && firstMark.positionY == secondMark.positionY)
    {
        return BLOK_OBJECt_EQUALS;
    }

    return BLOK_OBJECT_NOT_EQUALS;
}

void blokMarkPrint(struct Mark *mark)
{
    if (!mark)
    {
        return;
    }

    (void)printf(
        "Mark ( X: %d, Y: %d )\n", 
        mark->positionX, mark->positionY);
}