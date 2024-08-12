#include "obstructables.h"
#include "../../model/utility/vector.h"
#include "../graphics/drawing.h"
#include "block.h"
#include "../window.h"
#include <wingdi.h>

static NeonVector mObstructableSquares = { 0 };

void NeonInitObstructables(void)
{
    mObstructableSquares = NeonCreateVector(2);

    for (int index = 0; index < mObstructableSquares.max; index++)
    {
        NeonNode *nodePtr = NeonGetNodeAsPointer(&mObstructableSquares, index);

        if (!nodePtr) { continue; }

        nodePtr->indexed = 0;
        NeonCopyPosition(
            &(nodePtr->position), 
            NeonCreatePosition(-1, -1)
        );
    }
}

void NeonRenderObstructables(HDC displayContext)
{
    NeonSquare *square = NeonGetBlockAsPointer();

    if (!square) 
    { 
        NeonLog(NeonError, NeonCreateResult(NeonNullPtr, L"Failed to paint obstructable squares: square reference is null"));
        return; 
    }

    for (int index = 0; index < mObstructableSquares.max; index++)
    {
        NeonNode *nodePtr = NeonGetNodeAsPointer(&mObstructableSquares, index);

        if (!nodePtr) { continue; }

        if (nodePtr->position.x == -1 || nodePtr->position.y == -1 || nodePtr->indexed == 0)
        {
            continue;
        }

        RECT nodeAsRect = { nodePtr->position.x, nodePtr->position.y, nodePtr->position.x +  square->size.width, nodePtr->position.y + square->size.height};

        (void) FillRect(displayContext, &nodeAsRect, NeonGetForegroundBrush());
    }


}

void NeonAddObstrutable(const NeonPosition position)
{
    NeonNode node = {
        position, 1
    };

    NeonPushNode(&mObstructableSquares, node);

    InvalidateRect(NeonGetWindowHandle(), NULL, TRUE);
}

void NeonClearObstrutables(void)
{
    NeonClearVector(&mObstructableSquares);
}

int NeonGetObstrutableCount(void)
{
    return mObstructableSquares.size;
}

float NeonGetVectorMemoryPercentage(void)
{
    return ((mObstructableSquares.size * 1.0) / (mObstructableSquares.max * 1.0));
}

NeonPosition NeonGetObstructableAtIndex(int index)
{
    NeonPosition result = { -1, -1 };
    NeonNode *nodePtr = NeonGetNodeAsPointer(&mObstructableSquares, index);

    if (!nodePtr) 
    {
        return result;
    }

    NeonCopyPosition(&result, nodePtr->position);
    return result;
}

void NeonFreeObstructables(void)
{
    NeonDestroyVector(&mObstructableSquares);
}