/**
 * \file panel.c
 * \date 13-08-2024
 * \brief Function implementation for the panel component.
 *
 * This file contains the function implementation for the panel component for intialising,
 * rendering, releasing resources and state changes.
 */

#include "panel.h"
#include "../../core/log.h"
#include "../../model/object/square.h"
#include "../graphics/drawing.h"
#include "../graphics/theme.h"
#include "../objects/block.h"
#include "../objects/obstructables.h"
#include "../window.h"
#include <wchar.h>
#include <wingdi.h>


static RECT mPanelArea = {0};
static wchar_t mCoordinates[60];
static RECT mVectorMemoryOutline = {0};
static RECT mVectorMemoryBar = {0};
static wchar_t mObstructableSquaresCount[60];

static wchar_t mClearAll[60] = L"Clear All";
static RECT mClearAllButtonArea = {0};

static wchar_t mLock[60] = L"Lock";
static RECT mLockToggleArea = {0};
static RECT mLockToggleAreaSelect = {0};
static int mLockSelected = 0;

void NeonInitPanelComponent(void)
{
    (void)wcsncpy(mCoordinates, L"( X: 0, Y: 0 )", 60);
    (void)wcsncpy(mObstructableSquaresCount, L"0", 60);
    NeonUpdatePanelSize();
}

void NeonRenderPanelComponent(HDC displayContext)
{
    (void)SelectObject(displayContext, NeonGetBackgroundBrush());
    (void)SelectObject(displayContext, NeonGetForegroundPen());
    (void)Rectangle(displayContext, mPanelArea.left, mPanelArea.top, mPanelArea.right,
                    mPanelArea.bottom);
    (void)Rectangle(displayContext, mVectorMemoryOutline.left, mVectorMemoryOutline.top,
                    mVectorMemoryOutline.right, mVectorMemoryOutline.bottom);
    (void)FillRect(displayContext, &mVectorMemoryBar, NeonGetForegroundBrush());
    (void)SetBkColor(displayContext, NeonGetBackgroundColour());
    (void)SetTextColor(displayContext, NeonGetForegroundColour());
    (void)TextOutW(displayContext, 15, mPanelArea.top + 10, mCoordinates,
                   (int)wcslen(mCoordinates));
    (void)TextOutW(displayContext, mVectorMemoryOutline.left - 30, mPanelArea.top + 10,
                   mObstructableSquaresCount, (int)wcslen(mObstructableSquaresCount));
    (void)Rectangle(displayContext, mClearAllButtonArea.left, mClearAllButtonArea.top,
                    mClearAllButtonArea.right, mClearAllButtonArea.bottom);
    (void)TextOutW(displayContext, 200, mPanelArea.top + 10, mClearAll,
                   (int)wcslen(mClearAll));
    (void)Rectangle(displayContext, mLockToggleArea.left, mLockToggleArea.top,
                    mLockToggleArea.right, mLockToggleArea.bottom);
    if (mLockSelected)
    {
    (void)Rectangle(displayContext, mLockToggleAreaSelect.left, mLockToggleAreaSelect.top,
                    mLockToggleAreaSelect.right, mLockToggleAreaSelect.bottom);
    }
    (void)TextOutW(displayContext, 300, mPanelArea.top + 10, mLock,
                   (int)wcslen(mLock));
}

void NeonUpdateCoordinatesText(void)
{
    NeonSquare *square = NeonGetBlockAsPointer();

    if (!square)
    {
        NeonLog(NeonWarning,
                NeonCreateResult(NeonNullPtr,
                                 L"Failed to update coordinates: square is null"));
        return;
    }

    (void)swprintf(mCoordinates, 60, L"( X: %d, Y: %d )", square->position.x,
                   square->position.y);
}

void NeonUpdateSquareCountText(void)
{
    (void)swprintf(mObstructableSquaresCount, 60, L"%d", NeonGetObstrutableCount());
}

void NeonUpdatePanelSize(void)
{
    RECT windowArea = NeonGetWindowArea();

    mPanelArea = (RECT){windowArea.left + 2, windowArea.bottom - 40, windowArea.right - 1,
                        windowArea.bottom - 1};

    mVectorMemoryOutline = (RECT){mPanelArea.right - 110, mPanelArea.bottom - 30,
                                  mPanelArea.right - 10, mPanelArea.bottom - 10};

    mClearAllButtonArea.left = 197;
    mClearAllButtonArea.top = mPanelArea.top + 8;
    mClearAllButtonArea.right = mClearAllButtonArea.left + 62;
    mClearAllButtonArea.bottom = mClearAllButtonArea.top + 20;

    mLockToggleArea.left = mClearAllButtonArea.right + 10;
    mLockToggleArea.top = mPanelArea.top + 8;
    mLockToggleArea.right = mLockToggleArea.left + 20;
    mLockToggleArea.bottom = mLockToggleArea.top + 20;

    mLockToggleAreaSelect = (RECT){
        mLockToggleArea.left + 5,
        mLockToggleArea.top + 5,
        mLockToggleArea.right - 5,
        mLockToggleArea.bottom - 5,
    };

    NeonUpdateVectorMemoryBar();
}

void NeonUpdateVectorMemoryBar(void)
{
    mVectorMemoryBar =
        (RECT){mVectorMemoryOutline.left + 2, mVectorMemoryOutline.top + 2,
               mVectorMemoryOutline.right, mVectorMemoryOutline.bottom - 3};
    mVectorMemoryBar.right =
        (mVectorMemoryOutline.left) + (NeonGetVectorMemoryPercentage() * 100);
    NeonUpdateSquareCountText();
}

int NeonIsInClearButtonArea(const int x, const int y)
{
    return (x > mClearAllButtonArea.left - 1 && x < mClearAllButtonArea.right + 1 &&
            y > mClearAllButtonArea.top - 1 && y < mClearAllButtonArea.bottom + 1);
}

int NeonIsInLockToggleArea(const int x, const int y)
{
    return (x > mLockToggleArea.left - 1 && x < mLockToggleArea.right + 1 &&
            y > mLockToggleArea.top - 1 && y < mLockToggleArea.bottom + 1);
}

void NeonLockToggleButton(void)
{
    mLockSelected = (mLockSelected) ? 0 : 1;
}

int NeonIsLocked(void)
{
    return mLockSelected;
}

void NeonFreePanelComponent(void)
{
}