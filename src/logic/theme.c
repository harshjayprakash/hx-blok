#include "theme.h"

static enum Theme theme = ThemeLight;

void blokThemeSet(enum Theme _theme)
{
    theme = _theme;
}

enum Theme blokThemeGet(void)
{
    return theme;
}
