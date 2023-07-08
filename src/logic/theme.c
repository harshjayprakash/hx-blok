#include "theme.h"

static enum Theme theme = ThemeLight;
static unsigned long colourBlack = RGB(0, 0, 0);
static unsigned long colourWhite = RGB(255, 255, 255);
static unsigned long colourBlue = RGB(0, 15, 254);
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
