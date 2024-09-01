/**
 * \file drawing.c
 * \date 13-08-2024
 * \brief Implementation of the drawing module.
 *
 * This file contains the implementation for the drawing functions for the tools required
 * for drawing to the display.
 */

#include "drawing.h"
#include "../../core/log.h"
#include "theme.h"

static HBRUSH mBackgroundBrush = {0};
static HBRUSH mForegroundBrush = {0};
static HBRUSH mAccentBrush = {0};
static HPEN mForegroundPen = {0};

void NeonInitDrawingTools(void)
{
    mBackgroundBrush = CreateSolidBrush(NeonGetBackgroundColour());
    mForegroundBrush = CreateSolidBrush(NeonGetForegroundColour());
    mAccentBrush = CreateSolidBrush(NeonGetAccentColour());
    mForegroundPen = CreatePen(PS_SOLID, 2, NeonGetForegroundColour());

    NeonLog(NeonInformation,
            NeonCreateResult(NeonNone, L"Initialied GDI Drawing Tools."));
}

HBRUSH NeonGetBackgroundBrush(void)
{
    return mBackgroundBrush;
}

HBRUSH NeonGetForegroundBrush(void)
{
    return mForegroundBrush;
}

HBRUSH NeonGetAccentBrush(void)
{
    return mAccentBrush;
}

HPEN NeonGetForegroundPen(void)
{
    return mForegroundPen;
}

void NeonFreeDrawingTools(void)
{
    (void)DeleteObject(mBackgroundBrush);
    (void)DeleteObject(mForegroundBrush);
    (void)DeleteObject(mAccentBrush);
    (void)DeleteObject(mForegroundPen);

    NeonLog(NeonInformation,
            NeonCreateResult(NeonNone, L"Cleaned Up GDI Drawing Tools."));
}