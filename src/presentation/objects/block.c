/**
 * \file block.c
 * \date 13-08-2024
 * \brief Function implementation for the block object.
 *
 * This file contains the implementaion for the block object.
 */

#include "block.h"
#include "../../core/args.h"
#include "../../core/log.h"
#include "../../core/result.h"
#include "../../model/object/square.h"
#include "../graphics/drawing.h"
#include "obstructables.h"


static NeonSquare mMovableSquare = {0};
static NeonSquare mProjectedSquare = {0};
static NeonSize mMovableSquareBoundary = {0};
static RECT mMovableSquareAsRect = {0};
static RECT mMovableSquareInnerAsRect = {0};

void NeonInitBlockObject(void)
{
    mMovableSquare =
        NeonCreateSquare(NeonCreatePosition(0, 0),
                         NeonCreateSize(NeonGetBlockScale(), NeonGetBlockScale()));

    mMovableSquareAsRect =
        (RECT){mMovableSquare.position.x, mMovableSquare.position.y,
               (mMovableSquare.position.x + mMovableSquare.size.width),
               (mMovableSquare.position.y + mMovableSquare.size.height)};

    mMovableSquareInnerAsRect =
        (RECT){mMovableSquare.position.x + 5, mMovableSquare.position.y + 5,
               (mMovableSquare.position.x + (mMovableSquare.size.width - 5)),
               (mMovableSquare.position.y + (mMovableSquare.size.height - 5))};

    NeonLog(NeonInformation,
            NeonCreateResult(NeonNone, L"Initialised Movable Block Object."));
}

void NeonRenderBlock(HDC displayContext)
{
    FillRect(displayContext, &mMovableSquareAsRect, NeonGetAccentBrush());
    FillRect(displayContext, &mMovableSquareInnerAsRect, NeonGetBackgroundBrush());
}

static int _NeonCanMoveBlock()
{
    int insideBoundary = (mProjectedSquare.position.x >= 0 &&
                          mProjectedSquare.position.x < mMovableSquareBoundary.width &&
                          mProjectedSquare.position.y >= 0 &&
                          mProjectedSquare.position.y < mMovableSquareBoundary.height);

    int hitWall = 0;

    for (int index = 0; index < NeonGetObstrutableCount(); index++)
    {
        NeonPosition pos = NeonGetObstructableAtIndex(index);

        if (pos.x == mProjectedSquare.position.x && pos.y == mProjectedSquare.position.y)
        {
            hitWall = 1;
        }
    }

    return (insideBoundary == 1 && hitWall == 0);
}

void NeonMoveBlock(NeonDirection direction)
{
    NeonCopySquare(&mProjectedSquare, mMovableSquare);

    switch (direction)
    {
    case NeonNorth:
        NeonSetYPosition(&(mProjectedSquare.position),
                         mProjectedSquare.position.y - mProjectedSquare.size.height);
        break;
    case NeonEast:
        NeonSetXPosition(&(mProjectedSquare.position),
                         mProjectedSquare.position.x + mProjectedSquare.size.width);
        break;
    case NeonSouth:
        NeonSetYPosition(&(mProjectedSquare.position),
                         mProjectedSquare.position.y + mProjectedSquare.size.height);
        break;
    case NeonWest:
        NeonSetXPosition(&(mProjectedSquare.position),
                         mProjectedSquare.position.x - mProjectedSquare.size.width);
        break;
    }

    if (_NeonCanMoveBlock())
    {
        NeonCopySquare(&mMovableSquare, mProjectedSquare);
    }

    mMovableSquareAsRect =
        (RECT){mMovableSquare.position.x, mMovableSquare.position.y,
               (mMovableSquare.position.x + mMovableSquare.size.width),
               (mMovableSquare.position.y + mMovableSquare.size.height)};

    mMovableSquareInnerAsRect =
        (RECT){mMovableSquare.position.x + 5, mMovableSquare.position.y + 5,
               (mMovableSquare.position.x + (mMovableSquare.size.width - 5)),
               (mMovableSquare.position.y + (mMovableSquare.size.height - 5))};
}

void NeonSetBlockBoundary(const NeonSize size)
{
    NeonCopySize(&mMovableSquareBoundary, size);
}

NeonSquare *NeonGetBlockAsPointer(void)
{
    return &mMovableSquare;
}

RECT NeonGetBlockAsRect(void)
{
    return mMovableSquareAsRect;
}

void NeonFreeBlockObject(void)
{
    NeonLog(NeonInformation,
            NeonCreateResult(NeonNone, L"Cleaned Up Movable Block Object."));
}