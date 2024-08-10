/**
 * @file block.c
 * @date 2024-08-10
 * @brief
 */

#include "block.h"
#include "../graphics/drawing.h"
#include "../../core/log.h"
#include "../../core/result.h"

static NeonSquare mMovableSquare = { 0 };
static RECT mMovableSquareAsRect = { 0 };

void NeonInitBlockObject(void)
{
    NeonLog(NeonInformation, NeonCreateResult(NeonNone, L"Initialising movable square object."));
    mMovableSquare = NeonCreateSquare(
        NeonCreatePosition(0, 0),
        NeonCreateSize(15, 15)
    );
}

void NeonRenderBlock(HDC displayContext)
{
    mMovableSquareAsRect = (RECT) {
        mMovableSquare.position.x,
        mMovableSquare.position.y,
        (mMovableSquare.position.x + mMovableSquare.size.width),
        (mMovableSquare.position.y + mMovableSquare.size.height)
    };

    FillRect(displayContext, &mMovableSquareAsRect, NeonGetAccentBrush());
}

void NeonFreeBlockObject()
{
    NeonLog(NeonInformation, NeonCreateResult(NeonNone, L"Destroying movable square object."));
}