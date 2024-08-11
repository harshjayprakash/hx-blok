#include "obstructables.h"
#include "../../model/utility/vector.h"

static NeonVector mObstructableSquares = { 0 };

void NeonInitObstructables(void)
{
    mObstructableSquares = NeonCreateVector(10);

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

}

void NeonFreeObstructables(void)
{
    NeonDestroyVector(&mObstructableSquares);
}