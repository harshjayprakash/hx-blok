/**
 * @file panel.c
 * @date 2024-08-11
 * @brief
 */

#include "panel.h"
#include "../window.h"
#include "../graphics/drawing.h"
#include "../graphics/theme.h"
#include "../../model/object/square.h"
#include "../../core/log.h"
#include "../objects/block.h"
#include "../objects/obstructables.h"

static RECT mPanelArea = { 0 };
static wchar_t mCoordinates[60];
static RECT mVectorMemoryOutline = { 0 };
static RECT mVectorMemoryBar = { 0 };


void NeonInitPanelComponent(void)
{
    (void) wcsncpy(mCoordinates, L"( X: 0, Y: 0 )", 60);
    NeonUpdatePanelSize();
}

void NeonRenderPanelComponent(HDC displayContext)
{
    (void) SelectObject(displayContext, NeonGetBackgroundBrush());
    (void) SelectObject(displayContext, NeonGetForegroundPen());
    (void) Rectangle(displayContext, mPanelArea.left, mPanelArea.top, mPanelArea.right, mPanelArea.bottom);
    (void) Rectangle(displayContext, mVectorMemoryOutline.left, mVectorMemoryOutline.top, mVectorMemoryOutline.right, mVectorMemoryOutline.bottom);
    (void) FillRect(displayContext, &mVectorMemoryBar, NeonGetForegroundBrush());
    (void) SetBkColor(displayContext, NeonGetBackgroundColour());
    (void) SetTextColor(displayContext, NeonGetForegroundColour());
    (void) TextOutW(displayContext, 15, mPanelArea.top + 10, mCoordinates, (int) wcslen(mCoordinates));
}

void NeonUpdateCoordinatesText(void)
{
    NeonSquare *square = NeonGetBlockAsPointer();

    if (!square)
    {
        NeonLog(NeonWarning, NeonCreateResult(NeonNullPtr, L"Failed to update coordinates: square is null"));
        return;
    }

    (void) swprintf(
        mCoordinates, 60, L"( X: %d, Y: %d )",
        square->position.x, square->position.y
    );
}

void NeonUpdatePanelSize(void)
{
    RECT windowArea = NeonGetWindowArea();

    mPanelArea = (RECT) { 
        windowArea.left + 2, 
        windowArea.bottom - 40, 
        windowArea.right - 1, 
        windowArea.bottom - 1};
    
    mVectorMemoryOutline = (RECT) {
        mPanelArea.right - 110,
        mPanelArea.bottom - 30,
        mPanelArea.right - 10,
        mPanelArea.bottom - 10
    };

}

void NeonUpdateVectorMemoryBar(void)
{
    mVectorMemoryBar = (RECT) {
        mVectorMemoryOutline.left + 2,
        mVectorMemoryOutline.top + 2,
        mVectorMemoryOutline.right,
        mVectorMemoryOutline.bottom - 3
    };
    mVectorMemoryBar.right = (mVectorMemoryOutline.left + 2) + (NeonGetVectorMemoryPercentage() * 100);
}

void NeonFreePanelComponent(void)
{

}