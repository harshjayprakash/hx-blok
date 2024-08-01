#include "block.h"

static NeonSquare mMovableSquare = { 0 };
static RECT mMovableSquareConvert = { 0 };

void NeonInitBlock(void)
{
    mMovableSquare = NeonNewSquare(0, 0, 15, 15);
}

NeonSquare *NeonGetBlockReference(void)
{
    return &mMovableSquare;
}

void NeonRenderBlock(HDC inDisplayContextHandle, HBRUSH accentBrushHandle)
{
    mMovableSquareConvert = (RECT) {
        mMovableSquare.position.x,
        mMovableSquare.position.y,
        (mMovableSquare.position.x + mMovableSquare.size.width),
        (mMovableSquare.position.y + mMovableSquare.size.height)
    };

    FillRect(
        inDisplayContextHandle, 
        &mMovableSquareConvert,
        accentBrushHandle
    );
}