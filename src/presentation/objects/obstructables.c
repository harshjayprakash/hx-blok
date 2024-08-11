#include "obstructables.h"
#include "../../model/utility/vector.h"

static NeonVector mObstructableSquares = { 0 };

void NeonInitObstructables(void)
{
    mObstructableSquares = NeonCreateVector(100);
}

void NeonRenderObstructables(HDC displayContext)
{

}

void NeonFreeObstructables(void)
{
    NeonDestroyVector(&mObstructableSquares);
}