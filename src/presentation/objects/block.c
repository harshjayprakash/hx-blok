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

    mMovableSquareAsRect = (RECT) {
        mMovableSquare.position.x,
        mMovableSquare.position.y,
        (mMovableSquare.position.x + mMovableSquare.size.width),
        (mMovableSquare.position.y + mMovableSquare.size.height)
    };
}

void NeonRenderBlock(HDC displayContext)
{
    FillRect(displayContext, &mMovableSquareAsRect, NeonGetAccentBrush());
}

void NeonMoveBlock(NeonDirection direction)
{
    switch (direction)
    {
    case NeonNorth:
        NeonSetYPosition(&(mMovableSquare.position), mMovableSquare.position.y - mMovableSquare.size.height);
        break;
    case NeonEast:
        NeonSetXPosition(&(mMovableSquare.position), mMovableSquare.position.x + mMovableSquare.size.width);
        break;
    case NeonSouth:
        NeonSetYPosition(&(mMovableSquare.position), mMovableSquare.position.y + mMovableSquare.size.height);
        break;
    case NeonWest:
        NeonSetXPosition(&(mMovableSquare.position), mMovableSquare.position.x - mMovableSquare.size.width);
        break;
    }

    mMovableSquareAsRect = (RECT) {
        mMovableSquare.position.x,
        mMovableSquare.position.y,
        (mMovableSquare.position.x + mMovableSquare.size.width),
        (mMovableSquare.position.y + mMovableSquare.size.height)
    };
}

void NeonFreeBlockObject()
{
    NeonLog(NeonInformation, NeonCreateResult(NeonNone, L"Destroying movable square object."));
}