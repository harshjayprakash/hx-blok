#include "canvas.h"
#include "../graphics/renderer.h"
#include "../../model/objects/vector.h"

static NeonSquare mMovableSquare = { 0 };
static NeonVector mMarkedSquares = { 0 };
static RECT mMovableSquareConvert = { 0 };

void NeonInitCanvas(void)
{
    mMovableSquare = NeonNewSquare(0, 0, 15, 15);
    mMarkedSquares = NeonNewVector(10);
    NeonPrintVector(mMarkedSquares);
}

NeonSquare *NeonGetBlockReference(void)
{
    return &mMovableSquare;
}

NeonVector *NeonGetVectorReference(void)
{
    return &mMarkedSquares;
}

void NeonRenderCanvas(HDC displayContext)
{
    mMovableSquareConvert = (RECT) {
        mMovableSquare.position.x,
        mMovableSquare.position.y,
        (mMovableSquare.position.x + mMovableSquare.size.width),
        (mMovableSquare.position.y + mMovableSquare.size.height)
    };

    FillRect(
        displayContext, 
        &mMovableSquareConvert,
        NeonGetAccentBrush()
    );

    for (int index = 0; index < mMarkedSquares.max; index++)
    {
        NeonVectorItem *region = (mMarkedSquares.array + index);

        if (region->coordinates.x == -1 || region->coordinates.y == -1) { continue; }

        RECT markToPaint = {
            region->coordinates.x,
            region->coordinates.y,
            (region->coordinates.x + mMovableSquare.size.width),
            (region->coordinates.y + mMovableSquare.size.height)
        };

        (void) FillRect(displayContext, &markToPaint, NeonGetForegroundBrush());
    }

}

void NeonFreeCanvas(void)
{
    NeonFreeVector(&mMarkedSquares);
}