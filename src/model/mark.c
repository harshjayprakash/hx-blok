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