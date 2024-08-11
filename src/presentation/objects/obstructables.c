#include "obstructables.h"
#include "../../model/utility/vector.h"

static NeonVector mObstructableSquares = { 0 };

void NeonInitObstructables(void)
{
    mObstructableSquares = NeonCreateVector(100);

    for (int index = 0; index < mObstructableSquares.max; index++)
    {
        NeonCopyPosition(
            &(NeonGetNodeAsPointer(&mObstructableSquares, index)->position), 
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