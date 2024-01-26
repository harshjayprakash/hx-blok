#include "theme.h"

static enum TTheme programTheme = BLOK_THEME_UNSET;

static unsigned long colourBlack = RGB(0, 0, 0);

static unsigned long colourWhite = RGB(255, 255, 255);

static unsigned long colourBlue = RGB(0, 15, 254);

static unsigned long colourAqua = RGB(0, 229, 229);

void blokThemeSet(enum TTheme theme)
{
    programTheme = theme;
}

enum TTheme blokThemeGet(void)
{
    return programTheme;
}

unsigned long blokColourBackgroundGet(void)
{
    switch (programTheme)
    {

    case BLOK_THEME_LIGHT:
        return colourWhite;
    case BLOK_THEME_DARK:
    default:
        return colourBlack;
    }
}

unsigned long blokColourForegroundGet(void)
{
    switch (programTheme)
    {
    case BLOK_THEME_LIGHT:
        return colourBlack;
    case BLOK_THEME_DARK:
    default:
        return colourWhite;
    }
}

unsigned long blokColourMarkGet(void)
{
    switch (programTheme)
    {
    case BLOK_THEME_LIGHT:
        return colourBlue;
    case BLOK_THEME_DARK:
    default:
        return colourAqua;
    }
}
