/**
 * @file theme.c
 * @version 0.7.1
 * @date 14-09-2023
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
 * @brief Stores the colour aqua.
 */
static unsigned long colourAqua = RGB(0, 229, 229);

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
    case ThemeLight:
        return colourBlack;
    case ThemeDark:
    default:
        return colourWhite;
    }
}

unsigned long blokColourMarkGet(void)
{
    switch (theme)
    {
    case ThemeLight:
        return colourBlue;
    case ThemeDark:
    default:
        return colourAqua;
    }
}
