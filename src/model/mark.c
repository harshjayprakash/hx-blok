#include "mark.h"

struct Mark blokMarkNew(int _positionX, int _positionY)
{
    return (struct Mark){ _positionX, _positionY };
}

void blokMarkPositionSet(struct Mark *mark, int _positionX, int _positionY)
{
    BLOK_EXIT_IF(!mark);

    mark->positionX = _positionX;
    mark->positionY = _positionY;
}