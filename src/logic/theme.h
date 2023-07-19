#ifndef BLOK_THEME_H
#define BLOK_THEME_H

#include <Windows.h>

enum Theme
{
    Unset,
    ThemeLight,
    ThemeDark
};

void blokThemeSet(enum Theme _theme);

enum Theme blokThemeGet(void);

unsigned long blokColourBackgroundGet(void);

unsigned long blokColourForegroundGet(void);

unsigned long blokColourMarkGet(void);

#endif
