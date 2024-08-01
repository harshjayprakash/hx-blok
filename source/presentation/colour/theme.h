#ifndef NEON_THEME_H
#define NEON_THEME_H

typedef enum _NeonTheme
{
    NeonUnsetTheme,
    NeonLightTheme,
    NeonDarkTheme,
    NeonCustomTheme,
} NeonTheme;

void NeonUpdateColours(void);

void NeonSetColours(
    unsigned long background, 
    unsigned long foreground, 
    unsigned long accent
);

NeonTheme NeonGetTheme(void);

void NeonSetTheme(NeonTheme inTheme);

unsigned long NeonGetForegroundColour(void);

unsigned long NeonGetBackgroundColour(void);

unsigned long NeonGetAccentColour(void);

#endif