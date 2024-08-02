#include "canvas.h"
#include "../graphics/renderer.h"

static NeonSquare mMovableSquare = { 0 };
static RECT mMovableSquareConvert = { 0 };

void NeonInitCanvas(void)
{
    mMovableSquare = NeonNewSquare(0, 0, 15, 15);
}

NeonSquare *NeonGetBlockReference(void)
{
    return &mMovableSquare;
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
}