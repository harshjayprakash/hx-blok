#include "keyboard.h"
#include "../../model/objects/square.h"
#include "../components/block.h"
#include "../../model/utilities/direction.h"

void NeonArrowsKeyboardEvent(WPARAM inWordParam)
{
    NeonCompass directionToMove;

    switch ((int)inWordParam)
    {
    case VK_UP:
        directionToMove = NeonNorth;
        break;
    case VK_RIGHT:
        directionToMove = NeonEast;
        break;
    case VK_DOWN:
        directionToMove = NeonSouth;
        break;
    case VK_LEFT:
        directionToMove = NeonWest;
        break;
    default:
        return;
    }

    NeonMoveSquare(NeonGetBlockReference(), directionToMove);
}