#ifndef BLOK_LOGIC_THEME_H
#define BLOK_LOGIC_THEME_H

#include <Windows.h>

enum TTheme
{
    BLOK_THEME_UNSET,
    BLOK_THEME_LIGHT,
    BLOK_THEME_DARK,
};

void blokThemeSet(enum TTheme theme);

enum TTheme blokThemeGet(void);

unsigned long blokColourBackgroundGet(void);

unsigned long blokColourForegroundGet(void);

unsigned long blokColourMarkGet(void);


#endif