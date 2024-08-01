#include "theme.h"
#include <windows.h>

static NeonTheme theme = NeonUnsetTheme;

static unsigned long black = RGB(0, 0, 0);
static unsigned long white = RGB(255, 255, 255);
static unsigned long blue = RGB(0, 0, 255);
static unsigned long aqua = RGB(0, 255, 255);

static unsigned long background = 0UL;
static unsigned long foreground = 0UL;
static unsigned long accent = 0UL;

void NeonUpdateColours(void)
{
    switch (theme) {
    case NeonLightTheme:
        background = white;
        foreground = black;
        accent = blue;
        return;
    case NeonUnsetTheme:
    case NeonDarkTheme:
    case NeonCustomTheme:
    default:
        background = black;
        foreground = white;
        accent = aqua;
        return;
    }
}

void NeonSetColours(
    unsigned long inBackground, 
    unsigned long inForeground, 
    unsigned long inAccent
)
{
    background = inBackground;
    foreground = inForeground;
    accent = inAccent;
}


NeonTheme NeonGetTheme(void)
{
    return theme;
}

void NeonSetTheme(NeonTheme inTheme)
{
    theme = inTheme;
}

unsigned long NeonGetForegroundColour(void)
{
    return foreground;
}

unsigned long NeonGetBackgroundColour(void)
{
    return background;
}

unsigned long NeonGetAccentColour(void)
{
    return accent;
}