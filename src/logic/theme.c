/**
 * @file theme.c
 * @version 0.6.1
 * @date 18-07-2023
 * 
 * @brief Theme management.
 * 
 * This file contains the functions for theme management as defined in correspondance to
 * the header file. In addition, including addtional static properties for encapsulation.
 * 
 * @implements theme.h
 */

#include "theme.h"

/**
 * @brief Stores the current theme of the program.
 */
static enum Theme theme = Unset;

/**
 * @brief Store the colour black.
 */
static unsigned long colourBlack = RGB(0, 0, 0);

/**
 * @brief Stores the colour white.
 */
static unsigned long colourWhite = RGB(255, 255, 255);

/**
 * @brief Stores the colour blue.
 */
static unsigned long colourBlue = RGB(0, 15, 254);

/**
 * @brief Stores the colour pink.
 */
static unsigned long colourPink = RGB(255, 32, 100);

void blokThemeSet(enum Theme _theme)
{
    theme = _theme;
}

enum Theme blokThemeGet(void)
{
    return theme;
}

unsigned long blokColourBackgroundGet(void)
{
    switch (theme)
    {
    case ThemeDark:
        return colourBlack;
    case ThemeLight:
    default:
        return colourWhite;
    }
}

unsigned long blokColourForegroundGet(void)
{
    switch (theme)
    {
    case ThemeDark:
        return colourWhite;
    case ThemeLight:
    default:
        return colourBlack;
    }
}

unsigned long blokColourMarkGet(void)
{
    switch (theme)
    {
    case ThemeDark:
        return colourBlue;
    case ThemeLight:
    default:
        return colourPink;
    }
}
