/**
 * \file theme.c
 * \date 13-08-2024
 * \brief Implementation of the functions related to theme managing.
 * 
 * This file contains implementation of functions required for theming.
 */

#include "theme.h"

static NeonTheme mTheme = NeonUnsetTheme;

static unsigned long mBlackColour = RGB(0, 0, 0);
static unsigned long mWhiteColour = RGB(255, 255, 255);
static unsigned long mBlueColour = RGB(0, 0, 255);
static unsigned long mAquaColour = RGB(0, 255, 255);

static unsigned long mBackgroundColour = 0UL;
static unsigned long mForegroundColour = 0UL;
static unsigned long mAccentColour = 0UL;

void NeonUpdateColours(void)
{
    switch (mTheme)
    {
    case NeonLightTheme:
        mBackgroundColour = mWhiteColour;
        mForegroundColour = mBlackColour;
        mAccentColour = mBlueColour;
        return;
    case NeonUnsetTheme:
    case NeonDarkTheme:
    default:
        mBackgroundColour = mBlackColour;
        mForegroundColour = mWhiteColour;
        mAccentColour = mAquaColour;
        return;
    }
}

void NeonSetTheme(const NeonTheme theme)
{
    mTheme = theme;
}

unsigned long NeonGetBackgroundColour(void)
{
    return mBackgroundColour;
}

unsigned long NeonGetForegroundColour(void)
{
    return mForegroundColour;
}

unsigned long NeonGetAccentColour(void)
{
    return mAccentColour;
}

